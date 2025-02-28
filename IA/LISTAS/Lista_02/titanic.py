import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier, plot_tree
import matplotlib.pyplot as plt

# Passo 1: Ler a base de dados
df = pd.read_csv('train.csv')

# Passo 2: Pré-processamento
df.drop(["Name", "Ticket", "Cabin"], axis=1, inplace=True)  # Colunas irrelevantes
df.dropna(inplace=True)  # Remover valores nulos

# Transformar variáveis categóricas
df["Sex"] = df["Sex"].map({"male": 0, "female": 1})
df["Embarked"] = df["Embarked"].map({"C": 0, "Q": 1, "S": 2})

# Separando as variáveis
X = df.drop("Survived", axis=1)
y = df["Survived"]

# Passo 3: Dividir os dados em treino e teste
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Passo 4: Criar o modelo
modelo = DecisionTreeClassifier(criterion="entropy", max_depth=3)
modelo.fit(X_train, y_train)

# Passo 5: Visualizar a árvore de decisão
plt.figure(figsize=(15, 10))
plot_tree(modelo, feature_names=X.columns, class_names=["Não Sobreviveu", "Sobreviveu"], filled=True)
plt.show()
