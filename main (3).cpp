#include <GL/glut.h>

void scanlineFill(int x1, int y1, int x2, int y2) {
    glBegin(GL_LINES);
    for (int y = y1; y <= y2; y++) {
        glVertex2i(x1, y);
        glVertex2i(x2, y);
    }
    glEnd();
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw rectangle border
    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(100,100);
        glVertex2i(300,100);
        glVertex2i(300,300);
        glVertex2i(100,300);
    glEnd();

    // Fill using scanline (very simple for rectangle)
    glColor3f(0,0,1);
    scanlineFill(100, 100, 300, 290);

    glFlush();
}

void init() {
    glClearColor(0,0,0,0);
    gluOrtho2D(0,500,0,500);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Scanline Fill");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
