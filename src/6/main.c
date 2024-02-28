#include <GL/freeglut.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SCREEN_WIDTH 1366
#define SCREEN_HEIGH 768
#define W 900
#define H 600

#define π 3.141592653589793

void draw()
{
    glBegin(GL_LINE_STRIP);
    glVertex2d(-0.99, -0.99);
    glVertex2d(0.99, -0.99);
    glVertex2d(0.99, 0.99);
    glVertex2d(-0.99, 0.99);
    glVertex2d(-0.99, -0.99);
    glEnd();

    double sqrt3 = sqrt(3);

    glBegin(GL_TRIANGLES);
    glVertex2d(-0.5, -sqrt3 / 6);
    glVertex2d(0.5, -sqrt3 / 6);
    glVertex2d(0, sqrt3 / 3);
    glEnd();

    glColor3d(0,0,0);
    glBegin(GL_POLYGON);
    for (double i = 0; i < 2 * π; i += π / 18)
        glVertex2d((cos(i) + 2) / 25 + 0.5, (sin(i) + 1) / 25 - sqrt3 / 6);
    glEnd();
}

void onInitialization()
{
    glClearColor(1, 1, 1, 0);
    glPointSize(5);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

void onDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glViewport(10, 10, 400, 400);
    glColor3d(1, 0, 0);
    draw();

    glRotated(90, 0, 0, 1);
    glViewport(510, 10, 200, 200);
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
