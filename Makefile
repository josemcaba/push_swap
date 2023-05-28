# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 12:40:42 by jocaball          #+#    #+#              #
#    Updated: 2023/05/27 12:40:42 by jocaball         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HDR = 

SRC	= 	push_swap.c		parser.c	swap_rules.c
		
LIBFT = ./libft/libft.a

MAKE_LIBFT = @make -C ./libft

CC = gcc
CFLAGS = -Wall -Werror -Wextra -o $(NAME)

all : make_ft $(NAME)

make_ft:
	$(MAKE_LIBFT)

$(NAME): $(LIBFT) $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT)
	@echo "-------> Program $(NAME) has been created"

clean :
	rm -f $(OBJ)
	$(MAKE_LIBFT) clean 

fclean : clean
	rm -f $(NAME)
	$(MAKE_LIBFT) fclean

re : fclean all

.PHONY: all make_ft clean fclean re

# bonus : all
# 	$(MAKE_LIBFT) bonus
# 	@cp $(LIBFT) $(NAME)
# 	@$(LIB) $(NAME) $(OBJ)
# 	@echo "-------> Library $(NAME) has been created including bonus functions"
