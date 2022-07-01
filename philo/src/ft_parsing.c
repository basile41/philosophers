/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:43:36 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/30 18:28:46 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	ft_is_number(char *str)
// {
// 	while ()
// }

void	ft_error_args(char *arg)
{
	printf("error\n");
	printf("%s nb_of_philos time_to_die time_to_eat ", arg);
	printf("time_to_sleep [nb_of_meals_per_philo]\n");
}

int	ft_is_valid_nb(char *str)
{
	long	n;

	while (*str == ' ')
		str++;
	while (*str == '0')
		str++;
	if (ft_strlen(str) > 11)
		return (0);
	n = ft_atol(str);
	if (n > 0 && n <= 2147483647)
		return (n);
	else
		return (0);
}

int	ft_set_arg(t_arg *arg, int argc, char **argv)
{
	arg->nb_of_philo = ft_is_valid_nb(argv[1]);
	arg->t_to_die = ft_is_valid_nb(argv[2]);
	arg->t_to_eat = ft_is_valid_nb(argv[3]);
	arg->t_to_sleep = ft_is_valid_nb(argv[4]);
	if (argc == 6)
		arg->nb_of_meal = ft_is_valid_nb(argv[5]);
	else
		arg->nb_of_meal = -1;
	if ((arg->nb_of_philo && arg->t_to_die && arg->t_to_eat && arg->t_to_sleep
			&& arg->nb_of_meal) == 0)
		return (0);
	else
		return (1);
}

int	ft_parsing(t_arg *arg, int argc, char **argv)
{
	if (ft_set_arg(arg, argc, argv) == 0)
	{
		ft_error_args(argv[0]);
		return (0);
	}
	return (1);
}
