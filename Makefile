# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 13:38:37 by linhnguy          #+#    #+#              #
#    Updated: 2023/11/30 18:17:26 by linhnguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a
LIBFTDIR = libft
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): makelibft $(OBJS)
	@cp $(LIBFTDIR)/$(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@echo "Compiled $(NAME)"

makelibft:
	@make -C $(LIBFTDIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $<"

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFTDIR) clean
	@echo "Cleaned object files"

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFTDIR) fclean
	@echo "Fully cleaned the project"

re: fclean all