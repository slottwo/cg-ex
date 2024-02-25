#include <GL/freeglut.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SCREEN_WIDTH 1366
#define SCREEN_HEIGH 768
#define W 500
#define H 500

void onInitialization()
{
    glClearColor(1, 1, 1, 0);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 1, 0, 1);
}

void onDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glutSwapBuffers();
}

int main(int argc, char const *argv[])
{
    // GLUT Config
    glutInit(&argc, (char **)argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(
        (SCREEN_WIDTH - W) / 2,
        (SCREEN_HEIGH - H) / 2);
    glutInitWindowSize(W, H);
    glutCreateWindow("OpenGL");

    // Drawing presets
    onInitialization();

    // Draw
    glutDisplayFunc(onDisplay);

    // Loop
    glutMainLoop();

    return 0;
}
