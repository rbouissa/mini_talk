NAME = server
NAME_C = client
NAME_B = server_bonus
NAME_B_C = client_bonus

FLAGS = -Wall -Werror -Wextra
RM = rm -f

SRC =  mendatory/minitalk_helpers.c

SRC_B = bonus/minitalk_helpers_bonus.c
SRC_S = mendatory/server.c
SRC_S_B = bonus/server_bonus.c
SRC_C = mendatory/client.c
SRC_C_B = bonus/client_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)
OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)
OBJ_S_B = $(SRC_S_B:.c=.o)
OBJ_C_B = $(SRC_C_B:.c=.o)

all:	$(NAME) $(NAME_C) 

bonus: $(NAME_B) $(NAME_B_C)

$(NAME):	$(OBJ) $(OBJ_S)
	cc $(FLAGS) $(OBJ) $(OBJ_S) -o $(NAME)

$(NAME_C):	$(OBJ) $(OBJ_C)
	cc $(FLAGS) $(OBJ) $(OBJ_C) -o $(NAME_C)

$(NAME_B):	$(OBJ_B) $(OBJ_S_B)
	cc $(FLAGS) $(OBJ_B) $(OBJ_S_B) -o $(NAME_B)

$(NAME_B_C): $(OBJ_B)  $(OBJ_C_B)
	cc $(FLAGS) $(OBJ_B) $(OBJ_C_B) -o $(NAME_B_C)
clean:	
	$(RM) $(OBJ) $(OBJ_B) $(OBJ_S) $(OBJ_C) $(OBJ_S_B) $(OBJ_C_B)

fclean:	clean
	$(RM) $(NAME) $(NAME_C) $(NAME_B) $(NAME_B_C)

re: fclean all

.PHONY: all clean fclean re bonus
