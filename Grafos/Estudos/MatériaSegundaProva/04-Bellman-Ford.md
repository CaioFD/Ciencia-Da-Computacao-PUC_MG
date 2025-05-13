# Bellman-Ford

Página anterior:

[**Dijkstra**](https://www.notion.so/Dijkstra-1f1207a09b0780299ffbfa5fdc93c35e?pvs=21) 

---

O algoritmo de Bellman-Ford é utilizado para encontrar o caminho mais curto a partir de um vértice de origem para todos os outros vértices em um grafo dirigido e ponderado, inclusive quando existem arestas com pesos negativos. Ele também detecta ciclos negativos, algo que o Dijkstra não faz [5](https://pt.wikipedia.org/wiki/Algoritmo_de_Bellman-Ford) [3](https://www.scaler.in/bellmanford-algorithm/) [4](https://pt.slideshare.net/slideshow/anlise-de-algoritmos-problemas-em-grafos-caminho-mnimo-algoritmo-de-bellmanford/34528524).

**Características Principais**

- Funciona em grafos dirigidos com pesos negativos nas arestas.
- Detecta ciclos negativos (ciclos cujo somatório dos pesos é negativo).
- Utiliza relaxamento sucessivo das arestas, sem fila de prioridades.
- Complexidade: O(V⋅E)*O*(*V*⋅*E*), onde V*V* é o número de vértices e E*E* o número de arestas[5](https://pt.wikipedia.org/wiki/Algoritmo_de_Bellman-Ford)[4](https://pt.slideshare.net/slideshow/anlise-de-algoritmos-problemas-em-grafos-caminho-mnimo-algoritmo-de-bellmanford/34528524).

## Exemplo de Grafo

Considere o seguinte grafo direcionado:

```
graph LR
A -->|4| B
A -->|2| D
B -->|2| C
B -->|3| D
B -->|3| E
D -->|1| B
D -->|6| C
D -->|4| E
E -->|-5| C
```

Neste grafo, a aresta E→C possui peso negativo, mostrando uma situação em que o Bellman-Ford é útil [2](https://craftcodeclub.io/posts/dsa-bellman-ford).

## Passos do Algoritmo

**1. Inicialização**

- Defina a distância do vértice de origem como 0 e dos demais como infinito.
- Defina o predecessor de cada vértice como nulo.

**2. Relaxamento das Arestas**

- Repita V−1*V*−1 vezes: para cada aresta (u,v)(*u*,*v*) com peso w*w*, se dist[v]>dist[u]+w*dist*[*v*]>*dist*[*u*]+*w*, então atualize dist[v]=dist[u]+w*dist*[*v*]=*dist*[*u*]+*w* e defina o predecessor de v*v* como u*u* [5](https://pt.wikipedia.org/wiki/Algoritmo_de_Bellman-Ford) [3](https://www.scaler.in/bellmanford-algorithm/) [4](https://pt.slideshare.net/slideshow/anlise-de-algoritmos-problemas-em-grafos-caminho-mnimo-algoritmo-de-bellmanford/34528524).

**3. Verificação de Ciclos Negativos**

- Para cada aresta (u,v)(*u*,*v*), se dist[v]>dist[u]+w*dist*[*v*]>*dist*[*u*]+*w* após as V−1*V*−1 iterações, existe um ciclo negativo acessível a partir da origem [5](https://pt.wikipedia.org/wiki/Algoritmo_de_Bellman-Ford) [3](https://www.scaler.in/bellmanford-algorithm/).

## Exemplo de Execução

Tabela de distâncias por iteração (origem: A):

| **Iteração** | **A** | **B** | **C** | **D** | **E** |
| --- | --- | --- | --- | --- | --- |
| Inicial | 0 | ∞ | ∞ | ∞ | ∞ |
| 1ª | 0 | 4 | ∞ | 2 | ∞ |
| 2ª | 0 | 3 | 6 | 2 | 7 |
| 3ª | 0 | 3 | 2 | 2 | 7 |
| 4ª | 0 | 3 | -3 | 2 | 7 |

Observe que, após cada iteração, as distâncias vão sendo atualizadas, inclusive reduzidas por conta de arestas negativas [2](https://craftcodeclub.io/posts/dsa-bellman-ford).

## **Implementação em Python**

```python
def bellman_ford(V, edges, src):
    INF = float('inf')
    dist = [INF] * V
    dist[src] = 0
    pred = [None] * V

    for _ in range(V - 1):
        for u, v, w in edges:
            if dist[u] != INF and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                pred[v] = u

    # Verificação de ciclo negativo
    for u, v, w in edges:
        if dist[u] != INF and dist[u] + w < dist[v]:
            print("Ciclo negativo detectado")
            return None
    return dist, pred

# Exemplo de uso:
edges = [
    (0, 1, 4), (0, 3, 2),
    (1, 2, 2), (1, 3, 3), (1, 4, 3),
    (3, 1, 1), (3, 2, 6), (3, 4, 4),
    (4, 2, -5)
]
dist, pred = bellman_ford(5, edges, 0)
print("Distâncias:", dist)
print("Predecessores:", pred)

```

## Visualização Gráfica

A cada iteração, o algoritmo "relaxa" todas as arestas do grafo, ajustando as distâncias mínimas conhecidas. Isso pode ser visualizado como uma série de atualizações em uma tabela, conforme mostrado acima, até que nenhuma distância possa mais ser reduzida sem a presença de ciclos negativos.

## Comparação: Bellman-Ford vs Dijkstra

| **Característica** | **Bellman-Ford** | **Dijkstra** |
| --- | --- | --- |
| Pesos negativos | Suporta | Não suporta |
| Detecção de ciclo neg. | Sim | Não |
| Complexidade | O(V⋅E)*O*(*V*⋅*E*) | O(E+Vlog⁡V)*O*(*E*+*V*log*V*) |
| Estratégia | Relaxa todas as arestas | Usa fila de prioridade |
| Aplicação típica | Grafos com pesos negativos | Grafos com pesos positivos |

## Resumo das Características

- **Tipo de Grafo:** Dirigido, ponderado (com pesos negativos)
- **Estratégia:** Programação dinâmica (bottom-up)
- **Aplicações:** Roteamento, análise de arbitragem, detecção de ciclos negativos
- **Limitação:** Mais lento que Dijkstra para grafos sem pesos negativos [3](https://www.scaler.in/bellmanford-algorithm/) [4](https://pt.slideshare.net/slideshow/anlise-de-algoritmos-problemas-em-grafos-caminho-mnimo-algoritmo-de-bellmanford/34528524) [5](https://pt.wikipedia.org/wiki/Algoritmo_de_Bellman-Ford)

O algoritmo de Bellman-Ford é fundamental quando se trabalha com grafos que podem conter arestas negativas, além de ser a principal escolha quando é necessário detectar ciclos negativos no grafo.