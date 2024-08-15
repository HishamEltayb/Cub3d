# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 10:38:05 by heltayb           #+#    #+#              #
#    Updated: 2024/08/15 09:26:50 by heltayb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COLOURS
GREEN_B = "\033[1;32m"
RED_BI = "\033[1;3;31m"
BLUE_I = "\033[3;34m"
YELLOW = "\033[0;33m"
RESET = "\033[0m"


NAME		=	cub3D
CFLAGS		=	-Wall -Werror -Wextra -fsanitize=address -g3 -D $(OS)

SRCDIR		=	src
OBJDIR		=	obj
 
SRCS		=	$(shell find $(SRCDIR) -type f)
OBJS		=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

LIBFT		= 	libs/libft/libft.a

INCLUDE		:=
MLX_FOLDER	:=	
MLXLIB		:=	
LINKS		:= 

OS			:= $(shell uname)

ifeq ($(OS), Linux)
	MLX_FOLDER += libs/mlx_linux
	MLXLIB += libs/mlx_linux/libmlx_Linux.a
	LINKS += -L/usr/lib -L$(MLX_FOLDER) -lXext -lX11 -lm
	INCLUDE +=	-I./ -I./libs/mlx_linux -I./libs/libft 
else
	MLX_FOLDER += libs/mlx
	MLXLIB += libs/mlx/libmlx.a
	LINKS += -L$(MLX_FOLDER) -framework OpenGL -framework AppKit
	INCLUDE +=	-I./ -I./libs/mlx -I./libs/libft 
endif


all: $(NAME)
	@echo $(BLUE_I)
	@printf '                      MMMMMMM           MMMMMMH                            \n'
	@printf '                HMMMMM:::::::.MMMMMMMMMM:::::.TMM                          \n'
	@printf '              MMMI:::::::::::::::::::MMH::::::::TM                         \n'
	@printf '            MMIi::::::::::::.:::::::::::::::::::::MMMM                     \n'
	@printf '           MT::::.::::::::::::::::::::::::::::::.::=T.IMMM                 \n'
	@printf '         MMMi:::::::::::::::::::::::::::::::::::::::::::MT)MM              \n'
	@printf '     MMMI.:::::::::::::::::::::::::::::::::::::::::::.:::M= MM             \n'
	@printf '   XMXi::::::::::::::::::::::.:::::::::::::::::::::::::::::::=MM           \n'
	@printf '   MMi::::::::::::::::::::::::::::::::::::::::::::::::::.::..:=MMM         \n'
	@printf '  MM:MMT:::::::::.:::::::::::::::::.:::::::::::::::::::::::::::MiMM        \n'
	@printf '   MMM::::::::::::::::::.::::::::::::::::::::::::::.::::::::::.TM.MM       \n'
	@printf '   MMi::::::::::::::.::::::::::::::::::::::::::::::::::::::.:::.:: M       \n'
	@printf '   MM:::.::::::::::::::::::::::::::::::::.:.:::::::::::::::::::::: XM      \n'
	@printf ' MM:MT::.::::::::::::::::::::::::::::::::::::::::::::::::::::::::::XM      \n'
	@printf 'IMM:::.::::::::::::::::::::::::::::::::::: :::::::::::::::::::::::.=M      \n'
	@printf ' MM::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: :::M      \n'
	@printf ' XMT:::::::::::::::::::::: ::::::::::::::::: : ::::::::::::::::::: iM      \n'
	@printf '   MiMi:::::::::: :::::::::::::::::::::::::::::::: ::::::::::::::.:IM      \n'
	@printf '     M::::::HH::::::::::::::::::::::::::::::::::::::::::::::::::::: M      \n'
	@printf '     MT:::::iM::::::::Hi:iXH:::ii::XH:::::::::::::.::::::::::::::.:.M      \n'
	@printf '      MX:::::iMX:i::::iMi:iMH::XH::Mi:::::::::::::::::::::::::::::: M      \n'
	@printf '        Mii::::HMH:::::iMH::MH=:MM=TMi::::::::::::::::::::::::::::::MM     \n'
	@printf '          MMMMMMMMMMMXTi:MMHi:HMMIMMMMii::::::::::::::::::::::::::::XM     \n'
	@printf '           XXOXMMT:. ::T= :IMMMMMMM=iXMii:::::::::::::::::::::::::: MM     \n'
	@printf '            MMMH:::.:::::::.::::.::::.:XMi::::::::::::::::::::::::::MM     \n'
	@printf '           XMM::.:.:..::..:.:.::.:.::: ::XMi::::::::::::::::::::::::MX     \n'
	@printf '          XMMT::::.:.::.::::.::.::::::::.::XH:::::::::::::::::::::: M      \n'
	@printf '          HMX::...:..::..:.:.::::::..... :::XX::::::::::::::.:::::. M      \n'
	@printf '          MM:::....:::::.::::::..:::::.:..:::HX::::::::::::::::::::=M      \n'
	@printf '          MX::::::::::::::::::::::..::::.:..::X::::::::::::::::::::IM      \n'
	@printf '         XMI..  .:.::....:..::::.:: ::...::.:.MH:::::::::::::::::.: M      \n'
	@printf '         MM:. ::..::....::.::::::....:.:...:..MT::.   ::::::::: :..IM      \n'
	@printf '         MM=:::::.::.:::::..::::.: .::..::..::Mi:::::::::::::::::: MM      \n'
	@printf '         MMI:::...:  .::..::::::.:::::::.::::TM:::::::::::::::::::=MO      \n'
	@printf '          MH.: .::::.::.. .:::::iLMXX=::::.:.Mi::::::: ::::::::::.MM       \n'
	@printf '          MX:.:..:: .:.:.:.: :MMM:::..:::::.HM:::: :::::::::::::.MM        \n'
	@printf '          MM:::...::....: ::IMT:::.:...:.::.MT::::::: ::::::::: MM         \n'
	@printf '           M=::..::::..:::MM:i:..::.:...: ::M:::: ::: ::::::::::MI         \n'
	@printf '           MH::: :.:.: MMMM=:::.:.:...:....iM::: ::::::  ::::::LM          \n'
	@printf '          MMMMT.::. ::TM:::::..::::::::.::.IM::::HH:::::::::::.MO          \n'
	@printf '           MM:LM::T:MT.:: .......:....:.:: TMMiXMT.MH:::.::::.:M=          \n'
	@printf '            M:. :::MMi:::MMMM=::::::.::..::=MMMMMMXMH:::.:::::MM           \n'
	@printf '           XMI: :..::=MX  :M::.......:...:::.MXTHM MH:::.: :.XM            \n'
	@printf '           MM XMMI IM    M   ................:: :MIIM:::::::MMO            \n'
	@printf '            MMXXMILM  .ML.= :.:::....:.:..::.:..:::MMT:::::TMM             \n'
	@printf '              MXMLMMMT::.:...:........ ....::.:.=.MMMM:::::MM              \n'
	@printf '              MHM=:: :.:::...::::.:...:.....:: =MMM==Mi::::M               \n'
	@printf '              MM=:::.......:.:.::.:.::...:.: ::  . ::=M:: MM               \n'
	@printf '             MMi:=XMMMi::::...:::::.::.:::::::::..: ::Mi:=MT               \n'
	@printf '            MM=:I::  :iMH==:::::.::.:::::::::::::::.::MT:XMT  \n'
	@printf '           MT=:=MMMMMMM=HM::::.::::::MMT=Mi::::::..:::MI=MM\n'
	@printf '          M ::::::.=I= .MX:..: ::::.::MX::::.:::.:.  .XMMM\n'
	@printf '         M:MMMMMMM=.::::  ::.::...:.MMIM::.:::.::..::::M\n'
	@printf '                 M=:: : ::::.==XMMM:XMMM=:::.::.:.::::.M\n'
	@printf '                 M=.IMMM )X   M  MMMMMM=:::..::..:::.::M\n'
	@printf '                 MM  X  MMM:MMMMMMMMM=:::.:.:.. .:.::::M\n'
	@printf '                  MIMMMMMMMMMMMMMMI::::::::.:::.:...:.:M\n'
	@printf '                MMMMMMMMMMMMMX:.   .:..::....:...:::.:iM\n'
	@printf '               MMMMMMMMMMI::::::.:.::...:....:.....:.:=M\n'
	@printf '           MMMMMMMMMI:::::.:.. :.::.::..........:..:..:M\n'
	@printf '            M=:  :..::..::.........::.......::.:.....: M\n'
	@printf '             MMMi::::::.:.:==MMMMMMMMMT:.:.:::..:::..: OM \n'
	@printf '               MM=::..: OMMMM         MMMT:::....:.::: :M\n'
	@printf '                M=::::MM                MMI:::........:OM\n'
	@printf '                 MMMMM                   MMH:::..::MMMMMM\n'
	@printf '                                          MMMMMMMMMMMMMMM\n'
	@echo $(RED_BI)"\n\n				ENJOY🔥\n"$(RESET)
	
$(NAME): print $(MLXLIB) $(LIBFT) $(OBJS)
	@echo $(RESET)
	@cc $(CFLAGS) $(OBJS) $(LIBFT) $(MLXLIB)  -o $(NAME) $(LINKS)
	
run: $(NAME)
	@./$(NAME) maps/map.cub

print:
	@echo $(YELLOW)"Creating OBJECTS"$(RESET)

$(MLXLIB):
	@echo $(YELLOW)"Creating $(MLXLIB)"$(RESET)
	@make -C $(MLX_FOLDER)
	

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@cc $(INCLUDE) $(CFLAGS)  -c $< -o $@
	@echo $(YELLOW)".\c"$(RESET)

$(LIBFT):
	@echo $(GREEN_B)"\nOBJECTS are ready. ✅\n"$(RESET)
	@echo $(YELLOW)"Creating $(LIBFT)"$(RESET)
	@make -C libs/libft
	@echo $(GREEN_B)"\nLibft is ready. ✅\n"$(RESET)


clean:
	@rm -rf $(OBJDIR)
	@make clean -C libs/libft 
	@make clean -C libs/mlx
	@echo $(GREEN_B)"\nCLEANED. ✅\n"$(RESET)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libs/libft
	@echo $(GREEN_B)"\nFCLEANED. ✅\n"$(RESET)

valgrind: $(OBJS) $(NAME)
	@valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) maps/map.cub

print_re:
	@echo $(YELLOW)"Recreating OBJECTS"$(RESET)

re:
	make fclean
	make print_re
	make all

.PHONY: all clean fclean re 

