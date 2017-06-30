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
#define N 401

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
struct node{
    int h, a, c;
    node(){}
    node(int _h, int _a, int _c){
        h = _h; a = _a; c = _c;
    }
};
int dp[N][40001], n, maxVal;
node d[N];
bool cmp(node x, node y) {
    return (x.a < y.a);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d", &n); maxVal = 0;
	fr(i, 1, n) {
	    scanf("%d %d %d", &d[i].h, &d[i].a, &d[i].c);
	    maxVal = max(maxVal, d[i].a);
	}
	sort(d + 1, d + n + 1, cmp);
	fill(dp, 0); dp[0][0] = 1;
	for (int i = 1;i <= n;i++)
        for (int j = 0;j <= d[i].c;j++)
            for (int k = 0;k <= maxVal;k++)
                if (dp[i - 1][k])
                    if (j * d[i].h + k <= d[i].a)
                        dp[i][j * d[i].h + k] |= dp[i - 1][k];
    for (int i = maxVal;i >= 0;i--)
        if (dp[n][i]) {
            printf("%d\n", i);
            break;
        }
	return 0;
}