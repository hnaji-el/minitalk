
NAME = client server

SRCS_S = ./srcs/server.c \
		 ./srcs/server_utils.c

SRCS_C = ./srcs/client.c \
		 ./srcs/client_utils.c

INCLUDE_S = ./includes/server.h

INCLUDE_C = ./includes/client.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

server: $(SRCS_S) $(INCLUDE_S)
	gcc $(FLAGS) $(SRCS_S) -o server

client:  $(SRCS_C) $(INCLUDE_C)
	gcc $(FLAGS) $(SRCS_C) -o client

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
