# Fracamente, Semi e Fortemente Conexos

Pagina anterior:

[**Bellman-Ford**](https://www.notion.so/Bellman-Ford-1f2207a09b0780f6af12d9ead6d981d5?pvs=21) 

---

Em grafos direcionados (*digrafos*), a conectividade pode ser classificada em três principais tipos: **fracamente conexo**, **semi-fortemente conexo** e **fortemente conexo**. Cada uma dessas categorias descreve diferentes níveis de "alcançabilidade" entre pares de vértices, considerando ou não o sentido das arestas.

## **Fracamente Conexo**

- **Definição:** Um grafo é fracamente conexo se, ao ignorar a orientação das arestas (considerando o grafo subjacente não orientado), existe um caminho entre qualquer par de vértices.
- **Exemplo:**
    
    ```
    A → B    C ← D
    ```
    
    Se ignorarmos as setas, todos os vértices estão conectados. Portanto, o grafo é fracamente conexo, mesmo que não seja possível ir de C para A seguindo as direções.
    

## **Semi-fortemente Conexo (Unilateralmente Conexo)**

- **Definição:** Um digrafo é semi-fortemente conexo se, para qualquer par de vértices u e v, existe um caminho de u para v **ou** de v para u (mas não necessariamente nos dois sentidos).
- **Exemplo:**
    
    Considere o grafo dirigido abaixo:
    
    ```
    A → B → C → F
    ↑         ↓
    E ← D ←
    ```
    
    - De A para F: existe caminho (A → B → C → F)
    - De F para A: existe caminho (F → D → E → A)
    - De D para C: não existe caminho, mas de C para D existe (C → F → D)
    
    Para todo par de vértices, existe caminho em pelo menos um dos sentidos, mas não necessariamente nos dois sentidos para todos os pares. Portanto, este grafo é **semi-fortemente conexo**, mas **não** fortemente conexo.
    

## **Fortemente Conexo**

- **Definição:** Um grafo é fortemente conexo se, para todo par de vértices u e v, existe um caminho de u para v **e** um caminho de v para u.
- **Exemplo:**
    
    ```
    A → B
    ↑   ↓
    D ← C
    ```
    
    Aqui, é possível ir de qualquer vértice a qualquer outro, respeitando as direções das arestas. Portanto, o grafo é fortemente conexo.
    

## **Resumo Comparativo**

| **Tipo** | **Caminho de u para v** | **Caminho de v para u** | **Caminho no grafo subjacente** |
| --- | --- | --- | --- |
| Fortemente conexo | Sim | Sim | Sim |
| Semi-fortemente conexo | Sim (um dos dois) | Não necessariamente | Sim |
| Fracamente conexo | Não necessariamente | Não necessariamente | Sim |

## **Visualização Gráfica**

## Exemplo de Grafo Fracamente Conexo

```
A → B

C
↑
|
D
```

- Não há caminho de B para A, mas se ignorarmos as direções, todos os vértices estão conectados.

## Exemplo de Grafo Semi-fortemente Conexo

```
A → B → C → F
↑         ↓
E ← D ←
```

- Para todo par de vértices, existe caminho em pelo menos um dos sentidos, mas não em ambos.

## Exemplo de Grafo Fortemente Conexo

```
A → B
↑   ↓
D ← C
```

- Para qualquer par de vértices, existe caminho nos dois sentidos.

## **Observações**

- Todo grafo fortemente conexo é também semi-fortemente e fracamente conexo.
- Um grafo acíclico nunca é fortemente conexo, pois não há ciclos.
- Em grafos não-direcionados, o conceito se resume a conexo ou desconexo.

Essas definições são fundamentais para a análise de redes, fluxos e algoritmos em grafos direcionados, permitindo entender o grau de interligação entre os vértices e a estrutura geral do grafo.