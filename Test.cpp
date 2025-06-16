#include <iostream>
#include "Name.h"
#include "MovieBaseClass.h"
#include "SA.h"
#include "Date.h"

using namespace std;

int main()
{

    string day = "MoNdAy";

    cout <<"Enter"<<endl;
    cin >> day;
    day = lowercase(day);
    cout << day;
}
