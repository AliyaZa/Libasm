NAME = libasm.a

CC = gcc

SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s \
ft_write.s ft_read.s ft_strdup.s

BONSRC = ft_list_size_bonus.s

SFLAGS = -f macho64

OBJ = $(SRC:.s=.o)

BONUS_OBJ = $(BONSRC:.s=.o)

FLAGS = -Wall -Werror -Wextra -g

%.o: %.s
		nasm $(SFLAGS) $< -o $@ -g

all: $(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)
		ranlib $(NAME)

bonus: $(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	@echo "Cleaned! $(F_NONE)"

clean_test:
	rm -f main.o

clean_test_bonus:
	rm -f main_bonus.o

fclean: clean
	rm -f $(NAME)
	@echo "FCleaned! $(F_NONE)"

re: fclean all

test:
	gcc $(FLAGS) -c main.c
	gcc $(FLAGS) main.o $(NAME)

test_bonus:
	gcc $(FLAGS) -c main_bonus.c
	gcc $(FLAGS) main_bonus.o $(NAME)

.PHONY: clean fclean
