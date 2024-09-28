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
CFLAGS			= -Wall -Wextra -Werror -I./ #-fsanitize=address
RM				= rm -fr

NAME			= push_swap.a
HEADER			= push_swap.h
EXE				= push_swap

SOURCES			= srcs/ft_push_swap.c srcs/ft_create_lists.c srcs/ft_list_checker.c \
				srcs/ft_organize_lists.c srcs/ft_five_elements.c srcs/ft_utils_2.c \
				srcs/ft_instructions_1.c srcs/ft_instructions_2.c srcs/ft_utils_1.c

SOURCES_O		= $(SOURCES:srcs/%.c=objs/%.o)

all:			$(NAME)

$(NAME):		$(SOURCES_O)
	ar -rcs $(NAME) $(SOURCES_O)

objs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

run:	re
	${CC} ${CFLAGS} ${NAME} -o ${EXE}

clean:
	$(RM) $(SOURCES_O)

fclean:			clean
	$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re