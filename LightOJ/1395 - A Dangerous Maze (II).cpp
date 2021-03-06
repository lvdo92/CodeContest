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
int n, k, x, e1, e2, t1, t2;
double ans, y;
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0;
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%d %d", &n, &k);
	    e1 = e2 = t1 = t2 = 0;
	    rep(i, n) {
	        scanf("%d", &x);
	        if (x > 0) e1 += x, t1++;
	        else e2 -= x, t2++;
	    }
	    if (t1 == 0) {
	        printf("Case %d: -1\n", ++caseno);
	        continue;
	    }
	    ans = (double)e1 / (double)t1; y = 1.0;
	    for (int i = 0;i < t2 && i < k;i++) {
	        y *= (double)(t2 - i) / (double)(n - i);
	        ans += (double)(e2 * y) / (double)t2;
	    }
	    if (t2 > k) {
	        y *= (double)(t2 - k) / (double)(n - t2);
	        ans += (double)(e2 * y) / (double)t2;
	    }
	    printf("Case %d: %.10lf\n", ++caseno, ans);
	}
	return 0;
}
