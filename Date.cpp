#include "Date.h"
#include <iostream>
#include "SA.h"

using namespace std;

void Date::setday(int d){
    if(d > 0 && d < 8)
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
    setday(d);
    setmonth(m);
    setyear(y);
}

Date::Date(Date &d){
    setday(d.getday());
    setmonth(d.getmonth());
    setyear(d.getyear());
}

Date::~Date(){}

Date::Date(string d, string m, int year){
    d = lowercase(d);
    m = lowercase(m);
    bool validDay = false;
    bool validMonth = false;

    string DAYS[7] = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};
    string MONTHS[12] = {"january", "february", "march", "april", "may", "june", 
                         "july", "august", "september", "october", "november", "december"};

    for(int i = 0; i < 7; i++){
        if(d == DAYS[i]){
            setday(i + 1);
            validDay = true;
            break;
        }
    }

    for(int i = 0; i < 12; i++){
        if(m == MONTHS[i]){
            setmonth(i + 1);
            validMonth = true;
            break;
        }
    }

    if(!validDay)
        setday(0);
    if(!validMonth)
        setmonth(0);
    
}

Date::Date(int d, int m, int y){
    setday(d);
    setmonth(m);
    setyear(y);
}