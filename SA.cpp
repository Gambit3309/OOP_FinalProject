#include <iostream>
#include "SA.h"

using namespace std;

string lowercase(string s){
    for(int i = 0; i < s.length(); i++){
        s[i] = tolower(s[i]);
    }

    return s;
}