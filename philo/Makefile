# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junglee <junglee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 15:40:44 by junglee           #+#    #+#              #
#    Updated: 2023/09/09 16:57:38 by junglee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
#DEBUG_FLAGS = -g -fsanitize=thread
SRCS_DIR = srcs

SRCS = ft_atoi.c philo_action.c philo_init.c philo_print.c philo.c safety_func.c monitor.c arg_parse.c

OBJS = $(SRCS:.c=.o)

$(NAME) :: $(OBJS)
	$(CC) $(CFLAGS) -I. -o $(NAME) $^ $(DEBUG_FLAGS)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -I. $< $(DEBUG_FLAGS) -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re