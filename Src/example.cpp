#include "../Inc/example.h"

Body* create_planet(double mass, int scale, int R_color, int G_color, int B_color, double distance, double speed)
{
    Body* body = new Body();

    body->set_mass(mass);
    body->set_scale(scale);
    body->set_R_color(R_color);
    body->set_G_color(G_color);
    body->set_B_color(B_color);
    body->set_x(distance);
    body->set_y_velocity(speed);

    return body;
}

vector<Body*> create_solar_system()
{
    vector<Body*> solar_system;

    Body* SUN = create_planet(MASS_SUN, SCALE_SUN, 255, 255, 0, DISTANCE_SUN, SPEED_SUN);
    Body* MERCURY = create_planet(MASS_MERCURY, SCALE_MERCURY, 146, 137, 138, DISTANCE_MERCURY, SPEED_MERCURY);
    Body* VENUS = create_planet(MASS_VENUS, SCALE_VENUS, 206, 204, 196, DISTANCE_VENUS, SPEED_VENUS);
    Body* EARTH = create_planet(MASS_EARTH, SCALE_EARTH, 0, 0, 255, DISTANCE_EARTH, SPEED_EARTH);
    Body* MARS = create_planet(MASS_MARS, SCALE_MARS, 227, 106, 77, DISTANCE_MARS, SPEED_MARS);
    Body* JUPITER = create_planet(MASS_JUPITER, SCALE_JUPITER, 153, 96, 79, DISTANCE_JUPITER, SPEED_JUPITER);
    Body* SATURN = create_planet(MASS_SATURN, SCALE_SATURN, 235, 201, 130, DISTANCE_SATURN, SPEED_SATURN);
    Body* URANUS = create_planet(MASS_URANUS,SCALE_URANUS,207,245,246,DISTANCE_URANUS,SPEED_URANUS);
    Body* NEPTUNE = create_planet(MASS_NEPTUNE, SCALE_NEPTUNE, 66, 108, 252, DISTANCE_NEPTUNE, SPEED_NEPTUNE);

    solar_system.push_back(SUN);
    solar_system.push_back(MERCURY);
    solar_system.push_back(VENUS);
    solar_system.push_back(EARTH);
    solar_system.push_back(MARS);
    solar_system.push_back(JUPITER);
    solar_system.push_back(SATURN);
    solar_system.push_back(URANUS);
    solar_system.push_back(NEPTUNE);

    return solar_system;
}
