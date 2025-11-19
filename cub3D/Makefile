#libft
LIBFTDIR = ./Libft/
LIBFTLIB = ft
LIBFTFLAGS = -L$(LIBFTDIR) -l$(LIBFTLIB)

#mlx
MLXDIR = ./minilibx-linux
MLXLIB = mlx
MLXFLAG = -L$(MLXDIR) -l$(MLXLIB) -lXext -lX11 -lm

#common
COMDIR = ./common
COMSRC = $(COMDIR)/common.c

#pars
PARSDIR = ./pars
PARSSRC = $(PARSDIR)/map_check.c\
		$(PARSDIR)/map_check_util.c\
		$(PARSDIR)/check_error_utils.c\
		$(PARSDIR)/check_error_utils1.c\
		$(PARSDIR)/check_error_utils2.c\
		$(PARSDIR)/globality_error1.c\
		$(PARSDIR)/get_map.c\
		$(PARSDIR)/globality_error.c


#graph
GRAPHDIR = ./graph
GRAPHSRC = $(GRAPHDIR)/raycasting.c\
			$(GRAPHDIR)/raycasting_util.c\
			$(GRAPHDIR)/trapeze_map.c\
			$(GRAPHDIR)/draw.c

#event
EVENTDIR = ./event
EVENTSRC = $(EVENTDIR)/keyboard_event.c\
			$(EVENTDIR)/event_rotate.c\
			$(EVENTDIR)/event_move.c\
			$(EVENTDIR)/manage_event.c
#main
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = main.c $(COMSRC) $(GRAPHSRC) $(PARSSRC) $(EVENTSRC) $(RAYCASTSRC)
OBJ = $(SRC:.c=.o)
NAME = graph_

all : $(NAME)

$(NAME) : $(OBJ)
	make bonus -C $(LIBFTDIR)
	make -C $(MLXDIR)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBFTFLAGS) $(MLXFLAG)

%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@

clean :
	make clean -C $(LIBFTDIR)
	make clean -C $(MLXDIR)
	rm -f $(OBJ)

fclean : clean
	make fclean -C $(LIBFTDIR)
	rm -rf $(NAME)

re : fclean all
	make re -C $(MLXDIR)

.PHONY : all clean fclean re
