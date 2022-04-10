#include "string_.h"
#include "string.h"
#include <ctype.h>
#include "assert.h"
#include <memory.h>


int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

char *find(char *begin, const char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}


char *findNonSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin))
        begin++;

    return begin;
}

char *findSpace(char *begin) {
    while (*begin != '\0' && !isspace(*begin))
        begin++;

    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    assert(*rbegin != '\0');
    while (*rbegin >= *rend && isspace(*rbegin))
        rbegin--;

    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    assert(*rbegin != '\0');
    while (*rbegin >= *rend && !isspace(*rbegin))
        rbegin--;

    return rbegin;
}

int strcmp(const char *lhs, const char *rhs) {
    int f;
    while (*lhs != '\0' && *rhs != '\0')
        f = *lhs++ - *rhs++ < 0 ? -1 : *lhs - *rhs > 0;

    return f;
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    memcpy(beginDestination, beginSource, endSource - beginSource);

    return beginDestination + (endSource - beginSource);
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource))
            (*beginDestination++) = *beginSource;
        beginSource++;
    }
    return beginDestination;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rbeginSource != rendSource) {
        if (f(*rbeginSource)) {
            (*beginDestination++) = *rbeginSource;
        }
        rbeginSource--;
    }
    return beginDestination;
}

char *getEndOfString(char *begin) {
    while (*begin != '\0')
        begin++;

    return begin;
}

int strcmp_(const char *lhs, const char *rhs) {
    while (*lhs == *rhs && *lhs) {
        lhs++, rhs++;
    }
    return *rhs - *lhs;
}