#ifndef BODY_H_INCLUDED
#define BODY_H_INCLUDED

#include <vector>

constexpr double G = 6.674e-11;

using namespace std;

class Body
{
    double mass;
    int scale;

    int R_color;
    int G_color;
    int B_color;

    double x;
    double y;
    double z;

    double x_velocity;
    double y_velocity;
    double z_velocity;

    double x_force;
    double y_force;
    double z_force;

public:
    Body();

    void set_mass(double mass);
    void set_scale(int scale);
    void set_R_color(int color);
    void set_G_color(int color);
    void set_B_color(int color);
    void set_x(double x);
    void set_y(double y);
    void set_z(double z);
    void set_x_velocity(double x_velocity);
    void set_y_velocity(double y_velocity);
    void set_z_velocity(double z_velocity);

    double get_mass();
    int get_scale();
    int get_R_color();
    int get_G_color();
    int get_B_color();
    double get_x();
    double get_y();
    double get_z();

    double distance_to(Body other);

    void calculate_force(vector<Body*> planet_list);

    void update_velocity(double step);

    void update_position(double step);
};


#endif // BODY_H_INCLUDED
