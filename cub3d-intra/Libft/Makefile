SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
	ft_strlcpy.c ft_strcat.c ft_strlcat.c ft_strcpy.c ft_toupper.c ft_tolower.c ft_strchr.c\
	ft_strrchr.c ft_strcmp.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c\
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
	ft_free_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
	ft_putendl_fd.c ft_putnbr_fd.c get_next_line_utils.c get_next_line.c ft_strnbchr.c\
	ft_printf.c ft_printf_util.c ft_split_str.c ft_strlen_delim.c ft_join.c ft_free_null.c\
	ft_strtrimall.c ft_strlen_strtab.c
SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c\
	ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)
OBJ = $(SRC:.c=.o)
NAME = libft.a
CC = gcc
AR = ar
CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) scr $@ $^

$(OBJ:%.o) : $(SRC:%.c)
	$(CC) -c $(CFLAGS) $< -o $@

bonus : .bonus

.bonus : $(OBJ) $(OBJ_BONUS)
	$(AR) scr $(NAME) $(OBJ) $(OBJ_BONUS)
	touch $@

$(OBJ_BONUS:%.o) : $(SRC_BONUS:%.c)
	$(CC) -c $(CFLAGS) $< -o $@

clean : 
	rm -f $(OBJ) $(OBJ_BONUS) .bonus

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
