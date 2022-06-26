/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:11:54 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/26 16:12:25 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eating(t_philo *p)
{
	int	eat_time;

	eat_time = p->arg.t_to_eat - ft_get_time(p->start);
	if (eat_time <= 0)
		ft_start_to_sleep(p);
	else
		ft_sleep(p, eat_time);
}
