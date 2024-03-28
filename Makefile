NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Path: Source
SRC = parssing_push_swap.c push_swap.c utils/ft_split.c utils/ft_strdup.c utils/ft_strjoin.c utils/ft_strlen.c utils/ft_atoi.c sort_step/sort_three.c utils/ft_lstadd_back_bonus.c utils/ft_lstlast_bonus.c utils/ft_lstsize_bonus.c sort_step/pa.c sort_step/pb.c sort_step/ra.c sort_step/rb.c sort_step/rr.c sort_step/rra.c sort_step/rrb.c sort_step/rrr.c sort_step/sa.c sort_step/sb.c sort_step/sort_utils.c sort_step/ss.c
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_A)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all