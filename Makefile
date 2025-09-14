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
	@echo "\033[95mCompiling\033[0m $(notdir $<)"
	@sleep 0.0001

$(C_NAME): $(C_OBJ)
	@$(CC) $(C_OBJ) $(LIBFT) -o $(C_NAME)
	@echo "\033[95mCompiling\033[0m $(notdir $<)"
	@sleep 0.0001

$(O_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@echo "\033[95mCompiling\033[0m $(notdir $<)"
	@sleep 0.0001
	@$(CC) -c $< -o $@

$(LIBFT):
	@make --no-print-directory -C $(LIBPATH) printf

clean:
	@echo "\033[95mCleansing Minitalk Objects"
	@sleep 0.7
	@echo -n "."
	@sleep 0.2
	@echo -n "."
	@sleep 0.2
	@echo ".\033[0m"
	@sleep 0.2
	@make --no-print-directory -C $(LIBPATH) clean
	@rm -rf $(O_DIR)

fclean:
	@echo "\033[95mCleansing Minitalk"
	@sleep 0.7
	@echo -n "."
	@sleep 0.2
	@echo -n "."
	@sleep 0.2
	@echo ".\033[0m"
	@sleep 0.2
	@make --no-print-directory -C $(LIBPATH) fclean
	@rm -rf $(O_DIR)
	@rm -f $(S_NAME) $(C_NAME)

re: fclean all

.PHONY: $(LIBFT) re fclean clean