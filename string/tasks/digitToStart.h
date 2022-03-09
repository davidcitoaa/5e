#ifndef INC_5E_DIGITTOSTART_H
#define INC_5E_DIGITTOSTART_H

#include "../string_.h"

void digitToStartLetterToEnd(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1, _stringBuffer - 1, word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStart(char *s) {
    char *beginSearch = s;
    WordDescriptor word;

    while (getWord(beginSearch, &word)) {
        digitToStartLetterToEnd(word);

        beginSearch = word.end;
    }
}

void test_digitToStart1() {
    char s[] = "Hibro123 ";
    digitToStart(s);
    ASSERT_STRING("321Hibro", s);
}

void test_digitToStart2() {
    char s[] = "Hibro1h23 ";
    digitToStart(s);
    ASSERT_STRING("321Hibroh", s);
}

void test_digitToStart3() {
    char s[] = "Hibro1h23 j0 ";
    digitToStart(s);
    ASSERT_STRING("321Hibroh 0j", s);
}

void test_digitToStart4() {
    char s[] = "Hibro1h23 j0h41 ";
    digitToStart(s);
    ASSERT_STRING("321Hibroh 140jh", s);
}

void test_digitToStart() {
    test_digitToStart1();
    test_digitToStart2();
    test_digitToStart3();
    test_digitToStart4();
}



#endif //INC_5E_DIGITTOSTART_H
