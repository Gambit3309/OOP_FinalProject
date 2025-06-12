#include<iostream>
#include <iomanip>
#include "MovieBaseClass.h"

using namespace std;

    string Movie::getTitle()const{
        return title;
    }
    string Movie::getDirector()const{
        return director;
    }
    int Movie::getReleaseDate()const{
        return releaseDate;
    }
    double Movie::getRating()const{
        return rating;
    }

    void Movie::setTitle(string temp){
        title = temp;
    }
    void Movie::setDirector(string temp){
        director = temp;
    }
    void Movie::setReleaseDate(int temp){
        releaseDate = temp;
    }
    void Movie::setRating(double temp){
        rating = temp;
    }

    void Movie::displayDetails()const{
        cout << "-------Movie Details-------" << endl;
        cout << setw(12) << left << "Title: " << getTitle() << endl;
        cout << setw(12) << left << "Director" << ":" << getDirector() << endl;
        cout << setw(12) << left << "Rating" << ":" << getRating() << endl;
        cout << setw(12) << left << "Release Date" << ":" << getReleaseDate() << endl;
    }

    Movie::Movie(string t, string d, int rd, double r){
        setTitle(t);
        setDirector(d);
        setReleaseDate(rd);
        setRating(r);
    }

    Movie::Movie(Movie &temp){
        setTitle(getTitle());
        setDirector(getDirector());
        setReleaseDate(getReleaseDate());
        setRating(getRating());
    }

    Movie::~Movie(){}