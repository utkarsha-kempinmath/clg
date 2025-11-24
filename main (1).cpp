#include <GL/glut.h>
#include <iostream>
using namespace std;

int poly[20][2];
int n, seedx, seedy;

/* put pixel */
void putPixel(int x, int y, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();
    glFlush();
}

/* get pixel color */
void getPixel(int x, int y, float color[3]) {
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, color);
}

/* compare two colors with tolerance */
bool sameColor(float c1[3], float c2[3]) {
    float eps = 0.01;
    return (fabs(c1[0]-c2[0]) < eps &&
            fabs(c1[1]-c2[1]) < eps &&
            fabs(c1[2]-c2[2]) < eps);
}

/* flood fill 4-connected */
void floodFill4(int x, int y, float oldc[3], float newc[3]) {
    float curr[3];
    getPixel(x, y, curr);

    if (sameColor(curr, oldc)) {
        putPixel(x, y, newc[0], newc[1], newc[2]);

        floodFill4(x + 1, y, oldc, newc);
        floodFill4(x - 1, y, oldc, newc);
        floodFill4(x, y + 1, oldc, newc);
        floodFill4(x, y - 1, oldc, newc);
    }
}

/* draw polygon */
void drawPolygon() {
    glColor3f(1, 1, 1);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < n; i++)
        glVertex2i(poly[i][0], poly[i][1]);
    glEnd();
}

/* display */
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawPolygon();

    float oldc[3] = {0, 0, 0};   // background
    float newc[3] = {0, 1, 0};   // green color

    floodFill4(seedx, seedy, oldc, newc);

    glFlush();
}

/* init */
void init() {
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(0, 500, 0, 500);
}

/* main */
int main(int argc, char** argv) {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter vertices (x y):\n";
    for (int i = 0; i < n; i++) {
        cin >> poly[i][0] >> poly[i][1];
    }

    cout << "Enter seed point: ";
    cin >> seedx >> seedy;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Flood Fill 4-Connected");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
