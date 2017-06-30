/***********************************************
* Author LUONG VAN DO                        *
* Problem 12416 - Excessive Space Remover
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
#define N 1000000

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
int a[N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n, i, cnt, m, ans;
    while ( gets(s)) {
        n = strlen(s);
        i = m = 0;
        while (i < n) {
            cnt = 0;
            while (i < n && s[i] ==' ') {
                cnt++;
                i++;
            }
            if (cnt) a[m++] = cnt;
            while (i < n && s[i] !=' ') i++;
        }
        ans = 0;
        int flag;
        while ( true ) {
            flag = 0;
            for (int i = 0;i < n;i++)
                if (a[i] >= 2) {
                    if (a[i] & 1) a[i]++;
                    a[i]/=2;
                    flag = 1;
                }
            if (!flag) break;
            ans++;
        }
        printf("%d\n", ans);
    }
}