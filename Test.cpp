#include <iostream>
#include "MovieBaseClass.h"
#include "Date.h"
#include "Director.h"
#include "Scifi.h"
#include "Action.h"
#include "Animation.h"
#include "global.h"
#include "SA.h"

using namespace std;

int main()
{
    Action a("Gambit", 9, 2,2,2000,2,'M',true,3);
    cout << a;

    Date d(2,3,2000);

    cout << d;

    Date d1;
    cin >> d1;
    cout << d1;

    InputMoviesFromFile();
}
