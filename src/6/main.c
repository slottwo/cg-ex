#include <GL/freeglut.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SCREEN_WIDTH 1366
#define SCREEN_HEIGH 768
#define W 500 // 4 * 180
#define H 200 // 3 * 180

void draw()
{
    glBegin(GL_LINE_STRIP);
    glVertex2d(-0.99, -0.99);
    glVertex2d(0.99, -0.99);
    glVertex2d(0.99, 0.99);
    glVertex2d(-0.99, 0.99);
    glVertex2d(-0.99, -0.99);
    glEnd();
}

void onInitialization()
{
    glClearColor(1, 1, 1, 0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

void onDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glViewport(10, 10, 288, 288);
    glColor3d(1, 0, 0);
    draw();

    glViewport(370, 10, 144, 144);
    glColor3d(0, 1, 0);
    draw();

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
