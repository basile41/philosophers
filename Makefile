# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 17:45:27 by bregneau          #+#    #+#              #
#    Updated: 2022/06/11 18:30:58 by bregneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo


# **************************************************************************** #
#	SRCS	#

SRC_PATH =	./src/
OBJ_PATH =	./obj/

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

#SRC =		$(wildcard $(SRCSPATH)*.c) $(wildcard $(SRCSPATH)**/*.c)
SRC =		$(call rwildcard,$(SRC_PATH),*.c)
SRC_NAME =	$(subst $(SRC_PATH), , $(SRC))

OBJ_NAME =	$(SRC_NAME:.c=.o)
OBJ =		$(addprefix $(OBJ_PATH), $(OBJ_NAME))
					

# **************************************************************************** #

DEPS			=	$(addprefix $(OBJ_PATH),$(SRC:.c=.d))

LIBS			=	-lpthread

INC				=	-I ./inc

CC				=	cc
CFLAGS			=	-MMD -Wall -Wextra -Werror -g3 $(INC)

# **************************************************************************** #

all:				$(NAME)

$(OBJ_PATH)%.o:		$(SRC_PATH)%.c
					@mkdir -p $(dir $@)
					@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):			$(OBJ)
					$(CC) $(OBJ) $(LIBS) -o $(NAME) #-fsanitize=address

clean:		
					rm -rf $(OBJ_PATH)

fclean:				clean
					rm -f $(NAME)

re:					fclean
					make all

-include			$(DEPS)

.PHONY:				all bonus clean fclean re
