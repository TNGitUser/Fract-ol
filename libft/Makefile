# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucmarti <lucmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 15:37:09 by lucmarti          #+#    #+#              #
#    Updated: 2019/02/20 14:22:34 by lucmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC := 	./ft_atoi.c
SRC += 	./ft_atoi_base.c
SRC += 	./ft_bzero.c
SRC += 	./ft_isalnum.c
SRC +=  ./ft_isdigit.c
SRC +=	./ft_isalpha.c
SRC +=	./ft_isascii.c
SRC +=	./ft_isblank.c
SRC +=	./ft_isprint.c
SRC +=	./ft_isupper.c
SRC +=	./ft_itoa.c
SRC +=	./ft_lstadd.c
SRC +=	./ft_lstadd_back.c
SRC +=	./ft_lstdel.c
SRC +=	./ft_lstdelone.c
SRC +=	./ft_lstiter.c
SRC +=	./ft_lstmap.c
SRC +=	./ft_lstnew.c
SRC +=	./ft_lstfree_all.c
SRC +=	./ft_lstfree_at.c
SRC +=	./ft_lstsize.c
SRC +=	./ft_lstreplace.c
SRC +=	./ft_memalloc.c
SRC +=	./ft_memccpy.c
SRC +=	./ft_memchr.c
SRC +=	./ft_memcmp.c
SRC +=	./ft_memcpy.c
SRC +=	./ft_memdel.c
SRC +=	./ft_memmove.c
SRC +=	./ft_memset.c
SRC +=	./ft_putchar.c
SRC +=	./ft_putchar_fd.c
SRC +=	./ft_putendl.c
SRC +=	./ft_putendl_fd.c
SRC +=	./ft_putnbr.c
SRC +=	./ft_putnbr_fd.c
SRC +=	./ft_putstr.c
SRC +=	./ft_putstr_fd.c
SRC +=	./ft_strcapitalize.c
SRC +=	./ft_strcat.c
SRC +=	./ft_strchr.c
SRC +=	./ft_strclr.c
SRC +=	./ft_strcmp.c
SRC +=	./ft_strcpy.c
SRC +=	./ft_strdel.c
SRC +=	./ft_strdup.c
SRC +=	./ft_strequ.c
SRC +=	./ft_striter.c
SRC +=	./ft_striteri.c
SRC +=	./ft_strjoin.c
SRC +=	./ft_strlcat.c
SRC +=	./ft_strlen.c
SRC +=	./ft_strmap.c
SRC +=	./ft_strmapi.c
SRC +=	./ft_strncat.c
SRC +=	./ft_strncmp.c
SRC +=	./ft_strncpy.c
SRC +=	./ft_strnequ.c
SRC +=	./ft_strnew.c
SRC +=	./ft_strnstr.c
SRC +=	./ft_strrchr.c
SRC +=	./ft_strsplit.c
SRC +=	./ft_strstr.c
SRC +=	./ft_strsub.c
SRC +=	./ft_strtrim.c
SRC +=	./ft_tolower.c
SRC +=	./ft_toupper.c
SRC +=	./ft_vector2.c
SRC +=	./ft_dvector2.c
SRC +=	./ft_vector3.c
SRC +=	./ft_vector2cp.c
SRC +=	./ft_vector3cp.c
SRC +=  ./ft_max.c
SRC +=	./ft_mat.c
SRC +=	./ft_mat_op.c
SRC +=	./ft_mat_mul.c
SRC +=	./ft_power.c
SRC +=	./ft_abs.c
SRC +=	./ft_iscinstr.c
SRC +=	./ft_strfchr.c
SRC +=	./ft_ltoa.c
SRC +=	./ft_ftoa.c

# This is a minimal set of ANSI/VT100 color codes
_END=\x1b[0m
_BOLD=\x1b[1m
_UNDER=\x1b[4m
_REV=\x1b[7m

# Colors
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m

OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
	@echo "${_CYAN}Compilation done${_END}"
	@ar -rc $(NAME) $(OBJ) libft.h
	@echo "${_GREEN}Library created${_END}"
	@ranlib $(NAME)

%.o: %.c libft.h
	@gcc -Wall -Wextra -Werror -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@rm -f *.o
	@echo "${_RED}Objects cleaned${_END}"

fclean: clean
	@rm -f $(NAME)
	@echo "${_RED}Output deleted${_END}"

re: fclean all
