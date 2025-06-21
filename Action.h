#ifndef Action_H_INCLUDED
#define Action_H_INCLUDED

#include <iostream>
#include <fstream>
#include "MovieBaseClass.h"
#include "Date.h"

using namespace std;

class Action:public Movie{
private:
    char violenceLevel;
    bool hasStunts;
    int noOfFightScenes;
    string genre = "Action";

protected:
    void setviolenceLevel(char);
    void sethasStunts(bool);
    void setnoOfFightScenes(int);

    char getviolenceLevel()const;
    int getnoOfFightScenes()const;
    bool gethasStunts()const;

public:
    string getgenre()const;
    Action(string = "", int = 0, int = 0,int = 0,int = 0,int = 0,char = ' ', bool = false, int = 0);
    ~Action();
    Action(const Action &);

    void setmovie(string, int, int, int ,int, char, bool, int);


    void displayDetails()const;
    int calculateScore()const override;
    string assessCensorship()const;
    string stuntCoordinatorReport()const;
    int countExplosions()const;
 
    friend ostream& operator <<(ostream &,const Action &);
};

#endif