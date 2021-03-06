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
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
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
#define N 555

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
int c, n, ans, color[N], dp[N], val[N], lenMax;
ii a[N];
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d %d", &c, &n);
	rep(i, n * c) scanf("%d %d", &a[i].ff, &a[i].ss);
	rep(i, c) color[i + 1] = i + 1; ans = INF;
	do{
	    rep(i, n * c)
            val[i] = color[a[i].ff] * n + a[i].ss;
        lenMax = 1;
        rep(i, n * c) {
            dp[i] = 1;
            repr(k, i)
                if (val[k] < val[i] && dp[i] < dp[k] + 1)
                    dp[i] = dp[k] + 1;
            lenMax = max(lenMax, dp[i]);
        }
        if (ans > n * c - lenMax) ans = n * c - lenMax;
	}while (next_permutation(color + 1, color + c + 1));
	printf("%d\n", ans);
	return 0;
}
