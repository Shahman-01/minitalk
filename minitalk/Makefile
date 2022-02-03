# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/17 14:52:05 by ppeapod           #+#    #+#              #
#    Updated: 2021/10/17 14:52:08 by ppeapod          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRV = server
SRV_BONUS = server_bonus
CLN = client
CLN_BONUS = client_bonus
LH = minitalk.h
GCC = gcc -Wall -Wextra -Werror
LIB =  -L./libft -lft
LIBFT = libft.a

all:  $(LIBFT) $(SRV) $(CLN)

$(LIBFT):
	$(MAKE) -C libft
$(CLN): client.o
	$(GCC) $(LIB) client.o -o $@
$(SRV): server.o
	$(GCC) $(LIB) server.o -o $@

bonus: $(LIBFT) $(SRV_BONUS) $(CLN_BONUS)

$(CLN_BONUS): client_bonus.o
	$(GCC) $(LIB) client_bonus.o -o $@
$(SRV_BONUS): server_bonus.o
	$(GCC) $(LIB) server_bonus.o -o $@

%.o: %.c $(LH) Makefile
	$(GCC) -c $<
clean:
	rm -f client.o server.o client_bonus.o server_bonus.o
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(SRV) $(CLN) $(SRV_BONUS) $(CLN_BONUS)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
