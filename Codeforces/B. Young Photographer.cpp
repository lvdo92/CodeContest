/***********************************************
* Author - LUONG VAN DO                        *
* Problem B. Young Photographer ->AC
* Algorithm Adhoc
* Time Limit 30ms
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
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define M 100000

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
int a[101], b[101];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n, x0, run, ans;
    scanf("%d %d",&n,&x0);
    for (int i=1;i<=n;i++) {
        scanf("%d %d",&a[i],&b[i]);
        if (a[i] > b[i]) swap(a[i], b[i]);
    }
    ans = INF;
    for (int i=0;i<=1000;i++) {
        int flag = 0;
        for (int j=1;j<=n;j++)
            if (i>=a[j] && i<=b[j]) flag++;
        if (flag == n)
            if (abs(i - x0) < ans) ans = abs(i - x0);
    }
    if (ans != INF) printf("%d\n",ans);
    else printf("-1\n");
}
