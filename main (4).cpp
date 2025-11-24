#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;

void bresenhamNotebook(int x1, int y1, int x2, int y2) {

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int x = x1;
    int y = y1;

    bool steep = dy > dx;   // check slope > 1

    if (steep) {
        // Swap x and y
        swap(x, y);
        swap(x1, y1);
        swap(x2, y2);
        swap(dx, dy);
    }

    int sx = (x1 < x2) ? 1 : -1;   // direction of x
    int sy = (y1 < y2) ? 1 : -1;   // direction of y

    int p = 2 * dy - dx;   // decision parameter

    glBegin(GL_POINTS);

    while (true) {

        if (steep)
            glVertex2i(y, x);
        else
            glVertex2i(x, y);

        if (x == x2)
            break;

        if (p < 0) {
            // Case 1: pk < 0
            p = p + 2 * dy;
        }
        else {
            // Case 2: pk >= 0
            p = p + 2 * dy - 2 * dx;
            y = y + sy;    // update y
        }

        x = x + sx;        // always increment x
    }

    glEnd();
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    bresenhamNotebook(300, 150, 50, 50);
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
    glutCreateWindow("Bresenham Notebook Style - All Slopes");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
