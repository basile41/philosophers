/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:52:59 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/24 18:18:57 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_end(t_philo *p)
{
	int	i;

	i = 0;
	while (i < p->arg.nb_of_philo)
	{
		pthread_join(p->th, 0);
		i++;
		p++;
	}
}

void	ft_set_arg(t_arg *arg, int argc, char **argv)
{
	arg->nb_of_philo = ft_atoi(argv[1]);
	arg->t_to_eat = ft_atoi(argv[2]);
	arg->t_to_die = ft_atoi(argv[3]);
	arg->t_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		arg->nb_of_meal = ft_atoi(argv[5]);
	else
		arg->nb_of_meal = -1;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		memset(&data, 0, sizeof(data));
		ft_get_time();
		ft_set_arg(&data.arg, argc, argv);
		ft_init(&data);
		ft_philo_end(data.philo_tab);
		free(data.philo_tab);
		free(data.fork_tab);
	}
}
