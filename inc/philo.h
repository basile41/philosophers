/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:53:58 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/25 11:54:09 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define RIGHT 0
# define LEFT 1

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <errno.h>
# include <ctype.h>

typedef struct s_arg
{
	int	nb_of_philo;
	int	t_to_die;
	int	t_to_sleep;
	int	nb_of_meal;
}	t_arg;

typedef struct s_philo
{
	int			id;
	int			*my_fork[2];
	int			eaten;
	t_arg		*arg;
}	t_philo;

typedef struct s_data
{
	int				nb_of_philo;
	int				t_to_die;
	int				t_to_sleep;
	int				nb_of_meal;
	t_philo			philo_tab[200];
	int				fork_tab[200];
}	t_data;

void	*ft_philo(void *arg);

//utils

int		ft_atoi(const char *str);
int		ft_return_error(char *message);
int		ft_get_time(int d);

#endif