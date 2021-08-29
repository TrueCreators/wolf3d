
NAME= wolf3d

SRC= src/main.c \
	src/wolf3d.c \
	src/parsing_map1.c \
	src/parsing_map2.c \
	src/controls/controls.c \
	src/controls/window.c \
	src/controls/move.c \
	src/interface/main_menu.c \
	src/interface/button.c \
	src/interface/button_events.c \
	src/interface/init_menu.c \
	src/interface/init_menu_press.c \
	src/interface/button_events_menu.c \
	src/interface/animation_menu.c \
	src/raycasting1.c \
	src/raycasting2.c 

OBJ= $(SRC:%.c=%.o)

INCLDIR= includes/
INCLFILE= wolf3d.h
INC= $(addprefix $(INCLDIR), $(INCLFILE))

LIBPATH= library/

LIBFTDIR= libft/
LIBFTPATH= $(addprefix $(LIBPATH), $(LIBFTDIR))
LIBFT= libft.a
FTLK= ft

MLXDIR= minilibx/
MLXPATH= $(addprefix $(LIBPATH), $(MLXDIR))
LIBMLX= libmlx.a
MLXLK= mlx
FRAMEWORKS= -framework OpenGL -framework AppKit -framework OpenCL

ALLINC= -I$(LIBFTPATH) -I$(MLXPATH) -I$(INCLDIR)

CC= gcc
MAKE = make
FLAGS= -O3  -g

all: $(NAME)

$(NAME): $(LIBFTPATH)$(LIBFT) $(MLXPATH)$(LIBMLX) $(OBJ) $(INC)
	$(CC) -O3 -o $(NAME) $(ALLINC) -L$(LIBFTPATH) -lft -L$(MLXPATH) -lmlx $(FRAMEWORKS) $(OBJ)
	@echo "Wolf3D ready."

%.o: %.c $(INC)
	$(CC) $(FLAGS) -o $@ $(ALLINC) -c $<

$(LIBFTPATH)$(LIBFT):
	$(MAKE) -C $(LIBFTPATH)

$(MLXPATH)$(LIBMLX):
	$(MAKE) -C $(MLXPATH)

clean:
	$(MAKE) -C $(LIBFTPATH) clean
	$(MAKE) -C $(MLXPATH) clean
	rm -rf $(OBJ)
fclean: clean
	$(MAKE) -C $(LIBFTPATH) fclean
	$(MAKE) -C $(MLXPATH) clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
