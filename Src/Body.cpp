#include "../Inc/Body.h"
#include <cmath>

Body::Body()
{
    this->mass = 0;
    this->scale = 5;

    this->R_color = 255;
    this->G_color = 255;
    this->B_color = 255;

    this->x = 0;
    this->y = 0;
    this->z = 0;

    this->x_velocity = 0;
    this->y_velocity = 0;
    this->z_velocity = 0;
}

void Body::set_mass(double mass)
{
    this->mass = mass;
}

void Body::set_scale(int scale)
{
    this->scale = scale;
}

void Body::set_R_color(int color)
{
    this->R_color = color;
}

void Body::set_G_color(int color)
{
    this->G_color = color;
}

void Body::set_B_color(int color)
{
    this->B_color = color;
}

void Body::set_x(double x)
{
    this->x = x;
}

void Body::set_y(double y)
{
    this->y = y;
}

void Body::set_z(double z)
{
    this->z = z;
}

void Body::set_x_velocity(double x_velocity)
{
    this->x_velocity = x_velocity;
}

void Body::set_y_velocity(double y_velocity)
{
    this->y_velocity = y_velocity;
}

void Body::set_z_velocity(double z_velocity)
{
    this->z_velocity = z_velocity;
}

double Body::get_mass()
{
    return this->mass;
}

int Body::get_scale()
{
    return this->scale;
}

int Body::get_R_color()
{
    return this->R_color;
}

int Body::get_G_color()
{
    return this->G_color;
}

int Body::get_B_color()
{
    return this->B_color;
}

double Body::get_x()
{
    return this->x;
}

double Body::get_y()
{
    return this->y;
}

double Body::get_z()
{
    return this->z;
}

double Body::distance_to(Body other)
{
    double r_x = other.get_x() - this->x;
    double r_y = other.get_y() - this->y;
    double r_z = other.get_z() - this->z;
    return sqrt(pow(r_x, 2) + pow(r_y, 2) + pow(r_z, 2));
}

void Body::calculate_force(vector<Body*> planet_list)
{
    this->x_force = 0;
    this->y_force = 0;
    this->z_force = 0;
    for (vector<Body*>::iterator it = planet_list.begin(); it != planet_list.end(); it++)
    {
        Body* body = *it;
        if (body != this)
        {
            double masses = G * body->get_mass() * this->mass;
            this->x_force += masses * (body->get_x() - this->x) / pow(this->distance_to(*body),3);
            this->y_force += masses * (body->get_y() - this->y) / pow(this->distance_to(*body),3);
            this->z_force += masses * (body->get_z() - this->z) / pow(this->distance_to(*body),3);
        }
    }
}

void Body::update_velocity(double step)
{
    this->x_velocity += this->x_force * step / this->mass;
    this->y_velocity += this->y_force * step / this->mass;
    this->z_velocity += this->z_force * step / this->mass;
}

void Body::update_position(double step)
{
    this->x += this->x_velocity * step;
    this->y += this->y_velocity * step;
    this->z += this->z_velocity * step;
}
