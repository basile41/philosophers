/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:28:47 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/27 14:18:43 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_philos(t_philo *p)
{
	int	i;

	i = 0;
	while (i < p->arg.nb_of_philo)
	{
		pthread_create(&p->th, 0, ft_philo_routine, (void *)p);
		p++;
		i++;
	}
}

int	ft_init(t_data *data)
{
	int		i;
	t_philo	*p;

	p = ft_calloc(data->arg.nb_of_philo, sizeof(t_philo));
	data->fork_tab = ft_calloc(data->arg.nb_of_philo, sizeof(t_fork));
	if (p == NULL || data->fork_tab == NULL)
		return (ft_return_error("malloc error"));
	data->philo_tab = p;
	pthread_mutex_init(&data->print_mutex, 0);
	i = 0;
	while (i < data->arg.nb_of_philo)
	{
		p->print_mutex = &data->print_mutex;
		p->arg = data->arg;
		p->id = i + 1;
		p->my_fork[LEFT] = &data->fork_tab[i];
		p->my_fork[RIGHT] = &data->fork_tab[i + 1];
		p->is_end = &data->is_end;
		if (p->id == data->arg.nb_of_philo)
			p->my_fork[RIGHT] = &data->fork_tab[0];
		pthread_mutex_init(&data->fork_tab[i].mutex, 0);
		i++;
		p++;
	}
	ft_create_philos(data->philo_tab);
	return (0);
}
