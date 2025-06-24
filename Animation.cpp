#include <iostream>
#include "Animation.h"
#include "global.h"
#include <fstream>
#include <iomanip>
#include <conio.h>

using namespace std;

void Animation::setanimationStyle(int t){
        animationStyle = t;
}

void Animation::setageGroup(int f){
    ageGroup = f;
}

void Animation::setisMusical(bool a){
    isMusical = a;
}

int Animation::getanimationStyle()const{
    return animationStyle;
}

int Animation::getageGroup()const{
    return ageGroup;
}

bool Animation::getisMusical()const{
    return isMusical;
}

Animation::Animation(string title, int rating, int day, int month, int year,int director,int animation, bool musical, int agegroup): Movie(title, rating,day, month, year, director){
    setanimationStyle(animation);
    setisMusical(musical);
    setageGroup(agegroup);
}

Animation::Animation(const Animation &s):Movie(s){
    setanimationStyle(s.getanimationStyle());
    setisMusical(s.getisMusical());
    setageGroup(s.getageGroup());
}


Animation::~Animation(){}

string Animation::getgenreprivate()const{
    return genre;
}

string Animation::getgenre()const{
    return getgenre();
}

// void Animation::displayDetails()const{
//     Movie::displayDetails();
//     cout << setw(15) << left << "Genre" << ": " << getgenre() << endl;
//     cout << setw(15) << left << "Animation Style" << ": " << getanimationStyle() << endl;
//     cout << setw(15) << left << "Musical" << ": " << (getisMusical()? "Yes": "No") << endl;
//     cout << setw(15) << left << "Age Group" << ": " << getageGroup() << endl;
// }

int Animation::calculateScore()const{
    return (Movie::calculateScore() * (getageGroup() / getanimationStyle()))%10;
}

string Animation::suggestMerchandise()const{
    if(getanimationStyle() > 1)
        return "Cool";
    return "Not Cool";
}

bool Animation::isFamilyFriendly()const{
    if((getageGroup() == 18 && getisMusical()) || ((getageGroup() == 5 || getageGroup() == 7) && !getisMusical()) || getanimationStyle() == 3 )
        return true;
    return false;
}

void Animation::changeAnimationStyle(int newStyle) {
    setanimationStyle(newStyle);
}

void Animation::setmovie(string title, int rating, int day, int month, int year, int d, int animation, bool musical, int agegroup){
        Movie::setmovie(title,rating,day,month,year,d);
        setanimationStyle(animation);
        setisMusical(musical);
        setageGroup(agegroup);
    }

    ostream & operator <<(ostream & out, const Animation& a){
        a.displayDetails(out);
        return out;
}

void Animation::displayDetails(ostream& out)const{
    Movie::displayDetails(out);
    out << setw(15) << left << "Genre" << ": " << getgenre() << endl;
    out << setw(15) << left << "Animation Style" << ": " << getanimationStyle() << endl;
    out << setw(15) << left << "Musical" << ": " << (getisMusical()? "Yes": "No") << endl;
    out << setw(15) << left << "Age Group" << ": " << getageGroup() << endl;
    int director = getDirectorNum();
    if(director == 1 || director == 2 || director == 3)
        out << setw(15) << left << "Director" << ": " << d[director-1]->getName();
    else
        out << setw(15) << left << "Director" << ": " << "Unassigned";
}

istream& operator >> (istream & in, Animation&a){
    string title = "";
    string releaseDate = "";

    int rating = 0;
    int genrePointer = 0;
    int directorChoice = 0;
    int day, month, year;
    int AnimeSyle = 0;
    int ageG = 0;

    bool Musical = false;
      

    system("cls");

    cout << "--------------ADDING NEW MOVIE--------------" << endl;

    cout << "Enter" << endl;
    cout << "Movie Title: ";

    in.ignore();
    getline(in, title)
    
    ;

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

    cout << "Animation Style" << endl << "1. Animation Style 1" << endl << "2. Animation Style 2" << endl << "3. Animation Style 3" << endl;
        in >> AnimeSyle;

        cout << "Is it a Musical (Y/N)" << endl;
        char ch = getche();
        in.ignore();

        if(ch == 'Y' || ch == 'y')
            Musical = true;
        
        cout << "\nSelect Age Group "<< endl << "1. 5 Years" << endl << "2. 7 Years" << endl << "3. 18 Years" << endl;
        int ch1;
        in >> ch1;
        if(ch1 == 1)
            ageG = 5;
        else if(ch1 == 2)
            ageG = 7; 
        else if(ch1 == 3)
            ageG = 18;
        else
            ageG = 404;

    a.setmovie(title, rating, day, month, year, directorChoice, AnimeSyle, Musical, ageG);

    return in;
}