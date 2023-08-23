/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 22:16:30 by junglee           #+#    #+#             */
/*   Updated: 2023/08/23 18:34:13 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_action_eat(t_philosopher *philo)
{
	if (philo->self % 2 == 0)
	{
		//usleep(100);
		pthread_mutex_lock(&(philo->shared->fork[philo->right]));
		pthread_mutex_lock(&(philo->shared->fork[philo->left]));
		philo_print_take_fork(philo);
		philo->last_eat = get_time();
		philo_print_eating(philo);
		usleep(philo->arg.eating_time * 1000);
		pthread_mutex_unlock(&(philo->shared->fork[philo->right]));
		pthread_mutex_unlock(&(philo->shared->fork[philo->left]));
	}
	else
	{
		pthread_mutex_lock(&(philo->shared->fork[philo->left]));
		pthread_mutex_lock(&(philo->shared->fork[philo->right]));
		philo_print_take_fork(philo);
		philo->last_eat = get_time();
		philo_print_eating(philo);
		usleep(philo->arg.eating_time * 1000);
		pthread_mutex_unlock(&(philo->shared->fork[philo->left]));
		pthread_mutex_unlock(&(philo->shared->fork[philo->right]));
	}
	(philo->eat_cnt)++;
}

void	philo_action_sleep(t_philosopher *philo)
{
	philo_print_sleeping(philo);
	usleep(philo->arg.sleeping_time * 1000);
}

void	philo_action_thinking(t_philosopher *philo)
{
	philo_print_thinking(philo);
	usleep(100);
}
