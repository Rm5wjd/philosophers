/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:01:14 by junglee           #+#    #+#             */
/*   Updated: 2023/08/18 22:16:01 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philosopher
{
	int				self;
	int				left;
	int				right;
	unsigned int	last_eat;
	unsigned int	eat_cnt;
}	t_philosopher;

typedef struct s_visor
{
	t_philosopher	*philos;
	pthread_mutex_t	*fork;
	pthread_mutex_t	std_out;
	unsigned int	eat_time;
	unsigned int	sleep_time;
	unsigned int	die_time;
	unsigned int	must_eat;
}	t_visor;

#endif