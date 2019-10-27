#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIMER_ID (0)
#define TIMER_INTERVAL (20)
#define ESCAPE_KEY (27)

static void on_keyboard(unsigned char key, int x, int y);
static void on_timer(int timer_id);
static void on_display(void);

static bool animation_ongoing;
static const float size = 0.1;
float x_curr, y_curr;
float v_x, v_y;

static int window_height = 300;
static int window_width = 300;


int get_random_number_from_range(int end);
double normalize_coord(double coord, double value);

int main(int argc, char** argv)
{
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    
    glutInitWindowSize(window_width, window_height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    glutKeyboardFunc(on_keyboard);
    glutDisplayFunc(on_display);

    srand(time(NULL));

    x_curr = normalize_coord(get_random_number_from_range(window_width), window_width);
    y_curr = normalize_coord(get_random_number_from_range(window_height), window_height);

    printf("x_curr = %lf, y_curr = %lf\n", x_curr, y_curr);

    v_x = get_random_number_from_range(window_width);
    v_y = get_random_number_from_range(window_height);

    animation_ongoing = false;

    glClearColor(0.75, 0.75, 0.75, 0);
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return 0;
}

static void on_keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case ESCAPE_KEY:
        exit(0);
        break;
    
    case 'G':
    case 'g':
        printf("G pressed\n");
        if (!animation_ongoing) {
            printf("Usao u if\n");
            animation_ongoing = true;
            glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
        }
        break;
    case 'S':
    case 's':
        printf("S pressed\n");
        animation_ongoing = false;
        break;
    }
}

static void on_timer(int timer_id)
{
    if(TIMER_ID != timer_id) {
        return;
    }

    x_curr += v_x;
    if (x_curr <= -(1 - size / 2) || x_curr >= 1 - size / 2) {
        v_x *= -1;
    }

    y_curr += v_y;
    if (y_curr <= -(1 - size / 2) || y_curr >= 1 - size / 2) {
        v_y *= -1;
    }

    glutPostRedisplay();

    if (animation_ongoing) {
        glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
    }
}

static void on_display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
        glVertex3f(x_curr - size / 2, y_curr - size / 2, 0);
        glVertex3f(x_curr + size / 2, y_curr - size / 2, 0);
        glVertex3f(x_curr + size / 2, y_curr + size / 2, 0);
        glVertex3f(x_curr - size / 2, y_curr + size / 2, 0);
    glEnd();

    glutSwapBuffers();
}   

int get_random_number_from_range(int end)
{
    return rand() % end;
}

double normalize_coord(double coord, double value)
{
    return (coord / value);
}