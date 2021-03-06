/***********************************************
* Author LUONG VAN DO                        *
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

#define rep(i, n) for (int i=0;i<n;i++)
#define repr(i, n) for (int i = n - 1;i>=0;i--)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i=b;i>=a;i--)
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 111222333
#define N 301

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
char s[N];
uint64 dp[N][N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int k, n, l1, l2;
    fill(dp, 0);
    dp[0][0] = 1;
    for (int i = 1;i <= 300;i++)
        for (int j = i;j <= 300;j++)
            for (int k = 1;k <= 300;k++)
                dp[j][k]+=dp[j - i][k - 1];
    uint64 ans;
    while ( gets(s) ) {
        k = sscanf(s,"%d %d %d", &n, &l1, &l2);
        ans = 0;
        if (k == 1) {
            for (int i = 0;i <= n;i++)
                ans+=dp[n][i];
            printf("%llu\n", ans);
        }
        else
        if (k == 2) {
            for (int i = 0;i <= min(n, l1);i++)
                ans+=dp[n][i];
            printf("%llu\n", ans);
        }
        else
        if (k == 3) {
            for (int i = l1;i <= min(l2, n);i++)
                ans+=dp[n][i];
            printf("%llu\n", ans);
        }
    }
}
