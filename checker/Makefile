
CC				=	gcc
CFLAGS			=		-Wall -Wextra -g
TARGET			=	checker
SRC				=	checker.c errors.c checker_utils.c move.c
OBJ				=	$(SRC:.c=.o)
LIBFTPATH		=	libft
LIBFT			=	../$(LIBFTPATH)/libft.a
all: $(TARGET)

$(LIBFT):
					make -C $(LIBFTPATH) all

$(TARGET):			$(LIBFT) $(OBJ)
					$(CC) $(CFLAGS) $(LIBFT) -o $@ $^

%.o: %.c
					$(CC) $(CFLAGS) -c $< -o $@

clean:
					rm -f $(OBJ)

fclean: clean
					rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
