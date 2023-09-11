/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:01:14 by junglee           #+#    #+#             */
/*   Updated: 2023/09/11 16:38:10 by junglee          ###   ########.fr       */
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
	pthread_mutex_t		eat_cnt_check;
	unsigned long long	init_time;
	int					end_flag;
	int					done_philo;
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
	pthread_mutex_t		last_eat_check;
}	t_philosopher;

//main
void				*philo_start(void *data);
void				monitor_func(t_philosopher *philo, t_arg arg);
void				free_thread(pthread_t *p, t_arg arg, \
t_shared *shared, t_philosopher *philo);
unsigned long long	get_time(void);

// init
int					philo_init_arg(t_arg *arg, char *argv[], int argc);
void				philo_init_shared(t_shared **shared, int number);
void				philo_init_sopher(t_philosopher *philo, \
t_arg arg, t_shared *shared);
size_t				ft_strlen(const char *s);

//print
void				philo_print(t_philosopher *philo, const char *str);
void				philo_print_dying(t_philosopher *philo);

//action
void				philo_action_eat(t_philosopher *philo);
void				philo_action_sleep(t_philosopher *philo);
void				philo_action_thinking(t_philosopher *philo);
void				ft_usleep(useconds_t time);

//atoi
int					ft_atoi(const char *str);

//arg_parse
int					arg_range_check(t_arg *arg);

#endif