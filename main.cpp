#include <iostream>
#include <conio.h>
#include "menu.h"

using namespace std;

void space(){
    cout << "\t\t\t\t";
}

void pattern(){
    space();
    for(int i=0; i<54; i++){cout << char(178);}
    cout << endl;
}
int main(){

    pattern();
    space();
    cout<<"\tWELCOME TO THE MOVIE MANAGEMENT SYSTEM"<<endl;
    pattern();
    cout << "Press any key to continue...";
    getch();
    mainmenu();
}