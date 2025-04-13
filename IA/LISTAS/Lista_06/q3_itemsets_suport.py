# Instalação da biblioteca necessária
# $ pip install apyori

# Bibliotecas utilizadas
import pandas as pd
from itertools import combinations
from collections import Counter

# Carregamento do arquivo CSV
tabela = pd.read_csv('supermercado.csv', sep=';', encoding='utf-8', header=None)
print("Conteúdo da Tabela:")
print(tabela)
print("Tamanho da Tabela (linhas x colunas):", tabela.shape)
print("// =============================== //")

# Extraindo os itens e transações
nomes_itens = tabela.iloc[0, 1:].tolist()
linhas_transacoes = tabela.iloc[1:].reset_index(drop=True)
print("Lista de Itens:")
print(nomes_itens)
print("Transações Registradas:")
print(linhas_transacoes)
print("// =============================== //")

quantidade_transacoes = len(linhas_transacoes)

# Geração de todas as combinações possíveis
conjuntos_gerados = []
for _, linha in linhas_transacoes.iterrows():
    presentes = [nomes_itens[i] for i in range(len(nomes_itens)) if linha[i + 1] == 'Sim']
    for tam in range(1, len(presentes) + 1):
        combinacoes = combinations(sorted(presentes), tam)
        conjuntos_gerados.extend(combinacoes)

# Contabilização dos itemsets
frequencia_itemsets = Counter(conjuntos_gerados)

# Exibição do suporte dos itemsets
print("Suporte por Conjunto de Itens:")
nivel_atual = 0
for conjunto, ocorrencias in sorted(frequencia_itemsets.items(), key=lambda x: (len(x[0]), x[0])):
    tamanho_atual = len(conjunto)
    if tamanho_atual != nivel_atual:
        print(f"\nConjuntos com {tamanho_atual} item(ns):")
        nivel_atual = tamanho_atual
    suporte = ocorrencias / quantidade_transacoes
    print(f"  {list(conjunto)} -> suporte: {suporte:.3f} ({ocorrencias}/{quantidade_transacoes})")
