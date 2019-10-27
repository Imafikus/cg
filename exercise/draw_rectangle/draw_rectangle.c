#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <stdio.h>
#include <stdlib.h>

static void on_display(void);
double normalize_coord(double coord, double value); 
static const int window_width = 300;
static const int window_height = 300;

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    
    glutInitWindowSize(window_width, window_height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    glutDisplayFunc(on_display);

    glClearColor(0.75, 0.75, 0.75, 0);
    
    glutMainLoop();
}
static void on_display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, normalize_coord(150, window_height), 0.0);
    glEnd();
    glutSwapBuffers();
}

double normalize_coord(double coord, double value)
{
    return (coord / value);
}