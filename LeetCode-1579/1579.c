#include <stdlib.h>

#define MAX_N 100005

typedef struct {
    int p[MAX_N];
    int size[MAX_N];
    int cnt;
} UnionFind;

void uf_init(UnionFind* uf, int n) {
    for (int i = 0; i < n; ++i) {
        uf->p[i] = i;
        uf->size[i] = 1;
    }
    uf->cnt = n;
}

int uf_find(UnionFind* uf, int x) {
    if (uf->p[x] != x) {
        uf->p[x] = uf_find(uf, uf->p[x]);
    }
    return uf->p[x];
}

int uf_unite(UnionFind* uf, int a, int b) {
    int pa = uf_find(uf, a - 1);
    int pb = uf_find(uf, b - 1);
    if (pa == pb) {
        return 0;
    }
    if (uf->size[pa] > uf->size[pb]) {
        uf->p[pb] = pa;
        uf->size[pa] += uf->size[pb];
    } else {
        uf->p[pa] = pb;
        uf->size[pb] += uf->size[pa];
    }
    uf->cnt--;
    return 1;
}

int maxNumEdgesToRemove(int n, int** edges, int edgesSize, int* edgesColSize) {
    UnionFind ufa, ufb;
    uf_init(&ufa, n);
    uf_init(&ufb, n);

    int ans = 0;
    for (int i = 0; i < edgesSize; ++i) {
        int t = edges[i][0];
        int u = edges[i][1];
        int v = edges[i][2];
        if (t == 3) {
            if (uf_unite(&ufa, u, v)) {
                uf_unite(&ufb, u, v);
            } else {
                ++ans;
            }
        }
    }
    for (int i = 0; i < edgesSize; ++i) {
        int t = edges[i][0];
        int u = edges[i][1];
        int v = edges[i][2];
        if (t == 1 && !uf_unite(&ufa, u, v)) {
            ++ans;
        }
        if (t == 2 && !uf_unite(&ufb, u, v)) {
            ++ans;
        }
    }

    return (ufa.cnt == 1 && ufb.cnt == 1) ? ans : -1;
}
