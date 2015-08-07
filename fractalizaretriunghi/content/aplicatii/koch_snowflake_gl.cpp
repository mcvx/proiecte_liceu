#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;

struct punct{double x, y;};
int iteratii;
int l;				//dimensiunea ferestrei
int mode;			//modul de lucru

//Functiile problemei
punct punct_treime(punct A, punct B);
punct punct_mij(punct A, punct B);
void draw_line(punct A, punct B, punct C, punct D, punct E);
void draw_tri(punct A, punct B, punct C, punct D, punct E);
void koch_line(punct A, punct E, int n);
void koch_snowflake(punct A, punct B, punct C);
double random();
double white();

//Functii necesare OpenGL
void render(void);

int main(int argc, char **argv){

	cout<<"Introduceti x = dimensiunea ferestrei (x*x):";
	cin>>l;
	cout<<"AVERTISMENT: La un numar de iteratii mai mare decat 10 timpul de executie depaseste 2 minute"<<endl<<"Introduceti numarul de iteratii:";
	cin>>iteratii;
	cout<<"Introduceti 1 pentru culori aletorii, 2 pentru fulg de zapada si 0 pentru a desna doar conturul:";
	cin>>mode;

	glutInit(&argc,argv);						//Initializare OpenGL Utiity Toolkit
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);	//Setarea modului de afisare
	glutInitWindowPosition(100,0);					//Setarea pozitiei initiale a ferestrei
	glutInitWindowSize(l,l);					//Definirea dimensiunilor ferstrei
	glutCreateWindow("Koch Snowflake");			//Creeaza fereastra noua
	glutDisplayFunc(render);					//Genereaza continutul ferestrei cu functia "render"
	glutMainLoop();

	return 0;

}

void render(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		//Curatarea ferestrei
	gluOrtho2D(0,l,l,0);						//Seteaza centrul sistemului de coordonate in coltul din dreapta-sus

	punct A, B, C;
	A.x = l/2-0.8*l/2; A.y = l/2+0.8*l*sqrt(3)/6;
	B.x = l/2+0.8*l/2; B.y = A.y;
	C = punct_mij(B, A);

    if(mode==1) {
        glBegin(GL_QUADS);					//Deseneaza un dreptunghi de cuori aleatorii de dimensiunile ferestrei
			glColor3f(random(),random(),random()); glVertex2f(0,0);
			glColor3f(random(),random(),random()); glVertex2f(0,l);
			glColor3f(random(),random(),random()); glVertex2f(l,l);
			glColor3f(random(),random(),random()); glVertex2f(l,0);
		glEnd();}

	else if(mode==2) {
		glBegin(GL_QUADS);					//Deseneaza un dreptunghi albastru de dimensiunile ferestrei
			glColor3f(0,0.611,0.807); glVertex2f(0,0);
			glColor3f(0.545,0.89,1); glVertex2f(0,l);
			glColor3f(0.415,0.7725,0.886); glVertex2f(l,l);
			glColor3f(0.462,0.7325,0.843); glVertex2f(l,0);
		glEnd();
	}
	else{
		double c=white();
		glBegin(GL_QUADS);					//Deseneaza un dreptunghi alb de dimensiunile ferstrei
		glColor3f(c,c,c); glVertex2f(0,0);
		c=white();
		glColor3f(c,c,c); glVertex2f(0,l);
		c=white();
		glColor3f(c,c,c); glVertex2f(l,l);
		c=white();
		glColor3f(c,c,c); glVertex2f(l,0);
		glEnd();
		c=1-c;
		glColor3f(c,c,c);					//Seteaza culoare cu care se va desena la o nuanta aleatoare de negru
	}

	koch_snowflake(A, B, C);

	glutSwapBuffers();						//Curata Bufferul
}


void koch_line(punct A, punct E, int n=1){				//Imparte segmentul in 3 subsegmente generand al trilea punct(varful triunghiului cu subsegmentul din mijloc ca baza)
	punct B, C, D;
	B = punct_treime(A, E);
	D = punct_treime(E, A);
	C = punct_mij(B, D);
	if (mode) draw_tri(A, B, C, D, E);
	if (n<iteratii) {
		koch_line(A, B, n+1);
		koch_line(B, C, n+1);
		koch_line(C, D, n+1);
		koch_line(D, E, n+1);
	}
	else if(!mode) draw_line(A, B, C, D, E);
}

void koch_snowflake(punct A, punct B, punct C){
	if(mode==1) {							//Deseneaza triunghiul initial (in functie de modul ales)
		glBegin(GL_TRIANGLES);
			glColor3f(random(),random(),random()); glVertex2f(B.x, B.y);
			glColor3f(random(),random(),random()); glVertex2f(C.x, C.y);
			glColor3f(random(),random(),random()); glVertex2f(A.x, A.y);
		glEnd();
	}
	else if(mode==2) {
		double c=white();
		glBegin(GL_TRIANGLES);
			glColor3f(c,c,c); glVertex2f(B.x, B.y);
			c=white();
			glColor3f(c,c,c); glVertex2f(C.x, C.y);
			c=white();
			glColor3f(c,c,c); glVertex2f(A.x, A.y);
		glEnd();
	}

	if(iteratii>0) {						//Apeleaza functia de generat puncte doar in cazul in care numarul de iteratii introdus este mai mare ca 0
		koch_line(A, B);
		koch_line(B, C);
		koch_line(C, A);
	}
	else if(!mode) {						//In cazul in care nr de iteratii este 0 deseneaza conturul triunghiului initial
		glColor3f(random(),random(),random());
		glBegin(GL_LINE_LOOP);
			glVertex2f(B.x, B.y);
			glVertex2f(C.x, C.y);
			glVertex2f(A.x, A.y);
		glEnd();
	}
}

punct punct_treime(punct A, punct B){					//Returneaza coordonatele puntului de pe segmentul AB situat la 1/3 de A
	punct C;
	C.x = A.x + (B.x - A.x)/3;
	C.y = A.y + (B.y - A.y)/3;
	return C;
}

punct punct_mij(punct A, punct B){					//Returneaza coordonatele punctului care  impreuna cu A si B formeaza un triunghi echilateral
	punct E;
	E.x = A.x + (cos(M_PI/3) * (B.x - A.x) - sin(M_PI/3) * (B.y - A.y));
	E.y = A.y + (sin(M_PI/3) * (B.x - A.x) + cos(M_PI/3) * (B.y - A.y));
	return E;
}


void draw_line(punct A, punct B, punct C, punct D, punct E){		//Deseneaza o linie franta care uneste cele 5 puncte in ordine
	glBegin(GL_LINE_STRIP);
		glVertex2f(A.x, A.y);
		glVertex2f(B.x, B.y);
		glVertex2f(C.x, C.y);
		glVertex2f(D.x, D.y);
		glVertex2f(E.x, E.y);
	glEnd();
}

void draw_tri(punct A, punct B, punct C, punct D, punct E){		//Deseneaza segmentele AB si DE si triunghiul ecilateral BCD
	if(mode==2) glColor3f(1,1,1);
	glBegin(GL_LINE_STRIP);
		glVertex2f(A.x, A.y);
		glVertex2f(B.x, B.y);
	glEnd();
	if(mode==2) {							//Ajusteaza culoarea triunghiului in functie de modul de lucru
		double c=white();
		glBegin(GL_TRIANGLES);
			glColor3f(c,c,c); glVertex2f(B.x, B.y);
			c=white();
			glColor3f(c,c,c); glVertex2f(C.x, C.y);
			c=white();
			glColor3f(c,c,c); glVertex2f(D.x, D.y);
		glEnd();
	}
        else {
		glBegin(GL_TRIANGLES);
			glColor3f(random(),random(),random()); glVertex2f(B.x, B.y);
			glColor3f(random(),random(),random()); glVertex2f(C.x, C.y);
			glColor3f(random(),random(),random()); glVertex2f(D.x, D.y);
		glEnd();
	}
	glBegin(GL_LINE_STRIP);
		glVertex2f(D.x, D.y);
		glVertex2f(E.x, E.y);
	glEnd();
}

double random (){					//Returneaza un numar aleator intre 0 si 1
	double x=rand();
	while(x>1) x/=10;
	return x;
}

double white (){					//Returneaza un numar aleator intre 0.91 si 1
	double x=random();
	while(x<0.9) x=random();
	return x;
}
