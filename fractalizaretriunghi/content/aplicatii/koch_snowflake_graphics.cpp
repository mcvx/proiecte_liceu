#include <graphics.h>
#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <dos.h>

struct punct{double x, y;};
int iteratii;
int l;				//dimensiunea ferestrei
int mode;			//modul de lucru
int dly = 2;			//delay

punct punct_treime(punct A, punct B){				//Returneaza coordonatele punctului de pe segmentul AB situat la 1/3 de A
	punct C;
	C.x = A.x + (B.x - A.x)/3;
	C.y = A.y + (B.y - A.y)/3;
	return C;
}

punct punct_mij(punct A, punct B){				//Returneaza coordonatele punctului care  impreuna cu A si B formeaza un triunghi echilateral
	punct E;
	E.x = A.x + (cos(M_PI/3) * (B.x - A.x) - sin(M_PI/3) * (B.y - A.y));
	E.y = A.y + (sin(M_PI/3) * (B.x - A.x) + cos(M_PI/3) * (B.y - A.y));
	return E;
}

void draw(punct A, punct B, punct C, punct D, punct E){		//Deseneaza o linie franta care uneste cele 5 puncte in ordine
	moveto(A.x, A.y);
	lineto(B.x, B.y); delay(dly);
	lineto(C.x, C.y); delay(dly);
	lineto(D.x, D.y); delay(dly);
	lineto(E.x, E.y);
}

void koch_line(punct A, punct E, int n=1){			//Imparte segmentul in 3 subsegmente generand al trilea punct(varful triunghiului cu subsegmentul din mijloc ca baza)
	punct B, C, D;
	B = punct_treime(A, E);
	D = punct_treime(E, A);
	C = punct_mij(B, D);
	if (n<iteratii) {
		koch_line(A, B, n+1);
		koch_line(B, C, n+1);
		koch_line(C, D, n+1);
		koch_line(D, E, n+1);
	}
	else draw(A, B, C, D, E);
}

void koch_snowflake(punct A, punct B, punct C){			//Apeleaza functia de generat puncte pe fiecare din laturile unui triunghi initial
	koch_line(A, B);
	koch_line(B, C);
	koch_line(C, A);
	if (mode) {
		setfillstyle(CLOSE_DOT_FILL, WHITE);		//Seteaza culoarea cu care va fi umplut fulgul
		floodfill(getmaxx()/2, getmaxy()/2, WHITE);	//Umple fulgul
	}
}

int main(){
	int gd=DETECT, gm;
	initgraph(&gd,&gm,"C:\\borlandc\\bgi");
	
	cout<<"Introduceti x = dimensiunea laturii:";
	cin>>l;
	cout<<"AVERTISMENT: La un numar de iteratii mai mare decat 9 timpul de executie depaseste 2 minute"<<endl<<"Introduceti numarul de iteratii:";
	cin>>iteratii;
	cout<<"Introduceti 1 pentru fulg de zapada si 0 pentru a desna doar conturul:";
	cin>>mode;

	punct A, B, C;
	A.x = getmaxx()/2-l/2; A.y = getmaxy()/2+l*sqrt(3)/6;
	B.x = getmaxx()/2+l/2; B.y = A.y;
	C = punct_mij(B, A);

	koch_snowflake(A, B, C);
	
	getch();
	closegraph();
	return 0;
}

