/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:19:32 by junglee           #+#    #+#             */
/*   Updated: 2023/09/27 19:22:26 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define FAILURE 1
#define SUCCESS 0

int	pick_fork_left(t_philosopher *philo, int fork_num)
{
	pthread_mutex_lock(&(philo->shared->fork_mutex[fork_num]));
	if (philo->shared->fork[fork_num])
	{
		pthread_mutex_unlock(&(philo->shared->fork_mutex[fork_num]));
		return (FAILURE);
	}
	pthread_mutex_unlock(&(philo->shared->fork_mutex[fork_num]));
	return (SUCCESS);
}

int	pick_fork_right(t_philosopher *philo, int fork_num)
{
	pthread_mutex_lock(&(philo->shared->fork_mutex[fork_num]));
	if (!philo->shared->fork[fork_num])
	{
		pthread_mutex_unlock(&(philo->shared->fork_mutex[fork_num]));
		return (FAILURE);
	}
	pthread_mutex_unlock(&(philo->shared->fork_mutex[fork_num]));
	return (SUCCESS);
}

void	put_fork(t_philosopher *philo, int first, int second)
{
	pthread_mutex_lock(&(philo->shared->fork_mutex[second]));
	philo->shared->fork[second] = !philo->shared->fork[second];
	pthread_mutex_unlock(&(philo->shared->fork_mutex[second]));
	pthread_mutex_lock(&(philo->shared->fork_mutex[first]));
	philo->shared->fork[first] = !philo->shared->fork[first];
	pthread_mutex_unlock(&(philo->shared->fork_mutex[first]));
}
