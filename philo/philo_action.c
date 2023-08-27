/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 22:16:30 by junglee           #+#    #+#             */
/*   Updated: 2023/08/25 22:17:35 by junglee          ###   ########.fr       */
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
	philo_print_take_fork(philo);
	pthread_mutex_lock(&(philo->shared->fork[second]));
	philo_print_take_fork(philo);
	philo->last_eat = get_time();
	philo_print_eating(philo);
	ft_usleep(philo->arg.eating_time * 1000);
	pthread_mutex_unlock(&(philo->shared->fork[second]));
	pthread_mutex_unlock(&(philo->shared->fork[first]));
	(philo->eat_cnt)++;
	if ((philo->eat_cnt == philo->arg.must_eat) && (philo->eat_flag == 0))
	{
		(philo->shared->done_philo)++;
		philo->eat_flag = 1;
	}
}

void	philo_action_sleep(t_philosopher *philo)
{
	philo_print_sleeping(philo);
	ft_usleep(philo->arg.sleeping_time * 1000);
}

void	philo_action_thinking(t_philosopher *philo)
{
	philo_print_thinking(philo);
	usleep(10);
}

//void	ft_usleep(useconds_t time) //1000
//{
//	unsigned long long	slice_time;

//	slice_time = 0;
//	while (1)
//	{
//		slice_time += 100; // 100
//		usleep(100);
//		if (slice_time >= time)
//			return ;
//	}
//}

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
