/*
 * Copyright (c) 2019-2020 Jakub Kozłowicz
 * All rights reserved
 */

#include "module.h"

stackNumbers **push(stackNumbers **stack, long number) {
    stackNumbers *tmp;
    tmp = (stackNumbers *) malloc(sizeof(stackNumbers));

    if (tmp == NULL) {
        exit(0);
    }

    tmp->number_ = number;
    tmp->next_ = *stack;

    *stack = tmp;

    return (stack);
}

stackNumbers **pop(stackNumbers **stack, long *element) {
    stackNumbers *tmp = *stack;

    *element = (*stack)->number_;
    *stack = (*stack)->next_;
    free(tmp);

    return stack;
}

int notEmpty(stackNumbers *stack) {
    if (stack == NULL)
        return 0;

    return 1;
}

void print(stackNumbers *stack) {
    stackNumbers *current;
    current = stack;

    if (current != NULL) {
        printf("Stack: ");
        do {
            printf("%ld ", current->number_);
            current = current->next_;
        } while (current != NULL);
        printf("\n");
    } else {
        printf("Stack is empty :(\n");
    }
}

void init(stackNumbers **stack) {
    *stack = NULL;
}

void delete(stackNumbers **stack) {
    stackNumbers *tmp = *stack;

    while (*stack) {
        *stack = (*stack)->next_;
        free(tmp);
        tmp = *stack;
    }
}

void display(stackNumbers *stack) {
    if (stack != NULL) {
        printf("On the top of the stack is: ");
        printf("%ld \n", stack->number_);
    }
}

void help() {
    printf("Options in calculator:\n");
    printf("\t [ h ] - Display help\n");
    printf("\t [ + ] - Addition\n");
    printf("\t [ - ] - Subtraction\n");
    printf("\t [ * ] - Multiplication\n");
    printf("\t [ / ] - Division\n");
    printf("\t [ d ] - Duplicate two last numbers\n");
    printf("\t [ P ] - Delete last entered number\n");
    printf("\t [ p ] - Display last entered number\n");
    printf("\t [ c ] - Delete all stored numbers\n");
    printf("\t [ r ] - Change the order of the last two numbers entered\n");
    printf("\t [ f ] - Display all entered numbers\n");
    printf("\t [ q ] - End program\n");
}