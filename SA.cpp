#include <iostream>
#include "SA.h"
#include "MovieBaseClass.h"
#include <fstream>
#include <conio.h>
#include <string>
#include "Scifi.h"
#include "Action.h"
#include "Animation.h"
#include "global.h"

using namespace std;



void InputMoviesFromFile(){

    //Movie* mpointer[50];

    
 

    fstream file("movies.txt", ios::in);

    if(!file.is_open()){
        cout << "Error could not access Movies.txt" << endl;
    }
    else{
        string line;
        file.seekg(0, ios::beg);
        for(int j = 0; j < MaxNumberOfMovies-5; j++){
            string title = "";
            string releaseDate = "";
            string directorName = "";
            string nationality = "";
            string genre = "";
            string errorchecking = "Error";

            int experience = 0;
            int rating = 0;
            int techlvl = 0;
            int FutureY = 0;
            int AnimeSyle = 0;
            int ageG = 0;
            int NoOfFights = 0;
            int genrePointer = 0;
            int day, month, year;
            
            bool aliens = false;
            bool Musical = false;
            bool Stunts = false;

            char VLvl = ' ';



            for(int i = 0; i <= 8; i ++){
                getline(file,line);
            try{
                line = line.substr(18);

                switch(i){
                    case 1:    
                        title = line;
                        break;
                    case 2:    
                        rating = stoi(line);
                        break;
                    case 3:    
                        releaseDate = line.substr(0,2);
                        day = stoi(releaseDate);
                        releaseDate = line.substr(3,2);
                        month = stoi(releaseDate);
                        releaseDate = line.substr(6,4);
                        year = stoi(releaseDate);
                        break;
                    case 4:    
                        genre = line;
                        if(genre == "Scifi"){
                            genrePointer = 1;
                        }
                        else if(genre == "Action"){
                            genrePointer = 2;
                        }
                        else
                            genrePointer = 3;
                        break;
                    case 5:
                        if(genrePointer == 1){
                            errorchecking = line;    
                            techlvl = stoi(line);
                        }
                        else if(genrePointer == 3)    
                            AnimeSyle = stoi(line);
                        else if(genrePointer == 2)    
                            VLvl = line[0];
                        break;
                    case 6:
                        if (genrePointer == 1) // Scifi
                            aliens = (line == "Yes" || line == "yes");
                        else if (genrePointer == 2) // Action
                            Stunts = (line == "Yes" || line == "yes");
                        else if (genrePointer == 3) // Animation
                            Musical = (line == "Yes" || line == "yes");
                        break;
                    case 7:
                        if (genrePointer == 1) // Scifi
                            FutureY = stoi(line);
                        else if (genrePointer == 2) // Action
                            NoOfFights = stoi(line);
                        else if (genrePointer == 3) // Animation
                            ageG = stoi(line);
                        break;
                    default:
                        break;
                    }
            }
                catch(const exception& e)
                {
                    continue;
                }
                
            }
                // cout << "Movie" << j << endl;
                // cout << "Title: " << title << endl;
                // cout << "Rating: " << rating << endl;
                // cout << "Release Date: " << day << "/" << month << "/" << year << endl;
                // cout << "Genre: " << genre << endl;
                cout << "Tech Level: " << techlvl << endl;
                // cout << "Aliens: " << (aliens ? "Yes" : "No") << endl;
                // cout << "Future Year: " << FutureY << endl;
                 cout << "Animation Style: " << AnimeSyle << endl;
                // cout << "Musical: " << (Musical ? "Yes" : "No") << endl;
                 cout << "Age Group: " << ageG << endl;
                 cout << "Violence Level: " << VLvl << endl;
                // cout << "Stunts: " << (Stunts ? "Yes" : "No") << endl;
                 cout << "Fight Scenes: " << NoOfFights << endl;
                // cout << "Genre Pointer: " << genrePointer << endl;
                cout << "Error Checking Variiable: " << errorchecking<< endl << endl;
                //system("pause");
            if(genrePointer == 1){
                mpointer[j] = new scifi(title, rating, day,month,year, techlvl, aliens,FutureY);

            }
            else if(genrePointer == 2){
                mpointer[j] = new Action(title, rating, day,month,year, VLvl, Stunts,NoOfFights);
            }
            else{
                mpointer[j] = new Animation(title, rating, day,month,year,AnimeSyle,Musical,ageG);
            }
            cout<< "Movie" << j << endl;    
            cout << *mpointer[j];
            system("pause");
            system("cls");
            CurrentNumberOfMovies++;
        }
        file.close();
        
        
    }
}
void InputDirectorsFromFile(){
    fstream file("directors.txt", ios::in);

    if(!file.is_open()){
        cout << "Error could not access director.txt" << endl;
    }
    else{
        string fn,ln, nationality;
        int expY;
        string line;
        file.seekg(0,ios::beg);
        for(int i = 0; i < 3; i++){
            for(int i = 0; i < 6; i++){
                getline(file, line);
                try{
                    line = line.substr(18);
                    switch(i){
                        case 1:
                            fn = line;
                            break;
                        case 2:    
                            ln = line;
                            break;
                        case 3:    
                            nationality = line;
                            break;
                        case 4:    
                            expY = stoi(line);
                            break;
                        case 5:
                            break;
                    }
                }
                catch(const exception&){
                    continue;
                }
            }
            d[i] = new Director(fn, ln, expY, nationality);
        }
    }
    file.close();
}

void DeleteAllPointers(){
    for(int i = 0; i < 50; i++){
            delete mpointer[i];
        }
    for(int i = 0; i < 3; i++){
        delete d[i];
    }
}

bool AddNewMovie(){

    if(CurrentNumberOfMovies == MaxNumberOfMovies){
        return false;
    }
    string title = "";
    int rating = 0;
    string releaseDate = "";
    string directorName = "";
    int experience = 0;
    string nationality = "";
    string genre = "";
    int techlvl = 0;
    bool aliens = false;
    int FutureY = 0;

    int AnimeSyle = 0;
    bool Musical = false;
    int ageG = 0;
    
    char VLvl = ' ';
    bool Stunts = false;
    int NoOfFights = 0;
    
    int genrePointer = 0;
    
    int day, month, year;

    system("cls");

    cout << "--------------ADDING NEW MOVIE--------------" << endl;

    cout << "Enter" << endl;
    cout << "Movie Title: ";

    cin.ignore();
    getline(cin, title);

    cout << "Rating: ";

    cin >> rating;

    cout << "Release Date in Numeric for dd/mm/yyyy " << endl;
    cout << "Day: " << endl;
    cin >> day;

    cout << "Month: " << endl;
    cin >> month;

    cout << "Year: " << endl;
    cin >> year;

    cout << "Select Genre of the Movie you would like to add" << endl;
    cout << "1. Science Fiction" << endl
         << "2. Action" << endl
         << "3. Animation" << endl;
    
    int choice;
    cin >> choice;

    if(choice == 1){
        cout << "Select Tech Level" << endl << "1. Tech Level 1" << endl << "2. Tech Level 2" << endl << "3. Tech Level 3" << endl;
        cin >> techlvl;

        cout << "Does it Have Aliens (Y/N)";
        char ch = getche();
        if(ch == 'Y' || ch == 'y')
            aliens = true;
        
        cout << "Future Year: ";
        cin >> FutureY;

        mpointer[CurrentNumberOfMovies-1] = new scifi(title, rating, day,month,year, techlvl, aliens,FutureY);
    }
    else if(choice == 2){
        cout << "Select Violence Level" << endl;
        cout << "1. Domestic Violence" << endl << "2. Mafia Level" << endl << "3. Ultra Cool" << endl;
        cin >> VLvl;

        cout << "Does it Have Stunts (Y/N)";
        char ch = getche();

        if(ch == 'Y' || ch == 'y')
            Stunts = true;
        
        cout << "Number of Fight Scenes: ";
        cin >> NoOfFights;

        mpointer[CurrentNumberOfMovies-1] = new Action(title, rating, day,month,year, VLvl, Stunts,NoOfFights);
    }
    else{

        cout << "Animation Style" << endl << "1. Animation Style 1" << endl << "2. Animation Style 2" << endl << "3. Animation Style 3" << endl;
        cin >> AnimeSyle;

        cout << "Is it a Musical (Y/N)";
        char ch = getche();

        if(ch == 'Y' || ch == 'y')
            Musical = true;
        
        cout << "Select Age Group "<< endl << "1. 5 Years" << endl << "2. 7 Years" << endl << "3. 18 Years" << endl;
        int ch1;
        if(ch1 == 1)
            ageG = 5;
        else if(ch1 = 8)
            ageG = 8;
        else   
            ageG = 18;
        mpointer[CurrentNumberOfMovies-1] = new Animation(title, rating, day,month,year,AnimeSyle,Musical,ageG);

    }
    bool MovieAdded = true;

    if(MovieAdded){
        fstream file("movies.txt" , ios::app);
            file << endl << "-------Movie Details-------" << endl;
            file << "Title           : " << title << endl;
            file << "Rating          : " << rating << endl;
            file << "Release Date    : " << releaseDate << endl;

        if(choice == 1){
            file << "Genre           : " << "Scifi" << endl;
            file << "Tech Level      : " << techlvl << endl;
            file << "Aliens          : " << (aliens? "Yes":"No") << endl;
            file << "Future Year     : " << FutureY << endl;
        }
        else if(choice == 2){
            file << "Genre           : " << "Action" << endl;
            file << "Violence Level  : " << VLvl << endl;
            file << "Stunts          : " << (Stunts? "Yes":"No") << endl;
            file << "Fight Scenes    : " << NoOfFights << endl;
        }
        else if(choice == 3){
            file << "Genre           : " << "Animation" << endl;
            file << "Animation Style : " << AnimeSyle << endl;
            file << "Musical         : " << (Musical? "Yes": "No") << endl;
            file << "Age Group       : " << ageG << endl;
        }
        file.close();
    }


    return MovieAdded;
}