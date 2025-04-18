#include <stdlib.h>

#define MAX_N 100005  // número máximo de nós

// Estrutura de Union-Find (Disjoint Set Union - DSU)
typedef struct {
    int p[MAX_N];      // vetor de pais
    int size[MAX_N];   // tamanho do componente de cada nó
    int cnt;           // número de componentes conectados
} UnionFind;

// Inicializa a estrutura Union-Find com n elementos
void uf_init(UnionFind* uf, int n) {
    for (int i = 0; i < n; ++i) {
        uf->p[i] = i;      // cada nó é seu próprio pai (raiz)
        uf->size[i] = 1;   // tamanho inicial de cada conjunto é 1
    }
    uf->cnt = n;           // inicialmente há n componentes
}

// Função "find" com path compression: encontra o representante de x
int uf_find(UnionFind* uf, int x) {
    if (uf->p[x] != x) {
        uf->p[x] = uf_find(uf, uf->p[x]);  // compressão de caminho
    }
    return uf->p[x];
}

// Função "unite": une os conjuntos de a e b, retorna 1 se uniu, 0 se já estavam juntos
int uf_unite(UnionFind* uf, int a, int b) {
    int pa = uf_find(uf, a - 1);  // nota: os nós vêm de 1 a n, então ajustamos -1
    int pb = uf_find(uf, b - 1);
    if (pa == pb) {
        return 0;  // já estão no mesmo conjunto — aresta redundante
    }
    // união por tamanho: conecta o menor no maior
    if (uf->size[pa] > uf->size[pb]) {
        uf->p[pb] = pa;
        uf->size[pa] += uf->size[pb];
    } else {
        uf->p[pa] = pb;
        uf->size[pb] += uf->size[pa];
    }
    uf->cnt--;  // número de componentes diminui
    return 1;
}

// Função principal: retorna o número máximo de arestas que podem ser removidas
int maxNumEdgesToRemove(int n, int** edges, int edgesSize, int* edgesColSize) {
    UnionFind ufa, ufb;
    uf_init(&ufa, n);  // estrutura para Alice
    uf_init(&ufb, n);  // estrutura para Bob

    int ans = 0;  // número de arestas que podem ser removidas

    // Primeira passagem: processa arestas do tipo 3 (usadas por ambos)
    for (int i = 0; i < edgesSize; ++i) {
        int t = edges[i][0];  // tipo da aresta
        int u = edges[i][1];
        int v = edges[i][2];
        if (t == 3) {
            if (uf_unite(&ufa, u, v)) {
                uf_unite(&ufb, u, v);  // se uniu em ufa, une também em ufb
            } else {
                ++ans;  // já estavam unidos em ambos → aresta redundante
            }
        }
    }

    // Segunda passagem: processa tipo 1 (Alice) e tipo 2 (Bob)
    for (int i = 0; i < edgesSize; ++i) {
        int t = edges[i][0];
        int u = edges[i][1];
        int v = edges[i][2];
        if (t == 1 && !uf_unite(&ufa, u, v)) {
            ++ans;  // aresta redundante para Alice
        }
        if (t == 2 && !uf_unite(&ufb, u, v)) {
            ++ans;  // aresta redundante para Bob
        }
    }

    // Verifica se os dois grafos estão totalmente conectados (1 componente só)
    return (ufa.cnt == 1 && ufb.cnt == 1) ? ans : -1;
}
