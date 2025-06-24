#ifndef SA_H_INCLUDED
#define SA_H_INCLUDED

#include<iostream>

using namespace std;


void InputMoviesFromFile();
void InputDirectorsFromFile();
void DeleteAllPointers();

void AddNewMovie();
void RemoveMovie();

void DisplayAllMovies();
void DisplayAllDirectors();

void DisplayAllMoviesByGenre(string);
void DisplayAllMoviesByRating(int);

void DisplayByDirector(string);
void DisplayByYear(int);
void DisplayByTitle(string);
void DisplayByRating(int);
void DisplayByTitleAndRating(char, int);
void DisplayByScore(int);
void DisplayByALphabet(char);

void SortByTitle();
void SortMoviesByYear();

int SearchTitle(string);
int SearchAlphabet(char);

void RequestToAddNewMovie();
void RequestToAssignNewDirector();
void RequestToRemoveMovie();

void writeMoviesToNewFile();

string StringToLowercase(string);

void AdminConsole();
void viewUserRequest();

#endif 