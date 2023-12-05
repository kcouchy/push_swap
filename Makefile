# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 10:04:34 by kcouchma          #+#    #+#              #
#    Updated: 2023/12/05 15:09:29 by kcouchma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =								\
				push_swap			\
				errors				\
				check_inputs		\
				make_lists			\
				mod_lists			\
				sorting				\
				sorting_combi		\
				push_swap_utils

BONUS_SRCS =						\
				

INC_FILES = -I libft

SRC = $(addsuffix .c,$(SRCS))
BSRC = $(addsuffix .c,$(BONUS_SRCS))
OBJ = $(addsuffix .o,$(SRCS))
BOBJ = $(addsuffix .o,$(BONUS_SRCS))

CC = cc
CCFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

all: $(NAME)

$(NAME) : $(OBJ)
	make -C libft bonus
	$(CC) -o $@ $(OBJ) libft/libft.a

%.o: %.c
	$(CC) -c -o $@ $< $(CCFLAGS) $(INC_FILES)

bonus : all

clean :
	make -C libft clean
	rm -rf $(OBJ) $(BOBJ)

fclean : clean
	make -C libft fclean
	rm -rf $(NAME)

re : fclean
	make

.PHONY : all bonus clean fclean re