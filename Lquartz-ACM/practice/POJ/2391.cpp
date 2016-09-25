#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
 
#define PB push_back
#define PF push_front
#define PPB pop_back
#define PPF pop_front
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SORT(x) sort(x.begin(), x.end())
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)
 
const double eps = 1e-8;
const LL MOD = 1000000007;
const LL INF = (1LL<<50);
#define Maxn 411
#define Maxm 201111
//dinic O(m*n^2)
struct node {
    int u, v, c, next;
}e[Maxm];
int tot, last[Maxn];
int cur[Maxn], dist[Maxn], que[Maxn], sta[Maxn], head, tail, top;

void adde(int u, int v, int c, int c1) {
//    cout << "adde " << u << " " << v << " " << c << endl;
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
    e[tot].u = v; e[tot].v = u; e[tot].c = c1; e[tot].next = last[v]; last[v] = tot++;
}

bool bfs(int s, int t, int n) {
    int i, j, u, v;
    for(i = 0; i < n; i++) dist[i] = MOD;
    dist[s] = 0;
    head = tail = 0;
    que[tail++] = s;
    while(head < tail) {
        u = que[head++];
        for(j = last[u]; j != -1; j = e[j].next) {
            if(e[j].c == 0) continue;
            v = e[j].v;
            if(dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                if(v == t) return true;
                que[tail++] = v;
            }
        }
    }
    return false;
}

int dinic(int s, int t, int n) {
    int i, j, u, v;
    int maxflow = 0;
    while(bfs(s, t, n)) {
        for(i = 0; i < n; i++) cur[i] = last[i];
        u = s; top = 0;
        while(cur[s] != -1) {
            if(u == t) {
                int tp = MOD;
                for(i = top - 1; i >= 0; i--) {
                    tp = min(tp, e[sta[i]].c);
                }
                maxflow += tp;
                for(i = top - 1; i >= 0; i--) {
                    e[sta[i]].c -= tp;
                    e[sta[i] ^ 1].c += tp;
                    if(e[sta[i]].c == 0) top = i;
                }
                u = e[sta[top]].u;
            }
            else if(cur[u] != -1 && e[cur[u]].c > 0 && dist[u] + 1 == dist[e[cur[u]].v]) {
                sta[top++] = cur[u];
                u = e[cur[u]].v;
            }
            else {
                while(u != s && cur[u] == -1) {
                    u = e[sta[--top]].u;
                }
                cur[u] = e[cur[u]].next;
            }
        }
    }
    return maxflow;
}

LL f[Maxn][Maxn];
int cow[Maxn], she[Maxn];
int n, m, sum;

bool check(LL x) {
//    cout << "check " << x << endl;
    int i, j, u, v, w;
    int N = n * 2 + 2, S = 0, T = N - 1;
    for(i = 0; i <= N; i++) last[i] = -1;
    tot = 0;
    for(i = 1; i <= n; i++) {
        adde(S, i, cow[i], 0);
        adde(i + n, T, she[i], 0);
    }
    for(i = 1; i <= n; i++) {
        adde(i, i + n, MOD, 0);
        for(j = i + 1; j <= n; j++) {
            if(f[i][j] <= x) {
                adde(i, j + n, MOD, 0);
                adde(j, i + n, MOD, 0);
            }
        }
    }
    if(dinic(S, T, N) == sum) return true;
    else return false;
}

int main() {
    int i, j, k, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(scanf("%d%d", &n, &m) != EOF) {
        sum = 0;
        for(i = 1; i <= n; i++) {
            scanf("%d%d", &cow[i], &she[i]);
            sum += cow[i];
        }
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                f[i][j] = INF;
            }
            f[i][i] = 0;
        }
        for(j = 0; j < m; j++) {
            scanf("%d%d%d", &u, &v, &w);
            f[v][u] = cmin(f[u][v], (LL)w);
            
        }
        for(k = 1; k <= n; k++) {
            for(i = 1; i <= n; i++) {
                for(j = 1; j <= n; j++) {
                    cmin(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }
        LL dmax = 0;
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                if(f[i][j] == INF) continue;
                cmax(dmax, f[i][j]);
            }
        }
        LL L = 0, R = dmax, M;
        while(L < R - 1) {
            M = (L + R) >> 1;
            if(check(M)) R = M;
            else L = M + 1;
        }
        LL ans = -1;
        if(check(L)) ans = L;
        else if(check(R)) ans = R;
        cout << ans << endl;
    }
    return 0;
}

/*
6 6
10 0
0 3
0 7
3 0
0 2
0 1
1 2 120
5 2 80
5 1 20
5 6 30
6 1 110
4 3 30

ans:-1
*/
