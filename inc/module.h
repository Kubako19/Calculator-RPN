/*
 * Copyright (c) 2019-2020 Jakub Kozłowicz
 * All rights reserved
 */

#ifndef Calculator_RPN
#define Calculator_RPN

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * Structure to make stack.
 */
typedef struct t_stack {
    long number_;
    struct t_stack *next_;
} stackNumbers;

/**
 * Place one element on the top of the stack.
 * @param stack - set of numbers,
 * @param number - number to place on stack.
 * @return Stack increased by one element.
 */
stackNumbers **push(stackNumbers **stack, long number);

/**
 * Take one element from the top of the stack.
 * @param stack - set of numbers,
 * @param element - pointer to the place where the item removed from
 *                  the stack will be saved.
 * @return Stack without removed element.
 */
stackNumbers **pop(stackNumbers **stack, long *element);

/**
 * Check if stack is empty.
 * @param stack - set of numbers.
 * @return 0 - stack is empty
 * @return 1 - stack is not empty
 */
int notEmpty(stackNumbers *stack);

/**
 * Displays values on stack.
 * @param stack - set of numbers.
 */
void print(stackNumbers *stack);

/**
 * Initialize stack with NULL value.
 * @param stack - set of numbers.
 */
void init(stackNumbers **stack);

/**
 * Delete whole stack.
 * @param stack - set of numbers.
 */
void delete(stackNumbers **stack);

/**
 * Displays top of the stack.
 * @param stack - set of numbers.
 */
void display(stackNumbers *stack);

/**
 * Display available options.
 */
void help();

#endif //Calculator_RPN