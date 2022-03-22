NAME			=	philo_bonus

SRC	=				philo_bonus.c \
					src/philo_valid_bonus.c \
					src/philo_init_bonus.c \
					src/philo_start_bonus.c \
					src/philo_actions_bonus.c \
					src/philo_errors_bonus.c \
					src/philo_utils_bonus.c \

OBJ			=		$(patsubst %.c,%.o,$(SRC))

HEADERS		=		includes/philo_bonus.h \
					includes/defines_bonus.h \
					includes/structs_bonus.h \

CC				=	gcc

CFLAGS			=	-O2 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)