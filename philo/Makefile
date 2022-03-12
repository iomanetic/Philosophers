NAME_M			=	philo

SRC_MANDATORY	=	philo.c \
					src/philo_valid.c \
					src/philo_init.c \
					src/philo_start.c \
					src/philo_actions.c \
					src/philo_utils.c \
					src/philo_errors.c \

OBJ_M			=	$(patsubst %.c,%.o,$(SRC_MANDATORY))

HEADERS_M		=	includes/philo.h \
					includes/defines.h \
					includes/structs.h \

CC				=	gcc

CFLAGS			=	-O2 -Wall -Wextra -Werror -g3 -fsanitize=thread

all: $(NAME_M)

$(NAME_M): $(OBJ_M)
	$(CC) $(CFLAGS) $(OBJ_M) -o $@

%.o: %.c $(HEADERS_M)
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean:
	rm -rf $(OBJ_M)

fclean: clean
	rm -rf $(NAME_M)