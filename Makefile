# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 13:38:37 by linhnguy          #+#    #+#              #
#    Updated: 2023/12/01 15:05:06 by linhnguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a
LIBFTDIR = libft
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = ft_printf.c ft_speci.c ft_printx.c ft_printcs.c ft_printnbr.c
OBJS = $(SRCS:.c=.o)
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME):$(OBJS)
	@make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)
	
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[KCompiled $<\r"

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFTDIR) clean
	@echo "Cleaned object files"

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFTDIR) fclean
	@echo "Fully cleaned the project"

re: fclean all