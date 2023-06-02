# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 12:40:42 by jocaball          #+#    #+#              #
#    Updated: 2023/06/02 22:44:31 by jocaball         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

HDR = push_swap.h

SRC	= 	push_swap.c			\
		parser.c			\
		rules_push_swap.c	\
		rules_rot_rev.c		\
		play.c

SRC_BONUS	= 	checker.c			\
				parser.c			\
				rules_push_swap.c	\
				rules_rot_rev.c		\
				play_bonus.c
		
OBJ = $(SRC:%.c=%.o) $(SRC_BONUS:%.c=%.o)

LIBFT = ./libft/libft.a

MAKE_LIBFT = @make -C ./libft

CC = gcc
CFLAGS = -Wall -Werror -Wextra 

all : make_ft $(NAME)

make_ft:
	$(MAKE_LIBFT)

$(NAME): $(LIBFT) $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)
	@echo "\n-------> Program $(NAME) has been created <-------\n"

clean :
	rm -f $(OBJ)
	$(MAKE_LIBFT) clean 

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE_LIBFT) fclean

re : fclean all

bonus : make_ft $(NAME_BONUS) 

$(NAME_BONUS): $(LIBFT) $(SRC_BONUS) $(HDR)
	$(CC) $(CFLAGS) $(SRC_BONUS) $(LIBFT) -o $(NAME_BONUS)
	@echo "\n-------> Program $(NAME_BONUS) has been created <-------\n"

.PHONY: all make_ft clean fclean re bonus