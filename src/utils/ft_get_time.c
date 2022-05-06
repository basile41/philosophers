/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 00:34:39 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/07 00:51:14 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_diff_time(struct timeval *time_zero)
{
	int				ret;
	struct timeval	time;

	ret = gettimeofday(&time, 0);
	if (ret < 0)
		return (ft_return_error("gettimeofday error"));
	return (time.tv_usec - time_zero->tv_usec);
}
