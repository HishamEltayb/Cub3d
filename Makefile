# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 10:38:05 by heltayb           #+#    #+#              #
#    Updated: 2024/07/05 19:05:03 by heltayb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COLOURS
GREEN_B = "\033[1;32m"
RED_BI = "\033[1;3;31m"
BLUE_I = "\033[3;34m"
YELLOW = "\033[0;33m"
RESET = "\033[0m"

#-fsanitize=address -g3

NAME	=	cub3D
CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address  -g3

SRCDIR	=	src
OBJDIR	=	obj
 
SRCS	=	cub3d.c utils.c elements.c

SRCS := $(addprefix $(SRCDIR)/, $(SRCS))
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)


LIBFT 	= 	libs/libft/libft.a
MLX		=	libs/mlx/libmlx.a

INCLUDE =	-I./ -I./libs/mlx -I./libs/libft 
LINKS	=  -framework OpenGL -framework AppKit

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
	
$(NAME): print  $(MLX) $(LIBFT) $(OBJS)
	@echo $(RESET)
	@cc $(CFLAGS) $(OBJS)  $(LIBFT) $(MLX)  -o $(NAME)  $(LINKS)

print:
	@echo $(YELLOW)"Creating OBJECTS"$(RESET)

$(MLX):
	@echo $(YELLOW)"Creating $(MLX)"$(RESET)
	@make -C libs/mlx
	

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
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
	make clean -C libs/mlx
	@echo $(GREEN_B)"\nCLEANED. ✅\n"$(RESET)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libs/libft
	@echo $(GREEN_B)"\nFCLEANED. ✅\n"$(RESET)

valgrind: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) maps/map.cub

print_re:
	@echo $(YELLOW)"Recreating OBJECTS"$(RESET)

re: fclean print_re all

.PHONY: all clean fclean re 

