# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 14:24:51 by mkarim            #+#    #+#              #
#    Updated: 2022/04/25 14:41:47 by mkarim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

HEADER = fractol.h

SRC = fractol.c ft_utils.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "Compilation of fractol: \033[1;32mOK\033[m"

%.o : %.c
	$(CC) $(FLAGS) -c $<

clean :
	rm $(OBJ)
	@echo "\033[1;33m>> all objects files are deleted.\033[0m"

fclean : clean
	rm -rf $(NAME)
	@echo "\033[0;31m>> $(NAME) is deleted.\033[0m"

re : fclean all
