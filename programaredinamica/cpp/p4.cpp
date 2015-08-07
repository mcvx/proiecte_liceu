#include <fstream>

using namespace std;

int n, d[6][101];

void read () {
    ifstream f ("culori.in");
    f >> n;
    f.close ();
}

void solve () {
    int i;
    d[1][1]=d[2][1]=d[3][1]=d[4][1]=d[5][1]=1;
    for (i=2; i<=n; ++i) {
        d[1][i] = d[2][i-1];
        d[2][i] = d[1][i-1] + d[3][i-1];
        d[3][i] = d[2][i-1] + d[4][i-1];
        d[4][i] = d[3][i-1] + d[5][i-1];
        d[5][i] = d[4][i-1];
    }
}

void write () {
    ofstream g ("culori.out");
    g << d[1][n]+d[2][n]+d[3][n]+d[4][n]+d[5][n];
    g.close();
}

int main () {
    read ();
    solve ();
    write ();
    return 0;
}
