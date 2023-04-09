NAME		=	philosophers

CC			=	cc -g3
CFLAGS		=	-Wall -Wextra -Werror
#CFLAGS		+=	-fsanitize=thread,undefined

INC_DIR		=	./inc

CPPFLAGS	=	-I$(INC_DIR)
LDFLAGS		=	-lpthread

SRC_DIR		=	src
BUILD_DIR	=	bulid

SRC		=	$(addprefix $(SRC_DIR)/, main.c init.c philos_cycle.c util_01.c util_02.c)
OBJ		=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

all:	$(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)
	@echo "$(GREEN)SUCCESS!$(END)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | mkdir
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

mkdir:
	@mkdir -p $(BUILD_DIR)

clean:
	@$(RM) -r $(BUILD_DIR)
	@echo "${YELLOW}> All objects files of the philosophers have been deleted.❌${END}"

fclean: clean
	@$(RM) -r $(NAME)
	@echo "${YELLOW}> Cleaning of the philosophers has been done.❌${END}"

re: fclean
	@$(MAKE)
	@echo "$(GREEN)Cleaned and rebuilt everything for philosophers!${END}"

GREEN	=	$'\x1b[32m
YELLOW	=	$'\x1b[33m

.PHONY: all clean fclean re mkdir
