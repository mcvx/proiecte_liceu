#include <iostream.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>

struct punct{double x, y;};
struct triunghi{punct A, B, C;};
int iteratii;
int l;				//dimensiunea ferestrei
int mode;			//modul de lucru

punct punct_mij(punct A, punct B){			//Returneaza coordonatele punctului din mijlocul segmentului AB
	punct E;
	E.x = (A.x + B.x)/2;
	E.y = (A.y + B.y)/2;
	return E;
}

void draw(triunghi t){						//Deseneaza triungiul t conform modului ales
	if (!mode){
		moveto(t.B.x, t.B.y);
		lineto(t.C.x, t.C.y);
		lineto(t.A.x, t.A.y);
		lineto(t.B.x, t.B.y);
	}
	else {
		int puncte[] = {t.A.x, t.A.y, t.B.x, t.B.y, t.C.x, t.C.y, t.A.x, t.A.y};
		fillpoly(4, puncte);
	}
}

void sierpinski(triunghi t, int n) {
	punct D, E, F;
	triunghi u, v, w;
	D = punct_mij(t.A,t.B);
	E = punct_mij(t.B,t.C);
	F = punct_mij(t.A,t.C);
	u.A = D; u.B = E; u.C = t.B;
	v.A = D; v.B = F; v.C = t.A;
	w.A = E; w.B = F; w.C = t.C;
	if(iteratii>n) {
		sierpinski(u,n+1);
		sierpinski(v,n+1);
		sierpinski(w,n+1);
	}
	else draw(t);
}

int main(){
	int gd=DETECT, gm;
	initgraph(&gd,&gm,"C:\\borlandc\\bgi");
	
	cout<<"Introduceti x = dimensiunea laturii:";
	cin>>l;
	cout<<"AVERTISMENT: La un numar de iteratii mai mare decat 14 timpul de executie depaseste 2 minute"<<endl<<"Introduceti numarul de iteratii:";
	cin>>iteratii;
	cout<<"Introduceti 1 pentru culori si 0 pentru a desena doar conturul:";
	cin>>mode;

	punct A, B, C;
	A.x = getmaxx()/2-l/2; A.y = getmaxy();
	B.x = getmaxx()/2+l/2; B.y = A.y;
	C.x = A.x + (cos(M_PI/3) * (B.x - A.x) - sin(M_PI/3) * (B.y - A.y));
	C.y = A.y - (sin(M_PI/3) * (B.x - A.x) + cos(M_PI/3) * (B.y - A.y));
	
	triunghi t;
	t.A = A;
	t.B = B;
	t.C = C;

	if (mode) {
		rectangle(0, 0, getmaxx(), getmaxy());
		floodfill(1, 1, WHITE);
		setcolor(RED);
		setfillstyle(SOLID_FILL, RED);
	}

	sierpinski(t,0);
	
	getch();
	closegraph();
	return 0;
}
