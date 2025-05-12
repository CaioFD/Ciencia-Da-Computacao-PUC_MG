# 🌐 Árvores Geradoras Mínimas (AGM): Algoritmos de Prim e Kruskal

# 📘 Introdução :

Em grafos **conexos, não direcionados e ponderados**, encontrar uma forma eficiente de conectar todos os vértices com o menor custo possível é essencial. Para isso, usamos os algoritmos de **Prim** e **Kruskal**, que constroem uma **Árvore Geradora Mínima (AGM)**.

## O que é uma Árvore Geradora Mínima (AGM) ?

- Conecta **todos os vértices** do grafo.
- **Não tem ciclos**.
- Soma das arestas é a **mínima possível**.
- Um grafo pode ter várias AGMs com o mesmo custo.

## Algoritmo De Prim

IDEIA:
**Começamos de um vértice e expandimos a árvore escolhendo a aresta de menor peso que liga um vértice visitado a um não visitado.**

Grafo (pesos nas arestas):

```
   (1)
 A-------B
 |       |
3|       | 1
 |       | 
 C-------D
   (4)
```

Rodando o algoritmo de PRIM (Começando por A) temos :

### Inicial:

- Começo com **A**
- Arestas disponíveis:
    - A–B (1)
    - A–C (3)
        
        → **Escolho A–B** (peso 1)
        

### Agora tenho A, B:

- Arestas disponíveis:
    - A–C (3)
    - B–D (1)
        
        → **Escolho B–D** (peso 1)
        

### Agora tenho A, B, D:

- Arestas disponíveis:
    - A–C (3)
    - D–C (4)
        
        → **Escolho A–C** (peso 3), pois é menor que D–C
        

### Todos os vértices incluídos (A, B, C, D)

### Árvore Geradora Mínima (AGM) gerada por PRIM:

- A–B (1)
- B–D (1)
- A–C (3)

**Custo total:** 1 + 1 + 3 = **5**

## Código de Prim em C++

```jsx
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

typedef pair<int, int> pii;

void prim(int n, vector<vector<pii>>& adj) {
    vector<int> dist(n, INF), parent(n, -1);
    vector<bool> visited(n, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[0] = 0; // Começa no vértice 0
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        if (visited[u]) continue;
        visited[u] = true;

        for (auto [w, v] : adj[u]) {
            if (!visited[v] && w < dist[v]) {
                dist[v] = w;
                parent[v] = u;
                pq.push({w, v});
            }
        }
    }

    int cost = 0;
    for (int i = 0; i < n; i++)
        if (parent[i] != -1)
            cost += dist[i];

    cout << "Custo total da MST (Prim): " << cost << endl;
}

```

IDEIA:

Ordenamos todas as arestas por peso e vamos **adicionando as menores**, **evitando ciclos** com o uso de **Union-Find**.

```
     (1)
	A-------B
	|       |
3 |       | 1
	|       |
	C-------D
		 (4)
```

Rodando o algoritmo de KRUSKAL (Começando por A) temos :

> Kruskal **ordena as arestas pelo peso crescente** e vai adicionando as menores que **não formam ciclo**, usando **Union-Find**.
> 

### 1️⃣ Ordenar as arestas por peso:

1. A–B (1)
2. B–D (1)
3. A–C (3)
4. C–D (4)

### 2️⃣ Inicializar conjuntos disjuntos (Union-Find):

Cada vértice começa no seu próprio conjunto:

`A | B | C | D`

### 3️⃣ Iterar nas arestas ordenadas:

✅ A–B (1)

- A e B estão em conjuntos diferentes → **adiciona**
- Conjuntos: `[AB] [C] [D]`

✅ B–D (1)

- B e D estão em conjuntos diferentes (AB e D) → **adiciona**
- Conjuntos: `[ABD] [C]`

✅ A–C (3)

- A e C estão em conjuntos diferentes (ABD e C) → **adiciona**
- Conjuntos: `[ABDC]` → todos conectados

🚫 C–D (4)

- C e D já estão no mesmo conjunto → **forma ciclo**, então **ignora**

## ✅ AGM final com Kruskal:

- A–B (1)
- B–D (1)
- A–C (3)

**Custo total:** 1 + 1 + 3 = **5**

### 🧠 Observações:

- Mesmo resultado da AGM de **Prim**.
- Mas o caminho é diferente: **Kruskal trabalha aresta por aresta** (de menor pra maior), **independente do vértice inicial**.
- Muito eficiente quando as arestas já estão em lista (como em arquivos ou grafos esparsos).

## Código de Kruskal em C++

```jsx
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Aresta {
    int u, v, peso;
    bool operator<(const Aresta& other) const {
        return peso < other.peso;
    }
};

vector<int> pai, ranke;

int find(int u) {
    if (pai[u] != u) pai[u] = find(pai[u]);
    return pai[u];
}

bool unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (ranke[u] < ranke[v]) swap(u, v);
    pai[v] = u;
    if (ranke[u] == ranke[v]) ranke[u]++;
    return true;
}

void kruskal(int n, vector<Aresta>& arestas) {
    sort(arestas.begin(), arestas.end());
    pai.resize(n); ranke.resize(n, 0);
    for (int i = 0; i < n; i++) pai[i] = i;

    int custo = 0;
    for (auto [u, v, peso] : arestas) {
        if (unite(u, v)) {
            custo += peso;
        }
    }

    cout << "Custo total da MST (Kruskal): " << custo << endl;
}

```

## 🎓 Conclusão

- Use **Prim** quando o grafo for **denso** e representado como matriz/lista de adjacência.
- Use **Kruskal** quando o grafo for **esparso** e as arestas forem fáceis de ordenar.
- Ambos garantem **uma MST válida e ótima**, mas seus comportamentos podem gerar diferentes árvores mínimas, desde que com o **mesmo custo total mínimo** (quando não há pesos repetidos).

---

Continua na próxima página:

[Floresta Geradora Mínima](https://www.notion.so/Floresta-Geradora-M-nima-1f1207a09b07805fb773dbd3544eba28?pvs=21)