#ifndef SA_H_INCLUDED
#define SA_H_INCLUDED

#include<iostream>

using namespace std;

void InputMoviesFromFile();
void InputDirectorsFromFile();
void DeleteAllPointers();

bool AddNewMovie();
bool AddNewDirector();

void DisplayAllMovies();
void DisplayAllDirectors();

void DisplayAllMoviesByGenre(string);
void DisplayAllMoviesByRating(int);
void DisplayAllMoviesByDirector(string);

void DisplayByYear(int);
void DisplayByTitle(string);

void SortByYear();
// cout << "----------Search Menu----------" << endl;
//     cout<< "1. Search and Display Movies by Specific Director\n"
//         << "2. Search and Display Movies by Certain Score\n"
//         << "3. Search and Display Movies by Year\n"
//         << "4. Search and Display Movies by Title\n"
//         << "5. Search and Display Movies by Rating\n"
//         << "6. Search and Display Movies by Title and Ranking\n"
//         << "0. <- Go Back";

void writeMoviesToNewFile();
#endif 