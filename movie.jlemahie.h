//
// Created by James on 9/4/2024.
//

#ifndef HOMEWORK_1_MOVIE_JLEMAHIE_H
#define HOMEWORK_1_MOVIE_JLEMAHIE_H

#define MAX_MOVIE_NAME_LEN 63

typedef struct {
    char title[MAX_MOVIE_NAME_LEN+1];
    int year;
    int audience;
    int critics;
} Movie;

int initializeMovie(Movie *m, char *title, int year, int audience, int critics);

int compareByTitle(Movie *m1, Movie *m2);

int compareByAudience(Movie *m1, Movie *m2);

int compareByCritics(Movie *m1, Movie *m2);

int compareByYear(Movie *m1, Movie *m2);

#endif //HOMEWORK_1_MOVIE_JLEMAHIE_H
