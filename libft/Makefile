# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 15:28:27 by dgrigor2          #+#    #+#              #
#    Updated: 2026/01/20 18:33:54 by dgrigor2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC  = cc
CFLAGS = -Wall -Wextra -Werror
DEPS = libft.h get_next_line.h
NAME = libft.a
GNL_SRCS = get_next_line.c get_next_line_utils.c
SRCS = ft_isalnum.c ft_isascii.c ft_isprint.c ft_memmove.c ft_strlcpy.c \
ft_bzero.c ft_isalpha.c ft_isdigit.c ft_memcpy.c ft_memset.c ft_strlen.c \
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
$(GNL_SRCS)
OBJS = $(SRCS:.c=.o)
LIBA = ar -rcs
BON_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BON_OBJS = $(BON_SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(LIBA) $(NAME) $(OBJS)

bonus: $(OBJS) $(BON_OBJS)
	$(LIBA) $(NAME) $^

%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BON_OBJS)

fclean: clean
	rm -f  $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
