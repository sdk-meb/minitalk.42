
SERVER = server
CLIENT = client
LIBFT = libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJ_SERV = main_server.o
OBJ_CLNT = main_client.o

all: ${SERVER} ${CLIENT}
	@rm -rf ${OBJ_CLNT} ${OBJ_SERV}

${SERVER}: ${OBJ_SERV} 
	@CC ${FLAGS}  -o ${SERVER} ${OBJ_SERV} ${LIBFT}

${CLIENT}: ${OBJ_CLNT} 
	@CC ${FLAGS}  -o ${CLIENT} ${OBJ_CLNT} ${LIBFT}
 
bonus:

clean:

fclean:	clean
	@rm -rf ${NAME}  ${SERVER} ${CLIENT}

re : fclean all

.PHONY: re all fclean clean
