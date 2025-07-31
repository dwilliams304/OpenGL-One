#include <stdio.h>
#include <glew.h>
#include <glut.h>


int main(int argc, char* argv[]) 
{
	printf("Hi Open GL!");

	glutInit(&argc, argv);
	glutCreateWindow("GLEW Test");

	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}
	fprintf(stdout, "Status: Using Glew %s\n", glewGetString(GLEW_VERSION));
	getchar();
	return 0;
}