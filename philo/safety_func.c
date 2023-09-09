/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:11:24 by junglee           #+#    #+#             */
/*   Updated: 2023/09/09 16:39:47 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <unistd.h>

void	*malloc_s(size_t size)
{
	void	*re;

	re = malloc(size);
	if (!re)
	{
		write(2, "malloc crash!\n", ft_strlen("malloc crash!\n"));
		exit(1);
	}
	return (re);
}
