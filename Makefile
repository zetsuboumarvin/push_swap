# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/17 12:17:02 by jflorent          #+#    #+#              #
#    Updated: 2019/11/04 13:59:40 by jflorent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CH = checker
PR_NAME = libftprintf.a
MAKE = make
LIBDIR = ft_printf/libft/
PRINTFDIR = ft_printf/
FLAGS = -Wall -Werror -Wextra
SRCS = main.c parse_string.c stack.c
OBJS = $(SRCS:.c=.o)

all: $(NAME_CH)

$(PR_NAME):
	cd $(PRINTFDIR) && $(MAKE)

%.o: %.c
	gcc -c $(FLAGS) $<

$(NAME_CH): $(PR_NAME) $(OBJS)
	gcc $(FLAGS) -L$(PRINTFDIR) -lftprintf -o $@

clean:
	rm -f $(OBJS)
	cd $(PRINTFDIR) && $(MAKE) clean

fclean: clean
	rm -f $(NAME_CH)
	cd $(PRINTFDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
