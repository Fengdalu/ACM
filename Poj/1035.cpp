#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

char s[10010][100];
int dp[20][20];
char c[100];
int cnt;

int check(char *s, char *c) {
	int l1 = strlen(s), l2 = strlen(c);
	if(l1 == l2) {
		int err = 0;
		for(int i = 0; i < l1; i++) if(s[i] != c[i]) err++;
		if(err == 0) return 0;
		if(err <= 1) return 1;
		return -1;
	}
	memset(dp, 0, sizeof dp);
	for(int i = 1; i <= l1; i++)
		for(int j = 1; j <= l2; j++) {
			if(s[i - 1] == c[j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	int err;
	err = l1 + l2 - 2 * dp[l1][l2];
	if(err == 0) return 0;
	if(err <= 1) return 1;
	return -1;
}

int main() {
	cnt = 0;
	while(true) {
		scanf("%s", s[cnt]);
		if(s[cnt][0] == '#') break;
		else cnt++;
	}
	while(true) {
		scanf("%s", c);
		if(c[0] == '#') break;
		queue<int>ans;
		int flag = -1;
		for(int i = 0; i < cnt; i++) {
			int r = check(s[i], c);
			if(r == 0) { flag = i; break; }
			else if(r == 1)	ans.push(i);
		}
		if(flag != -1) printf("%s is correct\n", c);
		else {
			printf("%s:", c);
			while(ans.size()) {
				printf(" %s", s[ans.front()]);
				ans.pop();
			}
			puts("");
		}
	}
	return 0;
}
