#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>


/*GLOBAL DECLARATION*/
extern int monty_push;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* OPCODES INSTRACTIONS */
int main(char argc, char **argv);
void m_push(stack_t **stack, unsigned int line_number);
void m_pall(stack_t **stack, unsigned int line_number);
void m_pint(stack_t **stack, unsigned int line_number);
void m_pop(stack_t **stack, unsigned int line_number);
void m_swap(stack_t **stack, unsigned int line_number);
void m_add(stack_t **stack, unsigned int line_number);
void m_nop(stack_t **stack, unsigned int line_number);
void m_read(char *name, stack_t **stack);
op_instruction get_op_func(char *opcode);
char *m_parse(char *get_line, stack_t **stack, unsigned int line_number);
int checknum(char *op);
#endif
