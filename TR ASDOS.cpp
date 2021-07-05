#include <windows.h>
#include <stdlib.h>
#include <gl/glut.h>

void init (void);
void tampil (void);
void mouse (int button, int state, int x, int y);
void ukuran (int, int );
void mouseMotion(int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

int main ( int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(250,80);
	glutCreateWindow("3");
	init();
	glutDisplayFunc(tampil);
	glutReshapeFunc(ukuran);
	
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	
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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f , 0.0f, 1.0f, 0.0f);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
		glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glPushMatrix();
	
	//badan
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-50.0, -10.0, 10.0);
	glVertex3f(-50.0, 25.0, 10.0);
	glVertex3f(60.0, 25.0, 10.0);
	glVertex3f(60.0, -10.0, 10.0);
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
	glVertex3f(-50.0, -10.0, -10.0);
	glVertex3f(-50.0, 25.0, -10.0);
	glVertex3f(60.0, 25.0, -10.0);
	glVertex3f(60.0, -10.0, -10.0);
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
	glVertex3f(-50.0, 25.0, 10.0);
	glVertex3f(-50.0, 35.0, 0.0);
	glVertex3f(-3.0, 35.0, 0.0);
	glVertex3f(-10.0, 25.0, 10.0);
	glEnd();
	
	
		//genteng badan belakang 
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(-50.0, 35.0, 0.0);
	glVertex3f(-50.0, 25.0, -10.0);
	glVertex3f(60.0, 25.0, -10.0);
	glVertex3f(60.0, 35.0, 0.0);
	glEnd();
	
	
	
		
		//genteng badan kiri
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(22.0, 25.0, 10.0);
	glVertex3f(13.0, 35.0, 0.0);
	glVertex3f(60.0, 35.0, 0.0);
	glVertex3f(60.0, 25.0, 10.0);
	glEnd();
	
		//bawah
			glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(-50.0,-10.0, 10.0);
	glVertex3f(60.0, -10.0, 10.0);
	glVertex3f(60.0, -10.0, -10.0);
	glVertex3f(-50.0,-10.0, -10.0);
	glEnd();
	
	glEnd();
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
			//atas belakang kiri
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-4.0, 45.0, -1.0);
	glVertex3f(-4.0, 50.0, -1.0);
	glVertex3f(-1.0, 50.0, -1.0);
	glVertex3f(-1.0, 45.0, -1.0);
	glEnd();
	

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-4.0, 45.0, 2.0);
	glVertex3f(-4.0, 50.0, 2.0);
	glVertex3f(-1.0, 50.0, 2.0);
	glVertex3f(-1.0, 45.0, 2.0);
	glEnd();
	
			glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-4.0, 50.0, 2.0);
	glVertex3f(-4.0, 45.0, 2.0);
	glVertex3f(-4.0, 45.0, -1.0);
	glVertex3f(-4.0, 50.0, -1.0);
	glEnd();
	
	
		glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-1.0, 50.0, 2.0);
	glVertex3f(-1.0, 45.0, 2.0);
	glVertex3f(-1.0, 45.0, -1.0);
	glVertex3f(-1.0, 50.0, -1.0);
	glEnd();
	
	
	//atas depan kiri
		glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-4.0, 45.0, 18.0);
	glVertex3f(-4.0, 50.0, 18.0);
	glVertex3f(-1.0, 50.0, 18.0);
	glVertex3f(-1.0, 45.0, 18.0);
	glEnd();
	
			glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-4.0, 45.0, 15.0);
	glVertex3f(-4.0, 50.0, 15.0);
	glVertex3f(-1.0, 50.0, 15.0);
	glVertex3f(-1.0, 45.0, 15.0);
	glEnd();
	
	
		glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-1.0, 50.0, 18.0);
	glVertex3f(-1.0, 45.0, 18.0);
	glVertex3f(-1.0, 45.0, 15.0);
	glVertex3f(-1.0, 50.0, 15.0);
	glEnd();
	
		glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-4.0, 50.0, 18.0);
	glVertex3f(-4.0, 45.0, 18.0);
	glVertex3f(-4.0, 45.0, 15.0);
	glVertex3f(-4.0, 50.0, 15.0);
	glEnd();
	
	
	
	
	
	//atas depan  kanan
		glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(11.0, 45.0, 18.0);
	glVertex3f(11.0, 50.0, 18.0);
	glVertex3f(14.0, 50.0, 18.0);
	glVertex3f(14.0, 45.0, 18.0);
	glEnd();
	
			glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(11.0, 45.0, 15.0);
	glVertex3f(11.0, 50.0, 15.0);
	glVertex3f(14.0, 50.0, 15.0);
	glVertex3f(14.0, 45.0, 15.0);
	glEnd();
	
			
		glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(14.0, 50.0, 18.0);
	glVertex3f(14.0, 45.0, 18.0);
	glVertex3f(14.0, 45.0, 15.0);
	glVertex3f(14.0, 50.0, 15.0);
	glEnd();
	
		glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(11.0, 50.0, 18.0);
	glVertex3f(11.0, 45.0, 18.0);
	glVertex3f(11.0, 45.0, 15.0);
	glVertex3f(11.0, 50.0, 15.0);
	glEnd();
	
	
		//atas belakang kanan
		glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(11.0, 45.0, -1.0);
	glVertex3f(11.0, 50.0, -1.0);
	glVertex3f(14.0, 50.0, -1.0);
	glVertex3f(14.0, 45.0, -1.0);
	glEnd();
	
			glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(11.0, 45.0, 2.0);
	glVertex3f(11.0, 50.0, 2.0);
	glVertex3f(14.0, 50.0, 2.0);
	glVertex3f(14.0, 45.0, 2.0);
	glEnd();
	
		
		glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(11.0, 50.0, 2.0);
	glVertex3f(11.0, 45.0, 2.0);
	glVertex3f(11.0, 45.0, -1.0);
	glVertex3f(11.0, 50.0, -1.0);
	glEnd();
	
	
		
		glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(14.0, 50.0, 2.0);
	glVertex3f(14.0, 45.0, 2.0);
	glVertex3f(14.0, 45.0, -1.0);
	glVertex3f(14.0, 50.0, -1.0);
	glEnd();
	
			//bawah
			glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(-3.0,45.0, 17.0);
	glVertex3f(13.0,45.0, 17.0);
	glVertex3f(13.0,45.0, 0.0);
	glVertex3f(-3.0,45.0, 0.0);
	glEnd();
			glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(-4.0,50.0, 18.0);
	glVertex3f(-1.0,50.0, 18.0);
	glVertex3f(-1.0,50.0, 15.0);
	glVertex3f(-4.0,50.0, 15.0);
	glEnd();
	
				glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(-4.0,45.0, 18.0);
	glVertex3f(-1.0,45.0, 18.0);
	glVertex3f(-1.0,45.0, 15.0);
	glVertex3f(-4.0,45.0, 15.0);
	glEnd();
	
			glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(11.0,50.0, 18.0);
	glVertex3f(14.0,50.0, 18.0);
	glVertex3f(14.0,50.0, 15.0);
	glVertex3f(11.0,50.0, 15.0);
	glEnd();
	
			glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(11.0,45.0, 18.0);
	glVertex3f(14.0,45.0, 18.0);
	glVertex3f(14.0,45.0, 15.0);
	glVertex3f(11.0,45.0, 15.0);
	glEnd();
	
			glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(11.0,50.0, 2.0);
	glVertex3f(14.0,50.0, 2.0);
	glVertex3f(14.0,50.0, -1.0);
	glVertex3f(11.0,50.0, -1.0);
	glEnd();
				glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(11.0,45.0, 2.0);
	glVertex3f(14.0,45.0, 2.0);
	glVertex3f(14.0,45.0, -1.0);
	glVertex3f(11.0,45.0, -1.0);
	glEnd();
	
				glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(-4.0,50.0, 2.0);
	glVertex3f(-1.0,50.0, 2.0);
	glVertex3f(-1.0,50.0, -1.0);
	glVertex3f(-4.0,50.0, -1.0);
	glEnd();
					glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(-4.0,45.0, 2.0);
	glVertex3f(-1.0,45.0, 2.0);
	glVertex3f(-1.0,45.0, -1.0);
	glVertex3f(-4.0,45.0, -1.0);
	glEnd();
	
	
	
	

		//tembok atas L
			glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-3.0, 50.0, 15.0);
	glVertex3f(-3.0, 45.0, 15.0);
	glVertex3f(-3.0, 45.0, -1.0);
	glVertex3f(-3.0, 50.0, -1.0);
	glEnd();
	
		//tembok atas R
			glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(13.0, 50.0, 15.0);
	glVertex3f(13.0, 45.0, 15.0);
	glVertex3f(13.0, 45.0, -1.0);
	glVertex3f(13.0, 50.0, -1.0);
	glEnd();
	
	//tembok atas depan
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-3.0, 45.0, 17.0);
	glVertex3f(-3.0, 50.0, 17.0);
	glVertex3f(13.0, 50.0, 17.0);
	glVertex3f(13.0, 45.0, 17.0);
	glEnd();
	
	
		
	//tembok atas belakang
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-3.0, 45.0, 0.0);
	glVertex3f(-3.0, 50.0, 0.0);
	glVertex3f(13.0, 50.0, 0.0);
	glVertex3f(13.0, 45.0, 0.0);
	glEnd();
		
		

	glPopMatrix();
	glutSwapBuffers();
	
}
void idle(){
	if (!mouseDown)
	{
		xrot += 0.3f;
		yrot += 0.4f;
	}
	glutPostRedisplay();
}

void mouse (int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
		
	}
	else
	mouseDown = false;
}

void mouseMotion(int x, int y)
{
	if (mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;
		
		glutPostRedisplay();
	}
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

