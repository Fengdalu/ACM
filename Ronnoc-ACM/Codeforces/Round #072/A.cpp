#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double INF=1e20;
const double PI=acos( -1. );
const int MXN = 50;
const LL MOD = 1000000007;
int a[111111];
LL play(LL d){
	return (d+1)*d/2;
}
int main(){
	int i,j;
	int n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	LL ans=0;
	for(i=1;i<=n;){
		int l=i,r=i;
		while(r<=n&&a[l]==a[r])r++;
		ans+=play(r-l);
		i=r;
	}
	cout<<ans<<endl;
	return 0;
}
