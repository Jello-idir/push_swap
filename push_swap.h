/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-idi <aait-idi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 06:28:29 by aait-idi          #+#    #+#             */
/*   Updated: 2026/02/14 22:32:00 by aait-idi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	t_byte				*moves;
	int					mvlen;
	int					mvmax;
	int					klen;
	int					tmp;
	float				ratio;
	float				best_ratio;
}						t_data;

# define ERROR LONG_MAX

# define A 0
# define B 1
# define T 2

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

void					parse_stack(t_stack **stack, t_data *data);
void					execute_sort(t_stack **stack, t_data *data);

void					sort_few(t_stack **stack, t_data *data);

int						threshold(t_stack **stack, t_data *data, int threshold);
int						keys_to_top(t_stack **stack, t_data *data, int key_a,
							int key_b);

long					advanced_atoi(const char **str);
int						key_position(t_stack *stack, int key);
int						is_sorted(t_stack *stack);

int						do_move(t_stack **stack, t_data *data, t_byte idc);

int						stack_size(t_stack *stack);
t_stack					*stack_new(void);
t_stack					*stack_last(t_stack *stack);
void					stack_add_front(t_stack **stack, t_stack *node);
void					stack_clear(t_stack **stack);

// cleaning
void					purge_and_exit(t_stack **stack, t_data *data, int code);

#endif
