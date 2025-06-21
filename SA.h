#ifndef SA_H_INCLUDED
#define SA_H_INCLUDED

#include<iostream>

using namespace std;

void Search(string);
void Search(double);
void Search(string, double);

void InputMoviesFromFile();
void InputDirectorsFromFile();
void DeleteAllPointers();

bool AddNewMovie();
bool AddNewDirector();

void DisplayAllMovies();
void DisplayAllDirectors();

void DisplayAllMoviesByGenre(string);
void DisplayAllMoviesByRating(double);
void DisplayAllMoviesByDirector(string);

void writeMoviesToNewFile();
#endif 