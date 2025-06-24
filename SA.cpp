#include <iostream>
#include "SA.h"
#include "MovieBaseClass.h"
#include <fstream>
#include <conio.h>
#include <string>
#include <cctype>
#include "Scifi.h"
#include "Action.h"
#include "Animation.h"
#include "menu.h"
#include "global.h"

using namespace std;



void InputMoviesFromFile(){

    ifstream file("movies.txt");

    if(!file.is_open()){
        cout << "Error could not access Movies.txt" << endl;
    }
    else{
        string line;
        string skip;
        //file.seekg(0, ios::beg);
        getline(file,skip);//skips the first line
        for(int j = 0; j < MaxNumberOfMovies; j++){

            Variables v;
            
            for(int i = 0; i <= 8; i ++){
                getline(file,line);
                try{
                    line = line.substr(18); 

                    switch(i){
                        case 1:    
                            v.title = line;
                            break;
                        case 2:    
                            v.rating = stoi(line);
                            break;
                        case 3:    
                            v.releaseDate = line.substr(0,2);
                            v.day = stoi(v.releaseDate);
                            v.releaseDate = line.substr(3,2);
                            v.month = stoi(v.releaseDate);
                            v.releaseDate = line.substr(6,4);
                            v.year = stoi(v.releaseDate);
                            break;
                        case 4:    
                            v.genre = line;
                            if(v.genre == "Scifi"){
                                v.genrePointer = 1;
                            }
                            else if(v.genre == "Action"){
                                v.genrePointer = 2;
                            }
                            else
                                v.genrePointer = 3;
                            break;
                        case 5:
                            if(v.genrePointer == 1)    
                                v.techlvl = stoi(line);
                            else if(v.genrePointer == 3)    
                                v.AnimeSyle = stoi(line);
                            else if(v.genrePointer == 2)    
                                v.VLvl = line[0];
                            break;
                        case 6:
                            if (v.genrePointer == 1) // Scifi
                                v.aliens = (line == "Yes" || line == "yes");
                            else if (v.genrePointer == 2) // Action
                                v.Stunts = (line == "Yes" || line == "yes");
                            else if (v.genrePointer == 3) // Animation
                                v.Musical = (line == "Yes" || line == "yes");
                            break;
                        case 7:
                            if (v.genrePointer == 1) // Scifi
                                v.FutureY = stoi(line);
                            else if (v.genrePointer == 2) // Action
                                v.NoOfFights = stoi(line);
                            else if (v.genrePointer == 3) // Animation
                                v.ageG = stoi(line);
                            break;
                        case 8:
                            if(line == "Steven Spielberg")
                                v.directorChoice = 1;
                            else if(line == "Martin Scorsese")
                                v.directorChoice = 2;
                            else if(line == "Clint Eastwood")
                                v.directorChoice = 3;
                            else
                                v.directorChoice = 1;
                            break;
                        default:
                            break;
                        }
                }
                catch(const exception& e){
                    continue;
                }
            }

            if(v.genrePointer == 1){
                mpointer[CurrentNumberOfMovies++] = new scifi(v.title, v.rating, v.day,v.month,v.year, v.directorChoice, v.techlvl, v.aliens,v.FutureY);
            }
            else if(v.genrePointer == 2){
                mpointer[CurrentNumberOfMovies++] = new Action(v.title, v.rating, v.day,v.month,v.year, v.directorChoice, v.VLvl, v.Stunts,v.NoOfFights);
                
            }
            else if(v.genrePointer == 3){
                mpointer[CurrentNumberOfMovies++] = new Animation(v.title, v.rating, v.day,v.month,v.year, v.directorChoice, v.AnimeSyle,v.Musical,v.ageG);
                
            }
            else
                continue;
        }
    }
    file.close();
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
            for(int i = 0; i < 5; i++){
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
    for(int i = 0; i < MaxNumberOfMovies; i++){
            delete mpointer[i];
        }
    for(int i = 0; i < 3; i++){
        delete d[i];
    }
}

void RequestToAddNewMovie(){
    cout << "Enter Movie Title: ";
    string t;
    cin.ignore();
    getline(cin,t);
    int Index = SearchTitle(t);
    if(Index != 3309){
        cout << "Movie Already Exits" << endl;
        return;
    }

    cout << "Select Genre of the Movie you would like to add" << endl;
    cout << "1. Science Fiction" << endl
         << "2. Action" << endl
         << "3. Animation" << endl;
    
    int choice;
    cin >> choice;
    if(cin.fail()){
        cout << "ERROR: Invalid Input" << endl;
        return;
    }
    switch(choice){
        case 1:{
            scifi* s = new scifi();

            cin >> *s;

            fstream file("AddNewMovie.txt", ios::app);

            file << *s;

            file.close();

            fstream file1("UserRequest.txt", ios::app);

            if(file1.is_open()){
                file1 << "User would like to add a Movie" << endl;
                file1 << "Title: " << s->getTitle() << endl;
                cout << "Your Request has been registered\nWaiting for admin" << endl;
            }
            else
                cout << "Error in registering request" << endl;
            
            file1.close();
            
            delete s;
        }
            break;
        case 2:{
            Action* s = new Action();

            cin >> *s;

            fstream file("AddNewMovie.txt", ios::app);

            file << *s;

            file.close();

            fstream file1("UserRequest.txt", ios::app);

            if(file1.is_open()){
                file1 << "User would like to remove a Movie" << endl;
                file1 << "Title: " << s->getTitle();
                cout << "Your Request has been registered\nWaiting for admin" << endl;
            }
            else
                cout << "Error in registering request" << endl;
            
            file1.close();
            delete s;
        }
            break;
        case 3:{
            Animation* s = new Animation();

            cin >> *s;

            fstream file("AddNewMovie.txt", ios::app);

            file << *s;

            file.close();

            fstream file1("UserRequest.txt", ios::app);

            if(file1.is_open()){
                file1 << "User would like to remove a Movie" << endl;
                file1 << "Title: " << s->getTitle();
                cout << "Your Request has been registered\nWaiting for admin" << endl;
            }
            else
                cout << "Error in registering request" << endl;
            
            file1.close();
            delete s;
        }
            break;
        default:{
            cout << "ERROR: Invalid Input" << endl;
            return;
        }
    }
}

void writeMoviesToNewFile(){
        fstream file("movies1.txt", ios::out | ios::trunc);
    for(int i = 0; i < CurrentNumberOfMovies; i++){
        file << *mpointer[i];
    }
        file.close();
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
}

void DisplayAllDirectors(){
    system("cls");
    cout << "--------------ALL Directors--------------" << endl;
    
    bool found = false;
    for(int i = 0; i < 3; i++){
        if(d[i] != nullptr){
            cout << "Director " << (i + 1) << ":" << endl;
            cout << *d[i] << endl;
            found = true;
        }
    }
    
    if(!found){
        cout << "No Directors found in the system." << endl;
    }
}

void DisplayAllMoviesByGenre(string genre){
    bool found = false;
    for(int i = 0; i < CurrentNumberOfMovies; i++){
        if(mpointer[i] != nullptr){
            if(mpointer[i]->getgenre() == genre){
                cout << "\nMovie " << (i + 1) << ":" << endl;
                cout << *mpointer[i] << endl;
                found = true;
            }
        }
    }
    if(!found){
        cout << "No Movies found in the system." << endl;
    }
}

void DisplayAllMoviesByRating(int rating){
    bool found = false;
    for(int i = 0; i < CurrentNumberOfMovies; i++){
        if(mpointer[i] != nullptr){
            if(mpointer[i]->calculateScore() == rating){
                cout << "\nMovie " << (i + 1) << ":" << endl;
                cout << *mpointer[i] << endl;
                found = true;
            }
        }
    }
    if(!found){
        cout << "No Movies found in the system." << endl;
    }
}

void DisplayByDirector(string director){
    director = StringToLowercase(director);
    bool found = false;
    for(int i = 0; i < CurrentNumberOfMovies; i++){
        if(mpointer[i] != nullptr){
            string MDirector = StringToLowercase(mpointer[i]->getDirectorName());
            if(MDirector == director){
                cout << "\nMovie " << (i + 1) << ":" << endl;
                cout << *mpointer[i] << endl;
                found = true;
            }
        }
    }
    if(!found){
        cout << "No Movies found in the system." << endl;
    }
}

void DisplayByYear(int year){
    int size = CurrentNumberOfMovies;
    for(int i = 0; i < size; i++){
        int MovieYear;
        string releaseDate = mpointer[i]->getReleaseDate();
        int last_slash = releaseDate.find_last_of('/');
        releaseDate = releaseDate.substr(last_slash + 1);
        MovieYear = stoi(releaseDate);
        if(MovieYear == year)
            cout << *mpointer[i];
    }
}

void DisplayByTitle(string title){
    int Index = SearchTitle(title);
    if(Index != 3309)
        cout << *mpointer[Index];
    else
        cout << "No Moive Found" << endl;
}

int SearchTitle(string title){
        string MovieTitle;
        
        title = StringToLowercase(title);

        for(int i = 0; i < CurrentNumberOfMovies; i++){
            MovieTitle = StringToLowercase(mpointer[i]->getTitle());
            if(MovieTitle == title)
                return i;
        }
        return 3309;
}


void SortMoviesByYear(){
    int size = CurrentNumberOfMovies;
    int MovieYear[size];
    int MovieIndex[size];

    for(int i = 0; i < size; i++){
        string releaseDate = mpointer[i]->getReleaseDate();
        int last_slash = releaseDate.find_last_of('/');
        releaseDate = releaseDate.substr(last_slash + 1);
        MovieYear[i] = stoi(releaseDate);
        MovieIndex[i] = i;
    }

    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1 - i; j++){
            if(MovieYear[j] > MovieYear[j + 1]){
                swap(MovieYear[j], MovieYear[j + 1]);
                swap(MovieIndex[j], MovieIndex[j + 1]);
            }
        }
    }

    for(int i = 0; i < size; i++){
        cout << *mpointer[MovieIndex[i]];
    }
}

void RequestToAssignNewDirector(){

    string title;
    int directorChoice;
    
    cout << "Enter the Title of the movie for which you would like to assign an existing Director to: ";
    
    cin.ignore();
    getline(cin, title);

    cout << "Select Director" << endl << "1. Steven Spielberg" << endl << "2. Martin Scorsese" << endl << "3. Clint Eastwood" << endl;
    cin >> directorChoice;

    if(directorChoice < 1 || directorChoice > 3 || d[directorChoice - 1] == nullptr || directorChoice == 99){
        directorChoice = 0; 
    }

    if(directorChoice == 99){
        system("cls");
        int dc;
        cout << "Select Director" << endl << "1. Steven Spielberg" << endl << "2. Martin Scorsese" << endl << "3. Clint Eastwood" << endl;
        cin >> dc;


    }
    int index = SearchTitle(title);
    if( index != 3309){
        fstream file("UserRequest.txt", ios::app);
        if(file.is_open()){
            file << "User would like to Assign " << d[directorChoice - 1]->getName() << " as Director of " << title << endl;
            cout << "Your Request has been registered\nWaiting for admin" << endl;
        }
        else 
            cout << "Error in registering request" << endl;
    }
    else
        cout << "Movie does not Exist or incorrect title was entered" << endl;
}

string StringToLowercase(string s){
    for(int i = 0; s[i] != '\0'; i++){
        s[i] = tolower(s[i]);
    }
    return s;
}

void DisplayByRating(int rating){
    int MovieIndex[CurrentNumberOfMovies];
    int MovieRating[CurrentNumberOfMovies];
    int tot_M_toSort = 0;

    bool found = false;
    for(int i = 0; i < CurrentNumberOfMovies; i++){
        if(mpointer[i]->getRating() >= rating){
            MovieIndex[tot_M_toSort] = i;
            MovieRating[tot_M_toSort] = mpointer[i]->getRating();
            tot_M_toSort++;
            found = true;
        }
    }
    
    for(int i = 0; i < tot_M_toSort - 1; i++){
        for(int j = 0; j < tot_M_toSort - 1 - i; j++){
            if(MovieRating[j] < MovieRating[j + 1]){
                swap(MovieRating[j] , MovieRating[j + 1]);
                swap(MovieIndex[j] , MovieIndex[j + 1]);
            }
        }
    }
    system("cls");
    for(int i = 0; i < tot_M_toSort; i++){
        cout << *mpointer[MovieIndex[i]];
    }

    if(!found)
        cout << "No Movies Found" << endl;
}

void DisplayByScore(int score){
    int MovieIndex[CurrentNumberOfMovies];
    int MovieRating[CurrentNumberOfMovies];
    int tot_M_toSort = 0;

    bool found = false;
    for(int i = 0; i < CurrentNumberOfMovies; i++){
        if(mpointer[i]->calculateScore() >= score){
            MovieIndex[tot_M_toSort] = i;
            MovieRating[tot_M_toSort] = mpointer[i]->getRating();
            tot_M_toSort++;
            found = true;
        }
    }
    
    for(int i = 0; i < tot_M_toSort - 1; i++){
        for(int j = 0; j < tot_M_toSort - 1 - i; j++){
            if(MovieRating[j] < MovieRating[j + 1]){
                swap(MovieRating[j] , MovieRating[j + 1]);
                swap(MovieIndex[j] , MovieIndex[j + 1]);
            }
        }
    }
    system("cls");
    for(int i = 0; i < tot_M_toSort; i++){
        cout << *mpointer[MovieIndex[i]];
    }

    if(!found)
        cout << "No Movies Found" << endl;
}

void DisplayByALphabet(char ch){
    bool found = false;
    for(int i = 0; i < CurrentNumberOfMovies; i++){
        int Index = SearchAlphabet(ch);
        if(Index != 3309){
            found = true;
            cout << *mpointer[Index];
        }
    }
    if(!found)
        cout << "No Movies Found" << endl;
}

int SearchAlphabet(char ch){
        string MovieTitle;
        char MovieFchar = ' ';
        ch = tolower(ch);
        for(int i = 0; i < CurrentNumberOfMovies; i++){
            MovieTitle = StringToLowercase(mpointer[i]->getTitle());
            MovieFchar = MovieTitle[1];
            if(MovieFchar == ch)
                return i;
        }
        return 3309;
}

void DisplayByTitleAndRating(char ch, int rating){
    int MovieIndex[CurrentNumberOfMovies];
    int MovieRating[CurrentNumberOfMovies];
    string MovieTitle;
    char MovieFchar = ' ';
    int tot_M_toSort = 0;

    bool found = false;

    for(int i = 0; i < CurrentNumberOfMovies; i++){
        MovieTitle = StringToLowercase(mpointer[i]->getTitle());
        MovieFchar = MovieTitle[1];
        if((MovieFchar == ch) && (mpointer[i]->getRating() >= rating)){
            MovieIndex[tot_M_toSort] = i;
            tot_M_toSort++;
            found = true;
        }
    }
    
    for(int i = 0; i < tot_M_toSort - 1; i++){
        for(int j = 0; j < tot_M_toSort - 1 - i; j++){
            if(MovieRating[j] < MovieRating[j + 1]){
                swap(MovieIndex[j] , MovieIndex[j + 1]);
            }
        }
    }

    system("cls");
    for(int i = 0; i < tot_M_toSort; i++){
        cout << *mpointer[MovieIndex[i]];
    }

    if(!found)
        cout << "No Movies Found" << endl;
}

void RequestToRemoveMovie(){
    string title = "";
    
    cout << "Enter Title of the Movie: ";
    cin.ignore();
    getline(cin,title);
    
    int Index = SearchTitle(title);
    
    fstream file("UserRequest.txt", ios::app);

    if(file.is_open()){
        file << "User would like to remove a Movie" << endl;
        file << "Movie Number " << Index + 1 << endl;
        file << "Title: " << title << endl;
        cout << "Your Request has been registered\nWaiting for admin" << endl;
    }
    else
        cout << "Error in registering request" << endl;
}

void AddNewMovie(){
    if(CurrentNumberOfMovies == MaxNumberOfMovies){
        cout << "Max Number of Movies Reached cannot add more" << endl;
        return;
    }
    cout << "Enter Movie Title: ";
    string t;
    cin.ignore();
    getline(cin,t);

    int Index = SearchTitle(t);
    if(Index != 3309){
        cout << "Movie Already Exits" << endl;
        return;
    }

    cout << "Select Genre of the Movie you would like to add" << endl;
    cout << "1. Science Fiction" << endl
         << "2. Action" << endl
         << "3. Animation" << endl;
    
    int choice;
    cin >> choice;
    if(cin.fail()){
        cout << "ERROR: Invalid Input" << endl;
        return;
    }
    switch(choice){
        case 1:{
            scifi* s = new scifi();
            cin >> *s;
            mpointer[CurrentNumberOfMovies++] = s;
            break;
        }
        case 2:{
            Action* s = new Action();
            cin >> *s;
            mpointer[CurrentNumberOfMovies++] = s;
            break;
        }
        case 3:{
            Animation* s = new Animation();
            cin >> *s;
            mpointer[CurrentNumberOfMovies++] = s;
            break;
        }
        default:{
            cout << "ERROR: Invalid Input" << endl;
            return;
        }
    }
    fstream file("movies.txt", ios::app);
    if(file.is_open()){
        file << *mpointer[CurrentNumberOfMovies - 1];
    }
}

// Very dangerous fucks up the display fucntion and the pointer allocation
void RemoveMovie(){
    string title = "";
    
    cout << "Enter Title of the Movie: ";
    cin.ignore();
    getline(cin,title);
    
    int Index = SearchTitle(title);

    if(Index != 3309){
        fstream file("movies.txt",ios::out | ios::trunc);
        file.seekp(0, ios::beg);
        for(int i = 0; i < CurrentNumberOfMovies; i++){
            if(i == Index)
                continue;
            file << *mpointer[i];
        }
            file.close();
    }
}

void AdminConsole(){
    
    string username = "Gambit";
    string password = "sovamain";
    cout << "Enter \nUserName: ";
    string inputUserName, inputPassword;

    cin >> inputUserName;

    cout << "Password: ";
    cin.ignore();
    cin >> inputPassword;

    if(username == inputUserName && password == inputPassword){
        
        int choice;
        
        system("cls");
        cout << "1. Add new Movie" << endl //completed
        << "2. Remove a Movie" << endl
        << "3. View User Request" << endl
        << "0. Exit" << endl;
        
        cin >> choice;
        switch (choice){
            case 1:
                AddNewMovie();
                break;
            case 2:
                RemoveMovie();
                break;
            case 3:
                viewUserRequest();
                break;
            default:
                cout << "ERROR: Invalid Option" << endl;
                break;
        }
    }
    else
        cout << "Incorrect Credentials" << endl;
    return;
}

void viewUserRequest(){
    string line;
    ifstream file("UserRequest.txt");

    while(getline(file,line)){
        cout << line << endl;
    }
}