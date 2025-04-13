# Instalação do pacote necessário:
# $ pip install apyori

# Bibliotecas
import pandas as pd
from apyori import apriori

# Leitura do arquivo CSV
dados = pd.read_csv('supermercado.csv', sep=';', encoding='utf-8', header=None)
print("Conteúdo original:")
print(dados)
print("Dimensões (linhas x colunas):", dados.shape)
print("// ============================ //")

# Extração do cabeçalho e das transações
colunas = dados.iloc[0, 1:].tolist()
registros = dados.iloc[1:].reset_index(drop=True)
print("Itens identificados:")
print(colunas)
print("Registros de compra:")
print(registros)
print("// ============================ //")

# Preparando os dados para o algoritmo Apriori
lista_transacoes = []
for _, linha in registros.iterrows():
    itens_negados = [colunas[i] for i in range(len(colunas)) if linha[i + 1] == 'Não']
    lista_transacoes.append(itens_negados)

# Ordenar por tamanho das transações (opcional)
lista_transacoes.sort(key=len)
print("Transações formatadas:")
for t in lista_transacoes:
    print(t)
print("// ============================ //")

# Execução do algoritmo Apriori
resultados = apriori(lista_transacoes, min_support=0.3, min_confidence=0.8)
regras_brutas = list(resultados)
print("Total de regras encontradas:", len(regras_brutas))
print("Regras encontradas:")
for r in regras_brutas:
    print(r)
print("// ============================ //")

# Processamento das regras para exibição em DataFrame
antecedentes, consequentes, suportes, confiancas, lifts = [], [], [], [], []

for regra in regras_brutas:
    suporte_regra = regra.support
    detalhes = regra.ordered_statistics
    for d in detalhes:
        ant = list(d.items_base)
        cons = list(d.items_add)
        conf = d.confidence
        lf = d.lift

        if not ant or not cons: continue
        if 'nan' in ant or 'nan' in cons: continue

        antecedentes.append(ant)
        consequentes.append(cons)
        suportes.append(suporte_regra)
        confiancas.append(conf)
        lifts.append(lf)

# Criação do DataFrame final
tabela_regras = pd.DataFrame({
    'Antecedente': antecedentes,
    'Consequente': consequentes,
    'Suporte': suportes,
    'Confiança': confiancas,
    'Lift': lifts
})

print("Tabela de Regras Geradas:")
print(tabela_regras)
print("// ============================ //")

# Ordenação pela métrica lift
print("Tabela de Regras Ordenada por Lift:")
ordenadas = tabela_regras.sort_values(by='Lift', ascending=False)
print(ordenadas)
