# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/21 19:02:56 by heltayb           #+#    #+#              #
#    Updated: 2024/07/28 20:22:45 by heltayb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: clean
	cc -I mlx   main.c mlx/libmlx.a -framework OpenGL -framework AppKit -o raycast && ./raycast
3d: clean
	cc -I mlx   main3d.c mlx/libmlx.a -framework OpenGL -framework AppKit -o raycast3d && ./raycast3d

test: clean
	cc -fsanitize=address -g3 -I mlx   test.c mlx/libmlx.a -framework OpenGL -framework AppKit -o test && ./test

clean:
	rm -f raycast raycast3d test