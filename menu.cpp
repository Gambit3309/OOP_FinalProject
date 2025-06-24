#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "menu.h"
#include "SA.h"
#include "global.h"

void mainmenu(){

    InputDirectorsFromFile();
    InputMoviesFromFile();
    
    while(true){
        int choice;
    
    system("cls");
    cout << "1. Send Request Admin" << endl //completed
         << "2. Display Movies" << endl// completed
         << "3. Search Movies" << endl  //completed
         << "4. Sort Movies by year" << endl //completed
         << "5. Request to Remove a Movie" << endl
         << "6. Admin Console" << endl
         << "0. Exit" << endl;
    
    cin >> choice;
    
    switch(choice){
    case 1:
        cout << "1. Request to Add new movie with user-selected genre" << endl //completed
             << "2. Request to Remove a Movie" << endl
             << "3. Request to Assign existing Director to a movie" << endl;
        
        int temp;
        cin >> temp;
        switch(temp){
            case 1:
                RequestToAddNewMovie();
                break;
            case 2:
                RequestToRemoveMovie();
                break;
            case 3:
                RequestToAssignNewDirector();
                break;
        }
        system("pause");
        break;
    case 2:
        subMenuDisplay();//completed
        system("pause");
        break;
    case 3:
        subMenuSearch();//incomplete
        system("pause");
        break;
    case 4:
        SortMoviesByYear();
        system("pause");
        break;
    case 5:
        RequestToRemoveMovie();
        system("pause");
        break;
    case 6:
        AdminConsole();
        system("pause");
        break;
    case 0:
        DeleteAllPointers();
        exit(0);
    default:
        cout <<"ERROR: Invalid Option" << endl;
        system("pause");
        break;   
    }
}
}
//completed subMenuDisplay
void subMenuDisplay(){
    int i = 0;
    while(i == 0){
    system("cls");
    cout << "----------Display Menu----------" << endl;
    cout<< "1. Display all Movies\n"
        << "2. Display Sci-Fi Movies\n"
        << "3. Display Animation Movies\n"
        << "4. Display Action Movies\n"
        << "5. Display Directors\n"
        << "6. Display Movies by Specific Director\n"
        << "7. <- Go Back" << endl;

    int choice;
    cin >> choice;
    if(cin.fail()){
        cout << "ERROR: Invalid Option" << endl;
        system("pause");
    }
    switch(choice){
    case 1:
        DisplayAllMovies();
        system("pause");
        break;
    case 2:
        DisplayAllMoviesByGenre("Scifi");
        system("pause");
        break;
    case 3:
        DisplayAllMoviesByGenre("Animation");
        system("pause");
        break;
    case 4:
        DisplayAllMoviesByGenre("Action");
        system("pause");
        break;
    case 5:
        DisplayAllDirectors();
        system("pause");
        break;
    case 6:
        system("cls");
        cout << "1. " << d[0]->getName() << endl;
        cout << "2. " << d[1]->getName() << endl;
        cout << "3. " << d[2]->getName() << endl;
        int choice2;
        cin >> choice2;
        if(cin.fail()){
            cout << "ERROR: Invalid Option" << endl;
            system("pause");
        }
        switch(choice2){
            case 1:
                DisplayByDirector(d[0]->getName());
                system("pause");
                break;
            case 2:
                DisplayByDirector(d[1]->getName());
                system("pause");
                break;
            case 3:
                DisplayByDirector(d[2]->getName());
                system("pause");
                break;
            default:
                cout <<"ERROR: Invalid Option" << endl;
                system("pause");
                break;
        }
    case 7:
        i = 1;
        break;
    default:
        cout <<"ERROR: Invalid Option" << endl;
        i = 1;
        break;
    }
    }
}

void subMenuSearch(){
    int i = 0;
    while(i == 0){
    system("cls");
    cout << "----------Search Menu----------" << endl;
    cout<< "1. Search and Display Movies by Specific Director\n"//DONE
        << "2. Search and Display Movies by Certain Score\n"//DONE
        << "3. Search and Display Movies by Year\n"//DONE
        << "4. Search and Display Movies by Title\n"//DONE
        << "5. Search and Display Movies by Rating\n"//Done
        << "6. Search and Display Movies by Title and Ranking\n"
        << "7. <- Go Back" << endl;
        
    
    int choice;
    cin >> choice;
    if(cin.fail()){
        cout << "ERROR: Invalid Option" << endl;
        system("pause");
        i = 1;
    }
    
    switch(choice){
    case 1:
        system("cls");
        cout << "1. " << d[0]->getName() << endl;
        cout << "2. " << d[1]->getName() << endl;
        cout << "3. " << d[2]->getName() << endl;
        int choice2;
        cin >> choice2;
        if(cin.fail())
            cout << "ERROR: Invalid Option" << endl;
        else{
            switch(choice2){
                case 1:
                    DisplayByDirector(d[0]->getName());
                    system("pause");
                    break;
                case 2:
                    DisplayByDirector(d[1]->getName());
                    system("pause");
                    break;
                case 3:
                    DisplayByDirector(d[2]->getName());
                    system("pause");
                    break;
                default:
                    cout <<"ERROR: Invalid Option" << endl;
                    system("pause");
                    break;
            }
        }
        system("pause");
        break;
    case 2:
        cout << "Enter Rating of Movie: ";
        int r;
        cin >> r;
        if(cin.fail())
            cout << "ERROR: Invalid Option" << endl;
        else
            DisplayByScore(r);
        system("pause");
        break;
    case 3:{
        int year = 0;
        cout << "Enter Year: " << endl;
        cin >> year;
        if(cin.fail())
            cout << "ERROR: Invalid Option" << endl;
        else
            DisplayByYear(year);
        system("pause");
        break;
    }
    case 4:{
        cout << "Would you like" << endl;
        cout << "1. Prefix Search " << endl << "2. Exact Match" << endl;
        int c;
        cin >> c;
        string title = "";
        if(c == 1){
            cout << "Enter Alphabet: ";
            char ch;
            ch = getche();
            DisplayByALphabet(ch);
        }
        else if(c == 2){
        cout << "Enter Title of the Movie: ";
        cin.ignore();
        getline(cin,title);
        DisplayByTitle(title);
        }
        else 
            cout << "ERROR: Invalid Option" << endl;
        system("pause");
        break;
    }
    case 5:{
        cout << "Enter Rating of Movie: ";
        int rating;
        cin >> r;
        if(cin.fail())
            cout << "ERROR: Invalid Option" << endl;
        else
            DisplayByRating(r);
        system("pause");
        break;
    }
    case 6:{
        cout << "Enter Rating of Movie: ";
        int r;
        cin >> r;
        if(cin.fail()){
            cout << "ERROR: Invalid Option" << endl;
            system("pause");
        }
        cout << "Enter Alphabet: ";
        char ch;
        ch = getche();
        DisplayByTitleAndRating(ch,r);
    }
        system("pause");
        break;
    case 7:
        i = 1;
        break;
    default:
        cout <<"ERROR: Invalid Option" << endl;
        i = 1;
        break;
    }
}
}