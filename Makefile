
NAME = push_swap
INCLUDES_DIR = ./includes/

LIBFT_DIR = ./srcs/libft/
SOURCES_LIBFT = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_bzero.c\
	ft_strlcpy.c ft_strlen.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_atoi.c \
	ft_strdup.c ft_calloc.c\
	ft_substr.c ft_strjoin.c ft_itoa.c ft_split.c ft_strtrim.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

PUSH_SWAP_DIR = ./srcs/
SOURCE_PUSH_SWAP = \
	main.c ft_swap.c try_join.c
	

OBJ_DIR = obj
OBJECTS_LIBFT = $(SOURCES_LIBFT:%.c=$(OBJ_DIR)/%.o)
OBJECTS_PUSH_SWAP = $(SOURCE_PUSH_SWAP:%.c=$(OBJ_DIR)/%.o)
OBJECTS = $(OBJECTS_LIBFT) $(OBJECTS_PUSH_SWAP)
CC = cc
CFLAGS = -Wall -Wextra -Werror


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

clean:
	@echo "$(BRED)Cleaning up... -> $(GRN)[OK]$(NC)"
	@rm -rf $(OBJ_DIR) *a.out *.txt

fclean: clean
	@echo "$(BRED)Removing $(NAME), a.out and *.txt files... -> $(GRN)[OK]$(NC)"
	@rm -f $(NAME) bonus

re: fclean all

.PHONY: all clean fclean re create_dir
