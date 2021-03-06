#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
#define PII pair<int, int>
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
#define LL long long
#define OP begin()
#define ED end()
#define PB(x) push_back(x)
#define SZ size()
#define MOD 1000000009

const int N = 6000;
LL dp[N][N];
LL q[N][N];
LL sum[N][N];
int n;
typedef unsigned long long u64;
const u64 Base = 31;

char s[N];
u64 Hash[N];
u64 Pow[N];
void Init() {
    Pow[0] = 1;
    for(int i = 1; i < N; i++) Pow[i] = Pow[i - 1] * Base;
}

void Init(u64* Hash, int len) {
    Hash[len] = 0;
    for(int i = len - 1; i >= 0; i--) Hash[i] = (u64)Hash[i + 1] * Base + (s[i] - 'a' + 1);
}

u64 Get(u64* Hash, int p, int L) {
    return Hash[p] - Hash[p + L] * Pow[L];
}

u64 get(u64* Hash, int op, int ed) {
    return Get(Hash, op, ed - op + 1);
}

int main() {
    Init();

    scanf("%d", &n);
    scanf("%s", s + 1);
    Init(Hash, n + 1);

    for(int i = 1; i <= n; i++) {
        dp[i][i] = 1;
        for(int j = 1; j < i; j++) if(s[i - j + 1] != '0') {
            int p1 = i - j + 1;
            int p2 = i - j - j + 1;
            if(p2 <= 0) dp[i][j] = (dp[i][j] + sum[i - j + 1][i - j + 1]) % MOD;
            else {
                int l = 1, r = j;
                while(l < r) {
                    int mid = (l + r) / 2;
                    if(Get(Hash, p1, mid) != Get(Hash, p2, mid)) r = mid;
                    else l = mid + 1;
                }
                int p = p2 + l - 1;
                cout << i << " " << j << " " << l << " " << p << endl;
                cout << p << " " << p1 + l - 1 << endl;
                if(s[p] > s[p1 + l - 1]) dp[i][j] = (dp[i][j] + sum[i - j][min(i - j, i - j - p)]) % MOD;
                else dp[i][j] = (dp[i][j] + sum[i - j][min(i - j, i - j - p + 1)]) % MOD;
            }
        }
        for(int j = 1; j <= i; j++) sum[i][j] = (sum[i][j - 1] + dp[i][j]) % MOD;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) cout << dp[i][j] << " ";
        cout << endl;
    }
    LL ans = 0;
    for(int i = 0; i <= n; i++) ans = (ans + dp[n][i]) % MOD;
    cout << ans << endl;
    return 0;
}
