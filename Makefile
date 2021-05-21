# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: legunshi <legunshi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/05 18:32:38 by legunshi          #+#    #+#              #
#    Updated: 2020/12/14 21:05:58 by legunshi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

SRC =	src/ft_printf.c \
		src/char.c \
		src/string.c \
		src/diux.c \
		src/pointer.c \
		src/percent.c \
		src/parser.c \
		src/utils.c \
		src/conversions.c \
			
OBJ =	$(SRC:.c=.o)

CC =	gcc

FLAGS =	-Werror -Wall -Wextra

RM =	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		
%.o:%.c		ft_printf.h
		$(CC) $(FLAGS) -c $< -o $@

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: clean fclean all re
