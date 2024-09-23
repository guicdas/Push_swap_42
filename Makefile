# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 17:26:30 by gcatarin          #+#    #+#              #
#    Updated: 2023/06/07 13:12:51 by gcatarin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -I./
RM				= rm -fr

NAME			= push_swap.a
HEADER			= push_swap.h

SOURCES			= srcs/push_swap.c srcs/crialistas.c srcs/checker.c srcs/organize.c \
				 srcs/exceptions.c srcs/excephelp.c srcs/instructions.c srcs/swap_push.c

SOURCES_O		= $(SOURCES:srcs/%.c=objs/%.o)

all:			$(NAME)

$(NAME):		$(SOURCES_O)
	ar -rcs $(NAME) $(SOURCES_O)

objs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(SOURCES_O)

fclean:			clean
	$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re