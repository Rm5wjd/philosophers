/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 22:16:30 by junglee           #+#    #+#             */
/*   Updated: 2023/08/18 22:20:26 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_eat(t_visor *visor, int i)
{
	t_philosopher philo;

	philo = visor->philos[i];
	if (philo.self % 2 == 0)
	{
		pthread_mutex_lock(&visor->fork[philo.left]);
		pthread_mutex_lock(&visor->fork[philo.right]);
		usleep(visor->eat_time * 1000);
		pthread_mutex_unlock(&visor->fork[philo.left]);
		pthread_mutex_unlock(&visor->fork[philo.right]);
	}
	else
	{

	}
}