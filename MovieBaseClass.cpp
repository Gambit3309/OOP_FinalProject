#include<iostream>
#include <iomanip>
#include "MovieBaseClass.h"

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
    void Movie::setRating(double temp){
        rating = temp;
    }

    void Movie::displayDetails()const{
        cout << "-------Movie Details-------" << endl;
        cout << setw(12) << left << "Title" << ": " << getTitle() << endl;
        cout << setw(12) << left << "Rating" << ": " << getRating() << endl;
        cout << setw(12) << left << "Release Date" << ": " << releaseDate.DisplayDate() << endl;
        
        director.displayDirector();

    }

    Movie::Movie(string t, int r): Date(), Director(){
        setTitle(t);
        setRating(r);
    }

    Movie::Movie(const Movie &temp): Date(), Director(){
        setTitle(temp.getTitle());
        setRating(temp.getRating());
    }

    Movie::~Movie(){}

    int Movie::calculateScore()const{
            return (getRating() * releaseDate.convertDateToDays()); 
        
    }