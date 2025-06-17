#include <iostream>
#include "SA.h"

using namespace std;

string lowercase(string s){
    for(int i = 0; i < s.length(); i++){
        s[i] = tolower(s[i]);
    }

    return s;
}

int convertMonthtoint(string m){
    int m1;
    bool validMonth = false;
    string MONTHS[12] = {"january", "february", "march", "april", "may", "june", 
                         "july", "august", "september", "october", "november", "december"};

    for(int i = 0; i < 12; i++){
        if(m == MONTHS[i]){
            m1 = i + 1;
            validMonth = true;
            break;
        }
    }

    if(!validMonth)
        m1 = 0;

    return m1;
}

int convertDaytoint(string d){
    string DAYS[7] = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};

    int d1;
    bool validDay = false;
    for(int i = 0; i < 7; i++){
        if(d == DAYS[i]){
            d1 = i + 1;
            validDay = true;
            break;
        }
    }

    if(!validDay)
        d1 = 0;

    return d1;
}