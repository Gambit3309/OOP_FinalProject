#include <iostream>
#include "Name.h"
#include "MovieBaseClass.h"
#include "SA.h"
#include "Date.h"
#include "Director.h"

using namespace std;

int main()
{
    Date da(2,4,5);
    Director d;
    cout << d.getDirector() << endl;
    da.DisplayDate();
}
