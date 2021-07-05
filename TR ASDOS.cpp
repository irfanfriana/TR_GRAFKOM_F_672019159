#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
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
	glutCreateWindow("3");
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
	glColor3f(1.0, 1.0, 1.0);
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
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-3.0, -10.0, 17.0);
	glVertex3f(-3.0, 45.0, 17.0);
	glVertex3f(13.0, 45.0, 17.0);
	glVertex3f(13.0, -10.0, 17.0);
	glEnd();

		//depan belakang
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-3.0, 35.0, 0.0);
	glVertex3f(-3.0, 45.0, 0.0);
	glVertex3f(13.0, 45.0, 0.0);
	glVertex3f(13.0, 35.0, 0.0);
	glEnd();
	//depan
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(5.0, 45.0, 15.0);
	glVertex3f(-12.0, 25.0, 15.0);
	glVertex3f(22.0, 25.0, 15.0);
	glVertex3f(5.0, 45.0, 15.0);
	glEnd();


	//kanan	tengah
				glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(22.0, 25.0, 15.0);
	glVertex3f(22.0, -10.0, 15.0);
	glVertex3f(22.0, -10.0, 10.0);
	glVertex3f(22.0, 25.0, 10.0);
	glEnd();

		//kanan	depan
				glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(13.0, 45.0, 17.0);
	glVertex3f(13.0, -10.0, 17.0);
	glVertex3f(13.0, -10.0, 0.0);
	glVertex3f(13.0, 45.0, 0.0);
	glEnd();

		//kiri tengah
			glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-12.0, 25.0, 15.0);
	glVertex3f(-12.0, -10.0, 15.0);
	glVertex3f(-12.0, -10.0, 10.0);
	glVertex3f(-12.0, 25.0, 10.0);
	glEnd();

			//kiri depan
				glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-3.0, 45.0, 17.0);
	glVertex3f(-3.0, -10.0, 17.0);
	glVertex3f(-3.0, -10.0, 0.0);
	glVertex3f(-3.0, 45.0, 0.0);
	glEnd();


	//genteng tengah kanan
			glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(13.0,35.0, 15.0);//panjang,tinggi, dekat
	glVertex3f(22.0, 25.0, 15.0);
	glVertex3f(22.0, 25.0, 10.0);
	glVertex3f(13.0,35.0, 0.0);
	glEnd();
	//genteng tengah kiri

			glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(-12.0,25.0, 15.0);//
	glVertex3f(-3.0, 35.0, 15.0);
	glVertex3f(-3.0, 35.0, 0.0);
	glVertex3f(-12.0,25.0, 10.0);
	glEnd();

		//genteng badan kiri
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(-40.0, 25.0, 10.0);
	glVertex3f(-45.0, 35.0, 0.0);
	glVertex3f(-3.0, 35.0, 0.0);
	glVertex3f(-10.0, 25.0, 10.0);
	glEnd();


		//genteng badan belakang
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(-45.0, 35.0, 0.0);
	glVertex3f(-40.0, 25.0, -10.0);
	glVertex3f(50.0, 25.0, -10.0);
	glVertex3f(55.0, 35.0, 0.0);
	glEnd();




		//genteng badan kanan
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(22.0, 25.0, 10.0);
	glVertex3f(13.0, 35.0, 0.0);
	glVertex3f(55.0, 35.0, 0.0);
	glVertex3f(50.0, 25.0, 10.0);
	glEnd();

		//bawah
			glBegin(GL_QUADS);
	glColor3f(0.5,0,0 );
	glVertex3f(-40.0,-10.0, 10.0);
	glVertex3f(50.0, -10.0, 10.0);
	glVertex3f(50.0, -10.0, -10.0);
	glVertex3f(-40.0,-10.0, -10.0);
	glEnd();

	glEnd();
























			//atas belakang kiri
	glBegin(GL_QUADS);
	glColor3f(0.5,0,0 );
	glVertex3f(-4.0, 45.0, -1.0);
	glVertex3f(-4.0, 50.0, -1.0);
	glVertex3f(-1.0, 50.0, -1.0);
	glVertex3f(-1.0, 45.0, -1.0);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.5,0,0 );
	glVertex3f(-4.0, 45.0, 2.0);
	glVertex3f(-4.0, 50.0, 2.0);
	glVertex3f(-1.0, 50.0, 2.0);
	glVertex3f(-1.0, 45.0, 2.0);
	glEnd();

			glBegin(GL_QUADS);
	glColor3f(0.5,0,0 );
	glVertex3f(-4.0, 50.0, 2.0);
	glVertex3f(-4.0, 45.0, 2.0);
	glVertex3f(-4.0, 45.0, -1.0);
	glVertex3f(-4.0, 50.0, -1.0);
	glEnd();


		glBegin(GL_QUADS);
	glColor3f(0.5,0,0 );
	glVertex3f(-1.0, 50.0, 2.0);
	glVertex3f(-1.0, 45.0, 2.0);
	glVertex3f(-1.0, 45.0, -1.0);
	glVertex3f(-1.0, 50.0, -1.0);
	glEnd();


	//atas depan kiri
		glBegin(GL_QUADS);
	glColor3f(0.5,0,0 );
	glVertex3f(-4.0, 45.0, 18.0);
	glVertex3f(-4.0, 50.0, 18.0);
	glVertex3f(-1.0, 50.0, 18.0);
	glVertex3f(-1.0, 45.0, 18.0);
	glEnd();

			glBegin(GL_QUADS);
	glColor3f(0.5,0,0 );
	glVertex3f(-4.0, 45.0, 15.0);
	glVertex3f(-4.0, 50.0, 15.0);
	glVertex3f(-1.0, 50.0, 15.0);
	glVertex3f(-1.0, 45.0, 15.0);
	glEnd();


		glBegin(GL_QUADS);
	glColor3f(0.5,0,0 );
	glVertex3f(-1.0, 50.0, 18.0);
	glVertex3f(-1.0, 45.0, 18.0);
	glVertex3f(-1.0, 45.0, 15.0);
	glVertex3f(-1.0, 50.0, 15.0);
	glEnd();

		glBegin(GL_QUADS);
	glColor3f(0.5,0,0 );
	glVertex3f(-4.0, 50.0, 18.0);
	glVertex3f(-4.0, 45.0, 18.0);
	glVertex3f(-4.0, 45.0, 15.0);
	glVertex3f(-4.0, 50.0, 15.0);
	glEnd();





	//atas depan  kanan
		glBegin(GL_QUADS);
	glColor3f(0.5,0,0 );
	glVertex3f(11.0, 45.0, 18.0);
	glVertex3f(11.0, 50.0, 18.0);
	glVertex3f(14.0, 50.0, 18.0);
	glVertex3f(14.0, 45.0, 18.0);
	glEnd();

			glBegin(GL_QUADS);
	glColor3f(0.5,0,0 );
	glVertex3f(11.0, 45.0, 15.0);
	glVertex3f(11.0, 50.0, 15.0);
	glVertex3f(14.0, 50.0, 15.0);
	glVertex3f(14.0, 45.0, 15.0);
	glEnd();


		glBegin(GL_QUADS);
	glColor3f(0.5,0,0 );
	glVertex3f(14.0, 50.0, 18.0);
	glVertex3f(14.0, 45.0, 18.0);
	glVertex3f(14.0, 45.0, 15.0);
	glVertex3f(14.0, 50.0, 15.0);
	glEnd();

		glBegin(GL_QUADS);
	glColor3f(0.5,0,0 );
	glVertex3f(11.0, 50.0, 18.0);
	glVertex3f(11.0, 45.0, 18.0);
	glVertex3f(11.0, 45.0, 15.0);
	glVertex3f(11.0, 50.0, 15.0);
	glEnd();


		//atas belakang kanan
		glBegin(GL_QUADS);
	glColor3f(0.5,0,0 );
	glVertex3f(11.0, 45.0, -1.0);
	glVertex3f(11.0, 50.0, -1.0);
	glVertex3f(14.0, 50.0, -1.0);
	glVertex3f(14.0, 45.0, -1.0);
	glEnd();

			glBegin(GL_QUADS);
	glColor3f(0.5,0,0 );
	glVertex3f(11.0, 45.0, 2.0);
	glVertex3f(11.0, 50.0, 2.0);
	glVertex3f(14.0, 50.0, 2.0);
	glVertex3f(14.0, 45.0, 2.0);
	glEnd();


		glBegin(GL_QUADS);
	glColor3f(0.5,0,0 );
	glVertex3f(11.0, 50.0, 2.0);
	glVertex3f(11.0, 45.0, 2.0);
	glVertex3f(11.0, 45.0, -1.0);
	glVertex3f(11.0, 50.0, -1.0);
	glEnd();



		glBegin(GL_QUADS);
	glColor3f(0.5,0,0 );
	glVertex3f(14.0, 50.0, 2.0);
	glVertex3f(14.0, 45.0, 2.0);
	glVertex3f(14.0, 45.0, -1.0);
	glVertex3f(14.0, 50.0, -1.0);
	glEnd();

			//bawah
			glBegin(GL_QUADS);
	glColor3f(0.5,0,0 );
	glVertex3f(-3.0,45.0, 17.0);
	glVertex3f(13.0,45.0, 17.0);
	glVertex3f(13.0,45.0, 0.0);
	glVertex3f(-3.0,45.0, 0.0);
	glEnd();
			glBegin(GL_QUADS);
	glColor3f(0.5,0,0 );
	glVertex3f(-4.0,50.0, 18.0);
	glVertex3f(-1.0,50.0, 18.0);
	glVertex3f(-1.0,50.0, 15.0);
	glVertex3f(-4.0,50.0, 15.0);
	glEnd();

				glBegin(GL_QUADS);
	glColor3f(0.5,0,0 );
	glVertex3f(-4.0,45.0, 18.0);
	glVertex3f(-1.0,45.0, 18.0);
	glVertex3f(-1.0,45.0, 15.0);
	glVertex3f(-4.0,45.0, 15.0);
	glEnd();

			glBegin(GL_QUADS);
	glColor3f(0.5,0,0 );
	glVertex3f(11.0,50.0, 18.0);
	glVertex3f(14.0,50.0, 18.0);
	glVertex3f(14.0,50.0, 15.0);
	glVertex3f(11.0,50.0, 15.0);
	glEnd();

			glBegin(GL_QUADS);
	glColor3f(0.5,0,0 );
	glVertex3f(11.0,45.0, 18.0);
	glVertex3f(14.0,45.0, 18.0);
	glVertex3f(14.0,45.0, 15.0);
	glVertex3f(11.0,45.0, 15.0);
	glEnd();

			glBegin(GL_QUADS);
	glColor3f(0.5,0,0 );
	glVertex3f(11.0,50.0, 2.0);
	glVertex3f(14.0,50.0, 2.0);
	glVertex3f(14.0,50.0, -1.0);
	glVertex3f(11.0,50.0, -1.0);
	glEnd();
				glBegin(GL_QUADS);
	glColor3f(0.5,0,0 );
	glVertex3f(11.0,45.0, 2.0);
	glVertex3f(14.0,45.0, 2.0);
	glVertex3f(14.0,45.0, -1.0);
	glVertex3f(11.0,45.0, -1.0);
	glEnd();

				glBegin(GL_QUADS);
	glColor3f(0.5,0,0);
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
	glColor3f(1,0.5,0);
	glVertex3f(-3.0, 50.0, 15.0);
	glVertex3f(-3.0, 45.0, 15.0);
	glVertex3f(-3.0, 45.0, -1.0);
	glVertex3f(-3.0, 50.0, -1.0);
	glEnd();

		//tembok atas R
			glBegin(GL_QUADS);
	glColor3f(1,0.5,0);
	glVertex3f(13.0, 50.0, 15.0);
	glVertex3f(13.0, 45.0, 15.0);
	glVertex3f(13.0, 45.0, -1.0);
	glVertex3f(13.0, 50.0, -1.0);
	glEnd();

	//tembok atas depan
	glBegin(GL_QUADS);
	glColor3f(1,0.5,0);
	glVertex3f(-3.0, 45.0, 17.0);
	glVertex3f(-3.0, 50.0, 17.0);
	glVertex3f(13.0, 50.0, 17.0);
	glVertex3f(13.0, 45.0, 17.0);
	glEnd();



	//tembok atas belakang
	glBegin(GL_QUADS);
	glColor3f(1,0.5,0);
	glVertex3f(-3.0, 45.0, 0.0);
	glVertex3f(-3.0, 50.0, 0.0);
	glVertex3f(13.0, 50.0, 0.0);
	glVertex3f(13.0, 45.0, 0.0);
	glEnd();





		//tembok kirii depann
	glBegin(GL_QUADS);
	glColor3f(1,0.5,0);
	glVertex3f(-60.0, -10.0, 15.0);
	glVertex3f(-60.0, 25.0, 15.0);
	glVertex3f(-40.0, 25.0, 15.0);
	glVertex3f(-40.0, -10.0, 15.0);
	glEnd();

			//tembok kirii belakang
	glBegin(GL_QUADS);
	glColor3f(1,0.5,0);
	glVertex3f(-60.0, -10.0, -15.0);
	glVertex3f(-60.0, 25.0, -15.0);
	glVertex3f(-40.0, 25.0, -15.0);
	glVertex3f(-40.0, -10.0, -15.0);
	glEnd();

			//kiri pendek depan
				glBegin(GL_QUADS);
	glColor3f(1,0.5,0);
	glVertex3f(-40.0, 25.0, 15.0);
	glVertex3f(-40.0, -10.0, 15.0);
	glVertex3f(-40.0, -10.0, 10.0);
	glVertex3f(-40.0, 25.0, 10.0);
	glEnd();
			//kiri pendek belakang
				glBegin(GL_QUADS);
	glColor3f(1,0.5,0);
	glVertex3f(-40.0, 25.0, -10.0);
	glVertex3f(-40.0, -10.0, -10.0);
	glVertex3f(-40.0, -10.0, -15.0);
	glVertex3f(-40.0, 25.0, -15.0);
	glEnd();

				//kiri
				glBegin(GL_QUADS);
	glColor3f(1,0.5,0);
	glVertex3f(-60.0, 25.0, 15.0);
	glVertex3f(-60.0, -10.0, 15.0);
	glVertex3f(-60.0, -10.0, -15.0);
	glVertex3f(-60.0, 25.0, -15.0);
	glEnd();
			//tembok kanan depan
	glBegin(GL_QUADS);
	glColor3f(1,0.5,0);
	glVertex3f(70.0, -10.0, 15.0);
	glVertex3f(70.0, 25.0, 15.0);
	glVertex3f(50.0, 25.0, 15.0);
	glVertex3f(50.0, -10.0, 15.0);
	glEnd();

			//tembok kanan belakang
	glBegin(GL_QUADS);
	glColor3f(1,0.5,0);
	glVertex3f(70.0, -10.0, -15.0);
	glVertex3f(70.0, 25.0, -15.0);
	glVertex3f(50.0, 25.0, -15.0);
	glVertex3f(50.0, -10.0, -15.0);
	glEnd();
			//kanan pendek
				glBegin(GL_QUADS);
	glColor3f(1,0.5,0);
	glVertex3f(50.0, 25.0, 15.0);
	glVertex3f(50.0, -10.0, 15.0);
	glVertex3f(50.0, -10.0, 10.0);
	glVertex3f(50.0, 25.0, 10.0);
	glEnd();

					glBegin(GL_QUADS);
	glColor3f(1,0.5,0);
	glVertex3f(50.0, 25.0, -15.0);
	glVertex3f(50.0, -10.0, -15.0);
	glVertex3f(50.0, -10.0, -10.0);
	glVertex3f(50.0, 25.0, -10.0);
	glEnd();


			//kanan
				glBegin(GL_QUADS);
	glColor3f(1,0.5,0);
	glVertex3f(70.0, 25.0, 15.0);
	glVertex3f(70.0, -10.0, 15.0);
	glVertex3f(70.0, -10.0, -15.0);
	glVertex3f(70.0, 25.0, -15.0);
	glEnd();



















		//kiri atap depan
	glBegin(GL_QUADS);
	glColor3f(0.5,0,0);
	glVertex3f(-60.0, 25.0, 15.0);
	glVertex3f(-55.0, 30.0, 12.0);
	glVertex3f(-45.0, 30.0, 12.0);
	glVertex3f(-40.0, 25.0, 15.0);
	glEnd();
		//kiri atap
	glBegin(GL_QUADS);
	glColor3f(0.5,0,0);
	glVertex3f(-55.0, 30.0, 12.0);
	glVertex3f(-53.0, 40.0, 8.0);
	glVertex3f(-47.0, 40.0, 8.0);
	glVertex3f(-45.0, 30.0, 12.0);
	glEnd();


		//kiri atap depan
	glBegin(GL_QUADS);
	glColor3f(0.5,0,0);
	glVertex3f(-60.0, 25.0, -15.0);
	glVertex3f(-55.0, 30.0, -12.0);
	glVertex3f(-45.0, 30.0, -12.0);
	glVertex3f(-40.0, 25.0, -15.0);
	glEnd();

			//kiri atap
	glBegin(GL_QUADS);
	glColor3f(0.5,0,0);
	glVertex3f(-55.0, 30.0, -12.0);
	glVertex3f(-53.0, 40.0, -8.0);
	glVertex3f(-47.0, 40.0, -8.0);
	glVertex3f(-45.0, 30.0, -12.0);
	glEnd();

				//atap kiri
			glBegin(GL_QUADS);
	glColor3f(0.5,0,0);
	glVertex3f(-53.0,40.0, 8.0);
	glVertex3f(-47.0,40.0, 8.0);
	glVertex3f(-47.0,40.0, -8.0);
	glVertex3f(-53.0,40.0, -8.0);
	glEnd();





















		//kanan atap depan
	glBegin(GL_QUADS);
	glColor3f(0.5,0,0);
	glVertex3f(50.0, 25.0, 15.0);
	glVertex3f(55.0, 30.0, 12.0);
	glVertex3f(65.0, 30.0, 12.0);
	glVertex3f(70.0, 25.0, 15.0);
	glEnd();
		//kiri atap
	glBegin(GL_QUADS);
	glColor3f(0.5,0,0);
	glVertex3f(55.0, 30.0, 12.0);
	glVertex3f(57.0, 40.0, 8.0);
	glVertex3f(62.0, 40.0, 8.0);
	glVertex3f(65.0, 30.0, 12.0);
	glEnd();
				//kiri
				glBegin(GL_QUADS);
	glColor3f(0.5,0,0);
	glVertex3f(-55.0, 30.0, 12.0);
	glVertex3f(-60.0, 25.0, 15.0);
	glVertex3f(-60.0, 25.0, -15.0);
	glVertex3f(-55.0, 30.0, -12.0);
	glEnd();

				glBegin(GL_QUADS);
	glColor3f(0.5,0,0);
	glVertex3f(-45.0, 30.0, 12.0);
	glVertex3f(-40.0, 25.0, 15.0);
	glVertex3f(-40.0, 25.0, -15.0);
	glVertex3f(-45.0, 30.0, -12.0);
	glEnd();
			//kiri
				glBegin(GL_QUADS);
	glColor3f(0.5,0,0);
	glVertex3f(-53.0, 40.0, 8.0);
	glVertex3f(-55.0, 30.0, 12.0);
	glVertex3f(-55.0, 30.0, -12.0);
	glVertex3f(-53.0, 40.0, -8.0);
	glEnd();

				glBegin(GL_QUADS);
	glColor3f(0.5,0,0);
	glVertex3f(-47.0, 40.0, 8.0);
	glVertex3f(-45.0, 30.0, 12.0);
	glVertex3f(-45.0, 30.0, -12.0);
	glVertex3f(-47.0, 40.0, -8.0);
	glEnd();


		//kanan belakang
	glBegin(GL_QUADS);
	glColor3f(0.5,0,0);
	glVertex3f(50.0, 25.0, -15.0);
	glVertex3f(55.0, 30.0, -12.0);
	glVertex3f(65.0, 30.0, -12.0);
	glVertex3f(70.0, 25.0, -15.0);
	glEnd();

			//kanan atap
	glBegin(GL_QUADS);
	glColor3f(0.5,0,0);
	glVertex3f(55.0, 30.0, -12.0);
	glVertex3f(57.0, 40.0, -8.0);
	glVertex3f(62.0, 40.0, -8.0);
	glVertex3f(65.0, 30.0, -12.0);
	glEnd();

				//atap kanan
			glBegin(GL_QUADS);
	glColor3f(0.5,0,0);
	glVertex3f(57.0,40.0, 8.0);
	glVertex3f(62.0,40.0, 8.0);
	glVertex3f(62.0,40.0, -8.0);
	glVertex3f(57.0,40.0, -8.0);
	glEnd();

				//kanan
				glBegin(GL_QUADS);
	glColor3f(0.5,0,0);
	glVertex3f(65.0, 30.0, 12.0);
	glVertex3f(70.0, 25.0, 15.0);
	glVertex3f(70.0, 25.0, -15.0);
	glVertex3f(65.0, 30.0, -12.0);
	glEnd();

		glBegin(GL_QUADS);
	glColor3f(0.5,0,0);
	glVertex3f(55.0, 30.0, 12.0);
	glVertex3f(50.0, 25.0, 15.0);
	glVertex3f(50.0, 25.0, -15.0);
	glVertex3f(55.0, 30.0, -12.0);
	glEnd();
				glBegin(GL_QUADS);
	glColor3f(0.5,0,0);
	glVertex3f(62.0, 40.0, 8.0);
	glVertex3f(65.0, 30.0, 12.0);
	glVertex3f(65.0, 30.0, -12.0);
	glVertex3f(62.0, 40.0, -8.0);
	glEnd();

					glBegin(GL_QUADS);
	glColor3f(0.5,0,0);
	glVertex3f(57.0, 40.0, 8.0);
	glVertex3f(55.0, 30.0, 12.0);
	glVertex3f(55.0, 30.0, -12.0);
	glVertex3f(57.0, 40.0, -8.0);
	glEnd();

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

