//
// Created by Quirin Ecker on 30.09.19.
//

#include "Movie.h"

Movie::Movie(string title, int year, Person *director):
title(title), year(year), director(director)
{}

string Movie::getTitle() {
    return title;
}

int Movie::getYear() {
    return year;
}

Person *Movie::getDirector() {
    return director;
}

void Movie::addActor(Person *actor) {
    actors.push_back(actor);
}

vector<Person *> Movie::getActors() {
    return actors;
}
