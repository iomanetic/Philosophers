NAME			=	philo

SRC	=				philo.c \
					src/philo_valid.c \
					src/philo_init.c \
					src/philo_start.c \
					src/philo_actions.c \
					src/philo_utils.c \
					src/philo_errors.c \

OBJ			=		$(patsubst %.c,%.o,$(SRC))

HEADERS		=		includes/philo.h \
					includes/defines.h \
					includes/structs.h \

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