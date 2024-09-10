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
NAME	=	phonebook
SRCS	=	./src/main.cpp ./src/Contact.cpp ./src/PhoneBook.cpp
BIN_DIR =	./bin
OBJS	=	$(addprefix $(BIN_DIR)/, $(notdir $(SRCS:.cpp=.o)))
INC		=	$(wildcard /includes/*.hpp)

# Colors
GREEN	=	"\033[32;1m"
RED		=	"\033[31;1m"
CYAN	=	"\033[36;1;3m"
WHITE_U	=	"\033[37;1;4m"
WHITE	=	"\033[37;1m"
YELLOW	=	"\033[33;1m"
BLUE	=	"\033[34;1m"
MAGENT	=	"\033[35;1m"
LIMITER	=	"\033[0m"

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(BIN_DIR) $(NAME)

# Generates output file
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@

# Compiles sources into objects
$(BIN_DIR)/%.o: src/%.cpp $(INC)
	@echo $(MAGENT)[Compiling $<]$(LIMITER) $(GREEN)with$(LIMITER) $(CYAN)[$(CC) $(CFLAGS)]$(LIMITER)
	@$(CC) $(CFLAGS) -c $< -o $@

# Create bin directory
$(BIN_DIR):
	@echo $(MAGENT)[Creating $(BIN_DIR)]$(LIMITER)
	@mkdir -p $@

# Removes objects
clean:
	@echo $(RED)[Cleaning objects]$(LIMITER)
	@$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	@echo $(RED)[Cleaning $(NAME)]$(LIMITER)
	@$(RM) $(NAME)
	@$(RM) $(BIN_DIR)

# Removes objects and executables and remakes
re: fclean all
