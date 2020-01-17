# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: skhalil <skhalil@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/23 13:27:03 by skhalil        #+#    #+#                 #
#    Updated: 2020/01/17 19:44:31 by skhalil       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

H_DIR = .

NAME = libftprintf.a

BASENAMES = module_parser tools ft_printf_preprod
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
	@gcc $(FLAGS) $(SRCS) test_main.c -g -L. -lftprintf
	@./a.out
	@echo "===ENDTEST==="
	@echo ""

#bonus: $(BONUS_O) $(OBJS)
#	ar rc $(NAME) $(OBJS) $(BONUS_O)