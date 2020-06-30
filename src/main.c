/*
 * Copyright (c) 2019-2020 Jakub Kozłowicz
 * All rights reserved
 */

#include "module.h"

int main() {
    int character = '-';
    long number;
    long firstNumber = 0, secondNumber = 0;
    stackNumbers *numberStack;
    init(&numberStack);

    printf("Welcome in calculator RPN!\n");
    help();

    while (character != 'q') {
        character = getchar();

        if (isdigit(character)) {
            ungetc(character, stdin);
            scanf("%ld", &number);
            push(&numberStack, number);
        } else {
            switch (character) {
                case '+': {
                    if (notEmpty(numberStack)) {
                        pop(&numberStack, &firstNumber);
                        if (notEmpty(numberStack)) {
                            pop(&numberStack, &secondNumber);
                            push(&numberStack, firstNumber + secondNumber);
                        } else {
                            push(&numberStack, firstNumber);
                        }
                    }
                    break;
                }
                case '*': {
                    if (notEmpty(numberStack)) {
                        pop(&numberStack, &firstNumber);
                        if (notEmpty(numberStack)) {
                            pop(&numberStack, &secondNumber);
                            push(&numberStack, firstNumber * secondNumber);
                        } else {
                            push(&numberStack, firstNumber);
                        }
                    }
                    break;
                }
                case '/': {
                    if (notEmpty(numberStack)) {
                        pop(&numberStack, &firstNumber);
                        if (notEmpty(numberStack)) {
                            pop(&numberStack, &secondNumber);
                            push(&numberStack, secondNumber / firstNumber);
                        } else {
                            push(&numberStack, firstNumber);
                        }
                    }
                    break;
                }
                case '-': {
                    character = getchar();
                    if (isdigit(character)) {
                        ungetc(character, stdin);
                        scanf("%ld", &number);
                        push(&numberStack, -number);
                    } else {
                        if (notEmpty(numberStack))
                            pop(&numberStack, &firstNumber);
                        if (notEmpty(numberStack)) {
                            pop(&numberStack, &secondNumber);
                            push(&numberStack, secondNumber - firstNumber);
                        }
                    }
                    break;
                }
                case 'd': {
                    if (notEmpty(numberStack)) {
                        pop(&numberStack, &firstNumber);
                        push(&numberStack, firstNumber);
                        push(&numberStack, firstNumber);
                    }
                    break;
                }
                case 'P': {
                    if (notEmpty(numberStack)) {
                        pop(&numberStack, &number);
                    }
                    break;
                }
                case 'c': {
                    if (notEmpty(numberStack)) {
                        delete(&numberStack);
                    }
                    break;
                }
                case 'r': {
                    if (notEmpty(numberStack)) {
                        pop(&numberStack, &firstNumber);
                        if (notEmpty(numberStack)) {
                            pop(&numberStack, &secondNumber);
                        } else {
                            push(&numberStack, firstNumber);
                        }
                        push(&numberStack, firstNumber);
                        push(&numberStack, secondNumber);
                    }
                    break;
                }
                case 'f': {
                    print(numberStack);
                    break;
                }
                case 'p': {
                    if (notEmpty(numberStack))
                        display(numberStack);
                    break;
                }
                case 'h': {
                    help();
                }
                default: {
                    break;
                }
            }
        }
    }
    delete(&numberStack);
}