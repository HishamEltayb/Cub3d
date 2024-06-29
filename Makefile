# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 10:38:05 by heltayb           #+#    #+#              #
#    Updated: 2024/06/29 08:57:24 by heltayb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-fsanitize=address

NAME	=	cub3D

SRCS	=	

OBJS	=	$(SRCS:.c=.o)

LIBFT 	= 	libft/libft.a

MLX		:=

LIB		:=

INCLUDE	:=

LINKS	:=

CFLAGS	= -Wall -Werror -Wextra 

OS		=	$(shell uname)

SRCDIR	=	src

OBJDIR	=	obj

MLX_LINUX = mlx_Linux/libmlx_Linux.a

#for MAC		
MLX_MAC = mlx/libmlx.a

#for Operating system
ifeq ($(OS), Linux)
	MLX += $(MLX_LINUX)
	LIB += $(LIBFT) $(MLX)
	INCLUDE += -I/usr/include -Imlx_linux -Iutils -O3 -Ilibft
	LINKS += -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
endif
ifeq ($(OS), Darwin)
	MLX += $(MLX_MAC)
	LIB += $(LIBFT) $(MLX)
	INCLUDE += -Imlx -Ilibft
	LINKS += -L mlx -l mlx -framework OpenGL -framework AppKit
endif


$(MLX_MAC):
	@make -C mlx
	
$(MLX_LINUX):
	@make -C mlx_Linux

all: $(NAME)
	tput setaf 2
	printf '                      MMMMMMM           MMMMMMH                            \n'
	printf '                HMMMMM:::::::.MMMMMMMMMM:::::.TMM                          \n'
	printf '              MMMI:::::::::::::::::::MMH::::::::TM                         \n'
	printf '            MMIi::::::::::::.:::::::::::::::::::::MMMM                     \n'
	printf '           MT::::.::::::::::::::::::::::::::::::.::=T.IMMM                 \n'
	printf '         MMMi:::::::::::::::::::::::::::::::::::::::::::MT)MM              \n'
	printf '     MMMI.:::::::::::::::::::::::::::::::::::::::::::.:::M= MM             \n'
	printf '   XMXi::::::::::::::::::::::.:::::::::::::::::::::::::::::::=MM           \n'
	printf '   MMi::::::::::::::::::::::::::::::::::::::::::::::::::.::..:=MMM         \n'
	printf '  MM:MMT:::::::::.:::::::::::::::::.:::::::::::::::::::::::::::MiMM        \n'
	printf '   MMM::::::::::::::::::.::::::::::::::::::::::::::.::::::::::.TM.MM       \n'
	printf '   MMi::::::::::::::.::::::::::::::::::::::::::::::::::::::.:::.:: M       \n'
	printf '   MM:::.::::::::::::::::::::::::::::::::.:.:::::::::::::::::::::: XM      \n'
	printf ' MM:MT::.::::::::::::::::::::::::::::::::::::::::::::::::::::::::::XM      \n'
	printf 'IMM:::.::::::::::::::::::::::::::::::::::: :::::::::::::::::::::::.=M      \n'
	printf ' MM::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: :::M      \n'
	printf ' XMT:::::::::::::::::::::: ::::::::::::::::: : ::::::::::::::::::: iM      \n'
	printf '   MiMi:::::::::: :::::::::::::::::::::::::::::::: ::::::::::::::.:IM      \n'
	printf '     M::::::HH::::::::::::::::::::::::::::::::::::::::::::::::::::: M      \n'
	printf '     MT:::::iM::::::::Hi:iXH:::ii::XH:::::::::::::.::::::::::::::.:.M      \n'
	printf '      MX:::::iMX:i::::iMi:iMH::XH::Mi:::::::::::::::::::::::::::::: M      \n'
	printf '        Mii::::HMH:::::iMH::MH=:MM=TMi::::::::::::::::::::::::::::::MM     \n'
	printf '          MMMMMMMMMMMXTi:MMHi:HMMIMMMMii::::::::::::::::::::::::::::XM     \n'
	printf '           XXOXMMT:. ::T= :IMMMMMMM=iXMii:::::::::::::::::::::::::: MM     \n'
	printf '            MMMH:::.:::::::.::::.::::.:XMi::::::::::::::::::::::::::MM     \n'
	printf '           XMM::.:.:..::..:.:.::.:.::: ::XMi::::::::::::::::::::::::MX     \n'
	printf '          XMMT::::.:.::.::::.::.::::::::.::XH:::::::::::::::::::::: M      \n'
	printf '          HMX::...:..::..:.:.::::::..... :::XX::::::::::::::.:::::. M      \n'
	printf '          MM:::....:::::.::::::..:::::.:..:::HX::::::::::::::::::::=M      \n'
	printf '          MX::::::::::::::::::::::..::::.:..::X::::::::::::::::::::IM      \n'
	printf '         XMI..  .:.::....:..::::.:: ::...::.:.MH:::::::::::::::::.: M      \n'
	printf '         MM:. ::..::....::.::::::....:.:...:..MT::.   ::::::::: :..IM      \n'
	printf '         MM=:::::.::.:::::..::::.: .::..::..::Mi:::::::::::::::::: MM      \n'
	printf '         MMI:::...:  .::..::::::.:::::::.::::TM:::::::::::::::::::=MO      \n'
	printf '          MH.: .::::.::.. .:::::iLMXX=::::.:.Mi::::::: ::::::::::.MM       \n'
	printf '          MX:.:..:: .:.:.:.: :MMM:::..:::::.HM:::: :::::::::::::.MM        \n'
	printf '          MM:::...::....: ::IMT:::.:...:.::.MT::::::: ::::::::: MM         \n'
	printf '           M=::..::::..:::MM:i:..::.:...: ::M:::: ::: ::::::::::MI         \n'
	printf '           MH::: :.:.: MMMM=:::.:.:...:....iM::: ::::::  ::::::LM          \n'
	printf '          MMMMT.::. ::TM:::::..::::::::.::.IM::::HH:::::::::::.MO          \n'
	printf '           MM:LM::T:MT.:: .......:....:.:: TMMiXMT.MH:::.::::.:M=          \n'
	printf '            M:. :::MMi:::MMMM=::::::.::..::=MMMMMMXMH:::.:::::MM           \n'
	printf '           XMI: :..::=MX  :M::.......:...:::.MXTHM MH:::.: :.XM            \n'
	printf '           MM XMMI IM    M   ................:: :MIIM:::::::MMO            \n'
	printf '            MMXXMILM  .ML.= :.:::....:.:..::.:..:::MMT:::::TMM             \n'
	printf '              MXMLMMMT::.:...:........ ....::.:.=.MMMM:::::MM              \n'
	printf '              MHM=:: :.:::...::::.:...:.....:: =MMM==Mi::::M               \n'
	printf '              MM=:::.......:.:.::.:.::...:.: ::  . ::=M:: MM               \n'
	printf '             MMi:=XMMMi::::...:::::.::.:::::::::..: ::Mi:=MT               \n'
	printf '            MM=:I::  :iMH==:::::.::.:::::::::::::::.::MT:XMT  \n'
	printf '           MT=:=MMMMMMM=HM::::.::::::MMT=Mi::::::..:::MI=MM\n'
	printf '          M ::::::.=I= .MX:..: ::::.::MX::::.:::.:.  .XMMM\n'
	printf '         M:MMMMMMM=.::::  ::.::...:.MMIM::.:::.::..::::M\n'
	printf '                 M=:: : ::::.==XMMM:XMMM=:::.::.:.::::.M\n'
	printf '                 M=.IMMM )X   M  MMMMMM=:::..::..:::.::M\n'
	printf '                 MM  X  MMM:MMMMMMMMM=:::.:.:.. .:.::::M\n'
	printf '                  MIMMMMMMMMMMMMMMI::::::::.:::.:...:.:M\n'
	printf '                MMMMMMMMMMMMMX:.   .:..::....:...:::.:iM\n'
	printf '               MMMMMMMMMMI::::::.:.::...:....:.....:.:=M\n'
	printf '           MMMMMMMMMI:::::.:.. :.::.::..........:..:..:M\n'
	printf '            M=:  :..::..::.........::.......::.:.....: M\n'
	printf '             MMMi::::::.:.:==MMMMMMMMMT:.:.:::..:::..: OM \n'
	printf '               MM=::..: OMMMM         MMMT:::....:.::: :M\n'
	printf '                M=::::MM                MMI:::........:OM\n'
	printf '                 MMMMM                   MMH:::..::MMMMMM\n'
	printf '                                          MMMMMMMMMMMMMMM\n'
	printf '                        CUB3D\n'
	tput setaf 7

$(NAME): print $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LINKS) $(LIB) -o $(NAME)

comp_start:
	@$(LIBFT)
	@$(MLX)

print:
	@echo $(YELLOW)"Creating OBJECTS"$(RESET)

$(LIBFT):
	@echo $(GREEN_B)"\nOBJECTS are ready. ✅\n"$(RESET)
	@echo $(YELLOW)"Creating $(LIBFT)"$(RESET)
	@$(MAKE) -C $(LIBFT_DIR)
	@echo $(GREEN_B)"\nLibft is ready. ✅\n"$(RESET)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo $(YELLOW)".\c"$(RESET)

clean:
	@rm -rf $(OBJS)
	@make clean -C libft 

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft clean

re: fclean all

.PHONY: all clean fclean re 






CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR) -I$(LIBFT_DIR)
LDFLAGS = -L$(LIBFT_DIR) 
SRCDIR = src
OBJDIR = obj
INC_DIR = include
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
NAME = minishell

# Find all C source files in the source directory, including subdirectories
SOURCES = $(shell find $(SRCDIR) -type f -name '*.c')
# Define object files based on source files
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

	
# Default target
all: $(NAME)

$(NAME): print $(OBJECTS) $(LIBFT)
	@$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	@echo $(GREEN_B)"$(NAME) is ready. ✅\n"$(RESET)

# Pattern rule for compiling C to object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo $(YELLOW)".\c"$(RESET)

print:
	@echo $(YELLOW)"Creating OBJECTS"$(RESET)

$(LIBFT):
	@echo $(GREEN_B)"\nOBJECTS are ready. ✅\n"$(RESET)
	@echo $(YELLOW)"Creating $(LIBFT)"$(RESET)
	@$(MAKE) -C $(LIBFT_DIR)
	@echo $(GREEN_B)"\nLibft is ready. ✅\n"$(RESET)


clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f valgrind.log  # Clean up Valgrind log file as well
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re valgrind