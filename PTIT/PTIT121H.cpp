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
#define N 100100

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
    node *next;
    int val;
};
int k, m;
char str[N];
node* head, *p, *tail;
node *newNode(int v) {
    node *Node = new node();
    Node->next = NULL;
    Node->val = v;
    return Node;
}
void Insert(int x) {
    node *temp = newNode(x);
    tail->next = temp; tail = temp;
}
void Delete(node *at) {
    node *temp = at->next, *q;
    if (at == head) head = temp;
    else {
        q = head;
        q->next = q->next->next;
    }
    delete at;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf(" %d %d %s ", &m, &k, &str);
	head = newNode(0); tail = head;
	fr(i, 1, m - 1) {
	    p = newNode(i);
        tail->next = p; tail = p;
	}
	m = strlen(str);
	rep(i, m - 1) {
	    p = head;
	    if (str[i] == 'A') {
	        Insert(p->val);
	        Delete(head);
	    }
	    else {
	        p = p->next;
	        Insert(p->val);
	        Delete(p);
	    }
	}
	p = head;
	rep(i, k - 1) p = p->next;
	printf("%d", p->val);
	p = p->next;
	printf(" %d", p->val);
	p = p->next;
	printf(" %d\n", p->val);
	return 0;
}
