# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: skhalil <skhalil@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/23 13:27:03 by skhalil        #+#    #+#                 #
#    Updated: 2020/01/12 18:20:50 by skhalil       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

H_DIR = .

NAME = libftprintf.a

BASENAMES = test_func
SRCS = $(addsuffix .c,$(BASENAMES))
OBJS = $(addsuffix .o,$(BASENAMES))

FLAGS = -Wall -Werror -Wextra

#BONUS_O =

all: $(NAME)

$(NAME): lib

lib: $(OBJS)
	cd libft && make && cd ../;
	ar -q libft/libft.a $(OBJS)
	cp libft/libft.a $(NAME)

clean:
	cd libft && make clean && cd ../;
	/bin/rm -f $(OBJS)

fclean: clean
	cd libft && make fclean && cd ../;
	/bin/rm -f $(NAME)
#	/bin/rm -f $(BONUS_O)

re: fclean all
	cd libft && make re && cd ../;

%.o: %.c
	gcc -c $(FLAGS) -I $(H_DIR) $< -o $@

test:
	@echo ""
	@echo "===TEST SEQUENCE==="
	@gcc $(FLAGS) test_main.c ft_printf_preprod.c
	@./a.out
	@echo "===ENDTEST==="
	@echo ""

#bonus: $(BONUS_O) $(OBJS)
#	ar rc $(NAME) $(OBJS) $(BONUS_O)