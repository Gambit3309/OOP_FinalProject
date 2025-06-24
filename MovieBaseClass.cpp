#include<iostream>
#include<fstream>
#include <iomanip>
#include "MovieBaseClass.h"
#include "global.h"

using namespace std;

    string Movie::getTitleprivate()const{
        return title;
    }

    int Movie::getRatingprivate()const{
        return rating;
    }

    int Movie::getDirectorNumprivate()const{
        return director;
    }

    string Movie::getReleaseDateprivate()const{
        return releaseDate.getDate();
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
        cout << setw(16) << left << "Title" << ": " << getTitle() << endl;
        cout << setw(16) << left << "Rating" << ": " << getRating() << endl;
        cout << setw(16) << left << "Release Date" << ": " << releaseDate.getDate() << endl;
        cout << setw(16) << left << "Director" << ": " << d[getDirectorNum()-1]->getName() << endl;

    }*/

    Movie::Movie(string t, int r, int day, int month, int year, int director){
        setTitle(t);
        setRating(r);
        releaseDate.setDate(day,month,year);
        setDirectorNum(director);
    }

    Movie::Movie(const Movie &temp){
        setTitle(temp.getTitle());
        setRating(temp.getRating());
    }

    Movie::~Movie(){}

    int Movie::calculateScore()const{
            return (getRating() * releaseDate.convertDateToDays()); 
        
    }

    void Movie::setmovie(string t, int r, int day, int month, int year, int d){
        setTitle(t);
        setRating(r);
        setDirectorNum(d);
        releaseDate.setDate(day,month,year);
    }
    
  

    string Movie::getDirectorName()const{
        return d[director-1]->getName();
    }

    void Movie::displayDetails(ostream& out)const{
        out << "\n-------Movie Details-------" << endl;
        out << setw(16) << left << "Title" << ": " << getTitle() << endl;
        out << setw(16) << left << "Rating" << ": " << getRating() << endl;
        out << setw(16) << left << "Release Date" << ": " << getReleaseDate() << endl;
    }

    ostream & operator<<(ostream &out,const Movie& m){
        m.displayDetails(out);
        return out;
    }

    string Movie::getTitle()const{
        return getTitleprivate();
    }

    int Movie::getRating()const{
        return getRatingprivate();
    }

    int Movie::getDirectorNum()const{
        return getDirectorNumprivate();
    }

    string Movie::getReleaseDate()const{
        return getReleaseDateprivate();
    }