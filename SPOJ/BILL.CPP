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
int64 x, y, lo, hi, ans, d;
int dx[] = {20000, 2970000, 495000000};
int dy[] = {100, 9900, 990000};
int64 calckWh(int64 x) {
    int i, power = 100;
    int64 total = 0;
    for (i = 1;i <= 3;i++) {
        if (x >= dx[i - 1]) {
            x -= dx[i - 1];
            total += dy[i - 1];
        }
        else break;
    }
    if (x > 0) {
        if (i <= 3) {
            if (i == 1) total += x / 200;
            if (i == 2) total += x / 300;
            if (i == 3) total += x / 500;
        }
        else
            total += x / 700;
    }
    return total;
}
int64 money(int64 x) {
    int i;
    int64 total = 0;
    for (i = 1;i <= 3;i++) {
        if (x >= dy[i - 1]) {
            total += dx[i - 1];
            x -= dy[i - 1];
        }
        else break;
    }
    if (x > 0) {
        if (i <= 3) {
            if (i == 1) total += 200 * x;
            if (i == 2) total += 300 * x;
            if (i == 3) total += 500 * x;
        }
        else total += 700 * x;
    }
    return total;
}
bool check(int64 a) {
    int64 b = a + y;
    int64 sum = calckWh(a) + calckWh(b);
    return sum >= d;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%lld %lld", &x, &y);
	lo = 0; hi = x; d = calckWh(x);
	while (lo <= hi) {
	    int64 mid = (lo + hi) >> 1;
	    if ( check(mid) ) {
	        ans = mid;
	        hi = mid - 1;
	    }
	    else lo = mid + 1;
	}
	printf("%lld\n", ans);
	return 0;
}
