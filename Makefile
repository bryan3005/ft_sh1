# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/08 10:21:53 by mbryan            #+#    #+#              #
#    Updated: 2015/01/19 10:08:13 by mbryan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ft_minishell1

OBJ = ft_sh1.o get_next_line.o ft_setenv.o ft_unsetenv.o

PATH_INCLUDES = includes/

INCLUDES_NAME = ft_sh1.h get_next_line.h

INCLUDES = $(addprefix $(PATH_INCLUDES),$(INCLUDES_NAME))

FLAGS = -Wall -Wextra -Werror

.PHONY: make, all, $(NAME), libft/libft.a, clean, fclean, re, norme

all : $(NAME)

$(NAME) : $(OBJ) libft/libft.a
			gcc $(FLAGS) -o $(NAME) $(OBJ) libft/libft.a

$(OBJ): %.o: %.c $(INCLUDES)
			gcc $(FLAGS) -I $(PATH_INCLUDES) -c $< -o $@

libft/libft.a :
			make -C libft/

clean :
			@rm -f $(OBJ)
			@echo "clean done"

fclean : clean
			rm -f $(NAME)

re : fclean all

norme :
			norminette $(OBJ:.o=.c) $(INCLUDES)
			make -C libft/ norme