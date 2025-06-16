#ifndef Name_H_INCLUDED
#define Name_H_INCLUDED

#include<iostream>

using namespace std;

class Name{
private:
    string FirstName, LastName;
protected:
    void setFN(string);
    void setLN(string);
    string getFN()const;
    string getLN()const;
public:
    Name(string = "", string = "");
    Name(Name&);
    ~Name();
    string DisplayName();
};

#endif