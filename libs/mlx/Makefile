#
#
### COLOURS
GREEN_B = "\033[1;32m"
RED_BI = "\033[1;3;31m"
BLUE_I = "\033[3;34m"
YELLOW = "\033[0;33m"
RESET = "\033[0m"


NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11 -w

all: $(NOM)

$(NOM):	$(OBJ)
	@echo $(YELLOW)"\n"
	@-ar -r $(NOM) $(OBJ)
	@-ranlib $(NOM)
	@echo $(GREEN_B)"\nMLX is ready. ✅\n"$(RESET)

%.o: %.c
	@-cc $(CFLAGS) -c $< -o $@
	@echo $(YELLOW)".\c"$(RESET)

%.o: %.m
	@-cc $(CFLAGS) -c $< -o $@
	@echo $(YELLOW)".\c"$(RESET)
clean:
	@-rm -f $(NOM) $(OBJ) *~
	@-rm -f mlx_app

re: clean all
