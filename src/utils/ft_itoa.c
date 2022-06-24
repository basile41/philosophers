/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 21:33:35 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/12 21:52:36 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*ft_strdup(const char *s1)
{
	size_t	size;
	size_t	i;
	char	*dst;

	size = ft_strlen(s1);
	dst = malloc((size + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_itoa(int n)
{
	long int	nb;
	char		tmp[12];
	int			i;

	nb = n;
	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (nb < 0)
	{
		tmp[i++] = '-';
		nb = -nb;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	tmp[i] = '\0';
	while (nb)
	{
		tmp[--i] = nb % 10 + '0';
		nb /= 10;
	}
	return (ft_strdup(tmp));
}