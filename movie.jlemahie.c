//
// Created by James on 9/4/2024.
//
#include "movie.jlemahie.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int initializeMovie(Movie *m, char *title, int year, int audience, int critics){

    //checking of movie is null
    if (m == NULL) {
        printf("Movie is null cannot create a movie struct.\n");
        return 1;
    }

    //checking if title is null
    if (title == NULL) {
        printf("Title string is null. Cannot assign a null value to the title of a movie.\n");
        return 1;
    }

    //checking if title is the empty string
    if (strlen(title) == 0){
        printf("Movie cannot have an empty title.\n");
        return 1;
    }

    //checking if title is longer than allowed length of movie
    if (strlen(title) > MAX_MOVIE_NAME_LEN){
        printf("Movie title cannot be greater than 63 characters.\n");
        return 1;
    }

    //checking if year is >= 1900
    if (year < 1900){
        printf("Movie year cannot be less than 1900.\n");
        return 1;
    }

    //checking if audience is between 0 and 100
    if (audience < 0 || audience > 100){
        printf("Movie Audience score must be between 0 and 100 (inclusive).\n");
        return 1;
    }

    //checking if critics is between 0 and 100
    if (critics < 0 || critics > 100){
        printf("Movie Critics score must be between 0 and 100 (inclusive).\n");
        return 1;
    }

    strcpy(m->title, title);
    m->year = year;
    m->audience =  audience;
    m->critics = critics;
    return 0;
}
int compareByTitle(Movie *m1, Movie *m2){
    //making sure both movies are not null
    if (m1 == NULL || m2 == NULL){
        printf("One of the movies given were a null pointer. Cannot compare movies.");
        return -3;
    }

    //comparing the two movie titles
    int compare = strcmp(m1->title, m2->title);

    //returning the correct value
    if (compare == -1)
        return -1;
    else if (compare == 0)
        return 0;
    else
        return 1;
}

int compareByAudience(Movie *m1, Movie *m2){
    //making sure both movies are not null
    if (m1 == NULL || m2 == NULL){
        printf("One of the movies given were a null pointer. Cannot compare movies.");
        return -3;
    }

    //comparing audience value and returning correct value
    if (m1->audience < m2->audience){
        return -1;
    } else if (m1->audience == m2->audience){
        return 0;
    } else {
        return 1;
    }
}

int compareByCritics(Movie *m1, Movie *m2){
    //making sure both movies are not null
    if (m1 == NULL || m2 == NULL){
        printf("One of the movies given were a null pointer. Cannot compare movies.");
        return -3;
    }

    //comparing audience value and returning correct value
    if (m1->critics < m2->critics){
        return -1;
    } else if (m1->critics == m2->critics){
        return 0;
    } else {
        return 1;
    }
}

int compareByYear(Movie *m1, Movie *m2){
    //making sure both movies are not null
    if (m1 == NULL || m2 == NULL){
        printf("One of the movies given were a null pointer. Cannot compare movies.");
        return -3;
    }

    //comparing audience value and returning correct value
    if (m1->year < m2->year){
        return -1;
    } else if (m1->year == m2->year){
        return 0;
    } else {
        return 1;
    }
}


