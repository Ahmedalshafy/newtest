# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 09:31:12 by aalshafy          #+#    #+#              #
#    Updated: 2024/02/18 16:57:01 by aalshafy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###### // -Wall -Wextra -Werror -g3 -Wpedantic

NAME = push_swap
BONUS = checker
CFILES = 	ps_main_sort.c ps_stack_utils.c ps_swap.c ps_push.c push_swap.c \
			ps_prepare.c ps_parsing_1.c ps_parsing_2.c ps_last_cases.c \
			ps_rotate.c ps_rev_rotate.c ps_utils.c ps_utils_a.c ps_utils_b.c \
			ps_sort_3_a.c ps_sort_3_b.c ps_less_9.c ps_less_9_2.c
BONUS_FILES = ps_main_checker.c ps_parsing_1.c ps_parsing_2.c ps_stack_utils.c \
			ps_swap.c ps_push.c ps_rotate.c ps_rev_rotate.c ps_utils.c ps_prepare.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all:
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(CFILES) -o $(NAME) libft/libft.a

bonus:
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(BONUS_FILES) -o $(BONUS) libft/libft.a

clean:
	$(MAKE) clean -C ./libft

fclean: 
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re