/***********************************************
* Author - LUONG VAN DO                        *
* Problem 
* Algorithm
* Time Limit
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i = b;i >= a;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 100111

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, m, h, mark[N], valMax, ans;
int u, v, a[N], val[N];
vector <int> adj[N];
queue <int> q;
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d %d %d", &n, &m, &h);
	rep(i, n) {
	    val[i] = INF;
	    mark[i] = 0;
	}
	rep(i, m) {
	    scanf("%d", &a[i]);
	    val[a[i]] = 0;
	    q.push(a[i]);
	    mark[a[i]] = 1;
	}
	rep(i, h) {
	    scanf("%d %d", &u, &v);
	    adj[u].pb(v); adj[v].pb(u);
	}
	while ( !q.empty()) {
	    u = q.front(); q.pop();
	    for (int i = 0;i < adj[u].size();i++) {
	        if ( mark[adj[u][i]] == 0 ) {
	            val[ adj[u][i] ] = val[u] + 1;
	            mark[ adj[u][i] ] = 1;
	            q.push( adj[u][i] );
	        }
	    }
	}
	valMax = 0;
	rep(i, n) valMax = max(valMax, val[i]);
	rep(i, n) if ( valMax ==  val[i] ) {
	    ans = i;
	    break;
	}
	printf("%d\n", ans);
	return 0;
}