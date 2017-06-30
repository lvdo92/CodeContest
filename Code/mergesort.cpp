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
#define MAX_LOG 20
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
char s[N], ss[N];
int n;
void mergesort(int l, int r) {
    if (l < r) {
        int mid = (l + r) >> 1;
        mergesort(l, mid);
        mergesort(mid + 1, r);
        int x, y;
        for (x = mid;x >= l;x--) ss[x] = s[x];
        for (y = mid + 1;y <= r;y++) ss[y] = s[r - y + mid + 1];
        x++; y--;
        for (int k = l;k <= r;k++)
            if (ss[x] < ss[y]) {
                s[k] = ss[x];
                x++;
            }
            else {
                s[k] = ss[y];
                y--;
            }
        //cout<<s<<endl;
    }
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
    gets(s); n = strlen(s);
    mergesort(0, n - 1);
    cout << s << endl;
	return 0;
}