#ifndef INC_5E_REMOVEEXTRASPACES_H
#define INC_5E_REMOVEEXTRASPACES_H

#include "assert.h"
#include "../string_.h"

void removeExtraSpaces(char *s) {
    char *begin = s;
    char *destination = begin;
    char last = *begin;

    while (*begin != '\0') {
        if (*begin != last || last != ' ')
            *destination++ = *begin;

        last = *begin++;
    }
    if (last == ' ')
        destination--;

    *destination = '\0';
}

void test_removeExtraSpaces1() {
    char s[] = "Hola        amigo";
    removeExtraSpaces(s);
    ASSERT_STRING("Hola amigo", s);
}

void test_removeExtraSpaces2() {
    char s[] = "Hola      amigo   ";
    removeExtraSpaces(s);
    ASSERT_STRING("Hola amigo", s);
}

void test_removeExtraSpaces3() {
    char s[] = "   Hola        hermano";
    removeExtraSpaces(s);
    ASSERT_STRING("Hola hermano", s);
}

void test_removeExtraSpaces4() {
    char s[] = "Holahermano   ";
    removeExtraSpaces(s);
    ASSERT_STRING("Holahermano", s);
}


void test_removeExtraSpaces() {
    test_removeExtraSpaces1();
    test_removeExtraSpaces2();
    test_removeExtraSpaces3();
    test_removeExtraSpaces4();
}

#endif //INC_5E_REMOVEEXTRASPACES_H
