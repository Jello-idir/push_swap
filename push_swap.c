/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-idi <aait-idi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:27:05 by aait-idi          #+#    #+#             */
/*   Updated: 2026/02/14 22:32:04 by aait-idi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_move(int move)
{
	if (move == SA)
		write(1, "sa\n", 3);
	else if (move == SB)
		write(1, "sb\n", 3);
	else if (move == SS)
		write(1, "ss\n", 3);
	else if (move == PA)
		write(1, "pa\n", 3);
	else if (move == PB)
		write(1, "pb\n", 3);
	else if (move == RA)
		write(1, "ra\n", 3);
	else if (move == RB)
		write(1, "rb\n", 3);
	else if (move == RR)
		write(1, "rr\n", 3);
	else if (move == RRA)
		write(1, "rra\n", 4);
	else if (move == RRB)
		write(1, "rrb\n", 4);
	else if (move == RRR)
		write(1, "rrr\n", 4);
}

static void	display_moves(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->mvlen)
	{
		write_move(data->moves[i]);
		i++;
	}
}

int	main(int ac, const char **av)
{
	t_data	*data;
	t_stack	**stack;

	data = initialize(ac, av, &stack);
	if (data->klen <= 5)
		sort_few(stack, data);
	else
	{
		while (data->ratio <= 3)
		{
			execute_sort(stack, data);
			if (is_sorted(stack[A]) && !stack[B] && data->mvlen < data->mvmax)
			{
				data->mvmax = data->mvlen;
				data->best_ratio = data->ratio;
			}
			data->ratio += 0.03;
		}
		data->ratio = data->best_ratio;
		execute_sort(stack, data);
	}
	display_moves(data);
	purge_and_exit(stack, data, 0);
	return (0);
}
