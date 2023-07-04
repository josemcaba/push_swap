# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 12:40:42 by jocaball          #+#    #+#              #
#    Updated: 2023/07/04 17:31:32 by jocaball         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEF_COLOR = \033[0;39m
BLACK	  =	\033[0;30m
RED		  =	\033[1;91m
GREEN	  =	\033[1;92m
YELLOW	  = \033[0;93m
BLUE	  = \033[0;94m
MAGENTA	  = \033[0;95m
CYAN	  = \033[0;96m
GRAY	  = \033[0;90m
WHITE	  = \033[0;97m

NAME = push_swap

NAME_BONUS = checker

HDR = push_swap.h

SRC	= 	push_swap.c			\
		parser.c			\
		load_nodes.c 		\
		rules_push_swap.c	\
		rules_rot_rev.c		\
		check_order.c		\
		sort.c				\
		steps.c 			\
		exec.c				\
		setup.c				\
		let_move.c

SRC_BONUS	= 	checker.c			\
				parser.c			\
				load_nodes.c 		\
				rules_push_swap.c	\
				check_order.c		\
				rules_rot_rev.c		\
				sort.c				\
				steps.c 			\
				exec.c				\
				setup.c				\
				let_move.c
		
OBJ = $(SRC:%.c=%.o) $(SRC_BONUS:%.c=%.o)

LIBFT = ./libft/libft.a

MAKE_LIBFT = @make -C ./libft

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all : make_ft $(NAME)

make_ft:
	$(MAKE_LIBFT)

$(NAME): $(LIBFT) $(SRC) $(HDR)
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)\n-------> Program $(YELLOW)$(NAME)$(GREEN) has been created\n$(DEF_COLOR)"

clean :
	rm -f $(OBJ)
	$(MAKE_LIBFT) clean 

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE_LIBFT) fclean

re : fclean all

bonus : make_ft $(NAME_BONUS) 

$(NAME_BONUS): $(LIBFT) $(SRC_BONUS) $(HDR)
	@$(CC) $(CFLAGS) $(SRC_BONUS) $(LIBFT) -o $(NAME_BONUS)
	@echo "$(GREEN)\n-------> Program $(YELLOW)$(NAME_BONUS)$(GREEN) has been created\n$(DEF_COLOR)"
