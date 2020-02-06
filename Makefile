# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablane <ablane@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 17:25:56 by ablane            #+#    #+#              #
#    Updated: 2020/02/04 09:35:35 by ablane           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = #-Wall -Werror -Wextra

LDFLAGS = -L./libft

LDHEAD = ./libft/inc/

LDLIBS = -lft

SRC_NAME =  ft_halper.c \
            ft_printf.c \
            ft_find_flag.c \
            ft_itoa_base.c \
            func_c.c \
            func_di.c \
            func_percent.c \
            func_s.c \
            func_p.c \
            func_o.c \
            func_u.c \
            func_x.c \
            func_f.c \
            string_list.c

OBJ = ./obj/

SRC = ./

OBJ_NAME = $(SRC_NAME:.c=.o)

HEAD = ./

.PHONY: all clean fclean re

all: create_obj $(NAME)


create_obj:
	@mkdir -p $(OBJ)

$(NAME): $(addprefix $(OBJ), $(OBJ_NAME))
	@make -C ./libft
	@ar rc $@ $^
	@ranlib $(NAME)
	@echo "\033[0;32m$(NAME)'s program created.\033[0m"

$(OBJ)%.o: $(SRC)%.c
	@$(CC) $(CFLAGS) -I $(HEAD) -I $(LDHEAD) -o $@ -c $<

clean:
	@rm -rf $(addprefix $(OBJ), $(OBJ_NAME))
	@rm -rf $(OBJ)
	@make -C ./libft clean
	@echo "\033[0;32m$(NAME)'s .o files deleted.\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make -C ./libft fclean
	@echo "\033[0;32m$(NAME) Project fully cleaned.\033[0m"

re: fclean all