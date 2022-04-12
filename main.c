#include <stdio.h>
#include "string/string_.h"
#include "string/tasks/removeNonLetters.h"
#include "string/tasks/removeExtraSpaces.h"
#include "string/tasks/digitToStart.h"
#include "string/tasks/replaceNumbersWithSpaces.h"
#include "string/tasks/replace.h"

int main() {
    test_removeNonLetters();
    test_removeExtraSpaces();
    test_digitToStart();
    test_replacesNumbersWithSpaces_task4();
    test_replace_task5();

    return 0;
}
