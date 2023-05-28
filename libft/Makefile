# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 14:19:51 by jocaball          #+#    #+#              #
#    Updated: 2023/05/26 18:45:39 by jocaball         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HDR = libft.h

SRC	= ft_isalpha.c		ft_isdigit.c			ft_isalnum.c		\
	  ft_isascii.c		ft_isprint.c			ft_strlen.c			\
	  ft_memset.c		ft_bzero.c				ft_memcpy.c			\
	  ft_memmove.c		ft_strlcpy.c			ft_strlcat.c		\
	  ft_toupper.c		ft_tolower.c 			ft_strchr.c 		\
	  ft_strrchr.c		ft_strncmp.c 			ft_memchr.c 		\
	  ft_memcmp.c		ft_strnstr.c			ft_atoi.c 			\
	  ft_calloc.c 		ft_strdup.c				ft_substr.c 		\
	  ft_strjoin.c		ft_strtrim.c			ft_split.c			\
	  ft_itoa.c			ft_strmapi.c 			ft_striteri.c 		\
	  ft_putchar_fd.c	ft_putstr_fd.c			ft_putendl_fd.c		\
	  ft_putnbr_fd.c	ft_lstnew.c 			ft_lstadd_front.c	\
	  ft_lstsize.c		ft_lstlast.c			ft_lstadd_back.c 	\
	  ft_lstdelone.c	ft_lstclear.c			ft_lstiter.c		\
	  ft_lstmap.c		ft_printf.c				pf_char_convert.c	\
	  pf_str_convert.c	pf_hex_convert.c		pf_int_convert.c	\
	  pf_uint_convert.c	pf_flags_read.c			ft_htoa.c			\
	  ft_uitoa.c		ft_putchar.c			ft_putstr.c			\
	  get_next_line.c	get_next_line_utils.c

OBJ = $(SRC:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = ar rcs 

all : $(NAME)

$(NAME): $(OBJ) $(HDR)
	@$(LIB) $(NAME) $(OBJ)
	@echo "Library has been created"

clean :
	rm -f $(OBJ) $(OBJ_BONUS) 

fclean : clean
	rm -f $(NAME)

re : fclean all
