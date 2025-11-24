#include <GL/glut.h>
#include <iostream>
using namespace std;

void plotPoints(int xc, int yc, int x, int y) {
    glBegin(GL_POINTS);

    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);

    glVertex2i(xc + y, yc + x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - y, yc - x);

    glEnd();
}

void bresenhamCircle(int xc, int yc, int r) {

    int x = 0;
    int y = r;

    int d = 3 - 2 * r;     // decision parameter

    while (x <= y) {

        plotPoints(xc, yc, x, y);

        if (d < 0) {
            // Case 1: d < 0
            d = d + 4 * x + 6;
            x++;
        }
        else {
            // Case 2: d >= 0
            d = d + 4 * (x - y) + 10;
            x ++;
            y--;;
        }
    }
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    // Circle center (xc, yc) and radius r
    bresenhamCircle(250, 250, 100);

    glFlush();
}

void init() {
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham Circle Drawing");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
