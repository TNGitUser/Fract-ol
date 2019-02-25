# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 11:31:42 by lucmarti          #+#    #+#              #
#    Updated: 2019/02/25 10:16:54 by lucmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Green=\x1b[32m
End=\x1b[0m

TARGET = fractol

SRC := ./src/main.c ./src/init.c ./src/handle.c /src/err.c
OBJ = $(SRC:.c=.o)
LIB =	./libft.a ./libmlx.a

CFLAGS = -Wall -Wextra -Werror
DEB = #-O3 -g3 -fsanitize=address
LIBFLAGS = -framework OpenGL -framework AppKit -lm -lpthread

ifndef VERBOSE
.SILENT:
endif

all: $(TARGET)

$(TARGET): $(OBJ) libft libmlx 
	@gcc $(CFLAGS) $(LIBFLAGS) $(DEB) -o $(TARGET) $(OBJ) $(LIB)
	@echo "${Green}fractol compiled${End}"

%.o: %.c ./libft.h ./minilibx/mlx.h
	@gcc $(CFLAGS) $(LIBFLAGS) $(DEB) -o $@ -c $<

.PHONY: libft libmlx clean fclean re

libft:
	@$(MAKE) -C ./libft
	@cp ./libft/libft.a ./

libmlx:
	@$(MAKE) -C ./minilibx
	@cp ./minilibx/libmlx.a ./

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C ./minilibx/ clean
	@$(MAKE) -C ./libft/ clean

fclean: clean
	@rm -f $(TARGET)
	@rm -f $(LIB)
	@$(MAKE) -C ./minilibx/ clean
	@$(MAKE) -C ./libft/ fclean

re: fclean all
