# titanic_analysis.ipynb

import pandas as pd
import numpy as np
from sklearn.preprocessing import LabelEncoder, StandardScaler
from sklearn.ensemble import RandomForestClassifier
from sklearn.neural_network import MLPClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix
from skopt import BayesSearchCV
from skopt.space import Integer, Real, Categorical
from sklearn.cluster import DBSCAN
from sklearn.decomposition import PCA
import matplotlib.pyplot as plt
import seaborn as sns
from mlxtend.frequent_patterns import apriori, association_rules
from mlxtend.preprocessing import TransactionEncoder
import pickle

# Configurações iniciais
verbose = True

# Carregando os dados
train = pd.read_csv('sample_data/train.csv')
test = pd.read_csv('sample_data/test.csv')
truth = pd.read_csv('sample_data/gender_submission.csv')
test.insert(0, 'Survived', np.nan)

# Tratamento de dados
columns_to_drop = ['PassengerId', 'Name', 'SibSp', 'Parch', 'Ticket', 'Cabin', 'Embarked']
for df in [train, test]:
    df['Age'].fillna(df['Age'].mean(), inplace=True)
    df['Fare'].fillna(df['Fare'].mean(), inplace=True)
    df['Sex'] = LabelEncoder().fit_transform(df['Sex'])
    df['FamilySize'] = df.get('SibSp', 0) + df.get('Parch', 0) + 1
    df['isAlone'] = (df['FamilySize'] == 1).astype(int)

    df[['Age', 'Fare', 'FamilySize']] = StandardScaler().fit_transform(df[['Age', 'Fare', 'FamilySize']])
    df.drop(columns=columns_to_drop, inplace=True)

# Salvar dados limpos
train.to_csv('sample_data/processed_train.csv', index=False)
test.to_csv('sample_data/processed_test.csv', index=False)

# Preparar variáveis para treinamento
X_train = train.drop(columns=['Survived'])
y_train = train['Survived']
X_test = test.drop(columns=['Survived'])
y_test = truth['Survived']

with open('sample_data/train_test_data.pkl', 'wb') as f:
    pickle.dump((X_train, y_train, X_test, y_test), f)

# Otimização Bayesiana - Random Forest
rf_params = {
    'n_estimators': Integer(100, 1000),
    'max_depth': Integer(3, 30),
    'min_samples_split': Integer(2, 20),
    'min_samples_leaf': Integer(1, 20),
    'max_features': Categorical(['sqrt', 'log2', None]),
    'bootstrap': Categorical([True, False])
}
rf_search = BayesSearchCV(RandomForestClassifier(random_state=42), rf_params, n_iter=50, cv=5, scoring='accuracy', n_jobs=-1)
rf_search.fit(X_train, y_train)
best_rf = rf_search.best_estimator_

# Otimização Bayesiana - MLP
mlp_params = {
    'hidden_layer_sizes': Integer(5, 500),
    'activation': Categorical(['tanh', 'relu']),
    'solver': Categorical(['adam', 'sgd']),
    'alpha': Real(1e-5, 1e-1, prior='log-uniform'),
    'learning_rate_init': Real(1e-4, 1e-1, prior='log-uniform')
}
mlp_search = BayesSearchCV(MLPClassifier(max_iter=1000, random_state=42), mlp_params, n_iter=50, cv=5, scoring='accuracy', n_jobs=-1)
mlp_search.fit(X_train, y_train)
best_mlp = mlp_search.best_estimator_

# Avaliação dos modelos
rf_preds = best_rf.predict(X_test)
mlp_preds = best_mlp.predict(X_test)

print("\nRandom Forest")
print("Accuracy:", accuracy_score(y_test, rf_preds))
print(classification_report(y_test, rf_preds))
print("Confusion Matrix:\n", confusion_matrix(y_test, rf_preds))

print("\nMLP Classifier")
print("Accuracy:", accuracy_score(y_test, mlp_preds))
print(classification_report(y_test, mlp_preds))
print("Confusion Matrix:\n", confusion_matrix(y_test, mlp_preds))

# Clustering com DBSCAN
dbscan = DBSCAN(eps=0.5, min_samples=5)
clusters = dbscan.fit_predict(X_train)
X_clustered = train.copy()
X_clustered['Cluster'] = clusters

print("\nClusters encontrados:", len(set(clusters)) - (1 if -1 in clusters else 0))
print("Pontos de ruído:", list(clusters).count(-1))

# Visualização dos clusters
pca = PCA(n_components=2)
X_pca = pca.fit_transform(X_train)
X_clustered['PCA1'], X_clustered['PCA2'] = X_pca[:, 0], X_pca[:, 1]

plt.figure(figsize=(10, 6))
sns.scatterplot(data=X_clustered, x='PCA1', y='PCA2', hue='Cluster', palette='tab10', s=100)
plt.title('Clusters com DBSCAN após PCA')
plt.show()

# Regras de Associação
df_assoc = train.copy()
df_assoc['Sex'] = df_assoc['Sex'].map({0: 'male', 1: 'female'})
df_assoc['Survived'] = df_assoc['Survived'].map({0: 'Not Survived', 1: 'Survived'})
df_assoc['isAlone'] = df_assoc['isAlone'].map({0: 'not alone', 1: 'alone'})
df_assoc['Pclass'] = df_assoc['Pclass'].map({1: '1st class', 2: '2nd class', 3: '3rd class'})

transactions = df_assoc[['Sex', 'Pclass', 'isAlone', 'Survived']].astype(str).values.tolist()
te = TransactionEncoder()
te_ary = te.fit_transform(transactions)
df_encoded = pd.DataFrame(te_ary, columns=te.columns_)

frequent_itemsets = apriori(df_encoded, min_support=0.03, use_colnames=True)
rules = association_rules(frequent_itemsets, metric="confidence", min_threshold=0.6)
rules.sort_values(by='lift', ascending=False, inplace=True)

print("\nTop 10 Regras de Associação:")
print(rules[['antecedents', 'consequents', 'support', 'confidence', 'lift']].head(10))
