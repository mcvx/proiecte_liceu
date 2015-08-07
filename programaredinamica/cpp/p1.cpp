#include<iostream>
#include<fstream>
using namespace std;
 
#define NMAX 501
#define INF 1LL<<60
 
long long d[NMAX][NMAX];
int a[NMAX+1];
 
int main ()
{
    int i,j,k,n,l;
    ifstream f("podm.in");
    ofstream g("podm.out");
    f>>n;
    for(i=1;i<=n+1;i++)
        f>>a[i];
    f.close();
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            d[i][j]=INF;
    for(i=1;i<=n-1;i++)
        d[i][i+1]=1LL*a[i]*a[i+1]*a[i+2];
    for(i=1;i<=n;i++)
        d[i][i]=0;
    for(i=3;i<=n;i++) {
        for(j=1;j<=n-i+1;j++) {
            l=j+i-1;
            for(k=j;k<=l-1;k++) 
                d[j][l]=min(d[j][l],0LL+d[j][k]+d[k+1][l]+1LL*a[j]*a[k+1]*a[l+1]);
        }
    }
    g<<d[1][n];
    g.close();
    return 0;
}