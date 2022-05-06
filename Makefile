# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 17:45:27 by bregneau          #+#    #+#              #
#    Updated: 2022/05/06 21:48:15 by bregneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo

INC				=	-I ./inc

SRC_PATH		=	./src/
OBJ_PATH		=	./obj/

_PATH		=	

OBJ_DIRS		=	$(OBJ_PATH) \
					# $(addprefix $(OBJ_PATH),parser/ builtins/ exec/ utils/)

SRC				= 	main.c \
					philo.c \
#					$(addprefix $(PARSER_PATH), $(SRC_PARSER))
					
OBJ				=	$(addprefix $(OBJ_PATH),$(SRC:.c=.o))
DEPS			=	$(addprefix $(OBJ_PATH),$(SRC:.c=.d))

# LIBS			=	-lreadline -Llibft -lft

CC				=	cc
CFLAGS			=	-MMD -Wall -Wextra -Werror -g3 $(INC)

all:				$(NAME)

$(OBJ_DIRS):
					@mkdir -p $(OBJ_DIRS)

$(OBJ_PATH)%.o:		$(SRC_PATH)%.c
					@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):			$(OBJ_DIRS) $(OBJ)
					$(CC) $(OBJ) -o $(NAME) #-fsanitize=address

clean:		
					rm -rf $(OBJ_PATH)

fclean:				clean
					rm -f $(NAME)

re:					fclean
					make all

-include			$(DEPS)

.PHONY:				all bonus clean fclean re
