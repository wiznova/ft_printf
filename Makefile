# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: skhalil <skhalil@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/23 13:27:03 by skhalil        #+#    #+#                 #
#    Updated: 2020/02/12 18:47:24 by skhalil       ########   odam.nl          #
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
	@echo ""
	@echo "#################################"
	@echo "#################################"
	@echo "#################################"
	@echo "#################################"
	@echo "#################################"
	@date
	@echo "#################################"
	@echo "#################################"
	@echo ""
	@echo ""
	@echo "===\x1b[1mTEST SEQUENCE\x1b[0m==="
	@echo ""
	@gcc $(FLAGS) $(SRCS) test_main.c gnl/get_next_line.c gnl/get_next_line_utils.c -g -L./libft -lft -g 
	@./a.out
	@echo ""
	@echo "===\x1b[1mENDTEST\x1b[0m==="
	@echo ""
	@echo ""
	@echo "#################################"

test_pars:
	@gcc $(FLAGS) $(SRCS) test_parser.c gnl/get_next_line.c gnl/get_next_line_utils.c -g -L./libft -lft -g -o parser.out
	@./parser.out

#bonus: $(BONUS_O) $(OBJS)
#	ar rc $(NAME) $(OBJS) $(BONUS_O)