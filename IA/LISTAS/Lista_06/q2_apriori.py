# Instalação da biblioteca necessária
# $ pip install apyori

# Importações
import pandas as pd
from apyori import apriori

# Leitura do arquivo .csv
dados = pd.read_csv('supermercado.csv', sep=';', encoding='utf-8', header=None)
print("Dados carregados:")
print(dados)
print("Dimensões (linhas x colunas):", dados.shape)
print("// ========================== //")

# Extraindo os nomes dos produtos e transações
produtos = dados.iloc[0, 1:].values.tolist()
registros = dados.iloc[1:].reset_index(drop=True)
print("Produtos disponíveis:")
print(produtos)
print("Transações registradas:")
print(registros)
print("// ========================== //")

# Criando lista de listas para as transações
lista_transacoes = []
for _, linha in registros.iterrows():
    itens_presente = [produtos[i] for i in range(len(produtos)) if linha[i + 1] == 'Sim']
    lista_transacoes.append(itens_presente)
lista_transacoes.sort(key=lambda x: len(x))

print("Transações processadas:")
for trans in lista_transacoes:
    print(trans)
print("// ========================== //")

# Aplicação do algoritmo Apriori
regras_encontradas = apriori(lista_transacoes, min_support=0.3, min_confidence=0.8)
resultado = list(regras_encontradas)

print("Total de regras encontradas:", len(resultado))
print("Regras geradas:")
for r in resultado:
    print(r)
print("// ========================== //")

# Organização das regras em DataFrame
col_antecedente = []
col_consequente = []
col_suporte = []
col_confianca = []
col_lift = []

for regra in resultado:
    suporte_regra = regra.support
    estatisticas = regra.ordered_statistics
    for estatistica in estatisticas:
        lhs = list(estatistica.items_base)
        rhs = list(estatistica.items_add)
        conf = estatistica.confidence
        elev = estatistica.lift

        if not lhs or not rhs or 'nan' in lhs or 'nan' in rhs:
            continue

        col_antecedente.append(lhs)
        col_consequente.append(rhs)
        col_suporte.append(suporte_regra)
        col_confianca.append(conf)
        col_lift.append(elev)

tabela_regras = pd.DataFrame({
    'Antecedente': col_antecedente,
    'Consequente': col_consequente,
    'Suporte': col_suporte,
    'Confiança': col_confianca,
    'Lift': col_lift
})

print("DataFrame com regras formatadas:")
print(tabela_regras)
print("// ========================== //")
# Exibindo regras ordenadas por Lift
print("Regras ordenadas por 'Lift':")
print(tabela_regras.sort_values(by='Lift', ascending=False))
