#include <iostream>
#include <vector>
#include "Inc/Body.h"
#include "Inc/example.h"
#include "Inc/visualizer.h"

using namespace std;

int main(int argc, char** argv)
{
    cout << "INSTRUKCJA";
    cout << endl;
    cout << "Po prawej stronie znajduje sie suwak, ktory odpowiada za szybkosc tej symulacji." << endl;
    cout << "Po lewej stronie jest przycisk, ktory gdy jest zielony to zatrzymuje symulacje" << endl;
    cout << "oraz dodaje nam drugie Slonce w miejscu wskazanym przez kursor (po kliknieciu)." << endl;
    cout << "Aby wznowic symulacje nalezy skorzystac z suwaka po prawej stronie symulacji." << endl;

    vector<Body*> space = create_solar_system();

    init_animation(argc, argv, space);

    return 0;
}
