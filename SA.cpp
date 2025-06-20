#include <iostream>
#include "SA.h"
#include "MovieBaseClass.h"
#include <fstream>
#include <string>
#include "Scifi.h"
#include "Action.h"
#include "Animation.h"

using namespace std;



void readfromFile(){

    Movie* mpointer[50];

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
        cout << "Error" << endl;
    }
    
    string line;
    file.seekg(0, ios::beg);
    for(int j = 0; j < 13; j++){
    
        for(int i = 0; i < 15; i ++){
            getline(file,line);
            cout << line << endl;
            try
            {
                cout << line.substr(18) << endl;
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
            case 6:    
                directorName = line;
                break;
            case 7:    
                experience = stoi(line);
                break;
            case 8:    
                nationality = line;
                break;
            case 11:    
                genre = line;
                if(genre == "Scifi"){
                    genrePointer = 1;
                }
                else if(genre == "Action"){
                    genrePointer =2;
                }
                else
                    genrePointer = 3;
                break;
            case 12:
                if(genrePointer == 1)    
                    techLevel = stoi(line);
                else if(genrePointer == 3)    
                    AnimationStyle = stoi(line);
                else if(genrePointer == 2)    
                    ViolenceLevel = line[0];
                break;
            case 13:
                if (genrePointer == 1) // Scifi
                    aliens = (line == "Yes" || line == "yes");
                else if (genrePointer == 2) // Action
                    Stunts = (line == "Yes" || line == "yes");
                else if (genrePointer == 3) // Animation
                    Musical = (line == "Yes" || line == "yes");
                break;
            case 14:
                if (genrePointer == 1) // Scifi
                    futureYear = stoi(line);
                else if (genrePointer == 2) // Action
                    Fightscenes = stoi(line);
                else if (genrePointer == 3) // Animation
                    AgeGroup = stoi(line);
                break;
            }
        }
            catch(const exception& e)
            {
                continue;
            }
            
        }
        if(genrePointer == 1){
            //s[j].setmovie(title, rating, 1,1,1, 'A', Stunts,Fightscenes);
            mpointer[j] = new scifi(title, rating, 1,1,2020, 'A', Stunts,Fightscenes);

        }
        else if(genrePointer == 2){
            mpointer[j] = new Action(title, rating, 1,1,2020, 'A', Stunts,Fightscenes);
        }
        else
        {
            mpointer[j] = new Animation(title, rating, 1,1,2020,AnimationStyle,Musical,AgeGroup);

        }
        
        j++;
    }
    mpointer[1]->displayDetails();
    
        file.close();
}