/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:01:14 by junglee           #+#    #+#             */
/*   Updated: 2023/08/23 16:38:59 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_arg
{
	int				number;
	unsigned int	eating_time;
	unsigned int	sleeping_time;
	unsigned int	dying_time;
	unsigned int	must_eat;
}	t_arg;

typedef struct s_shared
{
	pthread_mutex_t		*fork;
	pthread_mutex_t		std_out;
	unsigned long long	init_time;
	int					end_flag;
}	t_shared;

typedef struct s_philosopher
{
	int					self;
	int					left;
	int					right;
	unsigned long long	last_eat;
	unsigned int		eat_cnt;
	t_arg				arg;
	t_shared			*shared;
}	t_philosopher;

//main
void				*philo_start(void *data);
void				monitor_func(t_philosopher *philo, t_arg arg);
unsigned long long	get_time(void);

// init
void				philo_init_arg(t_arg *arg, char *argv[], int argc);
void				philo_init_shared(t_shared **shared, int number);
void				philo_init_sopher(t_philosopher *philo, t_arg arg, t_shared *shared);

//print
void				philo_print_take_fork(t_philosopher *philo);
void				philo_print_eating(t_philosopher *philo);
void				philo_print_sleeping(t_philosopher *philo);
void				philo_print_thinking(t_philosopher *philo);
void				philo_print_dying(t_philosopher *philo);

//action
void				philo_action_eat(t_philosopher *philo);
void				philo_action_sleep(t_philosopher *philo);
void				philo_action_thinking(t_philosopher *philo);

int					ft_atoi(const char *str);

#endif