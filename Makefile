SRC_SERVER	= server.c\
			  ft_putnbr_fd.c\
			  
SRC_CLIENT	= client.c\
			  ft_atoi.c\

OBJS_SERVER	= $(SRC_SERVER:.c=.o)
OBJS_CLIENT	= $(SRC_CLIENT:.c=.o)

CC			= gcc -g -O2 -Wall -Werror -Wextra
RM			= rm -f
CLIENT		= client
SERVER		= server

all:		$(NAME)

$(SERVER):	 $(OBJS_SERVER)
				gcc -g ${OBJS_SERVER} -o server
				@echo "Done"

$(CLIENT):	 $(OBJS_CLIENT)
				gcc -g ${OBJS_CLIENT} -o client
				@echo "Done"

clean:
				$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)

fclean:
				$(RM) $(OBJS_CLIENT) $(OBJS_SERVER) $(SERVER) $(CLIENT)

re:			fclean $(NAME)

.PHONY:			all clean fclean re
