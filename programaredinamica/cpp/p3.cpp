#include <fstream>
#include <cstring>
#define MAXN 20001

using namespace std;

int n, m;
int a[2][MAXN];
bool ok = 0;
char s[MAXN], t[MAXN];

void read () {
    ifstream f ("in.txt");
    f>>n>>m;
    f>>s;
    f>>t;
    f.close();
}

void init () {
    int i;
    a[1][0] = 1;
    for (i=0; i<=m; ++i)
        a[0][i] = i;
}

int min (int a, int b, int c) {
    if (a<b && a<c) return a;
    if (b<a && b<c) return b;
    return c;
}

inline int max (int i, int j) {
    if (i>j) return i;
    return j;
}

void dyn () {
    init ();
    int i, j, c;
    for (i=1; i<=n; ++i) {
        a[!ok][0] = i;
        for (j=1; j<= m; ++j) {
            if (s[i-1] == t[j-1]) c = 0;
            else c = 1;
            a[!ok][j] = min (a[ok][j]+1, a[!ok][j-1]+1, a[ok][j-1]+c);
        }
        ok = !ok;
    }
}

void write () {
    ofstream g("out.txt");
    g<<a[ok][m];
    g.close();
}

int main () {
    read ();
    dyn ();
    write ();
    return 0;
}
