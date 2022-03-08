NAME_M			=	philo

SRC_MANDATORY	=	philo_mandatory/philo.c \
					philo_mandatory/src/philo_valid.c \
					philo_mandatory/src/philo_init.c \
					philo_mandatory/src/philo_start.c \
					philo_mandatory/src/philo_actions.c \
					philo_mandatory/src/philo_utils.c \
					philo_mandatory/src/philo_errors.c \

OBJ_M			=	$(patsubst %.c,%.o,$(SRC_MANDATORY))

HEADERS_M		=	philo_mandatory/includes/philo.h \
					philo_mandatory/includes/defines.h \
					philo_mandatory/includes/structs.h \

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

all: $(NAME_M)

$(NAME_M): $(OBJ_M)
	$(CC) $(CFLAGS) $(OBJ_M) -o $@

%.o: %.c $(HEADERS_M)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_M)

fclean: clean
	rm -rf $(NAME_M)