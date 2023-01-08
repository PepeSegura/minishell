# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 16:12:27 by psegura-          #+#    #+#              #
#    Updated: 2023/01/08 16:45:22 by psegura-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Colors ###

RESET	=	\033c
GREEN	=	\033[1;32m
RED		=	\033[0;31m
CYAN	=	\033[0;36m
WHITE	=	\033[0m

NAME = minishell

SRCS =							\
		srcs/main.c				\
								\
		srcs/readline/readline.c\
								\
		srcs/intro/intro.c		\

OBJS = $(SRCS:.c=.o)

LIB = libft/libft.a

CC = gcc
CFLAGS	 = #-Wall -Wextra -Werror
CFLAGS	+= -I inc
CFLAGS	+= -I libft
READLINE = -lreadline

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) $(READLINE) -o $(NAME)
	@echo "$(CYAN) ❄️ Operation Helsinki Completed ❄️"
	
all: $(NAME)

clean:
	make clean -C libft
	@rm -rf $(OBJS)

fclean: clean
	make fclean -C libft
	@rm -f $(NAME)

re: fclean all

norma:
	@echo 6e6f726d696e65747465207372637320696e6320313e2f6465762f6e756c6c3b206966205b5b20243f202d65712030205d5d3b207468656e206e6f726d696e65747465207372637320696e633b20656c7365206e6f726d696e65747465207372637320696e63207c206772657020274572726f7227203b206669 | xxd -r -p | zsh

.PHONY: all clean fclean re norma
