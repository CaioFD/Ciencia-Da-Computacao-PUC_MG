# Fracamente, Semi e Fortemente Conexos

Em grafos direcionados (*digrafos*), a conectividade pode ser classificada em três principais tipos: **fracamente conexo**, **semi-fortemente conexo** e **fortemente conexo**. Cada uma dessas categorias descreve diferentes níveis de "alcançabilidade" entre pares de vértices, considerando ou não o sentido das arestas.

## **Fracamente Conexo**

- **Definição:** Um grafo é fracamente conexo se, ao ignorar a orientação das arestas (ou seja, considerando o grafo subjacente não orientado), existe um caminho entre qualquer par de vértices [1](https://files.cercomp.ufg.br/weby/up/666/o/04_aula4_conectividade.pdf?1386698869) [5](https://www.inf.ufrgs.br/~prestes/Courses/Graph%20Theory/Capitulo%203.pdf) [6](https://www.ibilce.unesp.br/Home/Departamentos/MatematicaAplicada/docentes/socorro/grafosdirecionados.pdf) [8](http://profs.ic.uff.br/~lfignacio/grafos/Aula_21_2022_2.pdf).
- **Exemplo:**
    
    Imagine o grafo dirigido abaixo:
    
    ```
    A → B    C ← D
    
    ```
    
    Se ignorarmos as setas, todos os vértices estão conectados. Portanto, o grafo é fracamente conexo, mesmo que não seja possível ir de C para A seguindo as direções.
    

## **Semi-fortemente Conexo (ou Unilateralmente Conexo)**

- **Definição:** Um grafo é semi-fortemente conexo se, para qualquer par de vértices y e z existe um caminho de y para z ou de z para y (mas não necessariamente em ambos os sentidos) [2](https://www.producao.uff.br/conteudo/rpep/volume132013/RelPesq_V13_2013_B03.pdf).
- **Exemplo:**
    
    No grafo abaixo:
    
    ```
    A → B → C
    ```
    
    Para qualquer par de vértices, existe um caminho do primeiro para o segundo ou vice-versa, mas não necessariamente ambos. Por exemplo, existe caminho de A para C, mas não de C para A.
    

## **Fortemente Conexo**

- **Definição:** Um digrafo é fortemente conexo se, para todo par de vértices v e w, existe um caminho de v para w **e** um caminho de w para v [3](https://www.ime.usp.br/~pf/algoritmos_em_grafos/aulas/forte.html)[6](https://www.ibilce.unesp.br/Home/Departamentos/MatematicaAplicada/docentes/socorro/grafosdirecionados.pdf)[7](https://pt.wikipedia.org/wiki/Conectividade_(teoria_dos_grafos)).
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

## Exemplo de Grafo Fortemente Conexo

```
A → B
↑   ↓
D ← C
```

- Para qualquer par de vértices, existe caminho nos dois sentidos.

## **Observações**

- Todo grafo fortemente conexo é também semi-fortemente e fracamente conexo[8](http://profs.ic.uff.br/~lfignacio/grafos/Aula_21_2022_2.pdf).
- Um grafo acíclico nunca é fortemente conexo, pois não há ciclos[6](https://www.ibilce.unesp.br/Home/Departamentos/MatematicaAplicada/docentes/socorro/grafosdirecionados.pdf).
- Em grafos não-direcionados, o conceito se resume a conexo ou desconexo[2](https://www.producao.uff.br/conteudo/rpep/volume132013/RelPesq_V13_2013_B03.pdf)[7](https://pt.wikipedia.org/wiki/Conectividade_(teoria_dos_grafos)).

Essas definições são fundamentais para a análise de redes, fluxos e algoritmos em grafos direcionados, permitindo entender o grau de interligação entre os vértices e a estrutura geral do grafo.