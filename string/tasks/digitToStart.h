#ifndef INC_5E_DIGITTOSTART_H
#define INC_5E_DIGITTOSTART_H

#include "../string_.h"

void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIf(_stringBuffer,
                               endStringBuffer,
                               word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStartLetterToEndt(char *s) {
    char *beginSearch = s;
    WordDescriptor word;

    while (getWord(beginSearch, &word)) {
        digitToStart(word);

        beginSearch = word.end;
    }
}

void test_digitToStart1() {
    char s[] = "Hibro123";


    digitToStartLetterToEndt(s);
    ASSERT_STRING("123Hibro", s);
}

void test_digitToStart2() {
    char s[] = "Hibro1h23";
    digitToStartLetterToEndt(s);
    ASSERT_STRING("123Hibroh", s);
}

void test_digitToStart3() {
    char s[MAX_STRING_SIZE] = "Hibro1h23 j0";
    digitToStartLetterToEndt(s);
    ASSERT_STRING("123Hibroh 0j", s);
}

void test_digitToStart4() {
    char s[] = "Hibro1h23 j0h41";
    digitToStartLetterToEndt(s);
    ASSERT_STRING("123Hibroh 041jh", s);
}

void test_digitToStart() {
    test_digitToStart1();
    test_digitToStart2();
    test_digitToStart3();
    test_digitToStart4();
}

#endif //INC_5E_DIGITTOSTART_H
