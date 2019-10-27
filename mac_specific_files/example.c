#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>

static void on_display(void);


int main(int argc, char** argv)
{
    int window_width = 300;
    int window_height = 300;

    int window_pos_x = 100;
    int window_pos_y = 100;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowSize(window_height, window_width);
    glutInitWindowPosition(window_pos_x, window_pos_y);
    glutCreateWindow(argv[0]);

    glutDisplayFunc(on_display);
    glClearColor(0.75, 0.75, 0.75, 0);

    glutMainLoop();
    
    return 0;
}

static void on_display(void) 
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
        glVertex3f(0.5, 0.5, 0);
        glVertex3f(0.5, -0.5, 0);
        glVertex3f(-0.5, -0.5, 0);
        glVertex3f(-0.5, 0.5, 0);
    glEnd();

    glutSwapBuffers();
}