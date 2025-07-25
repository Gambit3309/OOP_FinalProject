#include <iostream>
#include "Scifi.h"
#include "global.h"
#include <fstream>
#include <iomanip>
#include <conio.h>

using namespace std;

void scifi::settechLevel(int t){
        techLevel = t;
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

string scifi::getgenreprivate()const{
    return genre;
}

string scifi::getgenre()const{
    return getgenreprivate();
}

/*void scifi::displayDetails()const{
    Movie::displayDetails();
    cout << setw(16) << left << "Genre" << ": " << getgenre() << endl;
    cout << setw(16) << left << "Tech Level" << ": " << gettechLevel() << endl;
    cout << setw(16) << left << "Aliens" << ": " << (gethasAliens()? "Yes": "No") << endl;
    cout << setw(16) << left << "Future Year" << ": " << getfutureYear() << endl;
}*/


void scifi::displayDetails(ostream &out)const{
    Movie::displayDetails(out);
    out << setw(16) << left << "Genre" << ": " << getgenre() << endl;
    out << setw(16) << left << "Tech Level" << ": " << gettechLevel() << endl;
    out << setw(16) << left << "Aliens" << ": " << (gethasAliens()? "Yes": "No") << endl;
    out << setw(16) << left << "Future Year" << ": " << getfutureYear() << endl;
    int director = getDirectorNum();
    if(director == 1 || director == 2 || director == 3)
        out << setw(16) << left << "Director" << ": " << d[director-1]->getName();
    else
        out << setw(16) << left << "Director" << ": " << "Unassigned";
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

void scifi::setmovie(string title, int rating, int day, int month, int year,int d ,int techl, bool Aliens, int futureY){
        Movie::setmovie(title,rating,day,month,year,d);
        settechLevel(techl);
        sethasAliens(Aliens);
        setfutureYear(futureY);
    }

ostream & operator <<(ostream & out, const scifi& a){
        a.displayDetails(out);
        return out;
}

istream& operator >> (istream & in, scifi&s){
    string title = "";
    string releaseDate = "";

    int rating = 0;
    int genrePointer = 0;
    int directorChoice = 0;
    int day, month, year;int techlvl = 0;
    int FutureY = 0;

    bool aliens = false;

    system("cls");

    cout << "--------------ADDING NEW MOVIE--------------" << endl;

    cout << "Enter" << endl;
    cout << "Movie Title: ";
    
    in.ignore();
    getline(in,title);

    cout << "Rating: ";

    in >> rating;

    cout << "Release Date in Numeric for dd/mm/yyyy " << endl;
    cout << "Day: " << endl;
    in >> day;

    cout << "Month: " << endl;
    in >> month;

    cout << "Year: " << endl;
    in >> year;    
    
    cout << "Select Director" << endl << "1. Steven Spielberg" << endl << "2. Martin Scorsese" << endl << "3. Clint Eastwood" << endl;
    in >> directorChoice;
    if(directorChoice < 1 || directorChoice > 3 || d[directorChoice-1] == nullptr){
        directorChoice = 0; 
    }

    cout << "Select Tech Level" << endl << "1. Tech Level 1" << endl << "2. Tech Level 2" << endl << "3. Tech Level 3" << endl;
    in >> techlvl;

    cout << "Does it Have Aliens (Y/N)" << endl;
    char ch = getche();
    in.ignore();
    if(ch == 'Y' || ch == 'y')
        aliens = true;
    
    cout << "\nFuture Year: ";
    in >> FutureY;

    s.setmovie(title, rating, day, month, year, directorChoice, techlvl, aliens, FutureY);

    return in;
}
