# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 09:31:12 by aalshafy          #+#    #+#              #
#    Updated: 2024/02/05 17:21:12 by aalshafy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFILES = \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c ft_atoi.c ft_strlen.c ft_strlcpy.c \
		ft_strlcat.c ft_strnstr.c ft_strncmp.c ft_strchr.c ft_strrchr.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
		ft_memcmp.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_puthex.c \
		ft_putadd.c ft_putunsigned.c ft_lstnew.c  ft_lstadd_front.c \
		ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c *ft_lstmap.c get_next_line.c \
		get_next_line_utils.c

OFILES = $(CFILES:.c=.o)
cc = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OFILES)
	ar -rcs $(NAME) $(OFILES)
	
%.o: %.c
	$(cc) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re