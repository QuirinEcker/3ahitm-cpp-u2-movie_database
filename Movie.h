//
// Created by Quirin Ecker on 30.09.19.
//

#ifndef MOVIE_DATABASE_MOVIE_H
#define MOVIE_DATABASE_MOVIE_H


#include <string>
#include <vector>

class Person;

using namespace std;

class Movie {
private:
    string title;
    int year;
    Person* director;
    vector<Person*> actors;

public:
    Movie(string title, int year, Person* director);
    string getTitle();
    int getYear();
    Person* getDirector();
    void addActor(Person* actor);
    vector<Person*> getActors();
};


#endif //MOVIE_DATABASE_MOVIE_H
