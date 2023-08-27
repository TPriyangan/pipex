# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpriyang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 09:42:00 by tpriyang          #+#    #+#              #
#    Updated: 2023/01/16 11:08:53 by tpriyang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

SRCS = ft_strlen.c \
       ft_atoi.c \
       ft_isprint.c \
       ft_memmove.c \
       ft_strchr.c \
       ft_strmapi.c \
       ft_toupper.c \
       ft_bzero.c \
       ft_itoa.c \
       ft_memset.c \
       ft_strdup.c \
       ft_strncmp.c \
       ft_calloc.c \
       ft_putchar_fd.c \
       ft_striteri.c \
       ft_strnstr.c \
       ft_isalnum.c \
       ft_putendl_fd.c \
       ft_strjoin.c \
       ft_strrchr.c \
       ft_isalpha.c \
       ft_memchr.c \
       ft_putnbr_fd.c \
       ft_strlcat.c \
       ft_strtrim.c \
       ft_isascii.c \
       ft_memcmp.c \
       ft_putstr_fd.c \
       ft_strlcpy.c \
       ft_substr.c \
       ft_isdigit.c \
       ft_memcpy.c \
       ft_split.c \
       ft_tolower.c

BONUS_SRCS = ft_lstmap.c \
	     ft_lstadd_back.c \
	     ft_lstnew.c \
	     ft_lstadd_front.c \
	     ft_lstsize.c \
	     ft_lstclear.c \
	     ft_lstdelone.c \
	     ft_lstiter.c \
	     ft_lstlast.c

OBJS = $(SRCS:.c=.o)

HEADER = libft.h

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	ar rcs $(NAME) $(OBJS)

.c.o:
	$(CC) ${CFLAGS} -c $< -o $(<:.c=.o)

bonus: ${OBJS} ${BONUS_OBJS}
	ar rcs ${NAME} ${BONUS_OBJS} ${OBJS}

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME) *.o

re: $(fclean) all

.PHONY: all bonus clean fclean re
