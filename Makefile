NAME := push_swap
BNAME := checker

SRCS := check_error.c push_swap_utils.c stack_operations.c swap.c \
	rotate.c reverse_rotate.c  sort_stack.c  sort_array.c  sort_small_element.c \
	ft_lstsize.c sort_small_element_utils.c  main.c

BSRCS := actions_bonus.c ft_strncmp.c main_bonus.c push_swap_utils_bonus.c \
		 stack_operations_bonus.c check_error_bonus.c get_next_line_utils.c \
		 reverse_rotate_bonus.c  swap_bonus.c ft_lstsize_bonus.c  get_next_line.c\
		 rotate_bonus.c 

OBJS := $(SRCS:.c=.o)
BOBJS := $(BSRCS:.c=.o)

CC = cc 
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = libft.a
LIBFTDIR = libft

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTDIR)/$(LIBFT) -o $(NAME)

bonus : $(BOBJS)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(BOBJS) $(LIBFTDIR)/$(LIBFT) -o $(BNAME)

clean :
	make -C $(LIBFTDIR) fclean
	rm -f $(OBJS) $(BOBJS)

fclean : clean
	make -C $(LIBFTDIR) fclean
	rm -f $(NAME) $(BNAME)

re : fclean all

.PHONY 	: clean
