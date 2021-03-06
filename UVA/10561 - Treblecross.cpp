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
#define pb push_back
#define ff first
#define ss second
#define fill(arr, val) memset(arr, val, sizeof(arr))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define uint32 unsigned int
#define INF 1000000000
#define N 222

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
char s[N];
vector <int> posWin;
int n, mark[N], f[2][N], cnt;
void clear() {
    rep(i, N) mark[i] = 0;
}
void build() {
    rep(i, 2) fr(j, 0, 200) f[i][j] = 0;
    for (int k = 1;k <= 200;k++) {
        clear();
        for (int i = 2;i < k - 2;i++) mark[ f[0][i] ^ f[0][k - i - 1] ] = 1;
        cnt = 0;
        while ( mark[cnt] ) ++cnt;
        f[0][k] = cnt;
        clear();
        
        for (int i = 0;i < k - 2;i++) mark[ f[1][i] ^ f[0][k - i - 1] ] = 1;
        for (int i = 2;i < k;i++) mark[ f[0][i] ^ f[1][k - i - 1] ] = 1;
        cnt = 0;
        while ( mark[cnt] ) ++cnt;
        f[1][k] = cnt;
    }
}
bool isWin(int pos) {
    s[pos] = 'X';
    for (int i=0;i<n - 2;i++)
        if (s[i] == 'X' && s[i + 1] == 'X' && s[i + 2] == 'X') {
            s[pos] = '.';
            return true;
        }
    for (int i=0;i<n - 1;i++)
        if (s[i] == 'X' && s[i + 1] == 'X') {
            s[pos] = '.';
            return false;
        }
    for (int i=0;i<n - 2;i++)
        if (s[i] == 'X' && s[i + 2] == 'X') {
            s[pos] = '.';
            return false;
        }
    char pre = '.';
    int p = 0, nim = 0;
    for (int i = 0;i < n;i++) {
        if (s[i] == '.') p++;
        else {
            if (pre == '.')
                nim ^= f[1][p];
            else
                nim ^= f[0][p];
            pre = s[i]; p = 0;
        }
    }
    s[pos] = '.';
    nim ^= f[1][p];
    return (nim == 0);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases;
	build();
	scanf(" %d ", &cases);
	while ( cases-- ) {
	    gets(s); n = strlen(s);
	    posWin.clear();
	    fr(i, 1, n)
            if (s[i - 1] == '.' && isWin(i - 1)) posWin.pb(i);
        if (!posWin.size()) {
            puts("LOSING");
            puts("");
        }
        else {
            puts("WINNING");
            rep(i, posWin.size()) {
                if (i) printf(" ");
                printf("%d", posWin[i]);
            }
            puts("");
        }
	}
	return 0;
}
