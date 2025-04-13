# Instalação da dependência:
# $ pip install mlxtend
# Docs:
# https://rasbt.github.io/mlxtend/user_guide/frequent_patterns/apriori/
# https://rasbt.github.io/mlxtend/user_guide/frequent_patterns/association_rules/

# Bibliotecas
import pandas as pd
from mlxtend.preprocessing import TransactionEncoder
from mlxtend.frequent_patterns import apriori, association_rules

# Leitura do arquivo CSV
dados_brutos = pd.read_csv('supermercado.csv', sep=';', encoding='utf-8')
print("Conteúdo inicial do DataFrame:")
print(dados_brutos)
print("Tamanho da tabela:", dados_brutos.shape)
print("// ============================== //")

# Conversão para lista de transações
colunas = list(dados_brutos.columns)
compras_formatadas = []

for _, linha in dados_brutos.iterrows():
    itens_confirmados = [colunas[i] for i in range(len(colunas)) if linha[i] == 'Sim']
    compras_formatadas.append(itens_confirmados)

print("Transações identificadas:")
print(compras_formatadas)
print("// ============================== //")

# Transformação com TransactionEncoder
encoder = TransactionEncoder()
dados_codificados = encoder.fit_transform(compras_formatadas)
df_binario = pd.DataFrame(dados_codificados, columns=encoder.columns_)
print("DataFrame binário para Apriori:")
print(df_binario)
print("// ============================== //")

# Execução do Apriori
itemsets_freq = apriori(df_binario, min_support=0.3, use_colnames=True)
itemsets_freq['Tamanho'] = itemsets_freq['itemsets'].apply(len)
print("Itemsets frequentes encontrados:")
print(itemsets_freq)
print("// ============================== //")

# Geração de regras de associação
regras_geradas = association_rules(itemsets_freq, metric="confidence", min_threshold=0.8)
print("Regras derivadas:")
print(regras_geradas)
print("// ============================== //")

# Impressão das regras de forma legível
print("Regras formatadas (quem compra leva):")
for _, linha in regras_geradas.iterrows():
    ant = [str(x) for x in linha['antecedents']]
    cons = [str(x) for x in linha['consequents']]
    print(f"Quem compra {', '.join(ant)} também compra {', '.join(cons)}")
