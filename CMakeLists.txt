cmake_minimum_required(VERSION 3.20)
project(5e C)

set(CMAKE_C_STANDARD 99)

add_executable(5e main.c string/tasks/removeNonLetters.h string/tasks/removeExtraSpaces.h string/tasks/digitToStart.h string/tasks/replaceNumbersWithSpaces.h string/tasks/replace.h string/tasks/areWordsOrdered.h string/tasks/getBagOfWords.h string/tasks/howManyWordsPalindromes.h string/tasks/alternatingWords.h string/tasks/reverseTheOrderOfWordsInString.h)

add_library(str string/string_.h string/string_.c
        )
target_link_libraries(5e str)
