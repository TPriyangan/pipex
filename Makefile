# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpriyang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 13:31:55 by tpriyang          #+#    #+#              #
#    Updated: 2023/08/27 15:17:23 by tpriyang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NOM	= pipex
HEADER	= pipex.h
SRCS	= srcs/pipex.c srcs/pipexutils.c
OBJS	= ${SRCS:.c=.o}
MAIN	= srcs/pipex.c

CC	= gcc
CFLAGS  = -Wall -Wextra -Werror

%.o:	%.c ${HEADER}
	$(CC) $(CFLAGS) -c $< -o $@

all:	${NOM}

${NOM}:	${OBJS}
	@make re -C ./libft
	@$(CC) ${OBJS} -Llibft -lft -o ${NOM}

clean:
	@make clean -C ./libft
	@rm -f ${OBJS}

fclean:	clean
	@make fclean -C ./libft
	@rm -f $(NOM)
	@rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
