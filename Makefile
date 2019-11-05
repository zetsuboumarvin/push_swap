# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/17 12:17:02 by jflorent          #+#    #+#              #
#    Updated: 2019/11/05 18:40:30 by jflorent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CH = checker
NAME_PS = push_swap
PR_NAME = libftprintf.a
MAKE = make
LIBDIR = ft_printf/libft/
PRINTFDIR = ft_printf/
FLAGS = -Wall -Werror -Wextra
SRCS = parse_string.c stack.c commands.c stack2.c
OBJS = $(SRCS:.c=.o)

all: $(NAME_CH) $(NAME_PS)

$(PR_NAME):
	cd $(PRINTFDIR) && $(MAKE)

%.o: %.c
	gcc -c $(FLAGS) $<

$(NAME_CH).o: $(NAME_CH).c
	gcc -c $(FLAGS) $<

$(NAME_PS).o: $(NAME_PS).c
	gcc -c $(FLAGS) $<

$(NAME_CH): $(PR_NAME) $(OBJS) $(NAME_CH).o
	gcc $(FLAGS) -L$(PRINTFDIR) -lftprintf $(OBJS) $@.o -o $@

$(NAME_PS): $(PR_NAME) $(OBJS) $(NAME_PS).o
	gcc $(FLAGS) -L$(PRINTFDIR) -lftprintf $(OBJS) $@.o -o $@

clean:
	rm -f $(OBJS) $(NAME_CH).o $(NAME_PS).o
	cd $(PRINTFDIR) && $(MAKE) clean

fclean: clean
	rm -f $(NAME_CH) $(NAME_PS)
	cd $(PRINTFDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
