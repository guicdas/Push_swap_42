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

OBJS_DIR		= objs
SRCS_DIR		= srcs
NAME			= push_swap
HEADER			= push_swap.h

SOURCES			= $(SRCS_DIR)/ft_push_swap.c $(SRCS_DIR)/ft_create_lists.c $(SRCS_DIR)/ft_list_checker.c \
				$(SRCS_DIR)/ft_organize_lists.c $(SRCS_DIR)/ft_five_elements.c $(SRCS_DIR)/ft_utils_2.c \
				$(SRCS_DIR)/ft_instructions_1.c $(SRCS_DIR)/ft_instructions_2.c $(SRCS_DIR)/ft_utils_1.c

SOURCES_O		= $(SOURCES:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

all:			$(NAME)

$(NAME):		$(SOURCES_O)
	clear
	${CC} ${CFLAGS} $(SOURCES_O) -o ${NAME}

$(OBJS_DIR):
	mkdir -p objs

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $^ -o $@


%.o: %.c
	$(CC) $(CFLAGS) -o ${NAME} -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean:			clean
	$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re