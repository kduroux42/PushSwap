
NAME = push_swap
INCLUDES_DIR = ./includes/

LIBFT_DIR = ./srcs/libft/
SOURCES_LIBFT = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_bzero.c\
	ft_strlcpy.c ft_strlen.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_strnstr.c \
	ft_strdup.c ft_calloc.c\
	ft_substr.c ft_strjoin.c ft_itoa.c ft_split.c ft_strtrim.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

PUSH_SWAP_DIR = ./srcs/pushswap/
SOURCE_PUSH_SWAP = \
	main.c move.c utils.c check_args.c create_stack.c advance_move.c advance_move_2.c \
	sort_of_three.c sort.c \
	utils_for_sort.c target.c push.c ft_printf_all.c utils_for_sort2.c \
	init.c

PRINTF_DIR  = ./srcs/printf/
SOURCES_PRINTF = \
	ft_printf.c ft_nbrhex.c ft_strptr.c
	

OBJ_DIR = obj
OBJECTS_LIBFT = $(SOURCES_LIBFT:%.c=$(OBJ_DIR)/%.o)
OBJECTS_PUSH_SWAP = $(SOURCE_PUSH_SWAP:%.c=$(OBJ_DIR)/%.o)
OBJECTS_PRINTF = $(SOURCES_PRINTF:%.c=$(OBJ_DIR)/%.o)
OBJECTS = $(OBJECTS_LIBFT) $(OBJECTS_PRINTF) $(OBJECTS_PUSH_SWAP)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3


BRED = \033[1;31m
RED  = \033[0;31m
BGRN = \033[1;32m
GRN  = \033[0;32m
YEL  = \033[0;33m
BYEL = \033[1;33m
BLU  = \033[0;34m
BBLU = \033[1;34m
BMAG = \033[1;35m
MAG  = \033[0;35m
CYN  = \033[0;36m
BCYN = \033[1;36m
BWHT = \033[1;37m
NC   = \033[0m

all: create_dir $(OBJECTS) $(NAME)

create_dir:
	@if [ ! -d $(OBJ_DIR) ]; then \
		mkdir -p $(OBJ_DIR); \
		echo "$(BRED)Created directory $(OBJ_DIR) -> $(GRN)[OK]$(NC)"; \
	fi
$(NAME): $(OBJECTS)
	@echo "$(BBLU)Creating Binary $(NAME) -> $(GRN)[OK]$(NC)"
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -o $@ $^

$(OBJ_DIR)/%.o: $(PUSH_SWAP_DIR)%.c
	@echo "$(BWHT)Compiling $< -> $(GRN)[OK]$(NC)"
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(LIBFT_DIR)%.c
	@echo "$(BCYN)Compiling $< -> $(GRN)[OK]$(NC)"
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(PRINTF_DIR)%.c
	@echo "$(BMAG)Compiling $< -> $(GRN)[OK]$(NC)"
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

clean:
	@echo "$(BRED)Cleaning up... -> $(GRN)[OK]$(NC)"
	@rm -rf $(OBJ_DIR) *a.out *.txt

fclean: clean
	@echo "$(BRED)Removing $(NAME), a.out and *.txt files... -> $(GRN)[OK]$(NC)"
	@rm -f $(NAME) bonus

re: fclean all

.PHONY: all clean fclean re create_dir
