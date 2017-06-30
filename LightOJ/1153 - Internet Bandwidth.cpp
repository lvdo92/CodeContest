/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1153 - Internet Bandwidth ->AC
* Algorithm maximum flow
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
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define frr(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i=n - 1; i>=0; i--)
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 110

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
int c[N][N], p[N], s, t, f;
int dist[N];
void findPath(int v, int minEdge) {
    if (v == s) {
        f = minEdge;
        return;
    }
    else
    if (p[v] != -1) {
        findPath(p[v], min(minEdge, c[p[v]][v]));
        c[p[v]][v]-=f;
        c[v][p[v]]+=f;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, u, v, w, m, n;
    int caseno = 0, mf;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d %d %d %d",&n,&s,&t,&m);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++) c[i][j] = 0;
        for (int i=0;i<m;i++) {
            scanf("%d %d %d",&u,&v,&w);
            c[u][v]+=w;
            c[v][u]+=w;
        }
        mf = 0;
        while ( true ) {
            f = 0;
            for (int i=1;i<=n;i++) {
                dist[i] = INF;
                p[i] = -1;
            }
            dist[s] = 0;
            queue <int> q; q.push(s);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (u == t) break;
                for (int v=1;v<=n;v++) {
                    if (dist[v] == INF && c[u][v] > 0) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                        p[v] = u;
                    }
                }
            }
            findPath(t, INF);
            if (!f) break;
            mf+=f;
        }
        printf("Case %d: %d\n",++caseno, mf);
    }
}