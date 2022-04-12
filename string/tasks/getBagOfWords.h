#ifndef INC_5E_GETBAGOFWORDS_H
#define INC_5E_GETBAGOFWORDS_H

#include "../string_.h"

char *copyReverse(char *rbeginSource, const char *rendSource, char *beginDestination) {
    while (rbeginSource != rendSource) {
        (*beginDestination++) = *rbeginSource--;
    }
    return beginDestination;
}

void getBagOfWords(BagOfWords *bag, char *s) {
    WordDescriptor word;
    bag->size = 0;
    while (getWord(s, &word)) {
        bag->words[bag->size] = word;
        bag->size++;
        s = word.end;
    }
}

void reverseWordsBag(char *s) {
    *copy(s, getEndOfString(s), _stringBuffer) = '\0';
    getBagOfWords(&_bag, _stringBuffer);
    char *copyS = s;
    for (int i = 0; i < _bag.size; i++) {
        copyS = copyReverse(_bag.words[i].end - 1, _bag.words[i].begin - 1, copyS);
        *copyS++ = ' ';
    }
    if (copyS != s) {
        copyS--;
    }
    *copyS = '\0';
}


void test_reverseWordsBag1() {
    char s[MAX_STRING_SIZE] = "a b c";
    reverseWordsBag(s);

    ASSERT_STRING("a b c", s);
}

void test_reverseWordsBag2() {
    char s[MAX_STRING_SIZE] = "Hello";
    reverseWordsBag(s);

    ASSERT_STRING("olleH", s);
}

void test_reverseWordsBag3() {
    char s[MAX_STRING_SIZE] = "";
    reverseWordsBag(s);

    ASSERT_STRING("", s);
}

void test_reverseWordsBag4() {
    char s[MAX_STRING_SIZE] = "Mama";
    reverseWordsBag(s);

    ASSERT_STRING("amaM", s);
}

void test_reverseWordsBag(){
    test_reverseWordsBag1();
    test_reverseWordsBag2();
    test_reverseWordsBag3();
    test_reverseWordsBag4();
}

#endif //INC_5E_GETBAGOFWORDS_H
