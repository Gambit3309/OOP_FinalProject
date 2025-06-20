#include<iostream>
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

    void Movie::setTitle(string temp){
        title = temp;
    }
    void Movie::setRating(int temp){
        rating = temp;
    }

    void Movie::displayDetails()const{
        cout << "-------Movie Details-------" << endl;
        cout << setw(12) << left << "Title" << ": " << getTitle() << endl;
        cout << setw(12) << left << "Rating" << ": " << getRating() << endl;
        cout << setw(12) << left << "Release Date" << ": " << releaseDate.DisplayDate() << endl;
        cout << setw(12) << left << "Director" << ": " << d[director]->getName() << endl;

    }

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