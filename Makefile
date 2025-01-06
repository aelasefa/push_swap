NAME := push_swap

SRCS := check_error.c push_swap_utils.c stack_operations.c swap.c \
	rotate.c reverse_rotate.c  sort_stack.c main.c

OBJS := $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft.a
LIBFTDIR = libft

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFT) $(NAME)
	$(CC) $(CFLAGS) $(OBJS) -L $(LIBFTDIR) -l ft -o $(NAME)

clean :
	make -C $(LIBFTDIR) clean
	rm -f $(OBJS)

fclean : clean
	make -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re : fclean all

.PHONY 	: clean
