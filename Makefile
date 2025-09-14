CC = cc -Wall -Werror -Wextra
O_DIR = obj/

### Server variables
S_SRC = server.c \
		server_srcs/get_binary.c \
		server_srcs/listen_for_string.c \
		server_srcs/mini_init.c \
		server_srcs/recreate_binary.c

S_OBJ = $(S_SRC:%.c=$(O_DIR)%.o)
S_NAME = server

### Client variables
C_SRC = client.c \
		client_srcs/fill_byte.c \
		client_srcs/itoba.c \
		client_srcs/send_bit.c \
		client_srcs/send_str.c \
		client_srcs/sighandler.c

C_OBJ = $(C_SRC:%.c=$(O_DIR)%.o)
C_NAME = client

### Libft
LIBFT= superLibft/libft.a
LIBPATH= superLibft/


all: $(LIBFT) $(S_NAME) $(C_NAME)

$(S_NAME): $(S_OBJ)
	@$(CC) $(S_OBJ) $(LIBFT) -o $(S_NAME)

$(C_NAME): $(C_OBJ)
	@$(CC) $(C_OBJ) $(LIBFT) -o $(C_NAME)

$(O_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@

$(LIBFT):
	@make --no-print-directory -C $(LIBPATH) printf

clean:
	@make --no-print-directory -C $(LIBPATH) clean
	@rm -rf $(O_DIR)

fclean:
	@make --no-print-directory -C $(LIBPATH) fclean
	@rm -rf $(O_DIR)
	@rm -f $(S_NAME) $(C_NAME)

re: fclean all

.PHONY: $(LIBFT) re fclean clean