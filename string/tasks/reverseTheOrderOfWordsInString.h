#ifndef INC_5E_REVERSETHEORDEROFWORDSINSTRING_H
#define INC_5E_REVERSETHEORDEROFWORDSINSTRING_H

#include "../string_.h"

void reverseTheOrderOfWordsInString(char *s) {
    char *copyS = s;
    *copy(copyS, getEndOfString(s), _stringBuffer) = '\0';
    getBagOfWords(&_bag, _stringBuffer);

    for (int i = _bag.size - 1; i >= 0; i--) {
        s = copy(_bag.words[i].begin, _bag.words[i].end, s);
        *s++ = ' ';
    }
    if (s != copyS) {
        s--;
    }
    *s = '\0';
}


void test_reverseTheOrderOfWordsInString1() {
    char s[MAX_STRING_SIZE] = "a b c";
    reverseTheOrderOfWordsInString(s);
    ASSERT_STRING("c b a", s);
}

void test_reverseTheOrderOfWordsInString2() {
    char s[MAX_STRING_SIZE] = "sleep zzz";
    reverseTheOrderOfWordsInString(s);
    ASSERT_STRING("zzz sleep", s);
}

void test_reverseTheOrderOfWordsInString3() {
    char s[MAX_STRING_SIZE] = "";
    reverseTheOrderOfWordsInString(s);
    ASSERT_STRING("", s);
}

void test_reverseTheOrderOfWordsInString4() {
    char s[MAX_STRING_SIZE] = "mama papa i";
    reverseTheOrderOfWordsInString(s);
    ASSERT_STRING("i papa mama", s);
}

void test_reverseEndOrderOfWordsInString(){
    test_reverseTheOrderOfWordsInString1();
    test_reverseTheOrderOfWordsInString2();
    test_reverseTheOrderOfWordsInString3();
    test_reverseTheOrderOfWordsInString4();
}

#endif //INC_5E_REVERSETHEORDEROFWORDSINSTRING_H
