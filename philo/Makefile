# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 17:45:27 by bregneau          #+#    #+#              #
#    Updated: 2022/07/01 15:38:14 by bregneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo

INC				=	-I ./inc

SRC_PATH		=	./src/
OBJ_PATH		=	./obj/

UTILS_DIR		=	utils/
THREADS_DIR		=	threads/

OBJ_DIRS		=	$(OBJ_PATH) \
					$(addprefix $(OBJ_PATH), utils/ threads)

SRC_THREADS		=	ft_create_philo.c \
					ft_destroy.c \
					ft_eating.c \
					ft_routine.c \
					ft_sleeping.c \
					ft_try_to_eat.c

SRC_UTILS		=	ft_atoi.c \
					ft_calloc.c \
					ft_get_time.c \
					ft_itoa.c \
					ft_nb_of_meal.c \
					ft_return_error.c \
					ft_safe_print.c \
					ft_str.c

SRC				= 	main.c \
					ft_init.c \
					ft_parsing.c \
					$(addprefix $(UTILS_DIR), $(SRC_UTILS)) \
					$(addprefix $(THREADS_DIR), $(SRC_THREADS))
					
OBJ				=	$(addprefix $(OBJ_PATH),$(SRC:.c=.o))
DEPS			=	$(addprefix $(OBJ_PATH),$(SRC:.c=.d))

LIB			=	-lpthread

CC				=	cc
CFLAGS			=	-MMD -Wall -Wextra -Werror -g3 $(INC)

all:				$(NAME)

$(OBJ_DIRS):
					@mkdir -p $(OBJ_DIRS)

$(OBJ_PATH)%.o:		$(SRC_PATH)%.c
					@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):			$(OBJ_DIRS) $(OBJ)
					$(CC) $(OBJ) $(LIB) -o $(NAME) #-fsanitize=address

clean:		
					rm -rf $(OBJ_PATH)

fclean:				clean
					rm -f $(NAME)

re:					fclean
					make all

-include			$(DEPS)

.PHONY:				all bonus clean fclean re
