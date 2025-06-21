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
                mpointer[j] = new scifi(title, rating, day,month,year, 0, techlvl, aliens,FutureY);
                CurrentNumberOfMovies++;
            }
            else if(genrePointer == 2){
                mpointer[j] = new Action(title, rating, day,month,year, 0, VLvl, Stunts,NoOfFights);
                CurrentNumberOfMovies++;
            }
            else{
                mpointer[j] = new Animation(title, rating, day,month,year, 0, AnimeSyle,Musical,ageG);
                CurrentNumberOfMovies++;
            }
            cout<< "Movie" << j << endl;    
            cout << *mpointer[j];
            system("pause");
            system("cls");
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
    string releaseDate = "";
    string directorName = "";
    string nationality = "";
    string genre = "";
    
    int rating = 0;
    int experience = 0;
    int techlvl = 0;
    int FutureY = 0;
    int ageG = 0;
    int AnimeSyle = 0;
    int NoOfFights = 0;
    int genrePointer = 0;
    int directorChoice = 0;
    int day, month, year;
    
    bool aliens = false;
    bool Musical = false;
    bool Stunts = false;
    
    char VLvl = ' ';

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
    
    cout << "Select Director" << endl << "1. " << endl << "2. " << endl << "3. " << endl;
    cin >> directorChoice;
    if(directorChoice < 1 || directorChoice > 3 || d[directorChoice-1] == nullptr){
        directorChoice = 0; 
    }

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
        cin.ignore();
        if(ch == 'Y' || ch == 'y')
            aliens = true;
        
        cout << "Future Year: ";
        cin >> FutureY;

        mpointer[CurrentNumberOfMovies] = new scifi(title, rating, day,month,year, directorChoice, techlvl, aliens,FutureY);
        CurrentNumberOfMovies++;
    }
    else if(choice == 2){
        cout << "Select Violence Level" << endl;
        cout << "1. Domestic Violence" << endl << "2. Mafia Level" << endl << "3. Ultra Cool" << endl;
        int violenceChoice;
        cin >> violenceChoice;

        switch(violenceChoice) {
            case 1: VLvl = 'D'; break;
            case 2: VLvl = 'M'; break;
            case 3: VLvl = 'U'; break;
            default: VLvl = ' '; break;
        }

        cout << "Does it Have Stunts (Y/N)";
        char ch = getche();
        cin.ignore();

        if(ch == 'Y' || ch == 'y')
            Stunts = true;
        
        cout << "Number of Fight Scenes: ";
        cin >> NoOfFights;

        mpointer[CurrentNumberOfMovies] = new Action(title, rating, day,month,year, directorChoice, VLvl, Stunts,NoOfFights);
        CurrentNumberOfMovies++;
    }
    else{

        cout << "Animation Style" << endl << "1. Animation Style 1" << endl << "2. Animation Style 2" << endl << "3. Animation Style 3" << endl;
        cin >> AnimeSyle;

        cout << "Is it a Musical (Y/N)";
        char ch = getche();
        cin.ignore();

        if(ch == 'Y' || ch == 'y')
            Musical = true;
        
        cout << "Select Age Group "<< endl << "1. 5 Years" << endl << "2. 7 Years" << endl << "3. 18 Years" << endl;
        int ch1;
        cin >> ch1;
        if(ch1 == 1)
            ageG = 5;
        else if(ch1 == 2)
            ageG = 7; 
        else if(ch1 == 3)
            ageG = 18;
        else
            ageG = 404;
        mpointer[CurrentNumberOfMovies] = new Animation(title, rating, day,month,year, directorChoice, AnimeSyle,Musical,ageG);
        CurrentNumberOfMovies++;
    }
    bool MovieAdded = true;

    if(MovieAdded){
        fstream file("movies.txt" , ios::app);
            file << endl << "-------Movie Details-------" << endl;
            file << "Title           : " << title << endl;
            file << "Rating          : " << rating << endl;
            file << "Release Date    : " << day << "/" << month << "/" << year << endl;

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

void writeMoviesToNewFile(){
        fstream file("movies1.txt", ios::out | ios::trunc);
    for(int i = 0; i < CurrentNumberOfMovies; i++){
        file << *mpointer[i];
    }
        file.close();
}

bool AddNewDirector(){
    // Check if we have space for more directors
    int currentDirectorCount = 0;
    for(int i = 0; i < 3; i++){
        if(d[i] != nullptr) currentDirectorCount++;
    }
    
    if(currentDirectorCount >= 3){
        cout << "Maximum number of directors (3) already reached." << endl;
        return false;
    }
    
    string firstName, lastName, nationality;
    int experienceYears;
    
    system("cls");
    cout << "--------------ADDING NEW DIRECTOR--------------" << endl;
    
    cout << "Enter Director Details:" << endl;
    
    cout << "First Name: ";
    cin.ignore();
    getline(cin, firstName);
    
    cout << "Last Name: ";
    getline(cin, lastName);
    
    cout << "Nationality: ";
    getline(cin, nationality);
    
    cout << "Experience Years: ";
    cin >> experienceYears;
    
    // Find the next available slot
    int slot = 0;
    for(int i = 0; i < 3; i++){
        if(d[i] == nullptr){
            slot = i;
            break;
        }
    }
    
    // Create new director
    d[slot] = new Director(firstName, lastName, experienceYears, nationality);
    
    // Write to directors.txt file
    fstream file("directors.txt", ios::app);
    if(file.is_open()){
        file << endl << "-----------Director " << (slot + 1) << " Details-----------" << endl;
        file << "First Name      : " << firstName << endl;
        file << "Last Name       : " << lastName << endl;
        file << "Nationality     : " << nationality << endl;
        file << "Experience Years: " << experienceYears << " years" << endl;
        file.close();
    }
    
    cout << "Director " << firstName << " " << lastName << " added successfully!" << endl;
    return true;
}

void DisplayAllMovies(){
    system("cls");
    cout << "--------------ALL Movies--------------" << endl;
    
    bool found = false;
    for(int i = 0; i < CurrentNumberOfMovies; i++){
        if(mpointer[i] != nullptr){
            cout << "\nMovie " << (i + 1) << ":" << endl;
            cout << *mpointer[i] << endl;
            found = true;
        }
    }
    
    if(!found){
        cout << "No Movies found in the system." << endl;
    }
    
    cout << "\nPress any key to continue...";
    system("pause");
}