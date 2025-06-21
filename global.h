#ifndef global_H_INCLUDED
#define global_H_INCLUDED

#include <iostream>
#include "Director.h"
#include "MovieBaseClass.h"

using namespace std;

extern Movie* mpointer[];
extern Director* d[];
extern int CurrentNumberOfMovies;
extern int MaxNumberOfMovies;
extern int NumberOfMovies;
#endif