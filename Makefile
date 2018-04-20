# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jukim <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/02 22:49:27 by jukim             #+#    #+#              #
#    Updated: 2018/04/18 20:21:55 by jukim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf 
CFILES = main.c errorline.c validation.c
OFILES = $(CFILES:.c=.o)
SRC = $(addprefix src/, $(CFILES))
MLX = src/minilibx_macos
LIBFT = src/libft
CFLAGS = -I. -I $(MLX) -I $(LIBFT) -Wall -Wextra -Werror
LFLAGS = -L $(LIBFT) -lft
MFLAGS = -L $(MLX) -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME):
	@make -C $(MLX)
	@make -C $(LIBFT)
	@gcc $(CFLAGS) -c $(SRC)
	@gcc $(CFLAGS) $(LFLAGS) $(MFLAGS) $(OFILES) -o $(NAME)

clean:
	@/bin/rm -f $(OFILES)

fclean: clean
	@make fclean -C $(LIBFT)
	@make clean -C $(MLX)
	@/bin/rm -f $(NAME)

re: fclean all
