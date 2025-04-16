# Lista de Exercícios em um Online Judger

**Número da Lista**: 1<br>
**Conteúdo da Disciplina**: Grafos 1<br>

## Alunos
|Matrícula | Aluno |
| -- | -- |
| 21/1031584  |  Ana Letícia Melo Pereira |
| 20/0073184 |  Mateus Fidelis Marinho Maia |

## Sobre 
Para desenvolver o conteúdo abordado no tópico de Grafos 1, a dupla selecionou três exercícios em um juiz online - o LeetCode -, sendo eles, dois de nível difícil e um de nível médio. Para obter mais informações sobre os enunciados propostos, basta clicar no link que aparece no título de cada um.

### 🔗 [2608. Shortest Cycle in a Graph](https://leetcode.com/problems/shortest-cycle-in-a-graph/description/)
- Resumo:
Você recebe um grafo não-direcionado. A tarefa é encontrar o menor ciclo possível (com 3 ou mais nós).
Retorne o comprimento desse menor ciclo, ou -1 se o grafo não contiver ciclos. 
- Nível de dificuldade: difícil.

🧠 Envolve BFS para detecção de ciclos curtos em grafos não-direcionados.


### 🔗 [785. Is Graph Bipartite?](https://leetcode.com/problems/is-graph-bipartite/description/)
- Resumo:
- Dado um grafo representado como lista de adjacência, determine se ele é bipartido, ou seja, se é possível dividir os nós em dois grupos sem que haja arestas entre nós do mesmo grupo. Nível de dificuldade: Médio.

🧠 Típico problema resolvido com BFS/DFS e "coloração" dos nós.


### [🔗 1579. Remove Max Number of Edges to Keep Graph Fully Traversable](https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/)
Resumo:
- Você tem um grafo com 2 jogadores (Alice e Bob) e tipos de arestas:

  Tipo 1: só Alice pode usar
  
  Tipo 2: só Bob pode usar
  
  Tipo 3: ambos podem usar

  Seu objetivo é remover o maior número de arestas mantendo o grafo conectado para os dois jogadores.
- Nível de dificuldade: Difícil.


🧠 Problema de grafos avançado envolvendo Union Find (DSU) e estratégia de otimização de conectividade.


## Screenshots
- Problema 2608
<img width="734" alt="Shortest cycle in a graph" src="https://github.com/projeto-de-algoritmos-2025/Grafos1-OnlineJudge/blob/main/img/leetcode_2608.png">

- Problema 1579 
<img width="734" alt="Remove Max Number of Edges to Keep Graph Fully Traversable" src="https://github.com/projeto-de-algoritmos-2025/Grafos1-OnlineJudge/blob/main/img/leetcode_1579.png">

- Problema 785 
<img width="734" alt="Is a Graph Bipartite" src="https://github.com/projeto-de-algoritmos-2025/Grafos1-OnlineJudge/blob/main/img/785%20Is%20Graph%20Bipartite.png">

## Instalação 

Linguagens: C e Python
Pré-requisitos: Compilador GCC, Python 3.4 

## 1. Clone o repositório 

```bash
git clone https://github.com/projeto-de-algoritmos-2025/Grafos1-OnlineJudge.git
```

### 2. Compile o programa

Em C:
```bash
gcc -o nome_do_arquivo.c nome_do_executável  
./nome_do_executável
```

Em Python:
```bash
python arquivo.py
```

## Uso 
Para aplicar os casos de teste (in e out), basta acessar o link referente ao exercício no LeetCode e inserí-los no prompt de comando, também é possível gerar novos casos de teste, desde que cumpram os requisitos do exercício em questão.

## Outros 
A apresentação da entrega pode ser visualizada [aqui](link do youtube aqui). 
