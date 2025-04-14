#include <string.h>

#define INF (1 << 30)
#define MAX_N 1000

int g[MAX_N][MAX_N];       // lista de adjacência
int g_size[MAX_N];         // tamanho da lista para cada nó
int dist[MAX_N];
int parent[MAX_N];
int queue[MAX_N];

int bfs(int n, int start) {
    for (int i = 0; i < n; ++i) {
        dist[i] = -1;
        parent[i] = -1;
    }

    int front = 0, back = 0;
    dist[start] = 0;
    queue[back++] = start;

    int ans = INF;

    while (front < back) {
        int u = queue[front++];
        for (int i = 0; i < g_size[u]; ++i) {
            int v = g[u][i];
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                queue[back++] = v;
            } else if (v != parent[u]) {
                int cycle_len = dist[u] + dist[v] + 1;
                if (cycle_len < ans) {
                    ans = cycle_len;
                }
            }
        }
    }

    return ans;
}

int findShortestCycle(int n, int** edges, int edgesSize, int* edgesColSize) {
    for (int i = 0; i < n; ++i) {
        g_size[i] = 0;
    }

    for (int i = 0; i < edgesSize; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        g[u][g_size[u]++] = v;
        g[v][g_size[v]++] = u;
    }

    int ans = INF;
    for (int i = 0; i < n; ++i) {
        int res = bfs(n, i);
        if (res < ans) {
            ans = res;
        }
    }

    return ans < INF ? ans : -1;
}
