NAME:= libft.a

SRCS := ft_isdigit.c  ft_strdup.c   ft_strlcat.c  ft_strlen.c \
	ft_atoi.c	ft_split.c    ft_strjoin.c  ft_strlcpy.c

OBJS := $(SRCS:.c=.o)

AR = ar rcs

CC = cc

CFLAGS := -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
		$(AR) $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY 	: clean
