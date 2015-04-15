#include <windows.h>
#include "GL/glut.h" 
#include "cSprite.h"

static int window;
static int menu_id;
static int submenu_id;
static int value = 1;

GLint texture1;

//create our main menu screen
void menu(int num)
{
	if (num == 0)
	{
		glutDestroyWindow(window);
		exit(0);
	}
	
	else
	{
		value = num;
	}
	glutPostRedisplay();
}

//allow the right click menu
void createMenu(void){
	submenu_id = glutCreateMenu(menu);
	    menu_id = glutCreateMenu(menu);
	glutAddMenuEntry("Quit", 0);
	glutAddMenuEntry("Start Game", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void display(void){
	glClear(GL_COLOR_BUFFER_BIT);   
	
	if (value == 1)
	{
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBindTexture(GL_TEXTURE_2D, texture1);

		glBegin(GL_QUADS);

		glColor3f(1, 1, 1);

		glTexCoord2f(0, 1);
		glVertex2f(-1, -1);

		glTexCoord2f(1, 1);
		glVertex2f(1, -1);

		glTexCoord2f(1, 0);
		glVertex2f(1, 1);

		glTexCoord2f(0, 0);
		glVertex2f(-1, 1);

		glEnd();

	}
	else if (value == 2)
	{
		WinMain(NULL, NULL, NULL, 0);
	}
	else if (value == 3){
		
	}
	else if (value == 4){
		
	}
	else if (value == 5){
	
	}
	glFlush();
}

//create the window and apply the texture
int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	window = glutCreateWindow("Ball Breaker Main Menu");
	createMenu();     
	cTexture textureBkgd = cTexture("Images\\Menu.png");

	texture1 = textureBkgd.getTexture();

	//play the background music
	mciSendString("open Audio/Space_Coast.mp3 type mpegvideo alias music", NULL, 0, 0);
	mciSendString("play music repeat", NULL, 0, 0);

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(display);     
	glutMainLoop();
	return EXIT_SUCCESS;
}