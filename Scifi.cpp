#include <iostream>
#include "Scifi.h"
#include <iomanip>

using namespace std;

void scifi::settechLevel(int t){
    if(t >= 1 && t < 4)
        techLevel = t;
    else if(t > 3)
        techLevel = 3;
    else
        techLevel = 1;
}

void scifi::setfutureYear(int f){
    futureYear = f;
}

void scifi::sethasAliens(bool a){
    hasAliens = a;
}

int scifi::gettechLevel()const{
    return techLevel;
}

int scifi::getfutureYear()const{
    return futureYear;
}

bool scifi::gethasAliens()const{
    return hasAliens;
}

scifi::scifi(string title, int rating, int day, int month, int year,int director, int tech, bool aliens, int futureY): Movie(title, rating, day, month, year, director){
    settechLevel(tech);
    sethasAliens(aliens);
    setfutureYear(futureY);
}

scifi::scifi(const scifi &s):Movie(s){
    settechLevel(s.gettechLevel());
    sethasAliens(s.gethasAliens());
    setfutureYear(s.getfutureYear());
}


scifi::~scifi(){}

string scifi::getgenre()const{
    return genre;
}

void scifi::displayDetails()const{
    Movie::displayDetails();
    cout << "-----------Genre Details-----------" << endl;
    cout << setw(11) << left << "Genre" << ": " << getgenre() << endl;
    cout << setw(11) << left << "Tech Level" << ": " << gettechLevel() << endl;
    cout << setw(11) << left << "Aliens" << ": " << (gethasAliens()? "Yes": "No") << endl;
    cout << setw(11) << left << "Future Year" << ": " << getfutureYear() << endl;
}

int scifi::calculateScore()const{
    return (Movie::calculateScore() * gettechLevel())%10;
}

string scifi::showTechAnalysis()const{
    if(calculateScore() > 7)
        return "Awesome";
    return "Not so Awesome";
}

string scifi::simulateFutureScenario()const{
    if((calculateScore() > 7) && hasAliens)
        return "Future is Bright";
    return "Future is not Bright";
}

void scifi::toggleAlienInvasion(){
    hasAliens = !hasAliens;
}

void scifi::setmovie(string title, int rating, int day, int month, int year, int techl, bool Aliens, int futureY){
        Movie::setmovie(title,rating,day,month,year);
        settechLevel(techl);
        sethasAliens(Aliens);
        setfutureYear(futureY);
    }