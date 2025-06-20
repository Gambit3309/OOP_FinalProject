#ifndef MovieBaseClass_H_INCLUDED
#define MovieBaseClass_H_INCLUDED

#include<iostream>
#include "Date.h"
#include "Director.h"

using namespace std;

class Movie{
private:
    string title;
    int director = 0;
    Date releaseDate;
    int rating;

protected:
    string getTitle()const;
    int getRating()const;

    void setTitle(string);
    void setRating(int);
    
public:

    Movie(string = "", int  = 0, int = 0, int = 0, int = 0, int = 0);
    Movie(const Movie&);
    ~Movie();
    virtual void displayDetails()const;
    virtual int calculateScore()const;
    virtual void setmovie(string, int, int, int, int);

};

#endif