CC = cc -Wall -Werror -Wextra

### General srcs
SRC = teste.c

O_DIR = obj/
OBJ = $(SRC:%.c=$(O_DIR)%.o)
### Server variables
S_SRC = server.c

S_OBJ = $(S_SRC:%.c=$(O_DIR)%.o)
S_NAME = server

### Client variables
C_SRC = client.c

C_OBJ = $(C_SRC:%.c=$(O_DIR)%.o)
C_NAME = client

### Libft
LIBFT= superLibft/libft.a
LIBPATH= superLibft/
L_OBJ= superLibft/.tmp


all: $(LIBFT) $(S_NAME) $(C_NAME)

$(S_NAME): $(S_OBJ) $(OBJ)
	@$(CC) $(S_OBJ) $(OBJ) $(LIBFT) -o $(S_NAME)

$(C_NAME): $(C_OBJ) $(OBJ)
	@$(CC) $(C_OBJ) $(OBJ) $(LIBFT) -o $(C_NAME)

$(O_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@

$(LIBFT): $(L_OBJ)
	
$(L_OBJ):
	@make --no-print-directory -C $(LIBPATH) printf

clean:
	@make --no-print-directory -C $(LIBPATH) clean
	@rm -rf $(O_DIR)

fclean:
	@make --no-print-directory -C $(LIBPATH) fclean
	@rm -rf $(O_DIR)
	@rm -f $(S_NAME) $(C_NAME)

re: fclean all
