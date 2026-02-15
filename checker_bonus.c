/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-idi <aait-idi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 00:03:42 by aait-idi          #+#    #+#             */
/*   Updated: 2026/02/14 23:51:10 by aait-idi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_move(char *move)
{
	if (!move)
		return (-1);
	if (!ft_strcmp(move, "sa"))
		return (SA);
	if (!ft_strcmp(move, "sb"))
		return (SB);
	if (!ft_strcmp(move, "pa"))
		return (PA);
	if (!ft_strcmp(move, "pb"))
		return (PB);
	if (!ft_strcmp(move, "ra"))
		return (RA);
	if (!ft_strcmp(move, "rb"))
		return (RB);
	if (!ft_strcmp(move, "rra"))
		return (RRA);
	if (!ft_strcmp(move, "rrb"))
		return (RRB);
	if (!ft_strcmp(move, "ss"))
		return (SS);
	if (!ft_strcmp(move, "rr"))
		return (RR);
	if (!ft_strcmp(move, "rrr"))
		return (RRR);
	return (-1);
}

static char	*get_instruction(void)
{
	static char	buff[4];
	ssize_t		r;

	buff[3] = 0;
	r = read(0, buff, 3);
	if (r == 0)
		return (NULL);
	if (r == -1)
		return ("q");
	if (r != 3)
		return ("e");
	if (buff[2] == '\n')
		return (buff[2] = 0, buff);
	r = read(0, buff + r, 1);
	if (r == -1)
		return ("q");
	if (!r || buff[3] != '\n')
		return ("e");
	return (buff[3] = 0, buff);
}

static void	execute_moves(t_stack **stack, t_data *data)
{
	char	*move;
	int		m;

	while (1)
	{
		move = get_instruction();
		if (!move)
			break ;
		if (!ft_strcmp(move, "e"))
			purge_and_exit(stack, data, 2);
		if (!ft_strcmp(move, "q"))
			purge_and_exit(stack, data, 1);
		m = check_move(move);
		if (m == -1)
			purge_and_exit(stack, data, 2);
		do_move(stack, m);
	}
}

int	main(int ac, const char **av)
{
	t_data	*data;
	t_stack	**stack;

	data = initialize(ac, av, &stack);
	parse_stack(stack, data);
	execute_moves(stack, data);
	if (!is_sorted(stack[A]) || stack[B])
	{
		write(1, "KO\n", 3);
		purge_and_exit(stack, data, 0);
	}
	write(1, "OK\n", 3);
	purge_and_exit(stack, data, 0);
	return (0);
}
