OS 				:=	$(shell uname)

NAME			=	push_swap

CC				=	cc
AR				=	ar -rc
SRC				=	$(wildcard *.c)
OBJ				=	$(SRC:.c=.o)
LIBFTPATH		=	libft
LIBFT			=	$(LIBFTPATH)/libft.a
CFLAGS			=	# -Wall -Werror -Wextra

# Generic rule for .o files
%.o: %.c
					$(CC) $(CFLAGS) -g -c $< -o $@

all: $(NAME)

$(LIBFT):
					make -C $(LIBFTPATH) all

$(NAME): 			$(LIBFT) $(OBJ)
					$(CC) $(SRC) $(LIBFT) -g -o $(NAME)

clean:
					rm -f $(OBJ)

fclean: clean
					rm -f $(NAME)
					rm -rf *.dSYM

re: fclean all