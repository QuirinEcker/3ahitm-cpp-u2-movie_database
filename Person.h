//
// Created by Quirin Ecker on 29.09.19.
//

#ifndef MOVIE_DATABASE_PERSON_H
#define MOVIE_DATABASE_PERSON_H

#include <string>
#include <vector>

using namespace std;
class Movie;

class Person {
private:
    string firstname;
    string middlename;
    string lastName;
    vector<struct Movie*> movies;

public:
    Person(string firstname, string middlename, string lastname);
    string getName() const;
    void addMovie(Movie *movie);
    vector<struct Movie *> getMovies();

    bool personIsAllreadyInMovie(Movie *movie);
};


#endif //MOVIE_DATABASE_PERSON_H