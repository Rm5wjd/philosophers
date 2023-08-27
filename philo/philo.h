/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:01:14 by junglee           #+#    #+#             */
/*   Updated: 2023/08/27 20:02:45 by junglee          ###   ########.fr       */
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
	pthread_mutex_t		end_check;
	unsigned long long	init_time;
	int					end_flag;
	int					done_philo;
}	t_shared;

typedef struct s_philosopher
{
	int					self;
	int					left;
	int					right;
	int					eat_flag;
	unsigned long long	last_eat;
	unsigned int		eat_cnt;
	t_arg				arg;
	t_shared			*shared;
}	t_philosopher;

//main
void				*philo_start(void *data);
void				monitor_func(t_philosopher *philo, t_arg arg);
void				free_thread(pthread_t *p, t_arg arg, t_shared *shared);
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
void				ft_usleep(useconds_t time);

int					ft_atoi(const char *str);

#endif