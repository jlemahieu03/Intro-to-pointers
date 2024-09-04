#include "movie.jlemahie.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int main() {
    //creating test movie and null movie
    Movie *test1 = malloc(sizeof(Movie));
    Movie *test2 = malloc(sizeof(Movie));
    Movie *test3 = malloc(sizeof(Movie));
    Movie *test4 = malloc(sizeof(Movie));


    int right_year = 1900;


    int correct_aud_1 = 0;

    int correct_crit_1 = 0;

    initializeMovie(test1, "Alien", 1950, correct_aud_1, correct_crit_1);
    initializeMovie(test2, "Alien", 1949, correct_aud_1, correct_crit_1);
    initializeMovie(test3, "Alien", 1951, correct_aud_1, correct_crit_1);
    initializeMovie(test4, "Alien", 1950, correct_aud_1, correct_crit_1);

    int result = compareByYear(test1, test2);
    printf("%d", result);

    result = compareByYear(test1, test3);
    printf("%d", result);

    result = compareByYear(test1, test4);
    printf("%d", result);

    //deallocating
    free(test1);
    free(test2);
    free(test3);
    free(test4);
    return 0;
}
