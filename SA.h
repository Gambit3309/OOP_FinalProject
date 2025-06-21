#ifndef SA_H_INCLUDED
#define SA_H_INCLUDED

#include<iostream>

using namespace std;

void StringToLowercase(string&);

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

void SortByTitle();
void SortMoviesByYear();

bool SearchTitle(string);

void RequestToAssignNewDirector();

void writeMoviesToNewFile();
#endif 