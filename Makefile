NAME=push_swap

CHECKERNAME=checker

CC=gcc

FLAGS=-Wall -Werror -Wextra -g

SRC=check_utils.c \
	checks.c \
	decide.c \
	find_a_way.c \
	find.c \
	move_utils.c \
	moves_both.c \
	moves.c \
	moves2.c \
	sort_utils.c \
	to_do.c \
	treat.c \
	utils.c \
	utils2.c \
	values.c

MAIN=main.c

MAINBONUS=checker.c

BONUSSRC=checker_ops.c \
	checker_ops_2.c \
	checker_ops_3.c

OBJS=$(SRC:.c=.o)
MAINO=$(MAIN:.c=.o)
CHECKEROBJS=$(BONUSSRC:.c=.o)
CHECKO=$(MAINBONUS:.c=.o)

LIBFT=./LIBFT/libft.a

$(NAME): $(OBJS) $(LIBFT) main.o
	$(CC) $(FLAGS) $(SRC) $(MAIN) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C ./LIBFT/

all: $(NAME)

$(CHECKERNAME): $(OBJS) $(CHECKEROBJS) $(CHECKO) $(LIBFT)
	$(CC) $(FLAGS) $(CHECKO) $(CHECKEROBJS) $(OBJS) $(LIBFT) -o $(CHECKERNAME)

bonus: $(CHECKERNAME)

clean:
	rm -f *.o
	$(MAKE) clean -C ./LIBFT

fclean: clean
	rm -f $(NAME)
	rm -f $(CHECKERNAME)
	$(MAKE) fclean -C ./LIBFT

re: fclean all

.PHONY: all clean fclean re