#include <iostream>
#include <cstdlib>
#include "menu.h"


void mainmenu(){
    int choice;

    system("cls");
    cout << "1. Add new movie with user-selected genre" << endl
         << "2. Assign existing Director to a movie " << endl
         << "3. Display Movies" << endl
         << "4. Search Movies" << endl  
         << "5. Sort Movies by year" << endl
         << "0. Exit" << endl;
    
    cin >> choice;

    switch(choice){
    case 1:
        
        break;
    case 2:

        break;
    case 3:
        subMenuDisplay();
        break;
    case 4:
        subMenuSearch();
        break;
    case 5:

        break;
    case 0:
        exit(0);
    default:
        break;   
    }
}

void subMenuDisplay(){
    system("cls");
    cout << "----------Display Menu----------" << endl;
    cout<< "1. Display all Movies\n"
        << "2. Display Sci-Fi Movies\n"
        << "3. Display Animation Movies\n"
        << "4. Display Action Movies\n"
        << "5. Display Directors\n"
        << "6. Display Movies by Specific Director\n"
        << "0. <- Go Back";

    int choice;
    cin >> choice;
    
    switch(choice){
    case 1:
        
        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    case 6:

        break;
    case 0:
        mainmenu();
    default:
        break;
    }

}

void subMenuSearch(){
    system("cls");
    cout << "----------Search Menu----------" << endl;
    cout<< "1. Search and Display Movies by Specific Director\n"
        << "2. Search and Display Movies by Certain Score\n"
        << "3. Search and Display Movies by Year\n"
        << "4. Search and Display Movies by Title\n"
        << "5. Search and Display Movies by Rating\n"
        << "6. Search and Display Movies by Title and Ranking\n"
        << "0. <- Go Back";
        
    
    int choice;
    cin >> choice;
    
    switch(choice){
    case 1:
        
        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    case 6:

        break;
    case 0:
        mainmenu();
    default:
        break;
    }
}