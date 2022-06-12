/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:53:58 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/12 21:52:24 by bregneau         ###   ########.fr       */
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

typedef struct s_fork
{
	int				status;
	pthread_mutex_t	*mutex;
}	t_fork;

typedef struct s_philo
{
	int			id;
	pthread_t	th;
	t_fork		*my_fork[2];
	int			eaten;
	t_arg		arg;
}	t_philo;

typedef struct s_data
{
	t_arg		arg;
	t_philo		*philo_tab;
	t_fork		*fork_tab;
}	t_data;

//threads

void	*ft_philo_routine(void *arg);

//utils

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dst, const char *src);


int		ft_return_error(char *message);
int		ft_get_time(int d);
void	ft_putstr_mutex(char *str, pthread_mutex_t *mutex);

#endif