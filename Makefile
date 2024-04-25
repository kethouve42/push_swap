# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 15:06:59 by kethouve          #+#    #+#              #
#    Updated: 2024/01/15 15:34:40 by kethouve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRC = ft_atoi.c ft_check_errors.c ft_split.c indexage.c\
		main.c operation_double.c operations.c\
		ps_utils.c push_swap.c sorting.c

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
		$(CC) $(FLAGS) -o $@ $(OBJ)

all: $(NAME)

%.o : %.c $(HEADER_FILE)
		$(CC) $(FLAGS) -c $< -o $@

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re