#include <iostream>
#include "Animation.h"
#include <iomanip>

using namespace std;

void Animation::setanimationStyle(int t){
    if(t >= 1 && t < 4)
        animationStyle = t;
}

void Animation::setageGroup(int f){
    if(f == 5 || f == 7 || f == 18)
    ageGroup = f;
}

void Animation::setisMusical(bool a){
    isMusical = a;
}

int Animation::getanimationStyle()const{
    return animationStyle;
}

int Animation::getageGroup()const{
    return ageGroup;
}

bool Animation::getisMusical()const{
    return isMusical;
}

Animation::Animation(int t, bool a, int f): Movie(){
    setanimationStyle(t);
    setisMusical(a);
    setageGroup(f);
}

Animation::Animation(const Animation &s){
    setanimationStyle(s.getanimationStyle());
    setisMusical(s.getisMusical());
    setageGroup(s.getageGroup());
}


Animation::~Animation(){}

string Animation::getgenre()const{
    return genre;
}

void Animation::displayDetails()const{
    Movie::displayDetails();
    cout << "-----------Genre Details-----------" << endl;
    cout << setw(15) << left << "Genre" << ": " << getgenre() << endl;
    cout << setw(15) << left << "Animation Style" << ": " << getanimationStyle() << endl;
    cout << setw(15) << left << "Musical" << ": " << (getisMusical()? "Yes": "No") << endl;
    cout << setw(15) << left << "Age Group" << ": " << getageGroup() << endl;
}

int Animation::calculateScore()const{
    return (Movie::calculateScore() * (getageGroup() / getanimationStyle()))%10;
}

string Animation::suggestMerchandise()const{
    if(getanimationStyle() > 1)
        return "Cool";
    return "Not Cool";
}

bool Animation::isFamilyFriendly()const{
    if((getageGroup() == 18 && getisMusical()) || ((getageGroup() == 5 || getageGroup() == 7) && !getisMusical()) || getanimationStyle() == 3 )
        return true;
    return false;
}

void Animation::changeAnimationStyle(int newStyle) {
    setanimationStyle(newStyle);
}