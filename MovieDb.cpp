//
// Created by Quirin Ecker on 30.09.19.
//

#include <iostream>
#include "MovieDb.h"
using namespace std;

void MovieDb::addMovie(string title, int year, string director) {
    findOrCreatePerson(director);
    Person* directorObject = findOrCreatePerson(director);
    Movie* movie = findOrCreateMovie(title, year, directorObject);
    movies.push_back(movie);
}

Movie *MovieDb::getMovie(string title) {
    for (int i = 0; i < movies.size(); ++i) {
        if (movies[i]->getTitle() == title) {
            return movies[i];
        }
    }

    return nullptr;
}

vector<Movie *> MovieDb::getMoviesDirectedBy(string director) {
    Person* directorObject = findOrCreatePerson(director);
    vector<Movie*> moviesdirectedby;

    for (int i = 0; i < movies.size(); ++i) {
        if (movies[i]->getDirector()->getName() == director) {
            moviesdirectedby.push_back(movies[i]);
        }
    }

    return moviesdirectedby;
}

void MovieDb::addActor(string movieTitle, string actorName) {
    Movie* movie = getMovie(movieTitle);
    Person* person = findOrCreatePerson(actorName);
    movie->addActor(person);
    person->addMovie(movie);
}

Person* MovieDb::getActors(string name) {
    return new Person("", "", "");
}

vector<Movie *> MovieDb::getMoviesWith(string actor) {
    Person* actorObject = findOrCreatePerson(actor);
    vector<Movie*> moviesWith;

    for (int i = 0; i < actorObject->getMovies().size(); ++i) {
        if (actorObject->getMovies()[i]->getDirector() != actorObject) {
            moviesWith.push_back(actorObject->getMovies()[i]);
        } else {
            for (int j = 0; j < actorObject->getMovies()[i]->getActors().size(); ++j) {
                if (actorObject->getMovies()[i]->getActors()[j] == actorObject) {
                    moviesWith.push_back(actorObject->getMovies()[i]);
                }
            }
        }
    }

    return moviesWith;
}

Person *MovieDb::findOrCreatePerson(string basicString) {
    for (int i = 0; i < movies.size(); ++i) {
        if (movies[i]->getDirector()->getName() == basicString) {
            return movies[i]->getDirector();
        }

        for (int j = 0; j < movies[i]->getActors().size(); ++j) {
            if (movies[i]->getActors()[j]->getName() == basicString) {
                return movies[i]->getActors()[j];
            }
        }
    }

    vector<string> nameComponents = split(basicString, ' ');

    if (nameComponents.size() == 2) {
        return new Person(nameComponents[0], "", nameComponents[1]);
    } else {
        return new Person(nameComponents[0], nameComponents[1], nameComponents[2]);
    }

}

vector<string> MovieDb::split(string text, char seperator) {
    vector<string> textComponents;
    textComponents.push_back("");
    int componentIndex = 0;

    for (int i = 0; i < text.size(); ++i) {
        if (text.at(i) == seperator) {
            componentIndex++;
            textComponents.push_back("");
        } else {
            textComponents[componentIndex] += text.at(i);
        }
    }

    return textComponents;
}

Movie *MovieDb::findOrCreateMovie(string title, int year, Person *director) {
    for (int i = 0; i < movies.size(); ++i) {
        if (movies[i]->getTitle() == title) {
            return movies[i];
        }
    }

    return new Movie(title, year, director);
}
