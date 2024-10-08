







#include "../includes/ft_push_swap.h"

void	ft_printf_stack(t_node *stack)
{
	while (stack)
	{
		printf("%d\n", stack->nb);
		stack = stack->next;
	}
}
