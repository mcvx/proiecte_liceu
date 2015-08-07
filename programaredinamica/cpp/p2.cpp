#include<iostream>
#include<fstream>

using namespace std;

int v[2][5001], d[2][5001][11];

inline int maxim(int a, int b) {     
	if(a >= b)         
		return a;     
	return b; 
} 

int main () {
	int n, m, kmax, k, max, i, j, l;
     	ifstream f("joc13.in"); 
    	f>> m >> kmax;
     	n = 1;
     	for(i=0; i<=n; i++)
        	for(j=1; j<=m; j++)
             		f >> v[i][j];
     	f.close();
     	d[0][1][1] = v[0][1];
     	d[1][1][1] = v[1][1]+d[0][1][1];
     	for(j=2; j<=m; j++)
        	 for(i=0; i<=n; i++)
            	 	for(k=1; k<=j && k<=kmax; k++) {
                 		d[i][j][k] = -(1<<30);
                 		if(k == 1) {
                     			for(l=1; l<=j-1 && l<=kmax-1; l++)
                          			d[i][j][k] = maxim(d[i][j][k], d[1-i][j-1][l]+v[1-i][j]+v[i][j]);
                 		}
                 		else d[i][j][k]=d[i][j-1][k-1]+v[i][j];
             		}
    	 max = -(1<<30);
    	 for(k=1; k<=kmax; k++)
        	 if(d[1][m][k] > max)
             		max = d[1][m][k];
     	ofstream g("joc13.out");
    	g << max;
     	g.close();
     	return 0;
}