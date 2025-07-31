#include <stdio.h>
#include <glew.h>
#include <glut.h>
#include <freeglut.h>

GLuint VBO;

struct Vector3f {
	float x;
	float y;
	float z;

	Vector3f() {}

	Vector3f(float _x, float _y, float _z) {
		x = _x;
		y = _y;
		z = _z;
	}

	Vector3f(const float* pFloat) {
		x = pFloat[0];
		y = pFloat[1];
		z = pFloat[2];
	}

	Vector3f(float f) {
		x = y = z = f;
	}
};


static void RenderSceneCallback() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_POINTS, 0, 1);

	glDisableVertexAttribArray(0);

	glutSwapBuffers();
}

static void CreateVertexBuffer() {
	Vector3f Vertices[1];

	Vertices[0] = Vector3f(0.0f, 0.0f, 0.0f);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
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
	
	GLenum res = glewInit();
	if (res != GLEW_OK) {
		fprintf(stderr, "Error: %s\n", glewGetErrorString(res));
		return 1;
	}


	GLclampf Red = 1.0f, Green = 0.0f, Blue = 0.0f, Alpha = 0.0f;
	glClearColor(Red, Green, Blue, Alpha);

	CreateVertexBuffer();
	
	glutDisplayFunc(RenderSceneCallback);

	glutMainLoop();

	return 0;
}