#include <string.h>

#define INF (1 << 30)   // Valor alto representando "infinito"
#define MAX_N 1000

// Representação do grafo: lista de adjacência
int g[MAX_N][MAX_N];       // g[u][i] = vizinho i do nó u
int g_size[MAX_N];         // número de vizinhos de cada nó u

int dist[MAX_N];           // distância do nó de origem até o nó atual
int parent[MAX_N];         // pai do nó atual na BFS (evita voltar por onde veio)
int queue[MAX_N];          // fila usada na BFS

// Função BFS para encontrar o menor ciclo começando do nó 'start'
int bfs(int n, int start) {
    // Inicializa distâncias e pais
    for (int i = 0; i < n; ++i) {
        dist[i] = -1;      // -1 indica que o nó ainda não foi visitado
        parent[i] = -1;
    }

    int front = 0, back = 0;
    dist[start] = 0;       // distância até si mesmo é 0
    queue[back++] = start; // coloca o nó inicial na fila

    int ans = INF;         // variável para armazenar o menor ciclo encontrado

    // Loop principal da BFS
    while (front < back) {
        int u = queue[front++];  // retira da fila

        // Percorre todos os vizinhos do nó u
        for (int i = 0; i < g_size[u]; ++i) {
            int v = g[u][i];

            if (dist[v] == -1) {
                // Se o nó v ainda não foi visitado
                dist[v] = dist[u] + 1;
                parent[v] = u;
                queue[back++] = v;
            } else if (v != parent[u]) {
                // Se o vizinho v já foi visitado, e não é o pai de u → ciclo detectado
                int cycle_len = dist[u] + dist[v] + 1; // comprimento do ciclo
                if (cycle_len < ans) {
                    ans = cycle_len; // atualiza menor ciclo
                }
            }
        }
    }

    return ans;  // retorna o menor ciclo encontrado a partir de start
}

// Função principal para encontrar o menor ciclo em todo o grafo
int findShortestCycle(int n, int** edges, int edgesSize, int* edgesColSize) {
    // Inicializa os tamanhos das listas de adjacência
    for (int i = 0; i < n; ++i) {
        g_size[i] = 0;
    }

    // Constrói o grafo com base nas arestas
    for (int i = 0; i < edgesSize; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        g[u][g_size[u]++] = v;  // adiciona v na lista de vizinhos de u
        g[v][g_size[v]++] = u;  // adiciona u na lista de vizinhos de v (grafo não direcionado)
    }

    int ans = INF;

    // Executa BFS a partir de cada nó para garantir que todos os ciclos sejam encontrados
    for (int i = 0; i < n; ++i) {
        int res = bfs(n, i);  // menor ciclo a partir do nó i
        if (res < ans) {
            ans = res;        // atualiza a resposta global
        }
    }

    // Se nenhum ciclo foi encontrado, retorna -1
    return ans < INF ? ans : -1;
}
