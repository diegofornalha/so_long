# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dida-sil <dida-sil@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 09:20:12 by dida-sil          #+#    #+#              #
#    Updated: 2022/09/08 20:20:44 by dida-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -o so_long -g -framework OpenGL -framework AppKit -L./minilibx -lmlx
RMFOR1337 = rm -rf a.out
RM = @rm -rf

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all:
	@echo $(B)[build started]$(B)
	$(CC) ./mainfiles/*.c $(FLAGS)
	make -C ./mainfiles
	@echo $(B)[build complete]$(B)

fclean:
	$(RM)  so_long so_long.dSYM
	$(RM) ./mainfiles/*.o ./mainfiles/mainfiles
	$(RM) ./minilibx/*.o
	@echo $(B)Removed [TEMPORARY FILES]$(X)
	@echo $(R)Removed [./mainfiles/*.o]$(X)
	@echo $(R)Removed [./minilibx/*.o]$(X)
	@echo $(R)Removed [REMOVED FINISH]$(X)
	@echo $(R)Removed [REMOVED FINISH]$(X)
	@echo $(R)Removed [REMOVED FINISH]$(X)
%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

norm:
	@echo $(B)[NORMINETTE SUCCES]$(B)
	norminette $(shell find ./mainfiles/ -name "*.c")

.PHONY: re norm fclean clean all
