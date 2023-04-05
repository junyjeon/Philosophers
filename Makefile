NAME		=	philosophers

CC			=	cc -g3
#CFLAGS		=	-Wall -Wextra -Werror
# CFLAGS		+=	-fsanitize=address

INC_DIR		=	./inc

LIBFT_DIR	=	./lib/libft
LIBFT_AC	=	$(LIBFT_DIR)/libft.a

CPPFLAGS	=	-I$(INC_DIR) -I$(LIBFT_DIR)
LDFLAGS		=	-L$(LIBFT_DIR) -lft -lpthread

SRC_DIR		=	src
BUILD_DIR	=	bulid

SRC		=	$(addprefix $(SRC_DIR)/, main.c init.c cycle.c util.c)
OBJ		=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

all:	$(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)
	@echo "$(GREEN)SUCCESS!$(END)"

$(LIBFT):
	@make -C $(LIBFT_DIR) bonus

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | mkdir
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

mkdir:
	@mkdir -p $(BUILD_DIR)

clean:
	@$(RM) -r $(BUILD_DIR)
	@echo "${YELLOW}> All objects files of the philosophers have been deleted.❌${END}"

fclean: clean
	@$(RM) -r $(NAME) $(LIBFT) 
	@echo "${YELLOW}> Cleaning of the philosophers has been done.❌${END}"

re: fclean
	@$(MAKE)
	@echo "$(GREEN)Cleaned and rebuilt everything for philosophers!${END}"

GREEN	=	$'\x1b[32m
YELLOW	=	$'\x1b[33m

.PHONY: all clean fclean re mkdir
