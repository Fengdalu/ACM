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
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x,a) (x=min(x,a))
#define SORT(p) sort(p.OP,p.ED)
typedef long long LL;
typedef pair<int, int> PII;
int dp[55][55];
int play( string a,string b ) {
	int i,j;
	for ( i=0; i<=a.SZ; i++ )for ( j=0; j<=b.SZ; j++ )
			dp[i][j]=1<<20;
	dp[0][0]=0;
	for ( i=0; i<=a.SZ; i++ )for ( j=0; j<=b.SZ; j++ ) {
			if ( i<a.SZ&&j<b.SZ&&a[i]==b[j] )cmin( dp[i+1][j+1],dp[i][j] );
			else cmin( dp[i+1][j+1],dp[i][j]+1 );
			cmin( dp[i][j+1],dp[i][j]+1 );
			cmin( dp[i+1][j],dp[i][j]+1 );
		}
//	cout<<a<<" "<<b<<" "<<dp[a.SZ][b.SZ]<<endl;
//	for(i=0;i<=a.SZ;i++){
//		for(j=0;j<=b.SZ;j++)cout<<dp[i][j]<<" ";
//		cout<<endl;
//	}
	return dp[a.SZ][b.SZ];
}
class MakeSquare {
public:
	int minChanges( string S ) {
		int ret=S.SZ;
		int i,j;
		for ( i=1; i<S.SZ; i++ )ret=min( ret,play( S.substr( 0,i ),S.substr( i,S.SZ-i ) ) );
		return ret;
	}
};

// BEGIN CUT HERE
namespace moj_harness {
int run_test_case( int );
void run_test( int casenum = -1, bool quiet = false ) {
	if ( casenum != -1 ) {
		if ( run_test_case( casenum ) == -1 && !quiet )
			cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
		return;
	}
	
	int correct = 0, total = 0;
	for ( int i=0;; ++i ) {
		int x = run_test_case( i );
		if ( x == -1 ) {
			if ( i >= 100 ) break;
			continue;
		}
		correct += x;
		++total;
	}
	
	if ( total == 0 ) {
		cerr << "No test cases run." << endl;
	} else if ( correct < total ) {
		cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
	} else {
		cerr << "All " << total << " tests passed!" << endl;
	}
}

int verify_case( int casenum, const int &expected, const int &received, clock_t elapsed ) {
	cerr << "Example " << casenum << "... ";
	
	string verdict;
	vector<string> info;
	char buf[100];
	
	if ( elapsed > CLOCKS_PER_SEC / 200 ) {
		sprintf( buf, "time %.2fs", elapsed * ( 1.0/CLOCKS_PER_SEC ) );
		info.push_back( buf );
	}
	
	if ( expected == received ) {
		verdict = "PASSED";
	} else {
		verdict = "FAILED";
	}
	
	cerr << verdict;
	if ( !info.empty() ) {
		cerr << " (";
		for ( int i=0; i<( int )info.size(); ++i ) {
			if ( i > 0 ) cerr << ", ";
			cerr << info[i];
		}
		cerr << ")";
	}
	cerr << endl;
	
	if ( verdict == "FAILED" ) {
		cerr << "    Expected: " << expected << endl;
		cerr << "    Received: " << received << endl;
	}
	
	return verdict == "PASSED";
}

int run_test_case( int casenum ) {
	switch ( casenum ) {
		case 0: {
				string S                  = "atcabcxx";
				int expected__            = 3;
				
				clock_t start__           = clock();
				int received__            = MakeSquare().minChanges( S );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 1: {
				string S                  = "abcdeabce";
				int expected__            = 1;
				
				clock_t start__           = clock();
				int received__            = MakeSquare().minChanges( S );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 2: {
				string S                  = "abcdeabxde";
				int expected__            = 1;
				
				clock_t start__           = clock();
				int received__            = MakeSquare().minChanges( S );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 3: {
				string S                  = "aabcaabc";
				int expected__            = 0;
				
				clock_t start__           = clock();
				int received__            = MakeSquare().minChanges( S );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 4: {
				string S                  = "aaaaabaaaaabaaaaa";
				int expected__            = 2;
				
				clock_t start__           = clock();
				int received__            = MakeSquare().minChanges( S );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
			
		// custom cases
		
		/*      case 5: {
					string S                  = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = MakeSquare().minChanges( S );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 6: {
					string S                  = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = MakeSquare().minChanges( S );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 7: {
					string S                  = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = MakeSquare().minChanges( S );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		default:
			return -1;
	}
}
}


int main( int argc, char *argv[] ) {
	if ( argc == 1 ) {
		moj_harness::run_test();
	} else {
		for ( int i=1; i<argc; ++i )
			moj_harness::run_test( atoi( argv[i] ) );
	}
}
// END CUT HERE
