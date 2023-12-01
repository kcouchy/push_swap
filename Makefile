# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 10:04:34 by kcouchma          #+#    #+#              #
#    Updated: 2023/12/01 10:30:15 by kcouchma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =								\
				push_swap			\
				errors				\
				check_inputs		\
				make_lists			\
				mod_lists

BONUS_SRCS =						\
				

INC_FILES = push_swap.h

SRC = $(addsuffix .c,$(SRCS))
BSRC = $(addsuffix .c,$(BONUS_SRCS))
OBJ = $(addsuffix .o,$(SRCS))
BOBJ = $(addsuffix .o,$(BONUS_SRCS))

CC = cc
CCFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) -o $@ $(OBJ)

%.o: %.c
	$(CC) -c $< -o $@ $(CCFLAGS)

bonus : all

clean :
	rm -rf $(OBJ) $(BOBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re