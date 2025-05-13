# Floresta Geradora Mínima

Página anterior:

[
🌐 **Árvores Geradoras Mínimas (AGM)**: Algoritmos de **Prim** e **Kruskal**](https://www.notion.so/rvores-Geradoras-M-nimas-AGM-Algoritmos-de-Prim-e-Kruskal-1a5207a09b0781a8905cc55cb9db0684?pvs=21) 

---

## 📌 O que é?

Uma Floresta Geradora Mínima é a união das Árvores Geradoras Mínimas (AGM) de cada componente conexo de um grafo não-conexo e ponderado. É uma forma de garantir que cada componente do grafo esteja conectado com o menor custo possível, sem formar ciclos.

Se o grafo for conexo, a Floresta Geradora Mínima equivale à Árvore Geradora Mínima (AGM).

## 🎯 Definição formal:

Uma Floresta Geradora Mínima é um subconjunto das arestas de um grafo ponderado e não conexo que:

- não forma ciclos (é acíclica),
- conecta todos os vértices de cada componente conexo (é uma floresta),
- e tem o menor peso total possível.

⚠️ Se o grafo for conexo, a FGM vira uma Árvore Geradora Mínima (AGM).

### 🚀 Onde isso é usado?

- Planejamento de redes (internet, elétrica, estradas)
- Segmentação de imagens em IA e visão computacional
- Otimização de rotas logísticas
- Design de circuitos eletrônicos
- Estruturação de clusters em Machine Learning

---

### 🔧 Algoritmos principais

1. ⚙️ Kruskal — O “conectador” de componentes

### 🛠️ Como funciona?

- Ordena todas as arestas pelo peso crescente.
- Usa uma estrutura Union-Find para evitar ciclos.
- Adiciona arestas de menor peso que não formem ciclos.
- Repete até formar todas as árvores possíveis (ou atingir V−1 arestas por componente).

---

### 📦 Código em C++:

```cpp
struct Aresta {
int u, v, peso;
bool operator<(const Aresta& o) const { return peso < o.peso; }
};

int find(vector<int>& pai, int x) {
return pai[x] == x ? x : pai[x] = find(pai, pai[x]);
}

void unite(vector<int>& pai, int a, int b) {
pai[find(pai, a)] = find(pai, b);
}

vector<Aresta> kruskalMSF(int n, vector<Aresta>& arestas) {
	sort(arestas.begin(), arestas.end());
	vector<int> pai(n); iota(pai.begin(), pai.end(), 0);
	vector<Aresta> msf;
	for (auto& a : arestas) {
		if (find(pai, a.u) != find(pai, a.v)) {
			msf.push_back(a);
			unite(pai, a.u, a.v);
		}
	}
	return msf;
}
```

1. 🌲 Prim — O “expansor” local
- Parte de um vértice e vai crescendo a árvore em direção às arestas mais baratas.
- Para MSF: roda Prim a partir de cada vértice não visitado (um por componente).

### 🧠 Complexidades

- Kruskal: O(E log E) — melhor em grafos esparsos.
- Prim com heap: O(E log V) — melhor para grafos densos.

### 📈 Exemplo visual

Suponha um grafo não conexo:

Componente 1:
(0)──2──(1)
 │                │
 3                 1
 │                │
(2)──2──(3)

Componente 2:
(4)──6──(5)

Resultado da MSF com Kruskal:

- C1: Arestas (1,3), (2,3), (0,1) → custo 1 + 2 + 2 = 5
- C2: Aresta (4,5) → custo 6

🟩 Total: 11 unidades de custo

### ✨ Conclusão

Uma MSF é como montar várias pequenas árvores, uma para cada pedaço do seu grafo. Você só conecta o que realmente precisa — e só isso. Um exemplo de simplicidade com eficiência!

---

Continua na próxima página:

[**Dijkstra**](https://www.notion.so/Dijkstra-1f1207a09b0780299ffbfa5fdc93c35e?pvs=21)