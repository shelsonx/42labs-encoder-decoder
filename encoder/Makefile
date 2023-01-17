NAME			= encoder

CC 				= cc
CF 				= -g -Wall -Wextra -Werror
SEM_FLAGS		= -lpthread -lrt
CFI 			= -I $(INCLUDE)

SRC_PATH 		= ./#sources/
OBJ_PATH		= ./obj/
INCLUDE 		= ./#includes/

SRC				= tree.c table.c queue.c dict.c queue_utils.c file.c\
				  encoder.c compress.c comp_decomp_utils.c memory_operations.c \
				  semaphore.c prints.c utils.c main.c

VPATH 			:= $(SRC_PATH)\
				#$(SRC_PATH)prompt\
				

OBJ				= $(addprefix $(OBJ_PATH), $(notdir $(SRC:.c=.o)))

RM 				= rm -rf

$(OBJ_PATH)%.o: %.c
				mkdir -p $(OBJ_PATH)
				$(CC) $(CF) $(CFI) -c $< -o $@

$(NAME):		$(OBJ)
				$(CC) -g $(CF)  -I $(INCLUDE) -o $(NAME) $(OBJ) $(SEM_FLAGS)
				@echo "$(GREEN)$(NAME) created$(DEFAULT)"

all:			$(NAME)

re:				fclean all

clean:
				$(RM) $(OBJ) $(OBJDIR)
				@echo "$(YELLOW)object files deleted$(DEFAULT)"

fclean:			clean
				$(RM) $(NAME)
				@echo "$(RED)all deleted$(DEFAULT)"

leak:							
				valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)

.PHONY:			all clean fclean re bonus

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m