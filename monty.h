#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
 * struct stack_s - represents a stack
 * @n: represents an integer
 * @prev: shows the previous stack-element
 * @next: shows the next stack-element
 *
 * Description: represents a doubly linked-list
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - contains the instructions.
 * @opcode: represents opcode
 * @f: represents the function
 *
 * Description: the instructions for the opcode
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct globals - represents the global structure
 * @lifo: represents the stack
 * @cont: shows the current line
 * @arg: represents 2nd parameter in the current line
 * @head: represents the doubly linked-list
 * @fd: represents the file descriptor
 * @buffer: the text to add
 *
 * Description: structure of the doubly linked-list
 */
typedef struct globals
{
	int lifo;
	unsigned int cont;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

extern global_t vglo;

/*all_prototypes*/
void _add(stack_t **doubly, unsigned int cline);
void _div(stack_t **doubly, unsigned int cline);
void _mod(stack_t **doubly, unsigned int cline);
void _mul(stack_t **doubly, unsigned int cline);
void _nop(stack_t **doubly, unsigned int cline);
void _pall(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **doubly, unsigned int cline);
void _pint(stack_t **doubly, unsigned int cline);
void _pop(stack_t **doubly, unsigned int cline);
void _pstr(stack_t **doubly, unsigned int cline);
void _push(stack_t **stack, unsigned int line_number);
void _queue(stack_t **doubly, unsigned int cline);
void _rotl(stack_t **doubly, unsigned int cline);
void _rotr(stack_t **doubly, unsigned int cline);
void _stack(stack_t **doubly, unsigned int cline);
void _sub(stack_t **doubly, unsigned int cline);
void _swap(stack_t **doubly, unsigned int cline);
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);
char *_strtoky(char *s, char *d);
int _strcmp(char *s1, char *s2);
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
void *_calloc(unsigned int nmemb, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void _swap(stack_t **doubly, unsigned int cline);
int _sch(char *s, char c);
void free_dlistint(stack_t *head);
void free_vglo(void);

#endif
