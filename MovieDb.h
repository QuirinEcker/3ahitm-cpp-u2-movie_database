//
// Created by Quirin Ecker on 30.09.19.
//

#ifndef MOVIE_DATABASE_MOVIEDB_H
#define MOVIE_DATABASE_MOVIEDB_H


#include <string>
#include "Movie.h"
#include "Person.h"

using namespace std;

class MovieDb {
private:
    vector<Movie*> movies;

public:
    void addMovie(string title, int year, string director);
    Movie* getMovie(string title);
    vector<Movie*> getMoviesDirectedBy(string director);
    void addActor(string movieTitle, string actorName);
    Person* getActors(string name);
    vector<Movie*> getMoviesWith(string actor);

    Person *findOrCreatePerson(string basicString);

    vector<string> split(string text, char seperator);

    Movie *findOrCreateMovie(string title, int year, Person *director);
};


#endif //MOVIE_DATABASE_MOVIEDB_H
