#include "monty.h"

void monty_add(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);

/**
 * monty add - adds the top two values of a stack_t linked list
 * stack: A pointer to the node of a stack_t linked list
 * @line_number: The current working line number of a Monty bytecodes file
 * Return : void
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == null)
	{
		set_op_tok_error(short_stack_error(line_number, "add"));
		return;
	}
	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_number);
}
