#include <iostream>
#include "MovieBaseClass.h"
#include "Date.h"
#include "Director.h"
#include "Scifi.h"
#include "Action.h"
#include "Animation.h"
#include <string>
#include "global.h"
#include "SA.h"

using namespace std;

int main()
{
    // string releaseDate;
    // int day, month, year;
    // string line = "01/02/2000";

    // releaseDate = line.substr(0,2);
    // //day = stoi(releaseDate);
    // day = stoi(releaseDate);
    // cout << day << "/";
    // releaseDate = line.substr(3,2);
    // //month = stoi(releaseDate);
    // month = stoi(releaseDate);
    // cout << month << "/";

    // releaseDate = line.substr(6,4);
    // //year = stoi(releaseDate);
    // year = stoi(releaseDate);
    // cout << year;


    InputMoviesFromFile();
    //cout << day << endl << month << endl << year<< endl;
    DeleteAllPointers();
}
