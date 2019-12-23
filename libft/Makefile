# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: skhalil <skhalil@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/30 17:27:40 by skhalil        #+#    #+#                 #
#    Updated: 2019/12/01 14:30:57 by skhalil       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

H_DIR = .
OBJS =	ft_bzero.o ft_memset.o ft_strchr.o ft_strlen.o ft_strnstr.o \
		ft_strrchr.o ft_memcpy.o ft_isalpha.o ft_isdigit.o ft_isalnum.o \
		ft_memccpy.o ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o \
		ft_strncmp.o ft_memmove.o ft_memchr.o ft_memcmp.o ft_strlcpy.o \
		ft_strlcat.o ft_calloc.o ft_strdup.o ft_atoi.o ft_substr.o \
		ft_strjoin.o ft_strtrim.o ft_split.o ft_itoa.o ft_strmapi.o \
		ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o
BONUS_O =	ft_lstnew_bonus.o ft_lstadd_front_bonus.o ft_lstsize_bonus.o \
			ft_lstlast_bonus.o ft_lstadd_back_bonus.o ft_lstdelone_bonus.o \
			ft_lstclear_bonus.o ft_lstiter_bonus.o ft_lstmap_bonus.o 
NAME = libft.a
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(BONUS_O)

re: fclean all

%.o: %.c
	gcc -c $(FLAGS) -I $(H_DIR) $< -o $@

bonus: $(BONUS_O) $(OBJS)
	ar rc $(NAME) $(OBJS) $(BONUS_O)
