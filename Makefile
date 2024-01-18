# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 14:40:09 by lzaengel          #+#    #+#              #
#    Updated: 2024/01/18 14:45:44 by lzaengel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME_C = client

NAME_S = server

CFLAGS = -Wall -Werror -Wextra

SRC_C = client.c libft.c

SRC_S = server.c libft.c

OBJ_C = $(SRC_C:.c=.o)

OBJ_S = $(SRC_S:.c=.o)

all : $(NAME_C) $(NAME_S)

$(NAME_C) : $(OBJ_C)
			cc -o $(NAME_C) $(OBJ_C) $(CFLAGS)

$(NAME_S) : $(OBJ_S)
			cc -o $(NAME_S) $(OBJ_S) $(CFLAGS)

clean :
			rm -rf $(OBJ_C) $(OBJ_S)

fclean : clean
			rm -rf $(NAME_C) $(NAME_S)

re : fclean all

.PHONY : all clean fclean re