#------------------------------------------------------------------------------#

# Special variables
DEFAULT_GOAL: all
.DELETE_ON_ERROR: $(NAME)
.PHONY: all bonus clean fclean re

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98
RM		=	rm -rf

# Dir and file names
NAME	=	Animals
SRCS	=	./src/main.cpp ./src/Animal.cpp ./src/Cat.cpp ./src/Dog.cpp
BIN_DIR =	./bin
OBJS	=	$(addprefix $(BIN_DIR)/, $(notdir $(SRCS:.cpp=.o)))
INC		=	$(wildcard /includes/*.hpp)

# Colors
WHITE_U	=	"\033[37;1;4m"
WHITE	=	"\033[37;1m"
RESET	=	"\033[0m"
GREEN	=	"\033[92m"
RED		=	"\033[91m"
CYAN	=	"\033[96m"
YELLOW	=	"\033[93m"
BLUE	=	"\033[94m"
MAGENT	=	"\033[95m"

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(BIN_DIR) $(NAME)

# Generates output file
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@

# Compiles sources into objects
$(BIN_DIR)/%.o: src/%.cpp $(INC)
	@echo $(MAGENT)[Compiling $<]$(RESET) $(GREEN)with$(RESET) $(CYAN)[$(CC) $(CFLAGS)]$(RESET)
	@$(CC) $(CFLAGS) -c $< -o $@

# Create bin directory
$(BIN_DIR):
	@echo $(MAGENT)[Creating $(BIN_DIR)]$(RESET)
	@mkdir -p $@

# Removes objects
clean:
	@echo $(RED)[Cleaning objects]$(RESET)
	@$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	@echo $(RED)[Cleaning $(NAME)]$(RESET)
	@$(RM) $(NAME)
	@$(RM) $(BIN_DIR)

# Removes objects and executables and remakes
re: fclean all
