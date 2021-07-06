#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

// GUMILANG ADI SAPUTRA - 672019159
// DENDY ILHAM NOVIADHI- 672019328
void init(void);
void tampil(void);
void ukuran(int,int);
void keyboard(unsigned char, int, int);
void mouseMove(int x, int y);
void mouseButton(int button, int state, int x, int y);
using namespace std;
float xrot = 0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mousedown = false;
int is_depth;

int main ( int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(900,700);
	glutInitWindowPosition(250,80);
	glutCreateWindow("TORONTO UNIVERSITY");
	init();
	glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);
	glutReshapeFunc(ukuran);
	glutIdleFunc(tampil);
	glutMainLoop();
	return 0;
}

void init(void){
	glClearColor (0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	is_depth=1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9.0);
	glLineWidth(6.0f);
}



void papantulis (void){
    //dari kanan
    glBegin(GL_QUADS);
    glColor3f(0.5,0.0,0.0);
    glVertex3f(-20.0,-10.0,-10.0);  
    glVertex3f(-20.0,10.0,-10.0);  
    glVertex3f(-20.0,10.0,5.0);  
    glVertex3f(-20.0,-10.0,5.0);  
    //PAPAN TULIS
        //depab
        glColor3f(1.0,1.0,1.0);
        glVertex3f(-19.5,-2.0,-8.0);  
        glVertex3f(-19.5,5.0,-8.0);  
        glVertex3f(-19.5,5.0,3.0);  
        glVertex3f(-19.5,-2.0,3.0);  
        //Kiri
        glColor3f(0.0,0.0,0.0);
        glVertex3f(-19.5,-2.0,3.0);  
        glVertex3f(-19.5,5.0,3.0);  
        glVertex3f(-20.0,5.0,3.0);  
        glVertex3f(-20.0,-2.0,3.0);  
        //Kanan
        glColor3f(0.0,0.0,0.0);
        glVertex3f(-19.5,-2.0,-8.0);  
        glVertex3f(-19.5,5.0,-8.0);  
        glVertex3f(-20.0,5.0,-8.0);  
        glVertex3f(-20.0,-2.0,-8.0);  
        //Aatas
        glColor3f(0.0,0.0,0.0);
        glVertex3f(-19.5,5.0,3.0);  
        glVertex3f(-20.0,5.0,3.0);  
        glVertex3f(-20.0,5.0,-8.0);  
        glVertex3f(-19.5,5.0,-8.0);  
        //Bawh
        glColor3f(0.0,0.0,0.0);
        glVertex3f(-19.5,-2.0,3.0);  
        glVertex3f(-20.0,-2.0,3.0);  
        glVertex3f(-20.0,-2.0,-8.0);  
        glVertex3f(-19.5,-2.0,-8.0);  
    glEnd();
}
void meja (void){
    	//KAKI
        //KIRI
        glBegin(GL_QUADS);
        glColor3f(0.0,0.0,.0);
        glVertex3f(-9,-10,-2.5);  
        glVertex3f(-9,-4,-2.5);  
        glVertex3f(-8.5,-4,-2.5);  
        glVertex3f(-8.5,-10,-2.5);  
        //Depan
        glVertex3f(-9,-10,-2);  
        glVertex3f(-9,-4,-2);  
        glVertex3f(-8.5,-4,-2);  
        glVertex3f(-8.5,-10,-2);  
        glEnd();
        //kanan
        glBegin(GL_QUADS);
        glColor3f(0.0,0.0,0.0);
        glVertex3f(-8.5,-10,-2);  
        glVertex3f(-8.5,-4,-2);  
        glVertex3f(-8.5,-4,-2.5);  
        glVertex3f(-8.5,-10,-2.5);  
        //krii
        glVertex3f(-9,-10,-2);  
        glVertex3f(-9,-4,-2);  
        glVertex3f(-9,-4,-2.5);  
        glVertex3f(-9,-10,-2.5);  
        glEnd();
        //KANAN
        glBegin(GL_QUADS);
        glColor3f(0.0,0.0,.0);
        glVertex3f(-7,-10,-2.5);  
        glVertex3f(-7,-4,-2.5);  
        glVertex3f(-6.5,-4,-2.5);  
        glVertex3f(-6.5,-10,-2.5);  
        //depan
        glVertex3f(-7,-10,-2);  
        glVertex3f(-7,-4,-2);  
        glVertex3f(-6.5,-4,-2);  
        glVertex3f(-6.5,-10,-2);  
        glEnd();
        //kamnan
        glBegin(GL_QUADS);
        glColor3f(0.0,0.0,0.0);
        glVertex3f(-6.5,-10,-2);  
        glVertex3f(-6.5,-4,-2);  
        glVertex3f(-6.5,-4,-2.5);  
        glVertex3f(-6.5,-10,-2.5);  
        //kii
        glVertex3f(-7,-10,-2);  
        glVertex3f(-7,-4,-2);  
        glVertex3f(-7,-4,-2.5);  
        glVertex3f(-7,-10,-2.5);  
        glEnd();

    	//BLAKANG
        //KIRI
        glBegin(GL_QUADS);
        glColor3f(0.0,0.0,.0);
        glVertex3f(-9,-10,-6.5);  
        glVertex3f(-9,-4,-6.5);  
        glVertex3f(-8.5,-4,-6.5);  
        glVertex3f(-8.5,-10,-6.5);  
        //depan
        glVertex3f(-9,-10,-6);  
        glVertex3f(-9,-4,-6);  
        glVertex3f(-8.5,-4,-6);  
        glVertex3f(-8.5,-10,-6);  
        glEnd();
        //kanan
        glBegin(GL_QUADS);
        glColor3f(0.0,0.0,0.0);
        glVertex3f(-8.5,-10,-6);  
        glVertex3f(-8.5,-4,-6);  
        glVertex3f(-8.5,-4,-6.5);  
        glVertex3f(-8.5,-10,-6.5);  
        //krii
        glVertex3f(-9,-10,-6);  
        glVertex3f(-9,-4,-6);  
        glVertex3f(-9,-4,-6.5);  
        glVertex3f(-9,-10,-6.5);  
        glEnd();

        //KANAN
        glBegin(GL_QUADS);
        glColor3f(0.0,0.0,.0);
        glVertex3f(-7,-10,-6.5);  
        glVertex3f(-7,-4,-6.5);  
        glVertex3f(-6.5,-4,-6.5);  
        glVertex3f(-6.5,-10,-6.5);  
        //depan
        glVertex3f(-7,-10,-6);  
        glVertex3f(-7,-4,-6);  
        glVertex3f(-6.5,-4,-6);  
        glVertex3f(-6.5,-10,-6);  
        glEnd();
        //kanan
        glBegin(GL_QUADS);
        glColor3f(0.0,0.0,0.0);
        glVertex3f(-6.5,-10,-6);  
        glVertex3f(-6.5,-4,-6);  
        glVertex3f(-6.5,-4,-6.5);  
        glVertex3f(-6.5,-10,-6.5);  
        //kiri
        glVertex3f(-7,-10,-6);  
        glVertex3f(-7,-4,-6);  
        glVertex3f(-7,-4,-6.5);  
        glVertex3f(-7,-10,-6.5);  
        glEnd();
    //ATAS
        //depan
        glBegin(GL_QUADS);
        glColor3f(0.0,0.0,0.1);
        glVertex3f(-9,-4.0,-2);  
        glVertex3f(-9,-3.5,-2);  
        glVertex3f(-6.5,-3.5,-2);  
        glVertex3f(-6.5,-4.0,-2);  
        //blakang
        glVertex3f(-9,-4.0,-6.5);  
        glVertex3f(-9,-3.5,-6.5);  
        glVertex3f(-6.5,-3.5,-6.5);  
        glVertex3f(-6.5,-4.0,-6.5);  
        //kanan
        glColor3f(0.0,0.0,1.0);
        glVertex3f(-6.5,-4.0,-2);  
        glVertex3f(-6.5,-3.5,-2);  
        glVertex3f(-6.5,-3.5,-6.5);  
        glVertex3f(-6.5,-4.0,-6.5);  
        //kiri
        glVertex3f(-9,-4.0,-2);  
        glVertex3f(-9,-3.5,-2);  
        glVertex3f(-9,-3.5,-6.5);  
        glVertex3f(-9,-4.0,-6.5);  
        //atas
        glColor3f(1.0,0.0,0.0);
        glVertex3f(-9,-3.5,-2);  
        glVertex3f(-9,-3.5,-6.5);  
        glVertex3f(-6.5,-3.5,-6.5);  
        glVertex3f(-6.5,-3.5,-2);  
        glEnd();

}

void kursi (void){
    //KAKI
        //KIRI
        glBegin(GL_QUADS);
        glColor3f(0.5,0.5,.0);
        glVertex3f(-3,-10,-3.5);  
        glVertex3f(-3,-7,-3.5);  
        glVertex3f(-2.5,-7,-3.5);  
        glVertex3f(-2.5,-10,-3.5);  
        //depan
        glVertex3f(-3,-10,-3);  
        glVertex3f(-3,-7,-3);  
        glVertex3f(-2.5,-7,-3);  
        glVertex3f(-2.5,-10,-3);  
        glEnd();
        //kanan
        glBegin(GL_QUADS);
        glColor3f(1.0,0.0,0.0);
        glVertex3f(-2.5,-10,-3);  
        glVertex3f(-2.5,-7,-3);  
        glVertex3f(-2.5,-7,-3.5);  
        glVertex3f(-2.5,-10,-3.5);  
        //krii
        glVertex3f(-3,-10,-3);  
        glVertex3f(-3,-7,-3);  
        glVertex3f(-3,-7,-3.5);  
        glVertex3f(-3,-10,-3.5);  
        glEnd();

        //KANAN
        glBegin(GL_QUADS);
        glColor3f(0.5,0.5,.0);
        glVertex3f(-1,-10,-3.5);  
        glVertex3f(-1,-4,-3.5);  
        glVertex3f(-0.5,-4,-3.5);  
        glVertex3f(-0.5,-10,-3.5);  
        //depan
        glVertex3f(-1,-10,-3);  
        glVertex3f(-1,-3,-3);  
        glVertex3f(-0.5,-3,-3);  
        glVertex3f(-0.5,-10,-3);  
        glEnd();
        //kanan
        glBegin(GL_QUADS);
        glColor3f(1.0,0.0,0.0);
        glVertex3f(-0.5,-10,-3);  
        glVertex3f(-0.5,-4,-3);  
        glVertex3f(-0.5,-4,-3.5);  
        glVertex3f(-0.5,-10,-3.5);  
        //krii
        glVertex3f(-1,-10,-3);  
        glVertex3f(-1,-4,-3);  
        glVertex3f(-1,-4,-3.5);  
        glVertex3f(-1,-10,-3.5);  
        glEnd();

    //BLAKANG
        //KIRI
        glBegin(GL_QUADS);
        glColor3f(0.5,0.5,.0);
        glVertex3f(-3,-10,-4.5);  
        glVertex3f(-3,-7,-4.5);  
        glVertex3f(-2.5,-7,-4.5);  
        glVertex3f(-2.5,-10,-4.5);  
        //depan
        glVertex3f(-3,-10,-5);  
        glVertex3f(-3,-7,-5);  
        glVertex3f(-2.5,-7,-5);  
        glVertex3f(-2.5,-10,-5);  
        glEnd();
        //Kanan
        glBegin(GL_QUADS);
        glColor3f(1.0,0.0,0.0);
        glVertex3f(-2.5,-10,-5);  
        glVertex3f(-2.5,-7,-5);  
        glVertex3f(-2.5,-7,-4.5);  
        glVertex3f(-2.5,-10,-4.5);  
        //kiri
        glVertex3f(-3,-10,-5);  
        glVertex3f(-3,-7,-5);  
        glVertex3f(-3,-7,-4.5);  
        glVertex3f(-3,-10,-4.5);  
        glEnd();

        //KANAN
        glBegin(GL_QUADS);
        glColor3f(0.5,0.5,.0);
        glVertex3f(-1,-10,-4.5);  
        glVertex3f(-1,-4,-4.5);  
        glVertex3f(-0.5,-4,-4.5);  
        glVertex3f(-0.5,-10,-4.5);  
        //depan
        glVertex3f(-1,-10,-5);  
        glVertex3f(-1,-3,-5);  
        glVertex3f(-0.5,-3,-5);  
        glVertex3f(-0.5,-10,-5);  
        glEnd();
        //Knan
        glBegin(GL_QUADS);
        glColor3f(1.0,0.0,0.0);
        glVertex3f(-0.5,-10,-5);  
        glVertex3f(-0.5,-4,-5);  
        glVertex3f(-0.5,-4,-4.5);  
        glVertex3f(-0.5,-10,-4.5);  
        //krii
        glVertex3f(-1,-10,-5);  
        glVertex3f(-1,-4,-5);  
        glVertex3f(-1,-4,-4.5);  
        glVertex3f(-1,-10,-4.5);  
        glEnd();
    //ATAS
        //depan
        glBegin(GL_QUADS);
        glColor3f(0.0,0.0,0.1);
        glVertex3f(-3,-7.0,-3);  
        glVertex3f(-3,-6.5,-3);  
        glVertex3f(-1,-6.5,-3);  
        glVertex3f(-1,-7.0,-3);  
        //blakang
        glVertex3f(-3,-7.0,-5);  
        glVertex3f(-3,-6.5,-5);  
        glVertex3f(-1,-6.5,-5);  
        glVertex3f(-1,-7.0,-5);  
        //kanan
        glColor3f(0.0,0.0,1.0);
        glVertex3f(-0.5,-7.0,-3.5);  
        glVertex3f(-0.5,-6.5,-3.5);  
        glVertex3f(-0.5,-6.5,-4.5);  
        glVertex3f(-0.5,-7.0,-4.5);  
        //kiri
        glVertex3f(-3,-7.0,-3);  
        glVertex3f(-3,-6.5,-3);  
        glVertex3f(-3,-6.5,-5);  
        glVertex3f(-3,-7.0,-5);  
        //atas
        glColor3f(0.0,0.0,1.0);
        glVertex3f(-3,-6.5,-3);  
        glVertex3f(-3,-6.5,-5);  
        glVertex3f(-0.5,-6.5,-5);  
        glVertex3f(-0.5,-6.5,-3);  
        //kanan atas
        glColor3f(1.0,1.0,1.0);
        glVertex3f(-0.5,-4,-3);  
        glVertex3f(-0.5,-3,-3);  
        glVertex3f(-0.5,-3,-5);  
        glVertex3f(-0.5,-4,-5);  
        //krii atas
        glVertex3f(-1,-4,-3);  
        glVertex3f(-1,-3,-3);  
        glVertex3f(-1,-3,-5);  
        glVertex3f(-1,-4,-5);  
        //Atas
        glVertex3f(-1,-3,-3);  
        glVertex3f(-1,-3,-5);  
        glVertex3f(-0.5,-3,-5);  
        glVertex3f(-0.5,-3,-3);  
        glEnd();
}

void loker (void){
    //kanan
    glBegin(GL_QUADS);
    glColor3ub(188, 188, 188);
    glVertex3f(20,-9.9,-9.9);  
    glVertex3f(20,0,-9.9);  
    glVertex3f(20,0,-7);  
    glVertex3f(20,-9.9,-7);  
    glEnd();
    //Kiri
    glBegin(GL_QUADS);
    glColor3ub(188, 188, 188);
    glVertex3f(10,-9.9,-9.9);  
    glVertex3f(10,0,-9.9);  
    glVertex3f(10,0,-7);  
    glVertex3f(10,-9.9,-7);  
    glEnd();
    //Depan
    glBegin(GL_POLYGON);
    glColor3ub(188, 188, 188);
    glVertex3f(20,-9.9,-7);  
    glVertex3f(20,0,-7);  
    glVertex3f(10,0,-7);  
    glVertex3f(10,-9.9,-7);  
    glEnd();
    //Blakang
    glBegin(GL_POLYGON);
    glColor3ub(188, 188, 188);
    glVertex3f(20,-9.9,-9.9);  
    glVertex3f(20,0,-9.9);  
    glVertex3f(10,0,-9.9);  
    glVertex3f(10,-9.9,-9.9);  
    glEnd();
    //Atas
    glBegin(GL_POLYGON);
    glColor3ub(188, 188, 188);
    glVertex3f(20,0,-7);  
    glVertex3f(20,0,-9.9);  
    glVertex3f(10,0,-9.9);  
    glVertex3f(10,0,-7);  
    glEnd();
    //Bawag
    glBegin(GL_POLYGON);
    glColor3ub(188, 188, 188);
    glVertex3f(20,-9.9,-7);  
    glVertex3f(20,-9.9,-9.9);  
    glVertex3f(10,-9.9,-9.9);  
    glVertex3f(10,-9.9,-7);  
    glEnd();
    //Pintu
    glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);
    //Kanan Bawah
    glVertex3f(17,-8,-6.8);  
    glVertex3f(17,-6,-6.8);  
    glVertex3f(19,-6,-6.8);  
    glVertex3f(19,-8,-6.8);  
    //Kanan Atas
    glVertex3f(17,-4,-6.8);  
    glVertex3f(17,-1,-6.8);  
    glVertex3f(19,-1,-6.8);  
    glVertex3f(19,-4,-6.8);  
    //Tengah Bawah
    glVertex3f(14,-8,-6.8);  
    glVertex3f(14,-6,-6.8);  
    glVertex3f(16,-6,-6.8);  
    glVertex3f(16,-8,-6.8);  
    //Tengah Atas
    glVertex3f(14,-4,-6.8);  
    glVertex3f(14,-1,-6.8);  
    glVertex3f(16,-1,-6.8);  
    glVertex3f(16,-4,-6.8);  
    //Kiri Bawah
    glVertex3f(11,-8,-6.8);  
    glVertex3f(11,-6,-6.8);  
    glVertex3f(13,-6,-6.8);  
    glVertex3f(13,-8,-6.8);  
    //Kiri Atas
    glVertex3f(11,-4,-6.8);  
    glVertex3f(11,-1,-6.8);  
    glVertex3f(13,-1,-6.8);  
    glVertex3f(13,-4,-6.8);  
        
    glEnd();

}

void ngon (int n,float cx, float cy,float radius, float rotAngle) {
    double angle,angleInc;
    int x;
    if(n<2) return;
    angle = rotAngle*3.14159265/180;
    angleInc = 2*3.14159265/n;
    glVertex3f(radius*cos(angle)+cx, radius*sin(angle)+cy,-9.9);
    for (x=0;x<n;x++){
        angle +=angleInc;
        glVertex3f(radius*cos(angle)+cx, radius*sin(angle)+cy,-9.9);
    }
}

void jamdinding(void){
    int a,b=0;
    glBegin(GL_POLYGON);
    for (a=0;a<10;a++){
        glColor3f(1.0,1.0,1.0);
        ngon(100,-3,3,2,20);
        a++;
    }
    glEnd();

    //jarum menit
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-3.0,3.0,-9.8);
    glVertex3f(-3.2,4.0,-9.8);
    glVertex3f(-3.0,5.0,-9.8);
    glVertex3f(-2.8,4.0,-9.8);
    glEnd();
    //jarum jam
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-3.0,3.0,-9.8);
    glVertex3f(-2.5,3.2,-9.8);
    glVertex3f(-2.0,3.0,-9.8);
    glVertex3f(-2.5,2.8,-9.8);
    glEnd();
}


void tampil (void)
{
	if (is_depth)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);

	//badan
	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(-40.0, -10.0, 10.0);
	glVertex3f(-40.0, 25.0, 10.0);
	glVertex3f(50.0, 25.0, 10.0);
	glVertex3f(50.0, -10.0, 10.0);
	glEnd();
	
	//tengah
	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(-12.0, -10.0, 15.0);
	glVertex3f(-12.0, 25.0, 15.0);
	glVertex3f(22.0, 25.0, 15.0);
	glVertex3f(22.0, -10.0, 15.0);
	glEnd();

	//tembok belakang
	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(-40.0, -10.0, -10.0);
	glVertex3f(-40.0, 25.0, -10.0);
	glVertex3f(50.0, 25.0, -10.0);
	glVertex3f(50.0, -10.0, -10.0);
	glEnd();

	//depan
	glBegin(GL_QUADS);
	glColor3ub(192,192,192);
	glVertex3f(-3.0, -10.0, 17.0);
	glVertex3f(-3.0, 45.0, 17.0);
	glVertex3f(13.0, 45.0, 17.0);
	glVertex3f(13.0, -10.0, 17.0);
	glEnd();

	//depan belakang
	glBegin(GL_QUADS);
	glColor3ub(192,192,192);
	glVertex3f(-3.0, 35.0, 0.0);
	glVertex3f(-3.0, 45.0, 0.0);
	glVertex3f(13.0, 45.0, 0.0);
	glVertex3f(13.0, 35.0, 0.0);
	glEnd();
	
	//depan
	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(5.0, 45.0, 15.0);
	glVertex3f(-12.0, 25.0, 15.0);
	glVertex3f(22.0, 25.0, 15.0);
	glVertex3f(5.0, 45.0, 15.0);
	glEnd();

	//kanan	tengah
	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(22.0, 25.0, 15.0);
	glVertex3f(22.0, -10.0, 15.0);
	glVertex3f(22.0, -10.0, 10.0);
	glVertex3f(22.0, 25.0, 10.0);
	glEnd();

	//kanan	depan
	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(13.0, 45.0, 17.0);
	glVertex3f(13.0, -10.0, 17.0);
	glVertex3f(13.0, -10.0, 0.0);
	glVertex3f(13.0, 45.0, 0.0);
	glEnd();

	//kiri tengah
	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(-12.0, 25.0, 15.0);
	glVertex3f(-12.0, -10.0, 15.0);
	glVertex3f(-12.0, -10.0, 10.0);
	glVertex3f(-12.0, 25.0, 10.0);
	glEnd();

	//kiri depan
	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(-3.0, 45.0, 17.0);
	glVertex3f(-3.0, -10.0, 17.0);
	glVertex3f(-3.0, -10.0, 0.0);
	glVertex3f(-3.0, 45.0, 0.0);
	glEnd();

	//genteng tengah kanan
	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(13.0,35.0, 15.0);//panjang,tinggi, dekat
	glVertex3f(22.0, 25.0, 15.0);
	glVertex3f(22.0, 25.0, 10.0);
	glVertex3f(13.0,35.0, 0.0);
	glEnd();
	
	//genteng tengah kiri
	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(-12.0,25.0, 15.0);//
	glVertex3f(-3.0, 35.0, 15.0);
	glVertex3f(-3.0, 35.0, 0.0);
	glVertex3f(-12.0,25.0, 10.0);
	glEnd();

	//genteng badan kiri
	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(-40.0, 25.0, 10.0);
	glVertex3f(-45.0, 35.0, 0.0);
	glVertex3f(-3.0, 35.0, 0.0);
	glVertex3f(-10.0, 25.0, 10.0);
	glEnd();

	//genteng badan belakang
	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(-45.0, 35.0, 0.0);
	glVertex3f(-40.0, 25.0, -10.0);
	glVertex3f(50.0, 25.0, -10.0);
	glVertex3f(55.0, 35.0, 0.0);
	glEnd();

	//genteng badan kanan
	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(22.0, 25.0, 10.0);
	glVertex3f(13.0, 35.0, 0.0);
	glVertex3f(55.0, 35.0, 0.0);
	glVertex3f(50.0, 25.0, 10.0);
	glEnd();

	//bawah
	glBegin(GL_QUADS);
	glColor3f(0.5,0,0 );
	glVertex3f(-50.0,-10.0, 10.0);
	glVertex3f(70.0, -10.0, 10.0);
	glVertex3f(70.0, -10.0, -10.0);
	glVertex3f(-50.0,-10.0, -10.0);
	glEnd();

	//atas belakang kiri
	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(-4.0, 45.0, -1.0);
	glVertex3f(-4.0, 50.0, -1.0);
	glVertex3f(-1.0, 50.0, -1.0);
	glVertex3f(-1.0, 45.0, -1.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(-4.0, 45.0, 2.0);
	glVertex3f(-4.0, 50.0, 2.0);
	glVertex3f(-1.0, 50.0, 2.0);
	glVertex3f(-1.0, 45.0, 2.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(-4.0, 50.0, 2.0);
	glVertex3f(-4.0, 45.0, 2.0);
	glVertex3f(-4.0, 45.0, -1.0);
	glVertex3f(-4.0, 50.0, -1.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(-1.0, 50.0, 2.0);
	glVertex3f(-1.0, 45.0, 2.0);
	glVertex3f(-1.0, 45.0, -1.0);
	glVertex3f(-1.0, 50.0, -1.0);
	glEnd();

	//atas depan kiri
		glBegin(GL_QUADS);
	glColor3ub		(169,169,169);
	glVertex3f(-4.0, 45.0, 18.0);
	glVertex3f(-4.0, 50.0, 18.0);
	glVertex3f(-1.0, 50.0, 18.0);
	glVertex3f(-1.0, 45.0, 18.0);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(-4.0, 45.0, 15.0);
	glVertex3f(-4.0, 50.0, 15.0);
	glVertex3f(-1.0, 50.0, 15.0);
	glVertex3f(-1.0, 45.0, 15.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(-1.0, 50.0, 18.0);
	glVertex3f(-1.0, 45.0, 18.0);
	glVertex3f(-1.0, 45.0, 15.0);
	glVertex3f(-1.0, 50.0, 15.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(-4.0, 50.0, 18.0);
	glVertex3f(-4.0, 45.0, 18.0);
	glVertex3f(-4.0, 45.0, 15.0);
	glVertex3f(-4.0, 50.0, 15.0);
	glEnd();

	//atas depan  kanan
	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(11.0, 45.0, 18.0);
	glVertex3f(11.0, 50.0, 18.0);
	glVertex3f(14.0, 50.0, 18.0);
	glVertex3f(14.0, 45.0, 18.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(11.0, 45.0, 15.0);
	glVertex3f(11.0, 50.0, 15.0);
	glVertex3f(14.0, 50.0, 15.0);
	glVertex3f(14.0, 45.0, 15.0);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(14.0, 50.0, 18.0);
	glVertex3f(14.0, 45.0, 18.0);
	glVertex3f(14.0, 45.0, 15.0);
	glVertex3f(14.0, 50.0, 15.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(11.0, 50.0, 18.0);
	glVertex3f(11.0, 45.0, 18.0);
	glVertex3f(11.0, 45.0, 15.0);
	glVertex3f(11.0, 50.0, 15.0);
	glEnd();

	//atas belakang kanan
	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(11.0, 45.0, -1.0);
	glVertex3f(11.0, 50.0, -1.0);
	glVertex3f(14.0, 50.0, -1.0);
	glVertex3f(14.0, 45.0, -1.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(11.0, 45.0, 2.0);
	glVertex3f(11.0, 50.0, 2.0);
	glVertex3f(14.0, 50.0, 2.0);
	glVertex3f(14.0, 45.0, 2.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(11.0, 50.0, 2.0);
	glVertex3f(11.0, 45.0, 2.0);
	glVertex3f(11.0, 45.0, -1.0);
	glVertex3f(11.0, 50.0, -1.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(14.0, 50.0, 2.0);
	glVertex3f(14.0, 45.0, 2.0);
	glVertex3f(14.0, 45.0, -1.0);
	glVertex3f(14.0, 50.0, -1.0);
	glEnd();

	//bawah
	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(-3.0,45.0, 17.0);
	glVertex3f(13.0,45.0, 17.0);
	glVertex3f(13.0,45.0, 0.0);
	glVertex3f(-3.0,45.0, 0.0);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(-4.0,50.0, 18.0);
	glVertex3f(-1.0,50.0, 18.0);
	glVertex3f(-1.0,50.0, 15.0);
	glVertex3f(-4.0,50.0, 15.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(-4.0,45.0, 18.0);
	glVertex3f(-1.0,45.0, 18.0);
	glVertex3f(-1.0,45.0, 15.0);
	glVertex3f(-4.0,45.0, 15.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(11.0,50.0, 18.0);
	glVertex3f(14.0,50.0, 18.0);
	glVertex3f(14.0,50.0, 15.0);
	glVertex3f(11.0,50.0, 15.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(11.0,45.0, 18.0);
	glVertex3f(14.0,45.0, 18.0);
	glVertex3f(14.0,45.0, 15.0);
	glVertex3f(11.0,45.0, 15.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(11.0,50.0, 2.0);
	glVertex3f(14.0,50.0, 2.0);
	glVertex3f(14.0,50.0, -1.0);
	glVertex3f(11.0,50.0, -1.0);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(11.0,45.0, 2.0);
	glVertex3f(14.0,45.0, 2.0);
	glVertex3f(14.0,45.0, -1.0);
	glVertex3f(11.0,45.0, -1.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(-4.0,50.0, 2.0);
	glVertex3f(-1.0,50.0, 2.0);
	glVertex3f(-1.0,50.0, -1.0);
	glVertex3f(-4.0,50.0, -1.0);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.5,0,0);
	glVertex3f(-4.0,45.0, 2.0);
	glVertex3f(-1.0,45.0, 2.0);
	glVertex3f(-1.0,45.0, -1.0);
	glVertex3f(-4.0,45.0, -1.0);
	glEnd();

	//tembok atas L
	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(-3.0, 50.0, 15.0);
	glVertex3f(-3.0, 45.0, 15.0);
	glVertex3f(-3.0, 45.0, -1.0);
	glVertex3f(-3.0, 50.0, -1.0);
	glEnd();

	//tembok atas R
	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(13.0, 50.0, 15.0);
	glVertex3f(13.0, 45.0, 15.0);
	glVertex3f(13.0, 45.0, -1.0);
	glVertex3f(13.0, 50.0, -1.0);
	glEnd();

	//tembok atas depan
	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(-3.0, 45.0, 17.0);
	glVertex3f(-3.0, 50.0, 17.0);
	glVertex3f(13.0, 50.0, 17.0);
	glVertex3f(13.0, 45.0, 17.0);
	glEnd();

	//tembok atas belakang
	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(-3.0, 45.0, 0.0);
	glVertex3f(-3.0, 50.0, 0.0);
	glVertex3f(13.0, 50.0, 0.0);
	glVertex3f(13.0, 45.0, 0.0);
	glEnd();

	//tembok kirii depann
	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(-60.0, -10.0, 15.0);
	glVertex3f(-60.0, 25.0, 15.0);
	glVertex3f(-40.0, 25.0, 15.0);
	glVertex3f(-40.0, -10.0, 15.0);
	glEnd();

	//tembok kirii belakang
	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(-60.0, -10.0, -15.0);
	glVertex3f(-60.0, 25.0, -15.0);
	glVertex3f(-40.0, 25.0, -15.0);
	glVertex3f(-40.0, -10.0, -15.0);
	glEnd();

	//kiri pendek depan
	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(-40.0, 25.0, 15.0);
	glVertex3f(-40.0, -10.0, 15.0);
	glVertex3f(-40.0, -10.0, 10.0);
	glVertex3f(-40.0, 25.0, 10.0);
	glEnd();
	
	//kiri pendek belakang
	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(-40.0, 25.0, -10.0);
	glVertex3f(-40.0, -10.0, -10.0);
	glVertex3f(-40.0, -10.0, -15.0);
	glVertex3f(-40.0, 25.0, -15.0);
	glEnd();

	//kiri
	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(-60.0, 25.0, 15.0);
	glVertex3f(-60.0, -10.0, 15.0);
	glVertex3f(-60.0, -10.0, -15.0);
	glVertex3f(-60.0, 25.0, -15.0);
	glEnd();
	
	//tembok kanan depan
	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(70.0, -10.0, 15.0);
	glVertex3f(70.0, 25.0, 15.0);
	glVertex3f(50.0, 25.0, 15.0);
	glVertex3f(50.0, -10.0, 15.0);
	glEnd();

	//tembok kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(70.0, -10.0, -15.0);
	glVertex3f(70.0, 25.0, -15.0);
	glVertex3f(50.0, 25.0, -15.0);
	glVertex3f(50.0, -10.0, -15.0);
	glEnd();
	
	//kanan pendek
	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(50.0, 25.0, 15.0);
	glVertex3f(50.0, -10.0, 15.0);
	glVertex3f(50.0, -10.0, 10.0);
	glVertex3f(50.0, 25.0, 10.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(50.0, 25.0, -15.0);
	glVertex3f(50.0, -10.0, -15.0);
	glVertex3f(50.0, -10.0, -10.0);
	glVertex3f(50.0, 25.0, -10.0);
	glEnd();


	//kanan
	glBegin(GL_QUADS);
	glColor3ub(169,169,169);
	glVertex3f(70.0, 25.0, 15.0);
	glVertex3f(70.0, -10.0, 15.0);
	glVertex3f(70.0, -10.0, -15.0);
	glVertex3f(70.0, 25.0, -15.0);
	glEnd();

	//kiri atap depan
	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(-60.0, 25.0, 15.0);
	glVertex3f(-55.0, 30.0, 12.0);
	glVertex3f(-45.0, 30.0, 12.0);
	glVertex3f(-40.0, 25.0, 15.0);
	glEnd();
	
	//kiri atap
	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(-55.0, 30.0, 12.0);
	glVertex3f(-53.0, 40.0, 8.0);
	glVertex3f(-47.0, 40.0, 8.0);
	glVertex3f(-45.0, 30.0, 12.0);
	glEnd();

	//kiri atap depan
	glColor3ub(105,105,105);
	glColor3f(0.5,0,0);
	glVertex3f(-60.0, 25.0, -15.0);
	glVertex3f(-55.0, 30.0, -12.0);
	glVertex3f(-45.0, 30.0, -12.0);
	glVertex3f(-40.0, 25.0, -15.0);
	glEnd();

	//kiri atap
	glColor3ub(105,105,105);
	glColor3f(0.5,0,0);
	glVertex3f(-55.0, 30.0, -12.0);
	glVertex3f(-53.0, 40.0, -8.0);
	glVertex3f(-47.0, 40.0, -8.0);
	glVertex3f(-45.0, 30.0, -12.0);
	glEnd();

	//atap kiri
	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(-53.0,40.0, 8.0);
	glVertex3f(-47.0,40.0, 8.0);
	glVertex3f(-47.0,40.0, -8.0);
	glVertex3f(-53.0,40.0, -8.0);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(-60.0, 25.0, -15.0);
	glVertex3f(-55.0, 30.0, -12.0);
	glVertex3f(-45.0, 30.0, -12.0);
	glVertex3f(-40.0, 25.0, -15.0);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(-55.0, 30.0, -12.0);
	glVertex3f(-53.0, 40.0, -8.0);
	glVertex3f(-47.0, 40.0, -8.0);
	glVertex3f(-45.0, 30.0, -12.0);
	glEnd();

	//kanan atap depan
	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(50.0, 25.0, 15.0);
	glVertex3f(55.0, 30.0, 12.0);
	glVertex3f(65.0, 30.0, 12.0);
	glVertex3f(70.0, 25.0, 15.0);
	glEnd();
	
	//kiri atap
	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(55.0, 30.0, 12.0);
	glVertex3f(57.0, 40.0, 8.0);
	glVertex3f(62.0, 40.0, 8.0);
	glVertex3f(65.0, 30.0, 12.0);
	glEnd();
	
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(-55.0, 30.0, 12.0);
	glVertex3f(-60.0, 25.0, 15.0);
	glVertex3f(-60.0, 25.0, -15.0);
	glVertex3f(-55.0, 30.0, -12.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(-45.0, 30.0, 12.0);
	glVertex3f(-40.0, 25.0, 15.0);
	glVertex3f(-40.0, 25.0, -15.0);
	glVertex3f(-45.0, 30.0, -12.0);
	glEnd();
	
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(-53.0, 40.0, 8.0);
	glVertex3f(-55.0, 30.0, 12.0);
	glVertex3f(-55.0, 30.0, -12.0);
	glVertex3f(-53.0, 40.0, -8.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(-47.0, 40.0, 8.0);
	glVertex3f(-45.0, 30.0, 12.0);
	glVertex3f(-45.0, 30.0, -12.0);
	glVertex3f(-47.0, 40.0, -8.0);
	glEnd();


	//kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(50.0, 25.0, -15.0);
	glVertex3f(55.0, 30.0, -12.0);
	glVertex3f(65.0, 30.0, -12.0);
	glVertex3f(70.0, 25.0, -15.0);
	glEnd();

	//kanan atap
	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(55.0, 30.0, -12.0);
	glVertex3f(57.0, 40.0, -8.0);
	glVertex3f(62.0, 40.0, -8.0);
	glVertex3f(65.0, 30.0, -12.0);
	glEnd();

	//atap kanan
	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(57.0,40.0, 8.0);
	glVertex3f(62.0,40.0, 8.0);
	glVertex3f(62.0,40.0, -8.0);
	glVertex3f(57.0,40.0, -8.0);
	glEnd();

	//kanan
	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(65.0, 30.0, 12.0);
	glVertex3f(70.0, 25.0, 15.0);
	glVertex3f(70.0, 25.0, -15.0);
	glVertex3f(65.0, 30.0, -12.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(55.0, 30.0, 12.0);
	glVertex3f(50.0, 25.0, 15.0);
	glVertex3f(50.0, 25.0, -15.0);
	glVertex3f(55.0, 30.0, -12.0);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(62.0, 40.0, 8.0);
	glVertex3f(65.0, 30.0, 12.0);
	glVertex3f(65.0, 30.0, -12.0);
	glVertex3f(62.0, 40.0, -8.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(105,105,105);
	glVertex3f(57.0, 40.0, 8.0);
	glVertex3f(55.0, 30.0, 12.0);
	glVertex3f(55.0, 30.0, -12.0);
	glVertex3f(57.0, 40.0, -8.0);
	glEnd();
	
	//bawah
	glBegin(GL_POLYGON);
    glColor3ub	(0,128,0);
    glVertex3f(100,-10.1,80);  
    glVertex3f(100,-10.1,8.0);  
    glVertex3f(-90,-10.1,8.0);  
    glVertex3f(-90,-10.1,80);  
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3ub	(0,128,0);
    glVertex3f(100,-10.1,8.0);  
    glVertex3f(100,-10.1,-8.0);  
    glVertex3f(70,-10.1,-8.0);  
    glVertex3f(70,-10.1,8.0);  
    glEnd();
	
	glBegin(GL_POLYGON);
    glColor3ub	(0,128,0);
    glVertex3f(-50,-10.1,8.0);  
    glVertex3f(-50,-10.1,-8.0);  
    glVertex3f(-90,-10.1,-8.0);  
    glVertex3f(-90,-10.1,8.0);  
    glEnd();
	
	
	glBegin(GL_POLYGON);
    glColor3ub	(0,128,0);
    glVertex3f(100,-10.1,-80);  
    glVertex3f(100,-10.1,-8.0);  
    glVertex3f(-90,-10.1,-8.0);  
    glVertex3f(-90,-10.1,-80);  
    glEnd();
    
    //pintu
    glBegin(GL_QUADS);
	glColor3ub	(245,222,179);
	glVertex3f(0.0, -10.0, 17.1);
	glVertex3f(0.0, 10.0, 17.1);
	glVertex3f(10.0, 10.0, 17.1);
	glVertex3f(10.0, -10.0, 17.1);
	glEnd();


//    	jendela
glBegin(GL_QUADS);
	glColor3ub	(245,222,179);
	glVertex3f(-21.0, 5.0, 10.2);
	glVertex3f(-21.0, 20.0, 10.2);
	glVertex3f(-15.0, 20.0, 10.2);
	glVertex3f(-15.0, 5.0, 10.2);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub	(245,222,179);
	glVertex3f(-29.0, 5.0, 10.2);
	glVertex3f(-29.0, 20.0, 10.2);
	glVertex3f(-23.0, 20.0, 10.2);
	glVertex3f(-23.0, 5.0, 10.2);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub	(245,222,179);
	glVertex3f(-37.0, 5.0, 10.2);
	glVertex3f(-37.0, 20.0, 10.2);
	glVertex3f(-31.0, 20.0, 10.2);
	glVertex3f(-31.0, 5.0, 10.2);
	glEnd();
	
	//pojok kiri
	glBegin(GL_QUADS);
	glColor3ub	(245,222,179);
	glVertex3f(-49.0, 5.0, 15.1);
	glVertex3f(-49.0, 20.0,15.1);
	glVertex3f(-42.0, 20.0, 15.1);
	glVertex3f(-42.0, 5.0, 15.1);
	glEnd();
	
		glBegin(GL_QUADS);
	glColor3ub	(245,222,179);
	glVertex3f(-58.0, 5.0, 15.1);
	glVertex3f(-58.0, 20.0, 15.1);
	glVertex3f(-51.0, 20.0, 15.1);
	glVertex3f(-51.0, 5.0, 15.1);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub	(245,222,179);
	glVertex3f(25.0, 5.0, 10.2);
	glVertex3f(25.0, 20.0, 10.2);
	glVertex3f(31.0, 20.0, 10.2);
	glVertex3f(31.0, 5.0, 10.2);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub	(245,222,179);
	glVertex3f(33.0, 5.0, 10.2);
	glVertex3f(33.0, 20.0, 10.2);
	glVertex3f(39.0, 20.0, 10.2);
	glVertex3f(39.0, 5.0, 10.2);
	glEnd();

		
	glBegin(GL_QUADS);
	glColor3ub	(245,222,179);
	glVertex3f(42.0, 5.0, 10.2);
	glVertex3f(42.0, 20.0, 10.2);
	glVertex3f(48.0, 20.0, 10.2);
	glVertex3f(48.0, 5.0, 10.2);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(245,222,179);
	glVertex3f(52.0, 5.0, 15.2);
	glVertex3f(52.0, 20.0, 15.2);
	glVertex3f(59.0, 20.0, 15.2);
	glVertex3f(59.0, 5.0, 15.2);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub	(245,222,179);
	glVertex3f(61.0, 5.0, 15.2);
	glVertex3f(61.0, 20.0, 15.2);
	glVertex3f(68.0, 20.0, 15.2);
	glVertex3f(68.0, 5.0, 15.2);
	glEnd();
	

    
        	    glBegin(GL_POLYGON);
    glColor3ub	(128,128,128);
    glVertex3f(100,-9.9,50);  
    glVertex3f(100,-9.9,30.0);  
    glVertex3f(-90,-9.9,30.0);  
    glVertex3f(-90,-9.9,50);  
    glEnd();
    
        
        	    glBegin(GL_POLYGON);
    glColor3ub	(128,128,128);
    glVertex3f(10.0,-9.9,50);  
    glVertex3f(10.0,-9.9,17.0);  
    glVertex3f(0.0,-9.9,17.0);  
    glVertex3f(0.0,-9.9,50);  
    glEnd();


	meja();
    kursi();
    papantulis();
    jamdinding();
    loker();

	glPopMatrix();
	glutSwapBuffers();

}
void mouseMove(int x, int y) {
    if (mousedown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void mouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mousedown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else {
        mousedown = false;
    }
    glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y) {

    switch (key)
    {
    case 'a':
    case 'A':
        glTranslatef(5.0, 0.0, 0.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(-5.0, 0.0, 0.0);
        break;
    case 'z' :
    case 'Z' :
        glTranslatef(0.0,5.0,0.0);
        break;
    case 'x' :
    case 'X' :
        glTranslatef(0.0,-5.0, 0.0);
        break;
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 5.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -5.0);
        break;
    case 'i':
    case 'I':
        glRotatef(3.0,1.0,0.0,0.0);
        break;
    case 'k':
    case 'K':
        glRotatef(-3.0,1.0,0.0,0.0);
        break;
    case 'j':
    case 'J':
        glRotatef(3.0,0.0,1.0,0.0);
        break;
    case 'l':
    case 'L':
        glRotatef(-3.0,0.0,1.0,0.0);
        break;
    case 'm':
    case 'M':
        glRotatef(3.0,0.0,0.0,1.0);
        break;
    case 'n':
    case 'N':
        glRotatef(-3.0,0.0,0.0,1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth=0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth=1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}

void ukuran (int lebar, int tinggi)
{
	if(tinggi == 0) tinggi = 1;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, lebar/tinggi,5.0,500.0);
	glTranslatef(0.0, -5.0, -150.0);
	glMatrixMode(GL_MODELVIEW);
}
