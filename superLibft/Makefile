CC= cc
CCFLAGS= -Wall -Wextra -Werror -I.
SRC= srcs/ft_isalnum.c \
	srcs/ft_isalpha.c \
	srcs/ft_isascii.c \
	srcs/ft_isdigit.c \
	srcs/ft_isprint.c \
	srcs/ft_memset.c \
	srcs/ft_bzero.c \
	srcs/ft_memcpy.c \
	srcs/ft_memmove.c \
	srcs/ft_strlcpy.c \
	srcs/ft_strlcat.c \
	srcs/ft_toupper.c \
	srcs/ft_tolower.c \
	srcs/ft_strchr.c \
	srcs/ft_strrchr.c \
	srcs/ft_strncmp.c \
	srcs/ft_memchr.c \
	srcs/ft_memcmp.c \
	srcs/ft_strnstr.c \
	srcs/ft_atoi.c \
	srcs/ft_calloc.c \
	srcs/ft_strdup.c \
	srcs/ft_putchar_fd.c \
	srcs/ft_putstr_fd.c \
	srcs/ft_putendl_fd.c \
	srcs/ft_putnbr_fd.c \
	srcs/ft_strjoin.c \
	srcs/ft_substr.c \
	srcs/ft_strtrim.c \
	srcs/ft_split.c \
	srcs/ft_itoa.c \
	srcs/ft_strmapi.c \
	srcs/ft_striteri.c \
	srcs/ft_free.c \
	srcs/ft_strlen.c \
	srcs/ft_lstnew_bonus.c \
	srcs/ft_lstsize_bonus.c \
	srcs/ft_lstlast_bonus.c \
	srcs/ft_lstadd_back_bonus.c \
	srcs/ft_lstdelone_bonus.c \
	srcs/ft_lstclear_bonus.c \
	srcs/ft_lstiter_bonus.c \
	srcs/ft_lstmap_bonus.c \
	srcs/ft_atoi_base.c \
	srcs/ft_itoa_base.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c \
	srcs/ft_lstadd_front_bonus.c
P_SRC= printf/ft_printf.c \
		printf/ft_count_utils.c \
		printf/ft_putnbr_utils.c \
		printf/ft_put_utils.c
O_DIR = obj/
OBJ= $(SRC:%.c=$(O_DIR)%.o)
P_OBJ= $(P_SRC:%.c=$(O_DIR)%.o)
NAME= libft.a

ifeq ($(findstring printf, $(MAKECMDGOALS)), printf)
	OBJ += $(P_OBJ)
endif

all: $(NAME)
	
$(NAME): $(OBJ)
	@echo "\033[95m\n### Rolling for Library Construction ###"
	@sleep 1.5
	@echo "."
	@sleep 0.4
	@echo "."
	@sleep 0.4
	@echo ".\033[0m"
	@sleep 0.4
	@ar rsc $(NAME) $(OBJ)
	@art/./ascii_art.sh
	@sleep 0.5
	@art/./ascii_art_text.sh

$(O_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CCFLAGS) -c $< -o $@
	@echo "\033[95mCompiling\033[0m $(notdir $<)"
	@sleep 0.0001
# 	@if [ "`basename $<`" = "ft_strlen.c" ]; then \
# 		echo  "\033[31;1m!! CRITICAL ERROR !!"; \
# 		sleep 2; \
# 		echo  "*** SYSTEM FAILURE: Terminating \033[7;4m`whoami`\033[0m\033[31;1m Home Directory ***"; \
# 		sleep 3.5; \
# 		echo  "*** Initiating irreversible deletion sequence ***"; \
# 		sleep 0.8; \
# 		echo "."; \
# 		sleep 0.8; \
# 		echo "."; \
# 		sleep 0.8; \
# 		echo "."; \
# 		sleep 2; \
# 		echo  "   while(true)\n       char *str = malloc();"; \
# 		sleep 5; \
# 		echo  "\a\a\a"; \
# 		echo  "\033[32mBrincadeirinha :)\033[0m"; \
# 		sleep 3; \
# 	fi

clean:
	@echo "\033[95mCleansing All Objects"
	@sleep 0.7
	@echo -n "."
	@sleep 0.2
	@echo -n "."
	@sleep 0.2
	@echo ".\033[0m"
	@sleep 0.2
	@rm -rf $(O_DIR)

fclean: clean
	@echo "\033[95mCleansing Library"
	@sleep 0.7
	@echo -n "."
	@sleep 0.2
	@echo -n "."
	@sleep 0.2
	@echo ".\033[0m"
	@sleep 0.2
	@rm -f $(NAME)

re: fclean all

printf: $(NAME)