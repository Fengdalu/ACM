#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

const int N = 10000 + 5;
const int M = 100000 + 5;

int dfn[N],low[N],head[N],etot,btot,n,m,nq,belong[N];
int num[N];
int fa[N];
bool is_cut[N],visited[N];
stack<int> stk;
vector<int>color[N];
int uu[N], vv[N];
struct Edge {
    int v,next,belong;
    bool visited,is_cut;
}g[M<<1];

void add_edge(int u,int v) {
    g[etot].belong = -1; g[etot].visited = g[etot].is_cut = false;
    g[etot].v = v; g[etot].next = head[u]; head[u] = etot ++;
}

void tarjan(int u, int fa, int root,int tim) {
    dfn[u] = low[u] = tim;
    visited[u] = true;
    int child_count = 0;
    for (int i = head[u]; i != -1; i = g[i].next) {
        Edge &e = g[i];
        if (e.visited) continue;
        stk.push(i);
        g[i].visited = g[i^1].visited = true;
        if (visited[e.v]) {
            if(fa != e.v) low[u] = std::min(low[u],dfn[e.v]);
            continue;
        }
        tarjan(e.v,u,root,tim+1);

        if (low[e.v]>=dfn[u]) {
            while (true) {
                int id = stk.top(); stk.pop();
                g[id].belong = g[id^1].belong = btot;
                if (id==i) break;
            }
            btot ++;
        }
        low[u] = std::min(low[e.v],low[u]);
        child_count ++;
    }
    if (u==root && child_count>1) is_cut[u] = true;
}

void bcc() {
    for (int i = 0; i < n; ++ i) {
        dfn[i] = 0;
        is_cut[i] = false;
        visited[i] = false;
    }
    btot = 0;
    for (int i = 0; i < n; ++ i) {
        if (!visited[i]) {
            tarjan(i,i,i,1);
        }
    }
}

int find(int x) {
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

int main() {
    int cas = 1;
    while(~scanf("%d%d%d", &n, &m, &nq)) {
        if(!n && !m && !nq) break;
        etot = 0;
        for(int i = 0; i < n; i++) head[i] = -1;
        for(int i = 0; i < n; i++) fa[i] = i;
        for(int i = 0; i < m; i++) {
            int x, y; scanf("%d%d", &x, &y);
            uu[i] = x; vv[i] = y;
            add_edge(x, y), add_edge(y, x);
            if(find(x) != find(y))fa[find(x)] = find(y);
        }
        bcc();
        for(int i = 0; i < n; i++) color[i].clear();
        for(int i = 0; i < n; i++) {
            for(int k = head[i]; k != -1; k = g[k].next) if(~g[k].belong) {
                int v = g[k].v;
                color[v].push_back(g[k].belong);
                color[i].push_back(g[k].belong);
            }
        }
        for(int i = 0; i < n; i++) {
            sort(color[i].begin(), color[i].end());
            color[i].resize(unique(color[i].begin(), color[i].end()) - color[i].begin());
        }
        for(int i = 0; i < n; i++) num[i] = 0;
        for(int i = 0; i < m; i++) {
            int u = uu[i], v = vv[i];
            bool flag = false;
            for(auto &a: color[u]) if(!flag)
                for(auto &b: color[v]) if(!flag)
                    if(a == b) num[a]++;
        }
        printf("Case %d:\n", cas++);
        for(int i = 0; i < nq; i++) {
            int x, y; scanf("%d%d", &x, &y);
            if(find(x) != find(y)) puts("zero");
            else {
                bool flag = false;
                int t = -1;
                for(auto &a: color[x]) if(!flag) for(auto &b: color[y])
                    if(a == b && num[a] > 1) { flag = true; }
                if(flag) puts("two or more");
                else puts("one");
            }
        }
    }
    return 0;
}
