CFLAGS = -g -Wall -Wextra -Werror

NAME = philo

OBJS = $(SRCS:.c=.o)

#-------------------------------------------------------COLORS--------------------------------------------------#

BLACK = "\e[30m"
RED = "\e[31m"
GREEN = "\e[32m"
YELLOW = "\e[33m"
BLUE = "\e[34m"
MAGENTA = "\e[35m"
CYAN = "\e[36m"
LIGHT_GRAY = "\e[37m"
DARK_GRAY = "\e[90m"
LIGHT_RED = "\e[91m"
LIGHT_GREEN = "\e[92m"
LIGHT_YELLOW = "\e[93m"
LIGHT_BLUE = "\e[94m"
LIGHT_MAGENTA = "\e[95m"
LIGHT_CYAN = "\e[96m"
WHITE = "\e[97m"
DEFAULT = "\e[39m"

#-------------------------------------------------------SRCS----------------------------------------------------#

SRCS = exec.c \
	   error.c \
	   parsing.c \
	   thread.c \
	   routine.c

#-----------------------------------------------------RULES-----------------------------------------------#

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo -n $(GREEN)
	@echo ">>>   Philosophers is compiled ✅  <<<"
	@echo -n $(DEFAULT)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJS)
	@echo -n $(YELLOW)
	@echo ">>>   Philosophers is cleaned 🧹  <<<"
	@echo -n $(DEFAULT)

fclean: clean
	@rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re
