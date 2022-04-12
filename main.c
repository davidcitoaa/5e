#include <stdio.h>
#include "string/string_.h"
#include "string/tasks/removeNonLetters.h"
#include "string/tasks/removeExtraSpaces.h"
#include "string/tasks/digitToStart.h"
#include "string/tasks/replaceNumbersWithSpaces.h"
#include "string/tasks/replace.h"
#include "string/tasks/areWordsOrdered.h"
#include "string/tasks/getBagOfWords.h"
#include "string/tasks/howManyWordsPalindromes.h"
#include "string/tasks/alternatingWords.h"

int main() {
    test_removeNonLetters();
    test_removeExtraSpaces();
    test_digitToStart();
    test_replacesNumbersWithSpaces_task4();
    test_replace_task5();
    test_areWordsOrdered_task6();
    test_reverseWordsBag();
    test_howManyWordsPalindromes_task8();
    test_alternatingWords_task9();

    return 0;
}
