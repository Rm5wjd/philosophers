/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 22:16:30 by junglee           #+#    #+#             */
/*   Updated: 2023/09/27 19:49:29 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define FAILURE 1
#define SUCCESS 0

void	philo_action_eat(t_philosopher *philo)
{
	while (pick_fork_left(philo, philo->left) == FAILURE)
		usleep (1);
	philo_print(philo, "has taken a fork");
	if (philo->arg.number == 1)
		return ;
	while (pick_fork_right(philo, philo->right) == FAILURE)
		usleep (1);
	philo_print(philo, "has taken a fork");
	pthread_mutex_lock(&(philo->last_eat_check));
	philo->last_eat = get_time();
	pthread_mutex_unlock(&(philo->last_eat_check));
	philo_print(philo, "is eating");
	ft_usleep(philo->arg.eating_time);
	put_fork(philo, philo->left, philo->right);
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
	ft_usleep(philo->arg.sleeping_time);
}

void	philo_action_thinking(t_philosopher *philo)
{
	philo_print(philo, "is thinking");
	usleep(100);
}

void	ft_usleep(unsigned int time)
{
	unsigned long long	into_function;

	into_function = get_time();
	while (1)
	{
		if (into_function + time <= get_time())
			break ;
		usleep(100);
	}
}
