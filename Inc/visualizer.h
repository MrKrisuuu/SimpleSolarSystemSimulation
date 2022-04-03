#ifndef VISUALIZER_H_INCLUDED
#define VISUALIZER_H_INCLUDED

#include <GL/glut.h>
#include "Body.h"

constexpr double MASS = 1.989e30;
constexpr double SCALE = 15;

constexpr double MAX_SIZE = 5e12;
constexpr int PIXELS = 900;
constexpr double SCALE_WINDOW = 0.6;
constexpr double RATIO = 0.8;
constexpr double BUTTON_HEIGHT = 0.15;
constexpr double MAX_SPEED = 10.0;

void create_rectangle(GLenum mode, double left, double right, double up, double down, int R_color, int G_color, int B_color);

void display();

void reshape(int w, int h);

void timer(int);

void mouse_click(int button, int state, int x, int y);

void init_animation(int argc, char** argv, vector<Body*> space);

#endif // VISUALIZER_H_INCLUDED
