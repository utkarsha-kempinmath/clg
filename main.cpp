#include <GL/glut.h>
#include <iostream>
using namespace std;

float x1s, y1s, x2s, y2s;
float xmin = 100, ymin = 100, xmax = 300, ymax = 300;

// Region codes
int getCode(float x, float y) {
    int code = 0;
    if (x < xmin) code |= 1;      // left
    if (x > xmax) code |= 2;      // right
    if (y < ymin) code |= 4;      // bottom
    if (y > ymax) code |= 8;      // top
    return code;
}

// Cohen–Sutherland clipping
void clipLine() {
    float x1 = x1s, y1 = y1s, x2 = x2s, y2 = y2s;
    int c1 = getCode(x1, y1), c2 = getCode(x2, y2);

    while (true) {
        if ((c1 | c2) == 0) break;            // fully inside
        else if (c1 & c2) return;             // fully outside
        else {
            int code = c1 ? c1 : c2;
            float x, y;

            if (code & 8) {                   // top
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if (code & 4) {              // bottom
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if (code & 2) {              // right
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else {                            // left  (FIXED HERE)
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (code == c1) {
                x1 = x; y1 = y;
                c1 = getCode(x1, y1);
            }
            else {
                x2 = x; y2 = y;
                c2 = getCode(x2, y2);
            }
        }
    }

    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Window rectangle
    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin, ymin);
    glVertex2f(xmax, ymin);
    glVertex2f(xmax, ymax);
    glVertex2f(xmin, ymax);
    glEnd();

    glColor3f(1, 0, 0);
    clipLine();
    glFlush();
}

void init() {
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv) {
    cout << "Enter x1 y1 x2 y2: ";o
    cin >> x1s >> y1s >> x2s >> y2s;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Cohen–Sutherland Line Clipping");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
