/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-idi <aait-idi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 00:03:42 by aait-idi          #+#    #+#             */
/*   Updated: 2026/02/14 22:34:38 by aait-idi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef unsigned char	t_byte;

typedef struct s_stack
{
	int					key;
	struct s_stack		*next;
}						t_stack;

typedef struct s_data
{
	int					*keys;
	int					klen;
}						t_data;

# define ERROR LONG_MAX

# define A 0
# define B 1

# define SA 0
# define SB 1

# define PA 2
# define PB 3

# define RA 4
# define RB 5

# define RRA 6
# define RRB 7

# define SS 8
# define RR 16
# define RRR 32

t_data					*initialize(int ac, const char **av, t_stack ***stack);
long					advanced_atoi(const char **str);
int						is_sorted(t_stack *stack);
void					parse_stack(t_stack **stack, t_data *data);
int						ft_strcmp(char *s1, char *s2);
int						do_move(t_stack **stack, t_byte idc);

t_stack					*stack_new(void);
t_stack					*stack_last(t_stack *stack);
void					stack_add_front(t_stack **stack, t_stack *node);
void					stack_clear(t_stack **stack);

void					purge_and_exit(t_stack **stack, t_data *data, int code);

#endif
