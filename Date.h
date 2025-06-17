#ifndef Date_H_INCLUDED
#define Date_H_INCLUDED
#include <iostream>

using namespace std;

class Date{
private:
    int day, month;
    int year;

protected:
    void setday(int);
    void setmonth(int);
    void setyear(int);

    int getday()const;
    int getmonth()const;
    int getyear()const;

public:
    void setDate(int, int, int);
    void setDate(string, string, int);
    void DisplayDate()const;

    Date(int = 0, int = 0, int = 0);
    Date(const Date &);
    ~Date();

    bool isLeapYear(int);
    void validateDate(int, int, int);

    
};

#endif