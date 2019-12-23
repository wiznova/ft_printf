# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: skhalil <skhalil@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/23 13:27:03 by skhalil        #+#    #+#                 #
#    Updated: 2019/12/23 16:01:24 by skhalil       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

H_DIR = .

NAME = libftprintf.a

BASENAMES = hello
SRCS = $(addsuffix .c,$(BASENAMES))
OBJS = $(addsuffix .o,$(BASENAMES))

FLAGS = -Wall -Werror -Wextra

#BONUS_O =

all: $(NAME)

$(NAME): 
	echo $(OBJS)

lib:
	cd libft && make && cp libft.a ../libft.a && cd ../;

clean:
	cd libft && make clean && cd ../;
	/bin/rm -f libft.a
	/bin/rm -f $(OBJS)

fclean: clean
	cd libft && make fclean && cd ../;
	/bin/rm -f $(NAME)
#	/bin/rm -f $(BONUS_O)

re: fclean all
	cd libft && make re && cd ../;

#%.o: %.c
#	gcc -c $(FLAGS) -I $(H_DIR) $< -o $@

#bonus: $(BONUS_O) $(OBJS)
#	ar rc $(NAME) $(OBJS) $(BONUS_O)