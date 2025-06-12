#ifndef MovieBaseClass_H_INCLUDED
#define MovieBaseClass_H_INCLUDED

#include<iostream>

using namespace std;

class Movie{
private:
    string title, director;
    int releaseDate;
    double rating;

protected:
    string getTitle()const;
    string getDirector()const;
    int getReleaseDate()const;
    double getRating()const;

    void setTitle(string);
    void setDirector(string);
    void setReleaseDate(int);
    void setRating(double);
    
public:

    Movie(string = "", string = "", int = 0, double = 0.0);
    Movie(Movie & cosnt);
    ~Movie();
    void displayDetails()const;
};

#endif MovieBaseClass_H_INCLUDED