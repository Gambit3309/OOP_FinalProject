#include "Date.h"
#include <iostream>
#include "SA.h"

using namespace std;

void Date::setday(int d){
    if(d > 0 && d < 32)
        day = d;
    else
        d = 0;
}

void Date::setmonth(int m){
    if(m >0 && m < 13){
        month = m;        
    }
    else
        month = 0;
}

void Date::setyear(int y){
    year = y;
}

int Date::getday()const{
    return day;
}

int Date::getmonth()const{
    return month;
}

int Date::getyear()const{
    return year;
}

Date::Date(int d, int m, int y){
    if(d > 0 && d < 32)
        setday(d);
    else
        setday(0);
    if(m > 0 && m < 13){
        setmonth(m);        
    }
    else
        setmonth(0);
    setyear(y);
}

Date::Date(const Date &d){
    setday(d.getday());
    setmonth(d.getmonth());
    setyear(d.getyear());
}

Date::~Date(){}

void Date::setDate(string d, string m, int y){
    d = lowercase(d);
    m = lowercase(m);
    
    setday(convertDaytoint(d));
    setmonth(convertMonthtoint(m));
}

void Date::DisplayDate()const{
    cout << getday() << "/" << getmonth() << "/" << getyear() << endl;
}

bool Date::isLeapYear(int y){
    if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        return true;
    return false;
}

void Date::validateDate(int d, int m, int y){
    
}

