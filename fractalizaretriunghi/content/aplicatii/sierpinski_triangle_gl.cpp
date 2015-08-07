#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;

struct punct{double x, y;};
struct triunghi{punct A, B, C;};
int iteratii;
int l;				//dimensiunea ferestrei
int mode;			//modul de lucru

//Functiile problemei
punct punct_mij(punct A, punct B);
void draw(triunghi t, int n);
void sierpinski(triunghi t, int n);
void sierpinski_albastru (triunghi t, int n);
double random();

//Functii necesare OpenGL
void render(void);

int main(int argc, char **argv){

	cout<<"Introduceti x = dimensiunea ferestrei (x*x):";
	cin>>l;
	cout<<"AVERTISMENT: La un numar de iteratii mai mare decat 14 timpul de executie depaseste un minut"<<endl<<"Introduceti numarul de iteratii:";
	cin>>iteratii;
	cout<<"Introduceti 1 pentru culori aletorii, 2 pentru albastru si 0 pentru a desna doar conturul:";
	cin>>mode;

	glutInit(&argc,argv);						//Initializare OpenGL Utiity Toolkit
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);	//Setarea modului de afisare
	glutInitWindowPosition(100,0);				//Setarea pozitiei initiale a ferestrei
	glutInitWindowSize(l,l);					//Definirea dimensiunilor ferstrei
	glutCreateWindow("Serpinski Triangle");		//Creeaza fereastra noua
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
	C.x = A.x + (cos(M_PI/3) * (B.x - A.x) - sin(M_PI/3) * (B.y - A.y));
	C.y = A.y - (sin(M_PI/3) * (B.x - A.x) + cos(M_PI/3) * (B.y - A.y));
	triunghi t;
	t.A = A;
	t.B = B;
	t.C = C;

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
	else {
	    glColor3f(1,1,1);
	    glBegin(GL_QUADS);
            glVertex2f(0,0);
            glVertex2f(0,l);
			glVertex2f(l,l);
			glVertex2f(l,0);
        glEnd();
        glColor3f(0,0,0);
	}


	if(mode<2) sierpinski(t,0);
	else sierpinski_albastru(t,0);

	glutSwapBuffers();						//Curata Bufferul
}


void sierpinski(triunghi t, int n) {
	draw(t,n);

	if(iteratii>n) {
	    punct D, E, F;
	    triunghi u, v, w;
		D = punct_mij(t.A,t.B);
		E = punct_mij(t.B,t.C);
		F = punct_mij(t.A,t.C);
		u.A = D; u.B = E; u.C = t.B;
		v.A = D; v.B = F; v.C = t.A;
		w.A = E; w.B = F; w.C = t.C;
		sierpinski(u,n+1);
		sierpinski(v,n+1);
		sierpinski(w,n+1);
	}
}

void sierpinski_albastru(triunghi t, int n) {
	punct D, E, F;
	triunghi u, v, w;
	D = punct_mij(t.A,t.B);
	E = punct_mij(t.B,t.C);
	F = punct_mij(t.A,t.C);
	u.A = D; u.B = E; u.C = t.B;
	v.A = D; v.B = F; v.C = t.A;
	w.A = E; w.B = F; w.C = t.C;
	if(iteratii>n) {
		sierpinski_albastru(u,n+1);
		sierpinski_albastru(v,n+1);
		sierpinski_albastru(w,n+1);
	}
	else draw(t, n);
}

punct punct_mij(punct A, punct B){					//Returneaza coordonatele punctului din mijlocul segmentului AB
	punct E;
	E.x = (A.x + B.x)/2;
	E.y = (A.y + B.y)/2;
	return E;
}



void draw(triunghi t, int n){		//Deseneaza triungiul t conform modului ales
    if(mode==1) {
        glBegin(GL_TRIANGLES);
            glColor3f(random(),random(),random()); glVertex2f(t.B.x, t.B.y);
            glColor3f(random(),random(),random()); glVertex2f(t.C.x, t.C.y);
            glColor3f(random(),random(),random()); glVertex2f(t.A.x, t.A.y);
        glEnd();
        }
    else if(mode==2){
        glColor3f(0,0.698,0.9333);
        glBegin(GL_TRIANGLES);
            glVertex2f(t.B.x, t.B.y);
            glVertex2f(t.C.x, t.C.y);
            glVertex2f(t.A.x, t.A.y);
        glEnd();
        glColor3f(0.09411,0.4549,0.80392);
        glBegin(GL_LINE_LOOP);
            glVertex2f(t.B.x, t.B.y);
            glVertex2f(t.C.x, t.C.y);
            glVertex2f(t.A.x, t.A.y);
        glEnd();
        }

    else {
        glBegin(GL_LINE_LOOP);
            glVertex2f(t.B.x, t.B.y);
            glVertex2f(t.C.x, t.C.y);
            glVertex2f(t.A.x, t.A.y);
        glEnd();
    }
}

double random (){					//Returneaza un numar aleator intre 0 si 1
	double x=rand();
	while(x>1) x/=10;
	return x;
}
