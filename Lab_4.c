//
// Created by Great_Society on 16.11.2020.
//
//Дан текст, состоящий из n предложений. Предложение представляет
//собой арифметическое выражение. Создать массив, включающий в себя
//идентификаторы из всех предложений.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NAMEIN 1
#define NAMEOUT 0

int main(){
    char inputArray[256], intermediateArray[32] = " "; // Массив на ввод, массив на запись (31 значимый символ)
    char stringArray[128][32]; // Массив строк на вывод
    char *pInputArray = inputArray;
    char *pIntermediateArray = intermediateArray;
    int status; // Флаг нахождения имени в массиве записи
    int printCounter; // Счетчик массива на запись
    int containerCounter = 0; // Счетчик массива на вывод.
    int matchFlag; // Флаг вхождения в массив

    puts ("Please, enter text with arithmetic expressions:");
    fgets(pInputArray,256,stdin);

    for(int i = 0; i <= strlen(pInputArray); i++){
        status = NAMEOUT;
        matchFlag = NAMEOUT;

        // Если буква или _ то записываем. Индентификатор в С может начинаться только с них.
        if (isalpha(*(pInputArray+i)) || *(pInputArray+i) == '_'){
            printCounter = 0;
            do {
                *(pIntermediateArray + printCounter) = *(pInputArray + i);
                ++printCounter;
                ++i;
            }while (isalpha(*(pInputArray+i)) ||
                    isdigit(*(pInputArray+i)) ||
                    *(pInputArray+i) == '_');
            // До тех пор пока на вводе буква, цифра или _ , после чего указываем на флаг нахождения;
            status = NAMEIN;

        }
        // Если значение не попало в первое условие, то переходим на следующую итерацию
        if (status == NAMEOUT){
            continue;
        }
        // Проверяем имя в массиве записи на вхождение в массив вывода.
        for (int j = 0; j < 128; j++){
            if(strcmp(stringArray[j],intermediateArray) == 0){
                memset(intermediateArray,0,32); // если да, то обнуляем массив
                matchFlag = NAMEIN; // Флаг вхождения 1
                continue; // проверяем до первого найденного вхождения
            }
        }
        // запись в массив вывода, если вхождения не найдено.
        if (matchFlag == NAMEOUT) {

            strcpy(stringArray[containerCounter], intermediateArray);
            //puts(*(stringArray + containerCounter));
            containerCounter++;
        }
        // обнуляем массив записи
        memset(intermediateArray,0,32);
    }
    --containerCounter;

    // Вывод на печать

    printf("\nYour text include a %d identifier%s\nHere %s:",
           containerCounter+1, (containerCounter>0?"'s ":" "), (containerCounter>0?"they are":"he is"));

    for (int i = containerCounter; i>=0; i--,i<0?putchar('.'):putchar(',')){
        printf(" %s",stringArray[i]);
    }
    //x = y*2 (2+g_mu1 - 85)/(150*sin(cos(x)) + 5_j / _j5 );
    getchar();
    return 0;
}

