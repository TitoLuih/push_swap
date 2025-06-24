NAME = push_swap
CC = cc
FLAGS = -Werror -Wextra -Wall

LIBFT_PATH = libs/libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC = src/moves/push.c\
	src/moves/swap.c\
	src/moves/reverse.c\
	src/moves/r_reverse.c\
	src/manager/control.c\
	src/manager/is_sorted.c\
	src/manager/parser.c\
	src/utils.c\
	src/utils_2.c\
	src/algorithm/algorithm.c\
	src/algorithm/cost_calc.c\
	src/algorithm/cost_exec.c\
	src/algorithm/special_cases.c\

OBJS = $(SRC:.c=.o)

RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c src/push_swap.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
	