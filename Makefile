# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 11:31:42 by lucmarti          #+#    #+#              #
#    Updated: 2019/02/28 14:22:13 by lucmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Green=\x1b[32m
End=\x1b[0m

TARGET = fractol

SRC_PATH = ./src
SRC_FILE := main.c init.c handler.c err.c julia. mandelbrot.c threads.c utils.c
SRC_FILE += pixel_color.c handler_aux.c tricorn.c burningship.c bonus.c

OBJ_PATH = ./objs
OBJ_FILE = $(SRC_FILE:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$($(SRC_FILE)))	
OBJ = $(addprefix $(OBJ_PATH)/,$($(OBJ_FILE)))	
LIB =	./libft.a ./libmlx.a

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I includes -I libft/ -I minilibx/

OPT = -O3 -funsafe-math-optimizations
LIBFLAGS = -framework OpenGL -framework AppKit -lm -lpthread

ifndef VERBOSE
.SILENT:
endif

all: $(TARGET)

$(TARGET): $(OBJ) libft libmlx 
	@gcc $(CFLAGS) $(LIBFLAGS) $(OPT) -o $(TARGET) $(OBJ) $(LIB)
	@echo "Compilation of fractol :    ${Green}Done${End}"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc $(CFLAGS) $(LIBFLAGS) $(OPT) -c $< $(CPPFLAGS) -o $@

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
