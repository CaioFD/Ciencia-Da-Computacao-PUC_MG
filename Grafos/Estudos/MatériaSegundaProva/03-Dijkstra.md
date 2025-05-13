# Dijkstra

Página anterior:

[Floresta Geradora Mínima](https://www.notion.so/Floresta-Geradora-M-nima-1f1207a09b07805fb773dbd3544eba28?pvs=21) 

---

O algoritmo de Dijkstra é um método clássico para encontrar o caminho de menor custo (ou caminho mais curto) entre dois vértices em um grafo ponderado, onde todos os pesos das arestas são não-negativos. Ele é amplamente utilizado em redes de computadores, sistemas de navegação, roteamento e otimização de rotas [1](https://elemarjr.com/clube-de-estudos/artigos/algoritmo-de-dijkstra-entendendo-o-caminho-minimo-em-grafos-ponderados/) [4](https://pt.wikipedia.org/wiki/Algoritmo_de_Dijkstra) [5](https://www.freecodecamp.org/portuguese/news/algoritmo-de-caminho-de-custo-minimo-de-dijkstra-uma-introducao-detalhada-e-visual/).

**Como funciona o Dijkstra?**

- O algoritmo parte de um vértice inicial e, iterativamente, expande para os vizinhos com menor custo acumulado, construindo uma árvore de caminhos mínimos a partir desse vértice.
- Mantém um registro das menores distâncias conhecidas até cada nó, atualizando essas distâncias sempre que encontra um caminho mais curto.
- Quando a menor distância para um nó é determinada, ele é marcado como "visitado" e não será mais atualizado.
- O processo segue até que todos os nós tenham sido visitados ou até que o destino seja alcançado[1](https://elemarjr.com/clube-de-estudos/artigos/algoritmo-de-dijkstra-entendendo-o-caminho-minimo-em-grafos-ponderados/)[4](https://pt.wikipedia.org/wiki/Algoritmo_de_Dijkstra)[5](https://www.freecodecamp.org/portuguese/news/algoritmo-de-caminho-de-custo-minimo-de-dijkstra-uma-introducao-detalhada-e-visual/).

## Exemplo de Grafo

Considere o seguinte grafo dirigido e ponderado:

```
	 (10)      (1)
A ------> B ------> C
|         |         |
(5)      (2)       (4)
|         |         |
v         v         v
D <------ E <------ F
		(2)        (6)
```

- Vértices: A, B, C, D, E, F
- Pesos nas arestas indicados entre parênteses

## Passos do Algoritmo

1. **Inicialização**:
    - Defina a distância do nó inicial como 0 e dos demais como infinito.
    - Marque todos os nós como não visitados.
2. **Seleção**:
    - Escolha o nó não visitado com a menor distância conhecida.
3. **Atualização (Relaxamento)**:
    - Para cada vizinho do nó atual, se o caminho passando pelo nó atual for mais curto, atualize a distância desse vizinho.
4. **Repetição**:
    - Marque o nó atual como visitado e repita o processo até visitar todos os nós ou encontrar o destino[4](https://pt.wikipedia.org/wiki/Algoritmo_de_Dijkstra)[5](https://www.freecodecamp.org/portuguese/news/algoritmo-de-caminho-de-custo-minimo-de-dijkstra-uma-introducao-detalhada-e-visual/).

## Exemplo de Execução

Suponha o grafo abaixo (representação simplificada):

```
Grafo:

0 --(10)--> 1
0 --(5)--> 3
1 --(1)--> 2
1 --(2)--> 3
2 --(4)--> 4
3 --(9)--> 2
3 --(2)--> 4
4 --(6)--> 2
4 --(7)--> 0
```

Rodando Dijkstra a partir do nó 0:

- Distâncias finais: **`[0, 8, 9,[7]`**
- Caminho mínimo de 0 a 4: 0 → 3 → 4 (custo total: 7) [2](https://malbarbo.pro.br/arquivos/2012/1747/dijkstra.py)

**Implementação em Python:**

```python
def dijkstra(g, s):
    n = len(g)
    d = [float('inf')] * n
    pai = [None] * n
    d[s] = 0
    S = [False] * n

    for _ in range(n):
        # Extrai o nó não visitado com menor distância
        u = min((d[v], v) for v in range(n) if not S[v])[1]
        S[u] = True
        for w, v in g[u]:
            if d[v] > d[u] + w:
                d[v] = d[u] + w
                pai[v] = u
    return d, pai

# Exemplo de uso:
g = [
    [(10, 1), (5, 3)],
    [(1, 2), (2, 3)],
    [(4, 4)],
    [(9, 2), (2, 4)],
    [(6, 2), (7, 0)]
]
d, pai = dijkstra(g, 0)
print("Distâncias:", d)
print("Pais:", pai)

```

## Visualização Gráfica

Ferramentas interativas, como as desenvolvidas com JavaScript e a biblioteca vis.js, permitem visualizar o funcionamento do algoritmo de Dijkstra em tempo real. O usuário pode criar grafos, definir nós de origem e destino, e observar o caminho mínimo destacado no grafo, facilitando o aprendizado[3](https://repositorio.ufersa.edu.br/bitstreams/9495c409-ed16-41f4-82e2-7bf4a09b33c1/download).

## Complexidade

- Usando heap binário: O(mlog⁡n)*O*(*m*log*n*)
- Usando heap de Fibonacci: O(m+nlog⁡n)*O*(*m*+*n*log*n*)
- Usando vetor simples: O(n2)*O*(*n*2)
    
    Onde n*n* é o número de vértices e m*m* o número de arestas[4](https://pt.wikipedia.org/wiki/Algoritmo_de_Dijkstra).
    

## Resumo das Características

- **Tipo de Grafo:** Ponderado, sem arestas negativas
- **Estratégia:** Gulosa
- **Aplicações:** Roteamento, mapas, redes, jogos
- **Limitação:** Não funciona com arestas de peso negativo

## Referências Visuais

Exemplo de visualização interativa (adaptado):

```
[ A ]---10---[ B ]---1---[ C ]
|             |
5             2
|             |
[ D ]---2---[ E ]
```

Caminho mínimo de A para C: A → B → C (custo total: 11)

O algoritmo de Dijkstra é uma das ferramentas mais fundamentais para problemas de caminhos mínimos em grafos ponderados, sendo eficiente, versátil e de fácil implementação

Continua na próxima página:

[**Bellman-Ford**](https://www.notion.so/Bellman-Ford-1f2207a09b0780f6af12d9ead6d981d5?pvs=21)