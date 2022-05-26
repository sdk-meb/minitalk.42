
SERVER = server
CLIENT = client
LIBFT = libft/libft.a
PATHLIB= libft/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJ_SERV = main_server.o
OBJ_CLNT = main_client.o

all: ${LIBFT} ${SERVER} ${CLIENT}

${LIBFT}:
	@cd ${PATHLIB} && make
	
${SERVER}: ${OBJ_SERV}
	@CC ${FLAGS}  -o ${SERVER} ${OBJ_SERV} ${LIBFT}

${CLIENT}: ${OBJ_CLNT} 
	@CC ${FLAGS}  -o ${CLIENT} ${OBJ_CLNT} ${LIBFT}
 
bonus: ${SERVER} ${CLIENT}

clean:
	@rm -rf ${OBJ_CLNT} ${OBJ_SERV}
	@cd ${PATHLIB} && make clean

fclean:	clean
	@rm -rf ${NAME}  ${SERVER} ${CLIENT}	
	@cd ${PATHLIB} && make fclean

re : fclean all

.PHONY: re all fclean clean
