#include "../Inc/visualizer.h"

vector<Body*> space;
double dt = 3600;
double speed = 0.0;
double step = dt * speed;
bool choice = false;

void create_rectangle(GLenum mode, double left, double right, double up, double down, int R_color, int G_color, int B_color)
{
    glBegin(mode);
    glColor3f(R_color/255.0, G_color/255.0, B_color/255.0);
    glVertex2f(left, up);
    glVertex2f(right, up);
    glVertex2f(right, down);
    glVertex2f(left, down);
    glVertex2f(left, up);
    glEnd();
}


void display()
{
    step = dt * speed;

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // pasek szybkosci
    create_rectangle(GL_POLYGON,
                     1 + SCALE_WINDOW/2 - SCALE_WINDOW/2*RATIO/2,
                     1 + SCALE_WINDOW/2 + SCALE_WINDOW/2*RATIO/2,
                     -RATIO + speed/MAX_SPEED*2*RATIO,
                     -RATIO,
                     0, 255, 0);

    create_rectangle(GL_LINE_LOOP,
                     1 + SCALE_WINDOW/2 - SCALE_WINDOW/2*RATIO/2,
                     1 + SCALE_WINDOW/2 + SCALE_WINDOW/2*RATIO/2,
                     RATIO,
                     -RATIO,
                     255, 0, 0);

    // przycisk add
    glBegin(GL_POLYGON);
    int red, green;
    if (choice)
    {
        red = 0;
        green = 255;
    }
    else
    {
        red = 255;
        green = 0;
    }
    create_rectangle(GL_LINE_LOOP,
                     -1 - SCALE_WINDOW/2 - SCALE_WINDOW/2*RATIO,
                     -1 - SCALE_WINDOW/2 + SCALE_WINDOW/2*RATIO,
                     RATIO * BUTTON_HEIGHT,
                     -RATIO * BUTTON_HEIGHT,
                     red, green, 0);

    glEnable(GL_POINT_SMOOTH);
    for (vector<Body*>::iterator it = space.begin(); it != space.end(); it++)
    {
        Body* body = *it;

        glPointSize(body->get_scale());
        glBegin(GL_POINTS);
        glColor3f(body->get_R_color() / 256.0, body->get_G_color() / 256.0, body->get_B_color() / 256.0);
        glVertex3f(body->get_x() / MAX_SIZE, body->get_y() / MAX_SIZE, body->get_z() / MAX_SIZE);
        glEnd();
    }

    glutSwapBuffers();
}


void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1 - SCALE_WINDOW, 1 + SCALE_WINDOW, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}


void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(10, timer, 0);

    for (int i=0; i<24; i++)
    {
        for (vector<Body*>::iterator it = space.begin(); it != space.end(); it++)
        {
            Body* body = *it;

            body->calculate_force(space);
        }

        for (vector<Body*>::iterator it = space.begin(); it != space.end(); it++)
        {
            Body* body = *it;

            body->update_velocity(step);
            body->update_position(step);
        }
    }
}


void mouse_click(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        // slider
        int slider_right = PIXELS + 0.75*PIXELS*SCALE_WINDOW + 0.25*PIXELS*SCALE_WINDOW*RATIO/2;
        int slider_left = PIXELS + 0.75*PIXELS*SCALE_WINDOW - 0.25*PIXELS*SCALE_WINDOW*RATIO/2;
        int slider_top = ((1-RATIO)*PIXELS)/2;
        int slider_bottom = PIXELS-((1-RATIO)*PIXELS)/2;

        // przycisk
        int button_right = 0.25*PIXELS*SCALE_WINDOW + 0.25*PIXELS*SCALE_WINDOW*RATIO;
        int button_left = 0.25*PIXELS*SCALE_WINDOW - 0.25*PIXELS*SCALE_WINDOW*RATIO;
        int button_top = PIXELS/2 - PIXELS/2 * RATIO * BUTTON_HEIGHT;
        int button_bottom = PIXELS/2 + PIXELS/2*RATIO * BUTTON_HEIGHT;

        if (x > slider_left && x < slider_right && y > slider_top && y < slider_bottom)
        {
            speed = (PIXELS-((1-RATIO)*PIXELS)/2 - y) / (PIXELS-((1-RATIO)*PIXELS)/2 - ((1-RATIO)*PIXELS)/2) * MAX_SPEED;
            choice = false;
        }
        // dodawanie
        else if (x > button_left && x < button_right && y > button_top && y < button_bottom)
        {
            choice = true;
            speed = 0;
        }
        // dodanie slonca
        else if (choice)
        {
            choice = false;

            Body* object = new Body();
            object->set_mass(MASS);
            object->set_scale(SCALE);
            object->set_R_color(255);
            object->set_G_color(255);
            object->set_B_color(0);
            object->set_x(2*(x-PIXELS*(1+SCALE_WINDOW)/2)/PIXELS*MAX_SIZE);
            object->set_y(2*(PIXELS/2.0-y)/PIXELS*MAX_SIZE);

            space.push_back(object);
        }
    }
}


void init_animation(int argc, char** argv, vector<Body*> planets)
{
    space = planets;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200, 40);
    glutInitWindowSize((1 + SCALE_WINDOW) * PIXELS, PIXELS);

    glutCreateWindow("Solar System simulation");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    glutMouseFunc(mouse_click);
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glutMainLoop();
}

