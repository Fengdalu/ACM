#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL long long
#define u32  unsigned int
#define AA first
#define BB second
typedef pair<int, int> PII;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define PB(x) push_back(x)
#define SZ size()
#define MP(a, b) make_pair(a, b)
#define OP begin()
#define ED end()
#define CLR clear()
#define INS(x) insert(x)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, n) for(int i = 1; i <= n; i++)
#define MEM(a) memset(a, 0, sizeof a)
#define ECH(x) for(__typeof x.OP it = x.OP; it != x.ED; it++)
#define ONES(x) __builtin_popcount(x)
/*===========================================================*/

int a[1002];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0; i <= n; i++)
        a[i] = 1;
    int x,y;
    FOR(i,m)
    {
        scanf("%d%d",&x,&y);
        for(int j = x; j < y; j++)
            a[j] = 3;
    }
    int ans = 0;
    for(int i = 0; i <= n; i++)
        ans += a[i];
    printf("%d\n",ans);
}
