#ifndef Scifi_H_INCLUDED
#define Scifi_H_INCLUDED

#include <iostream>
#include "MovieBaseClass.h"
#include "Date.h"

using namespace std;

class scifi:public Movie{
private:
    int techLevel = 0;
    bool hasAliens;
    int futureYear;
    string genre = "SciFi";

protected:
    void settechLevel(int);
    void sethasAliens(bool);
    void setfutureYear(int);

    int gettechLevel()const;
    int getfutureYear()const;
    bool gethasAliens()const;
    
public:
    string getgenre()const;
    scifi(string = "", int = 0, int = 0,int = 0,int = 0,int = 0,int = 0, bool = false, int = 0);
    ~scifi();
    scifi(const scifi &);

    void displayDetails()const;
    int calculateScore()const override;
    string showTechAnalysis()const;
    string simulateFutureScenario()const;
    void toggleAlienInvasion();
    void setmovie(string, int, int, int ,int, int, bool, int);
};

#endif