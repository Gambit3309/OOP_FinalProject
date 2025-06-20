#include <iostream>
#include "Action.h"
#include <iomanip>

using namespace std;

void Action::setviolenceLevel(char v){
    if(v == 'D' || v == 'M' || v == 'U')
        violenceLevel = v;
    else
        violenceLevel = ' ';
}

void Action::setnoOfFightScenes(int f){
    if(f == 5 || f == 7 || f == 18)
    noOfFightScenes = f;
    else
        noOfFightScenes = 0;
}

void Action::sethasStunts(bool a){
    hasStunts = a;
}

char Action::getviolenceLevel()const{
    return violenceLevel;
}

int Action::getnoOfFightScenes()const{
    return noOfFightScenes;
}

bool Action::gethasStunts()const{
    return hasStunts;
}

Action::Action(string title, int rating, int day, int month, int year,char violence, bool stunt, int fightscene): Movie(title, rating, day, month, year){
    setviolenceLevel(violence);
    sethasStunts(stunt);
    setnoOfFightScenes(fightscene);
}

Action::Action(const Action &s):Movie(s){
    setviolenceLevel(s.getviolenceLevel());
    sethasStunts(s.gethasStunts());
    setnoOfFightScenes(s.getnoOfFightScenes());
}


Action::~Action(){}

string Action::getgenre()const{
    return genre;
}

void Action::displayDetails()const{
    Movie::displayDetails();
    cout << "-----------Genre Details-----------" << endl;
    cout << setw(14) << left << "Genre" << ": " << getgenre() << endl;
    cout << setw(14) << left << "Violence Level" << ": " << getviolenceLevel() << endl;
    cout << setw(14) << left << "Stunts" << ": " << (gethasStunts()? "Yes": "No") << endl;
    cout << setw(14) << left << "Fight Scenes" << ": " << getnoOfFightScenes() << endl;
}

int Action::calculateScore()const{
    return (Movie::calculateScore() * ((getnoOfFightScenes() > 7? 2:getnoOfFightScenes())/countExplosions()))%10;
}

string Action::assessCensorship()const{
    if(getviolenceLevel() == 'D')
        return "Domestic Violence";
    else if(getviolenceLevel() == 'M')
        return "Mafia";
    return "Ultra Cool";
}

string Action::stuntCoordinatorReport()const{
    if(gethasStunts() && (getnoOfFightScenes() >= 5 && getnoOfFightScenes() <= 10))
        return "Cool";
    return "Might be boring";
}

int Action::countExplosions()const{
    if(getnoOfFightScenes() > 5)
        return 8;
    return 2;
}

void Action::setmovie(string title, int rating, int day, int month, int year, char violenceLevel, bool stunts, int fightscene){
        Movie::setmovie(title,rating,day,month,year);
        setviolenceLevel(violenceLevel);
        sethasStunts(stunts);
        setnoOfFightScenes(fightscene);
    }