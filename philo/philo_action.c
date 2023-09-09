/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 22:16:30 by junglee           #+#    #+#             */
/*   Updated: 2023/09/09 16:17:47 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

inline static void	set_fork_order(int *first, int *second, \
t_philosopher *philo);

void	philo_action_eat(t_philosopher *philo)
{
	int	first;
	int	second;

	set_fork_order(&first, &second, philo);
	pthread_mutex_lock(&(philo->shared->fork[first]));
	philo_print(philo, "has taken a fork");
	if (philo->arg.number == 1)
		return ;
	pthread_mutex_lock(&(philo->shared->fork[second]));
	philo_print(philo, "has taken a fork");
	pthread_mutex_lock(&(philo->last_eat_check));
	philo->last_eat = get_time();
	// test **
	// pthread_mutex_lock(&(philo->shared->std_out));
	// printf("%d %lld\n", philo->self + 1, philo->last_eat);
	// pthread_mutex_unlock(&(philo->shared->std_out));
	// **
	pthread_mutex_unlock(&(philo->last_eat_check));
	philo_print(philo, "is eating");
	ft_usleep(philo->arg.eating_time * 1000);
	pthread_mutex_unlock(&(philo->shared->fork[second]));
	pthread_mutex_unlock(&(philo->shared->fork[first]));
	(philo->eat_cnt)++;
	if (philo->eat_cnt == philo->arg.must_eat)
	{
		pthread_mutex_lock(&(philo->shared->eat_cnt_check));
		(philo->shared->done_philo)++;
		pthread_mutex_unlock(&(philo->shared->eat_cnt_check));
	}
}

void	philo_action_sleep(t_philosopher *philo)
{
	philo_print(philo, "is sleeping");
	ft_usleep(philo->arg.sleeping_time * 1000);
}

void	philo_action_thinking(t_philosopher *philo)
{
	philo_print(philo, "is thinking");
	usleep(100);
}

void	ft_usleep(useconds_t time)
{
	unsigned long long	into_function;

	into_function = get_time();
	while (1)
	{
		if (into_function + (time / 1000) <= get_time())
			break ;
		usleep(100);
	}
}

inline static void	set_fork_order(int *first, int *second, \
t_philosopher *philo)
{
	if (philo->self % 2 == 0)
	{
		*first = philo->right;
		*second = philo->left;
	}
	else
	{
		*first = philo->left;
		*second = philo->right;
	}
}
