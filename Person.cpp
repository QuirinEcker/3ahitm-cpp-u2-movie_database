//
// Created by Quirin Ecker on 29.09.19.
//

#include "Person.h"

Person::Person(string firstname, string middlename, string lastname)
: firstname(firstname), middlename(middlename), lastName(lastname)
{}

string Person::getName() const {
    if (middlename == "") {
        return firstname + " " + lastName;
    } else {
        return firstname + " " + middlename + " " + lastName;
    }
}

void Person::addMovie(Movie *movie) {
    if (!personIsAllreadyInMovie(movie)) {
        movies.push_back(movie);
    }
}

vector<struct Movie *> Person::getMovies() {
    return movies;
}

bool Person::personIsAllreadyInMovie(Movie *movie) {
    for (int i = 0; i < movies.size(); ++i) {
        if (movies[i] == movie) {
            return true;
        } else return false;
    }
}
