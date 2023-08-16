# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ercdeniz <ercdeniz@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/16 12:56:48 by ercdeniz          #+#    #+#              #
#    Updated: 2023/08/16 12:56:49 by ercdeniz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
CLIENT = @$(CC) $(CFLAGS) client.c print.c -o $(NAME_CL)
SERVER = @$(CC) $(CFLAGS) server.c print.c -o $(NAME_SV)
NAME_CL = client
NAME_SV = server

all: $(NAME_CL) $(NAME_SV)
$(NAME_CL):
	$(CLIENT)
	@echo "\n\033[92m $@ built 💼\033[0m\n"
$(NAME_SV):
	$(SERVER)
	@echo "\n\033[92m $@ built 🖥️⚡\033[0m\n"
clean:
	@rm -rf $(NAME_CL) $(NAME_SV)
	@echo "\n\033[91m $(NAME_CL) and $(NAME_SV) removed 🗑️\033[0m\n"
fclean: clean
re: clean all
.PHONY: all clean fclean re
