#include<iostream>
#include<fstream>
#include <iomanip>
#include "MovieBaseClass.h"
#include "global.h"

using namespace std;

    string Movie::getTitle()const{
        return title;
    }

    int Movie::getRating()const{
        return rating;
    }

    int Movie::getDirectorNum()const{
        return director;
    }

    void Movie::setTitle(string temp){
        title = temp;
    }
    void Movie::setRating(int temp){
        rating = temp;
    }

    void Movie::setDirectorNum(int temp){
        director = temp;
    }

    /*void Movie::displayDetails()const{
        cout << "-------Movie Details-------" << endl;
        cout << setw(15) << left << "Title" << ": " << getTitle() << endl;
        cout << setw(15) << left << "Rating" << ": " << getRating() << endl;
        cout << setw(15) << left << "Release Date" << ": " << releaseDate.getDate() << endl;
        cout << setw(15) << left << "Director" << ": " << d[getDirectorNum()-1]->getName() << endl;

    }*/

    Movie::Movie(string t, int r, int day, int month, int year, int director){
        setTitle(t);
        setRating(r);
        releaseDate.setDate(day,month,year);
    }

    Movie::Movie(const Movie &temp){
        setTitle(temp.getTitle());
        setRating(temp.getRating());
    }

    Movie::~Movie(){}

    int Movie::calculateScore()const{
            return (getRating() * releaseDate.convertDateToDays()); 
        
    }

    void Movie::setmovie(string t, int r, int day, int month, int year){
        setTitle(t);
        setRating(r);
        releaseDate.setDate(day,month,year);
    }

    string Movie::displayReleaseDate()const{
        return releaseDate.getDate();
    }

    string Movie::getDirectorName()const{
        return d[director-1]->getName();
    }

    void Movie::displayDetails(ostream& out)const{
        out << "-------Movie Details-------" << endl;
        out << setw(15) << left << "Title" << ": " << getTitle() << endl;
        out << setw(15) << left << "Rating" << ": " << getRating() << endl;
        out << setw(15) << left << "Release Date" << ": " << releaseDate << endl;
        if(getDirectorNum() > 0 && getDirectorNum() <= 3 && d[getDirectorNum()-1] != nullptr) {
            out << setw(15) << left << "Director" << ": " << d[getDirectorNum()-1]->getName() << endl;
        } else {
            out << setw(15) << left << "Director" << ": " << "Not Assigned" << endl;
        }
    }

    ostream & operator<<(ostream &out,const Movie& m){
        m.displayDetails(out);
        return out;
    }