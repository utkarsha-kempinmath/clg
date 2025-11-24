#include <GL/glut.h>

float boundaryColor[3] = {1.0, 0.0, 0.0};   // red boundary
float fillColor[3]     = {0.0, 1.0, 0.0};   // green fill

void putPixel(int x, int y, float color[3]) {
    glColor3fv(color);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void getPixel(int x, int y, float color[3]) {
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, color);
}

void boundaryFill8(int x, int y) {

    float currColor[3];
    getPixel(x, y, currColor);

    bool isBoundary =
        currColor[0] == boundaryColor[0] &&
        currColor[1] == boundaryColor[1] &&
        currColor[2] == boundaryColor[2];

    bool isFilled =
        currColor[0] == fillColor[0] &&
        currColor[1] == fillColor[1] &&
        currColor[2] == fillColor[2];

    if (!isBoundary && !isFilled) {

        putPixel(x, y, fillColor);

        // 8-connected neighbors
        boundaryFill8(x + 1, y);
        boundaryFill8(x - 1, y);
        boundaryFill8(x, y + 1);
        boundaryFill8(x, y - 1);
        boundaryFill8(x + 1, y + 1);
        boundaryFill8(x - 1, y + 1);
        boundaryFill8(x + 1, y - 1);
        boundaryFill8(x - 1, y - 1);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(3); // thicker boundary (important!)

    // Draw red rectangle boundary
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(100, 100);
        glVertex2i(300, 100);
        glVertex2i(200, 300);
        //glVertex2i(100, 300);
    glEnd();

    glFlush();

    boundaryFill8(150, 150);   // seed inside
}

void init() {
    glClearColor(0, 0, 0, 0);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("8-Connected Boundary Fill");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
