#include "classes.h"
#include "initials.h"
#include <windows.h>
#include <MMsystem.h>
//#include <mciapi.h>
#include <cstdlib>

#pragma comment(lib, "winmm.lib")
using namespace std;

int refreshMillis = 30;      // Refresh period in milliseconds
double handSpeed1 = 0.1;	//speed of left hand movement
double handSpeed2 = 0.05;	//speed of right hand movement
double fingerSpeed1 = 1.0;   //speed of finger movement
double fingerSpeed2 = -1.0;
double keyDown = 5.0;			//set piano key movement
char title[] = "Keyboard";		//set title
GLfloat angleCam = 45.0f;     // Rotational angle for cube [NEW]
int angleKey[21];				//set range of piano key movement
double angleFinger[8] = {5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0};  //set angle of finger movement
GLfloat handPost[2] = { -3.0, 3.0 };  //set intitial hand position
Piano objpiano;
Hand objHand;
int i = 0;
static bool paused = false;


/* Initialize OpenGL Graphics */
void initGL() {

	srand(1);
	glClearColor(0.2f, 0.3f, 0.4f, 1.0f); // Set background color to black and opaque

	GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat yellow[] = { 1.0, 1.0, 0.0, 1.0 };
	GLfloat red[] = { 0.647059, 0.164706, 0.164706, 1.0 };
	GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat direction[] = { 1.0, 1.0, 0.0, 1.0 };

	for (int i = 0; i < 21; i++)
	{
		angleKey[i] = 0;
	}


	//PlaySound(TEXT("happy_birthday.wav"), NULL, SND_ASYNC | SND_LOOP);  //play sound in loop

	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
	glMaterialfv(GL_FRONT, GL_SPECULAR, black);
	glMaterialf(GL_FRONT, GL_SHININESS, 30);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

	glLightfv(GL_LIGHT0, GL_AMBIENT, red);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white);
	glLightfv(GL_LIGHT0, GL_POSITION, direction);
	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_LIGHTING);                // so the renderer considers light
	glEnable(GL_LIGHT0);                  // turn LIGHT0 on
	//glEnable(GL_DEPTH_TEST);              // so the renderer considers depth

	glClearDepth(1.0f);                   // Set background depth to farthest
	glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
	glShadeModel(GL_SMOOTH);   // Enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

void windowKey(unsigned char key, int x, int y)
{
	if (key == 27) exit(0); //press ESC to exit
	if (key == 'p')
	{
		paused = !paused;
	}
}

void keyPressed(unsigned char key, int x, int y) {
 
	switch (key) {  //set action when keys are pressed
	case 'q':
		(angleKey[0] += 5.0) %= 360;
		(handPost[0] = -4);
		break;
	case 'w':
		(angleKey[1] += 5.0) %= 360;
		(handPost[0] = -4);
		break;
	case 'e':
		(angleKey[2] += 5.0) %= 360;
		(handPost[0] = -3);
		break;
	case 'r':
		(angleKey[3] += 5.0) %= 360;
		PlaySound(TEXT("piano_A.wav"), NULL, SND_ASYNC);
		(handPost[0] = -2);
		break;
	case 't':
		(angleKey[4] += 5.0) %= 360;
		PlaySound(TEXT("piano_B.wav"), NULL, SND_ASYNC);
		(handPost[0] = -2);
		break;
	case 'y':
		(angleKey[5] += 5.0) %= 360;
		PlaySound(TEXT("piano_middle_C.wav"), NULL, SND_ASYNC);
		(handPost[0] = -1);
		break;
	case 'u':
		(angleKey[6] += 5.0) %= 360;
		PlaySound(TEXT("piano_D.wav"), NULL, SND_ASYNC);
		(handPost[1] = 0);
		break;
	case 'i':
		(angleKey[7] += 5.0) %= 360;
		PlaySound(TEXT("piano_E.wav"), NULL, SND_ASYNC);
		(handPost[1] = 1);
		break;
	case 'o':
		(angleKey[8] += 5.0) %= 360;
		PlaySound(TEXT("piano_F.wav"), NULL, SND_ASYNC);
		(handPost[1] = 2);
		break;
	case 'p':
		(angleKey[9] += 5.0) %= 360;
		PlaySound(TEXT("piano_G.wav"), NULL, SND_ASYNC);
		(handPost[1] = 2);
		break;
	case '[':
		(angleKey[10] += 5.0) %= 360;
		(handPost[1] = 3);
		break;
	case ']':
		(angleKey[11] += 5.0) %= 360;
		(handPost[1] = 4);
		break;
	case ';':
		(angleKey[12] += 5.0) %= 360;
		(handPost[1] = 4);
		break;
	case '3':
		(angleKey[13] += 5.0) %= 360;
		(handPost[0] = -4);
		break;
	case '4':
		(angleKey[14] += 5.0) %= 360;
		(handPost[0] = -3);
		break;
	case '5':
		(angleKey[15] += 5.0) %= 360;
		PlaySound(TEXT("piano_A_sharp.wav"), NULL, SND_ASYNC);
		(handPost[0] = -2);
		break;
	case '7':
		(angleKey[16] += 5.0) %= 360;
		PlaySound(TEXT("piano_C_sharp.wav"), NULL, SND_ASYNC);
		(handPost[0] = -1);
		break;
	case '8':
		(angleKey[17] += 5.0) %= 360;
		PlaySound(TEXT("piano_D_sharp.wav"), NULL, SND_ASYNC);
		(handPost[1] = 1);
		break;
	case '0':
		(angleKey[18] += 5.0) %= 360;
		PlaySound(TEXT("piano_F_sharp.wav"), NULL, SND_ASYNC);
		(handPost[1] = 2);
		break;
	case '-':
		(angleKey[19] += 5.0) %= 360;
		PlaySound(TEXT("piano_G_sharp.wav"), NULL, SND_ASYNC);
		(handPost[1] = 3);
		break;
	case '=':
		(angleKey[20] += 5.0) %= 360;
		(handPost[1] = 4);
		break;
	case 'z':
		break;
	default: return;
	}


	glutPostRedisplay();
}

void keyUp(unsigned char key, int x, int y) {

	switch (key) {  //set action when key is released
	case 'q':
		(angleKey[0] -= 5.0) %= 360;
		break;
	case 'w':
		(angleKey[1] -= 5.0) %= 360;
		break;
	case 'e':
		(angleKey[2] -= 5.0) %= 360;
		break;
	case 'r':
		(angleKey[3] -= 5.0) %= 360;
		break;
	case 't':
		(angleKey[4] -= 5.0) %= 360;
		break;
	case 'y':
		(angleKey[5] -= 5.0) %= 360;
		break;
	case 'u':
		(angleKey[6] -= 5.0) %= 360;
		break;
	case 'i':
		(angleKey[7] -= 5.0) %= 360;
		break;
	case 'o':
		(angleKey[8] -= 5.0) %= 360;
		break;
	case 'p':
		//(angleKey[9] -= 5.0) %= 360;
		break;
	case '[':
		(angleKey[10] -= 5.0) %= 360;
		break;
	case ']':
		(angleKey[11] -= 5.0) %= 360;
		break;
	case ';':
		(angleKey[12] -= 5.0) %= 360;
		break;
	case '3':
		(angleKey[13] -= 5.0) %= 360;
		break;
	case '4':
		(angleKey[14] -= 5.0) %= 360;
		break;
	case '5':
		(angleKey[15] -= 5.0) %= 360;
		break;
	case '7':
		(angleKey[16] -= 5.0) %= 360;
		break;
	case '8':
		(angleKey[17] -= 5.0) %= 360;
		break;
	case '0':
		(angleKey[18] -= 5.0) %= 360;
		break;
	case '-':
		(angleKey[19] -= 5.0) %= 360;
		break;
	case '=':
		(angleKey[20] -= 5.0) %= 360;
		break;
	default: return;
	}
	glutPostRedisplay();
}


/*windowKey - GLUT calls this routine when non-special key is pressed */
//void windowKey(unsigned char key, int x, int y)
//{
//	if (key == 27) exit(0);
//	if (key == 32) PlaySound(TEXT("happy_birthday.wav"), NULL, SND_ASYNC);
//	
//	glutPostRedisplay();
//}


/* Handler for window-repaint event. Called back when the window first appears and
whenever the window needs to be re-painted. */
void display(void) {

	//if (!paused)
	//{

	//	PlaySound(TEXT("happy_birthday.wav"), NULL, SND_ASYNC | SND_LOOP);  //play sound in loop
	//}

	if (!paused)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
		glMatrixMode(GL_MODELVIEW);
		gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
		glLoadIdentity();

		glTranslatef(0.0f, 0.0f, -10.0f); //translate camera further from scene
		glRotatef(20.0, 1.0f, 0.0f, 0.0f); //rotate 20 degrees around x axis
		glRotatef(angleCam, 0.0f, 1.0f, 0.0f); //rotate camera around the scene aroub=nd y axis

	

		glPushMatrix();

		glTranslatef(handPost[0], 1.0f, 2.5f); //draw left hand
		glRotatef(-90.0, 1.0f, 0.0f, 0.0f);
		glScalef(0.25, 0.25, 0.25);
		objHand.drawHandLeft();

		glPushMatrix();
		glRotatef(angleFinger[0], 1.0f, 0.0f, 0.0f); //left pinky
		objHand.leftFingers1();
		glPopMatrix();

		glPushMatrix();
		glRotatef(angleFinger[1], 1.0f, 0.0f, 0.0f); //left ring
		objHand.leftFingers2();
		glPopMatrix();

		glPushMatrix();
		glRotatef(angleFinger[2], 1.0f, 0.0f, 0.0f); //left middle
		objHand.leftFingers3();
		glPopMatrix();

		glPushMatrix();
		glRotatef(angleFinger[3], 1.0f, 0.0f, 0.0f); //left index
		objHand.leftFingers4();
		glPopMatrix();

		glPopMatrix();

		glPushMatrix();

		glTranslatef(handPost[1], 1.0f, 2.5f); //draw right hand
		glRotatef(-90.0, 1.0f, 0.0f, 0.0f);
		glScalef(0.25, 0.25, 0.25);
		objHand.drawHandRight();

		glPushMatrix();
		glRotatef(angleFinger[4], 1.0f, 0.0f, 0.0f); //right pinky
		objHand.rightFingers1();
		glPopMatrix();

		glPushMatrix();
		glRotatef(angleFinger[5], 1.0f, 0.0f, 0.0f); //right ring
		objHand.rightFingers2();
		glPopMatrix();

		glPushMatrix();
		glRotatef(angleFinger[6], 1.0f, 0.0f, 0.0f); //right middle
		objHand.rightFingers3();
		glPopMatrix();

		glPushMatrix();
		glRotatef(angleFinger[7], 1.0f, 0.0f, 0.0f); //right index
		objHand.rightFingers4();
		glPopMatrix();

		glPopMatrix();

		glPushMatrix();
		glRotatef(angleKey[6], 1.0f, 0.0f, 0.0f);//centre white key
		objpiano.whiteKey(0.0);
		glPopMatrix();

		glPushMatrix();
		glRotatef(angleKey[7], 1.0f, 0.0f, 0.0f);//1st right white key
		objpiano.whiteKey(0.85);
		glPopMatrix();

		glPushMatrix();
		glRotatef(angleKey[5], 1.0f, 0.0f, 0.0f);//1st left white key
		objpiano.whiteKey(-0.85);
		glPopMatrix();

		glPushMatrix();
		glRotatef(angleKey[8], 1.0f, 0.0f, 0.0f);//2nd right white key
		objpiano.whiteKey(1.70);
		glPopMatrix();

		glPushMatrix();
		glRotatef(angleKey[4], 1.0f, 0.0f, 0.0f);//2nd left white key
		objpiano.whiteKey(-1.70);
		glPopMatrix();

		glPushMatrix();
		glRotatef(angleKey[9], 1.0f, 0.0f, 0.0f);//3rd right white key
		objpiano.whiteKey(2.55);
		glPopMatrix();

		glPushMatrix();
		glRotatef(angleKey[3], 1.0f, 0.0f, 0.0f);//3rd left white key
		objpiano.whiteKey(-2.55);
		glPopMatrix();

		glPushMatrix();
		glRotatef(angleKey[10], 1.0f, 0.0f, 0.0f);//4th right white key
		objpiano.whiteKey(3.40);
		glPopMatrix();

		glPushMatrix();
		glRotatef(angleKey[2], 1.0f, 0.0f, 0.0f);//4th left white key
		objpiano.whiteKey(-3.40);
		glPopMatrix();

		glPushMatrix();
		glRotatef(angleKey[11], 1.0f, 0.0f, 0.0f);//5th right white key
		objpiano.whiteKey(4.25);
		glPopMatrix();

		glPushMatrix();
		glRotatef(angleKey[1], 1.0f, 0.0f, 0.0f);//5th left white key
		objpiano.whiteKey(-4.25);
		glPopMatrix();

		glPushMatrix();
		glRotatef(angleKey[12], 1.0f, 0.0f, 0.0f);//6th right white key
		objpiano.whiteKey(5.10);
		glPopMatrix();

		glPushMatrix();
		glRotatef(angleKey[0], 1.0f, 0.0f, 0.0f);//6th left white key
		objpiano.whiteKey(-5.10);
		glPopMatrix();



		glPushMatrix();
		glRotatef(angleKey[17], 1.0f, 0.0f, 0.0f);//centre right black key
		objpiano.blackKey(0.4);
		glPopMatrix();

		glPushMatrix();
		glRotatef(angleKey[16], 1.0f, 0.0f, 0.0f);//centre left black key
		objpiano.blackKey(-0.4);
		glPopMatrix();

		glPushMatrix();
		glRotatef(angleKey[18], 1.0f, 0.0f, 0.0f);//1st right black key
		objpiano.blackKey(2.1);
		glPopMatrix();

		glPushMatrix();
		glRotatef(angleKey[15], 1.0f, 0.0f, 0.0f);//1st left black key
		objpiano.blackKey(-2.1);
		glPopMatrix();

		glPushMatrix();
		glRotatef(angleKey[19], 1.0f, 0.0f, 0.0f);//2nd right black key
		objpiano.blackKey(2.95);
		glPopMatrix();

		glPushMatrix();
		glRotatef(angleKey[14], 1.0f, 0.0f, 0.0f);//2nd left black key
		objpiano.blackKey(-2.95);
		glPopMatrix();

		glPushMatrix();
		glRotatef(angleKey[20], 1.0f, 0.0f, 0.0f);//3rd right black key
		objpiano.blackKey(3.8);
		glPopMatrix();

		glPushMatrix();
		glRotatef(angleKey[13], 1.0f, 0.0f, 0.0f);//3rd left black key
		objpiano.blackKey(-3.8);
		glPopMatrix();

		//angleCam += 0.2; //add degree of rotation on every refresh

		//handPost[1] += handSpeed1; //add movement to hand
		//handPost[0] += handSpeed2;

		//angleFinger[0] += fingerSpeed1; //add movement for all fingers
		//angleFinger[1] += fingerSpeed2;
		//angleFinger[2] += fingerSpeed1;
		//angleFinger[3] += fingerSpeed2;
		//angleFinger[4] += fingerSpeed1;
		//angleFinger[5] += fingerSpeed2;
		//angleFinger[6] += fingerSpeed1;
		//angleFinger[7] += fingerSpeed2;



		//if (angleKey[i] == 0) //generate random number
		//{
		//	i = rand() % 20;
		//}

		//angleKey[i] += keyDown; //add key movement

		//if (angleKey[i] > 5) //reset key movement
		//{
		//	keyDown = -keyDown;
		//}
		//else if (angleKey[i] < 0)
		//{
		//	keyDown = -keyDown;
		//}

		//if (handPost[0] > -1) //reset hand movement
		//{
		//	handPost[0] = -1;
		//	handSpeed2 = -handSpeed2;
		//}
		//else if (handPost[0] < -4)
		//{
		//	handPost[0] = -4;
		//	handSpeed2 = -handSpeed2;
		//}
		//if (handPost[1] > 4)
		//{
		//	handPost[1] = 4;
		//	handSpeed1 = -handSpeed1;
		//}
		//else if (handPost[1] < 1)
		//{
		//	handPost[1] = 1;
		//	handSpeed1 = -handSpeed1;
		//}

		//if (angleFinger[4] > 10) //reset finger movement
		//{
		//	fingerSpeed2 = -fingerSpeed2;
		//}
		//else if (angleFinger[4] < 0)
		//{
		//	fingerSpeed2 = -fingerSpeed2;
		//}
		//if (angleFinger[0] > 10)
		//{
		//	fingerSpeed1 = -fingerSpeed1;
		//}
		//else if (angleFinger[0] < 0)
		//{
		//	fingerSpeed1 = -fingerSpeed1;
		//}



		glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

	}


}

/* Called back when timer expired [NEW] */
void timer(int value) {
	glutPostRedisplay();      // Post re-paint request to activate display()
	glutTimerFunc(refreshMillis, timer, 0); // next timer call milliseconds later
}

/* Handler for window re-size event. Called back when the window first appears and
whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
											   // Compute aspect ratio of the new window
	if (height == 0) height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping volume to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset
								  // Enable perspective projection with fovy, aspect, zNear and zFar
	gluPerspective(50.0f, aspect, 0.1f, 100.0f);
}

void Timer(int value) {
	glutPostRedisplay();					// Post a paint request to activate display()
	glutTimerFunc(refreshMillis, Timer, 0); // subsequent timer call at milliseconds
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
	glutInit(&argc, argv);            // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
	glutInitWindowSize(740, 480);   // Set the window's initial width & height
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutCreateWindow(title);          // Create window with the given title

	//glutSpecialFunc(special);
	glutDisplayFunc(display);       // Register callback handler for window re-paint event
	glutReshapeFunc(reshape);       // Register callback handler for window re-size event
	glutKeyboardFunc(keyPressed);   //register callback when key is pressed
	glutKeyboardUpFunc(keyUp);      //register callback when key is released
	//glutKeyboardFunc(windowKey);
	glutTimerFunc(0, Timer, 0);						//set timer function for refresh rate

	initGL();                       // Our own OpenGL initialization
									//    glutTimerFunc(0, timer, 0);     // First timer call immediately [NEW]
	glutMainLoop();                 // Enter the infinite event-processing loop
	return 0;
}

