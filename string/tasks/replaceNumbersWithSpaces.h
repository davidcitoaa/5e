#ifndef INC_5E_REPLACENUMBERSWITHSPACES_H
#define INC_5E_REPLACENUMBERSWITHSPACES_H

#include "../string_.h"

void replacesNumbersWithSpaces(char *s) {
    char *endSource = getEndOfString(s);
    char *stringBufferStart = _stringBuffer;
    char *endOfStringBuffer = copy(s, endSource, stringBufferStart);
    *endOfStringBuffer = '\0';
    while (*stringBufferStart != '\0') {
        if (isalpha(*stringBufferStart)) {
            *s++ = *stringBufferStart;
        } else if (isdigit(*stringBufferStart)) {
            while (*stringBufferStart - 48 > 0) {
                *s++ = ' ';
                (*stringBufferStart)--;
            }
        }
        ++stringBufferStart;
    }
}

void test_replacesNumbersWithSpaces_stringIsEmpty() {
    char s[MAX_STRING_SIZE] = "";
    replacesNumbersWithSpaces(s);
    ASSERT_STRING("", s);
}

void test_replacesNumbersWithSpaces_onlyLetters() {
    char s[MAX_STRING_SIZE] = "ABC";
    replacesNumbersWithSpaces(s);
    ASSERT_STRING("ABC", s);
}

void test_replacesNumbersWithSpaces_onlydigits() {
    char s[MAX_STRING_SIZE] = "123";
    replacesNumbersWithSpaces(s);
    ASSERT_STRING("      ", s);
}

void test_replacesNumbersWithSpaces_lettersAndDigits() {
    char s[MAX_STRING_SIZE] = "A3B0C1";
    replacesNumbersWithSpaces(s);
    ASSERT_STRING("A   BC ", s);
}

void test_replacesNumbersWithSpaces_task4() {
    test_replacesNumbersWithSpaces_stringIsEmpty();
    test_replacesNumbersWithSpaces_onlyLetters();
    test_replacesNumbersWithSpaces_onlydigits();
    test_replacesNumbersWithSpaces_lettersAndDigits();
}
#endif //INC_5E_REPLACENUMBERSWITHSPACES_H