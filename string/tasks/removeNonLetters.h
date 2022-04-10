#ifndef INC_5E_REMOVENONLETTERS_H
#define INC_5E_REMOVENONLETTERS_H

#include "assert.h"
#include "../string_.h"


void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    int x = strcmp_(expected, got);
    if (x) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}


void test_removeNonLetters1() {
    char s[] = "Hi123";
    removeNonLetters(s);
    ASSERT_STRING("Hi123", s);
}

void test_removeNonLetters2() {
    char s[] = "Hi 123";
    removeNonLetters(s);
    ASSERT_STRING("Hi123", s);
}

void test_removeNonLetters3() {
    char s[] = "Hi123 ";
    removeNonLetters(s);
    ASSERT_STRING("Hi123", s);
}

void test_removeNonLetters4() {
    char s[] = " Hi123 ";
    removeNonLetters(s);
    ASSERT_STRING("Hi123", s);
}

void test_removeNonLetters() {
    test_removeNonLetters1();
    test_removeNonLetters2();
    test_removeNonLetters3();
    test_removeNonLetters4();
}


#endif //INC_5E_REMOVENONLETTERS_H
