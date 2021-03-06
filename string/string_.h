#ifndef INC_5E_STRING__H
#define INC_5E_STRING__H

#include <stdio.h>
#include <ctype.h>
#define ASSERT_STRING(expected, got)assertString(expected, got, \
 __FILE__, __FUNCTION__, __LINE__)
#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20
char _stringBuffer[MAX_STRING_SIZE + 1];

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

BagOfWords _bag;
BagOfWords _bag2;

//Функция getWord вернёт значение 0, если слово не было считано, в противном
//случае будет возвращено значение 1 и в переменную word типа WordDescriptor
//будут записаны позиции начала слова, и первого символа после конца слова
int getWord(char *beginSearch, WordDescriptor *word);

// возвращает количество символов в строке
size_t strlen_(const char *begin);

// Возвращает указатель на первый элемент с кодом ch, расположенным на ленте памяти между
//адресами begin и end не включая end.
char *find(char *begin, const char *end, int ch);

// Возвращает указатель на первый символ,
// отличный от пробельных115, расположенный на ленте памяти, начиная с begin и заканчивая ноль-символом
char *findNonSpace(char *begin);

/* Возвращает указатель на первый пробельный символ, расположенный
на ленте памяти начиная с адреса begin или на первый ноль-символ.
*/
char *findSpace(char *begin);

/* Возвращает указатель на первый справа символ, отличный от пробельных,
расположенный на ленте памяти, начиная с rbegin (последний символ
строки, за которым следует ноль-символ) и заканчивая rend (адрес символа перед началом строки).
Если символ не найден, возвращается адрес rend.
*/
char *findNonSpaceReverse(char *rbegin, const char *rend);

/*
Возвращает указатель на первый пробельный символ справа, расположенный на ленте памяти,
начиная с rbegin и заканчивая rend. Если символ не найден, возвращается адрес rend.
 */
char *findSpaceReverse(char *rbegin, const char *rend);

/* Записывает по адресу beginDestination
фрагмент памяти, начиная с адреса beginSource до endSource.
Возвращает указатель на следующий свободный фрагмент памяти в
destination
 */
char *copy(const char *beginSource, const char *endSource, char *beginDestination);;

/*
Записывает по адресу
beginDestination элементы из фрагмента памяти начиная с beginSource
заканчивая endSource, удовлетворяющие функции-предикату f. Функция
возвращает указатель на следующий свободный для записи фрагмент в
памяти.
*/
char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

/*
 Записывает по адресу
beginDestination элементы из фрагмента памяти начиная с rbeginSource
заканчивая rendSource, удовлетворяющие функции-предикату f.
Функция возвращает значение beginDestination по окончанию работы функции.
 */
char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

char *getEndOfString(char *begin);

int strcmp_(const char *lhs, const char *rhs);

int areWordsEqual(WordDescriptor w1, WordDescriptor w2);

#endif
