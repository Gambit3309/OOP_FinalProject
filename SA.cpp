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

    string title = "";
    int rating = 0;
    string releaseDate = "";
    string directorName = "";
    int experience = 0;
    string nationality = "";
    string genre = "";
    int techLevel = 0;
    bool aliens = false;
    int futureYear = 0;

    int AnimationStyle = 0;
    bool Musical = false;
    int AgeGroup = 0;

    char ViolenceLevel = ' ';
    bool Stunts = false;
    int Fightscenes = 0;

    int genrePointer = 0;

 

    fstream file("movies.txt", ios::in);

    if(!file.is_open()){
        cout << "Error could not access Movies.txt" << endl;
    }
    else{
        string line;
        file.seekg(0, ios::beg);
        for(int j = 0; j < MaxNumberOfMovies-5; j++){
            for(int i = 0; i <= 8; i ++){
                getline(file,line);
                try
                {
                    
                    line = line.substr(18);

                    switch(i){
                case 1:    
                    title = line;
                    break;
                case 2:    
                    rating = stoi(line);
                    break;
                case 3:    
                    releaseDate = line;
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
                    if(genrePointer == 1)    
                        techLevel = stoi(line);
                    else if(genrePointer == 3)    
                        AnimationStyle = stoi(line);
                    else if(genrePointer == 2)    
                        ViolenceLevel = line[0];
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
                        futureYear = stoi(line);
                    else if (genrePointer == 2) // Action
                        Fightscenes = stoi(line);
                    else if (genrePointer == 3) // Animation
                        AgeGroup = stoi(line);
                    break;
                case 8:
                    //for the empty line seperating 2 movies
                    break;
                }

                /*cout << "Title: " << title << endl;
                cout << "Rating: " << rating << endl;
                cout << "Release Date: " << releaseDate << endl;
                cout << "Genre: " << genre << endl;
                cout << "Tech Level: " << techLevel << endl;
                cout << "Aliens: " << (aliens ? "Yes" : "No") << endl;
                cout << "Future Year: " << futureYear << endl;
                cout << "Animation Style: " << AnimationStyle << endl;
                cout << "Musical: " << (Musical ? "Yes" : "No") << endl;
                cout << "Age Group: " << AgeGroup << endl;
                cout << "Violence Level: " << ViolenceLevel << endl;
                cout << "Stunts: " << (Stunts ? "Yes" : "No") << endl;
                cout << "Fight Scenes: " << Fightscenes << endl;
                cout << "Genre Pointer: " << genrePointer << endl;*/
            }
                catch(const exception& e)
                {
                    continue;
                }
                
            }
            if(genrePointer == 1){
                mpointer[j] = new scifi(title, rating, 1,1,2020, techLevel, aliens,futureYear);

            }
            else if(genrePointer == 2){
                mpointer[j] = new Action(title, rating, 1,1,2020, ViolenceLevel, Stunts,Fightscenes);
            }
            else{
                mpointer[j] = new Animation(title, rating, 1,1,2020,AnimationStyle,Musical,AgeGroup);
            }
            
            CurrentNumberOfMovies++;
        }
        file.close();
        system("cls");
        for(int j = 0; j < 50; j++){    
            mpointer[j]->displayDetails();
        }
          
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
    int techLevel = 0;
    bool aliens = false;
    int futureYear = 0;

    int AnimationStyle = 0;
    bool Musical = false;
    int AgeGroup = 0;
    
    char ViolenceLevel = ' ';
    bool Stunts = false;
    int Fightscenes = 0;
    
    int genrePointer = 0;
    
    int day, month, year;

    system("cls");

    cout << "--------------ADDING NEW MOVIE--------------" << endl;

    cout << "Enter" << endl;
    cout << "Movie Title: ";

    cin.ignore();
    getline(cin,title);

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
        cin >> techLevel;

        cout << "Does it Have Aliens (Y/N)";
        char ch = getche();
        if(ch == 'Y' || ch == 'y')
            aliens = true;
        
        cout << "Future Year: ";
        cin >> futureYear;

        mpointer[CurrentNumberOfMovies-1] = new scifi(title, rating, day,month,year, techLevel, aliens,futureYear);
    }
    else if(choice == 2){
        cout << "Select Violence Level" << endl;
        cout << "1. Domestic Violence" << endl << "2. Mafia Level" << endl << "3. Ultra Cool" << endl;
        cin >> ViolenceLevel;

        cout << "Does it Have Stunts (Y/N)";
        char ch = getche();

        if(ch == 'Y' || ch == 'y')
            Stunts = true;
        
        cout << "Number of Fight Scenes: ";
        cin >> Fightscenes;

        mpointer[CurrentNumberOfMovies-1] = new Action(title, rating, day,month,year, ViolenceLevel, Stunts,Fightscenes);
    }
    else{

        cout << "Animation Style" << endl << "1. Animation Style 1" << endl << "2. Animation Style 2" << endl << "3. Animation Style 3" << endl;
        cin >> AnimationStyle;

        cout << "Is it a Musical (Y/N)";
        char ch = getche();

        if(ch == 'Y' || ch == 'y')
            Musical = true;
        
        cout << "Select Age Group "<< endl << "1. 5 Years" << endl << "2. 7 Years" << endl << "3. 18 Years" << endl;
        int ch1;
        if(ch1 == 1)
            AgeGroup = 5;
        else if(ch1 = 8)
            AgeGroup = 8;
        else   
            AgeGroup = 18;
        mpointer[CurrentNumberOfMovies-1] = new Animation(title, rating, day,month,year,AnimationStyle,Musical,AgeGroup);

    }
    bool MovieAdded = true;

    if(MovieAdded){
        fstream file("movies.txt" , ios::app);

        if(choice == 1){

            file << endl << "-------Movie Details-------" << endl;
            file << "Title           : " << title << endl;
            file << "Rating          : " << rating << endl;
            file << "Release Date    : " << releaseDate << endl;
            file << "Genre           : " << "Scifi" << endl;
            file << "Tech Level      : " << techLevel << endl;
            file << "Aliens          : " << (aliens? "Yes":"No") << endl;
            file << "Future Year     : " << futureYear << endl;
        }
        else if(choice == 2){

            file <<  endl << "-------Movie Details-------" << endl;
            file << "Title           : " << title << endl;
            file << "Rating          : " << rating << endl;
            file << "Release Date    : " << releaseDate << endl;
            file << "Genre           : " << "Action" << endl;
            file << "Violence Level  : " << ViolenceLevel << endl;
            file << "Stunts          : " << (Stunts? "Yes":"No") << endl;
            file << "Fight Scenes    : " << Fightscenes << endl;
        }
        else if(choice == 3){
            
            file <<  endl << "-------Movie Details-------" << endl;
            file << "Title           : " << title << endl;
            file << "Rating          : " << rating << endl;
            file << "Release Date    : " << releaseDate << endl;
            file << "Genre           : " << "Animation" << endl;
            file << "Animation Style : " << AnimationStyle << endl;
            file << "Musical         : " << (Musical? "Yes": "No") << endl;
            file << "Age Group       : " << AgeGroup << endl;
        }
        file.close();
    }


    return MovieAdded;
}