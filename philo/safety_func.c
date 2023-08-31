/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:11:24 by junglee           #+#    #+#             */
/*   Updated: 2023/08/31 20:40:57 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static size_t	ft_strlen(const char *s);

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

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
