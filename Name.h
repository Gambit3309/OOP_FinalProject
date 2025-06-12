#ifndef Name_H_INCLUDED
#define Name_H_INCLUDED

#include<iostream>

using namespace std;

class Name{
private:
    string FirstName, LastName;
protected:
    void setName(string temp);

public:
    string getName();
};

#endif