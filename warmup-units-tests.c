//
// Created by James on 9/4/2024.
//
// jdh CS3010 Fall 2024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "movie.jlemahie.h"

bool createAndCheck(char *testname, char *title, int year, int audience, int critics, bool expectFail, Movie *movie) {
    int rc;
    int numfails = 0;

    rc = initializeMovie(movie, title, year, audience, critics);
    if ( expectFail ) {
        if (rc == 0) {
            printf("error: test %s fails; expected return value of zero; got %d\n", testname, rc);
            ++numfails;
        }
    } else {
        if ( strcmp(movie->title, title) ) {
            printf("error: test %s fails; title is not correct\n", testname);
            ++numfails;
        }
        if (movie->year != year) {
            printf("error: test %s fails; year is not correct\n", testname);
            ++numfails;
        }
        if (movie->audience != audience) {
            printf("error: test %s fails; audience is not correct\n", testname);
            ++numfails;
        }
        if (movie->critics != critics) {
            printf("error: test %s fails; critics is not correct\n", testname);
            ++numfails;
        }
    }

    if ( numfails == 0 )
        printf("pass test %s\n", testname);

    return numfails;
} // createAndCheck()

//-------------------------------------------------------------------

int compareCheck(char *testname, Movie *m1, Movie *m2, int (compare)(Movie*, Movie*), int expectedValue) {
    int rc;
    bool fail;

    fail = false;

    rc = compare(m1, m2);
    if (expectedValue == 0) {
        if (rc != 0) {
            printf("error: test %s fails; expected zero from comparison; got %d\n", testname, rc);
            fail = true;
        }
    } else if (expectedValue > 0) {
        if (rc <= 0) {
            printf("error: test %s fails; expected positive return value from comparison; got %d\n", testname, rc);
            fail = true;
        }
    } else {
        if (rc >= 0) {
            printf("error: test %s fails; expected negative return value from comparison; got %d\n", testname, rc);
            fail = true;
        }
    }

    if ( ! fail )
        printf("pass test %s\n", testname);

    return fail;
} // compareCheck()

//-------------------------------------------------------------------

int main() {
    Movie m1, m2, m3, m4;
    int numfails = 0;
    int rc;

    // should fail: movie is NULL
    rc = createAndCheck("T1", "Barbie", 2023, 83, 88, true, NULL);
    if ( rc != 0 )
        ++numfails;

    // should fail: name is NULL
    rc = createAndCheck("T2", NULL, 2023, 83, 88, true, &m1);
    if ( rc != 0 )
        ++numfails;

    // should fail: year is < 1900
    rc = createAndCheck("T3", "Barbie", 1867, -3, 88, true, &m1);
    if ( rc != 0 )
        ++numfails;

    // should fail: audience is < 0
    rc = createAndCheck("T4", "Barbie", 2023, -3, 88, true, &m1);
    if ( rc != 0 )
        ++numfails;

    // should fail: critics is < 0
    rc = createAndCheck("T5", "Barbie", 2023, 83, -8, true, &m1);
    if ( rc != 0 )
        ++numfails;

    // should fail: audience is > 100
    rc = createAndCheck("T6", "Barbie", 2023, 103, 88, true, &m1);
    if ( rc != 0 )
        ++numfails;

    // should fail: critics is > 100
    rc = createAndCheck("T7", "Barbie", 2023, 83, 108, true, &m1);
    if ( rc != 0 )
        ++numfails;

    // should pass
    rc = createAndCheck("T8", "Barbie", 2023, 83, 88, false, &m1);
    if ( rc != 0 )
        ++numfails;

    // should pass
    rc = createAndCheck("T9", "Barbie", 2023, 83, 88, false, &m2);
    if ( rc != 0 )
        ++numfails;

    // should pass
    rc = createAndCheck("T10", "Blade Runner", 1982, 91, 89, false, &m3);
    if ( rc != 0 )
        ++numfails;

    // should pass
    rc = createAndCheck("T11", "Tenet", 2020, 76, 69, false, &m4);
    if ( rc != 0 )
        ++numfails;

    // compare should produce zero
    rc = compareCheck("T12", &m1, &m2, compareByTitle, 0);
    if ( rc != 0 )
        ++numfails;

    // compare should produce 1: m3 title > m3 title
    rc = compareCheck("T13", &m3, &m1, compareByTitle, 1);
    if ( rc != 0 )
        ++numfails;

    // compare should produce -1: m2 audience < m3 audience
    rc = compareCheck("T14", &m2, &m3, compareByAudience, -1);
    if ( rc != 0 )
        ++numfails;

    // compare should produce 0: m1 audience == m2 audience
    rc = compareCheck("T15", &m1, &m2, compareByAudience, 0);
    if ( rc != 0 )
        ++numfails;

    // compare should produce -1: m2 critics < m3 critics
    rc = compareCheck("T16", &m2, &m3, compareByCritics, -1);
    if ( rc != 0 )
        ++numfails;

    // compare should produce 1: m3 critics > m4 critics
    rc = compareCheck("T17", &m3, &m4, compareByCritics, 1);
    if ( rc != 0 )
        ++numfails;

    if (numfails == 0) {
        printf("all tests pass\n");
        return 0;
    } else {
        printf("%d test(s) failed\n", numfails);
        return 8;
    }
    return 0;
}
