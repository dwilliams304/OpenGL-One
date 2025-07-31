#include <stdio.h>
#include <glew.h>
#include <glut.h>


static void RenderSceneCallback() 
{
	static GLclampf c = 0.0f;

	glClearColor(c * 2, c / 2, 0, c);

	c += 1.0f / 256.f;
	if (c >= 1.0f) {
		c = 0.0f;
	}
	glClear(GL_COLOR_BUFFER_BIT);
	glutPostRedisplay();
	glutSwapBuffers();
}

int main(int argc, char* argv[]) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	int width = 1028;
	int height = 760;

	glutInitWindowSize(width, height);

	int x = 200;
	int y = 100;

	glutInitWindowPosition(x, y);
	int win = glutCreateWindow("Open GL-One");

	printf("window id: %d\n", win);

	GLclampf Red = 1.0f, Green = 0.0f, Blue = 0.0f, Alpha = 0.0f;
	glClearColor(Red, Green, Blue, Alpha);
	
	glutDisplayFunc(RenderSceneCallback);

	glutMainLoop();

	return 0;
}