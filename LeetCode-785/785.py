from typing import List

class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)  # numero de nos no grafo
        colors = [-1] * n  # inicializa todos os nos sem cor (-1)
        isPossible = True  

        def dfs(node, color):
            nonlocal isPossible
            if not isPossible:
                return
            
            colors[node] = color  # colore o no atual
            for neighbor in graph[node]:  # explora todos os vizinhos
                if colors[neighbor] == -1:  # se o vizinho nao for colorido:
                    dfs(neighbor, color ^ 1)  # coloca a cor oposta
                elif colors[neighbor] == colors[node]:  # se for da mesma cor
                    isPossible = False  # grafo não é bipartido

        # checando todos os nos para lidar com nos desconexos 
        for i in range(n):
            if not isPossible:
                return False
            if colors[i] == -1:  # não foi visitado ainda
                dfs(i, 0)  # começa a DFS a partir desse no com cor 0

        return True  # o grafo é bipartido