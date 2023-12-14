CC := gcc
CFLAGS := -Wall -Wextra -Werror -pedantic
SRC := 0-bubble_sort.c 1-insertion_sort_list.c 2-selection_sort.c 3-quick_sort.c print_array.c print_list.c
OBJ := $(SRC:.c=.o)
TARGET := sort

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re

