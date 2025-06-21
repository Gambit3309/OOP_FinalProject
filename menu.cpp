#include <iostream>
#include <cstdlib>
#include "menu.h"
#include "SA.h"
#include "global.h"

void mainmenu(){

    InputDirectorsFromFile();
    InputMoviesFromFile();
    int choice;

    system("cls");
    cout << "1. Add new movie with user-selected genre" << endl //completed
         << "2. Assign existing Director to a movie " << endl
         << "3. Display Movies" << endl// completed
         << "4. Search Movies" << endl  
         << "5. Sort Movies by year" << endl //completed
         << "0. Exit" << endl;
    
    cin >> choice;

    switch(choice){
    case 1:
        AddNewMovie();//completed
        system("pause");
        system("cls");
        mainmenu();
        break;
    case 2:
        RequestToAssignNewDirector();
        system("pause");
        system("cls");
        mainmenu();
        break;
    case 3:
        subMenuDisplay();//completed
        system("pause");
        system("cls");
        mainmenu();
        break;
    case 4:
        subMenuSearch();//incomplete
        system("pause");
        system("cls");
        mainmenu();
        break;
    case 5:
        SortMoviesByYear();
        system("pause");
        system("cls");
        mainmenu();
        break;
    case 0:
        DeleteAllPointers();
        exit(0);
    default:
        cout <<"ERROR: Invalid Option" << endl;
        system("pause");
        system("cls");
        mainmenu();
        break;   
    }
}

//completed subMenuDisplay
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
        DisplayAllMovies();
        system("pause");
        system("cls");
        subMenuDisplay();
        break;
    case 2:
        DisplayAllMoviesByGenre("Scifi");
        system("pause");
        system("cls");
        subMenuDisplay();
        break;
    case 3:
        DisplayAllMoviesByGenre("Animation");
        system("pause");
        system("cls");
        subMenuDisplay();
        break;
    case 4:
        DisplayAllMoviesByGenre("Action");
        system("pause");
        system("cls");
        subMenuDisplay();
        break;
    case 5:
        DisplayAllDirectors();
        system("pause");
        system("cls");
        subMenuDisplay();
        break;
    case 6:
        system("cls");
        cout << "1. " << d[0]->getName() << endl;
        cout << "2. " << d[1]->getName() << endl;
        cout << "3. " << d[2]->getName() << endl;
        int choice;
        cin >> choice;
        switch(choice){
            case 1:
                DisplayAllMoviesByDirector(d[0]->getName());
                system("pause");
                system("cls");
                subMenuDisplay();
                break;
            case 2:
                DisplayAllMoviesByDirector(d[1]->getName());
                system("pause");
                system("cls");
                subMenuDisplay();
                break;
            case 3:
                DisplayAllMoviesByDirector(d[2]->getName());
                system("pause");
                system("cls");
                subMenuDisplay();
                break;
            default:
                cout <<"ERROR: Invalid Option" << endl;
                system("pause");
                system("cls");
                subMenuDisplay();
                break;
        }
        break;
    case 0:
        mainmenu();
    default:
        cout <<"ERROR: Invalid Option" << endl;
        system("pause");
        system("cls");
        mainmenu();
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
        



        system("pause");
        system("cls");
        subMenuDisplay();
        break;
    case 2:
        



        system("pause");
        system("cls");
        subMenuDisplay();
        break;
    case 3:
        int year;
        cout << "Enter Year: " << endl;
        cin >> year;
        DisplayByYear(year);
        system("pause");
        system("cls");
        subMenuDisplay();
        break;
    case 4:



        system("pause");
        system("cls");
        subMenuDisplay();
        break;
    case 5:



        system("pause");
        system("cls");
        subMenuDisplay();
        break;
    case 6:



        system("pause");
        system("cls");
        subMenuDisplay();
        break;
    case 0:
        mainmenu();
    default:
        cout <<"ERROR: Invalid Option" << endl;
        system("pause");
        system("cls");
        subMenuDisplay();
        break;
    }
}