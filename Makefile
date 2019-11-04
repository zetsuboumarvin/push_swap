# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/17 12:17:02 by jflorent          #+#    #+#              #
#    Updated: 2019/11/04 18:34:21 by jflorent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CH = checker
PR_NAME = libftprintf.a
MAKE = make
LIBDIR = ft_printf/libft/
PRINTFDIR = ft_printf/
FLAGS = -Wall -Werror -Wextra
SRCS = parse_string.c stack.c checker.c commands.c stack2.c
OBJS = $(SRCS:.c=.o)

all: $(NAME_CH)

$(PR_NAME):
	cd $(PRINTFDIR) && $(MAKE)

%.o: %.c
	gcc -c $(FLAGS) $<

$(NAME_CH): $(PR_NAME) $(OBJS)
	gcc -g $(FLAGS) -L$(PRINTFDIR) -lftprintf $(OBJS) -o $@

clean:
	rm -f $(OBJS)
	cd $(PRINTFDIR) && $(MAKE) clean

fclean: clean
	rm -f $(NAME_CH)
	cd $(PRINTFDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
