#ifndef EXAMPLE_H_INCLUDED
#define EXAMPLE_H_INCLUDED

#include <vector>
#include "Body.h"

constexpr double DISTANCE_SUN = 0;
constexpr double DISTANCE_MERCURY = 5.790e10;
constexpr double DISTANCE_VENUS = 1.082e11;
constexpr double DISTANCE_EARTH = 1.496e11;
constexpr double DISTANCE_MARS = 2.279e11;
constexpr double DISTANCE_JUPITER = 7.786e11;
constexpr double DISTANCE_SATURN = 1.434e12;
constexpr double DISTANCE_URANUS = 2.875e12;
constexpr double DISTANCE_NEPTUNE = 4.500e12;

constexpr double MASS_SUN = 1.989e30;
constexpr double MASS_MERCURY = 3.301e23;
constexpr double MASS_VENUS = 4.867e24;
constexpr double MASS_EARTH = 5.972e24;
constexpr double MASS_MARS = 6.417e23;
constexpr double MASS_JUPITER = 1.898e27;
constexpr double MASS_SATURN = 5.683e26;
constexpr double MASS_URANUS = 8.681e25;
constexpr double MASS_NEPTUNE = 1.024e26;

constexpr int SCALE_SUN = 15;
constexpr int SCALE_MERCURY = 3;
constexpr int SCALE_VENUS = 5;
constexpr int SCALE_EARTH = 5;
constexpr int SCALE_MARS = 4;
constexpr int SCALE_JUPITER = 10;
constexpr int SCALE_SATURN = 9;
constexpr int SCALE_URANUS = 7;
constexpr int SCALE_NEPTUNE = 7;

constexpr double SPEED_SUN = 0;
constexpr double SPEED_MERCURY = 4.736e4;
constexpr double SPEED_VENUS = 3.502e4;
constexpr double SPEED_EARTH = 2.978e4;
constexpr double SPEED_MARS = 2.401e4;
constexpr double SPEED_JUPITER = 1.307e4;
constexpr double SPEED_SATURN = 9.680e3;
constexpr double SPEED_URANUS = 6.800e3;
constexpr double SPEED_NEPTUNE = 5.43e3;

using namespace std;

Body* create_planet(double mass, int scale, int R_color, int G_color, int B_color, double distance, double speed);

vector<Body*> create_solar_system();

#endif // EXAMPLE_H_INCLUDED
