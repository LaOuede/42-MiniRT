# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macote <macote@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/31 12:57:00 by gle-roux          #+#    #+#              #
#    Updated: 2023/08/01 14:57:22 by macote           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                          BANNER & COLOR SETTINGS                             #
#------------------------------------------------------------------------------#

#Banner
define BANNER1
                   
$G	               $Y_$G       $Y_$G ____  ______
$G	    ____ ___  $Y(_)$G___  $Y(_)$G __ \/_  __/
$G	   / __ `__ \/ / __ \/ / /_/ / / /   
$C	  / / / / / / / / / / / _, _/ / /    
$C	 /_/ /_/ /_/_/_/ /_/_/_/ |_| /_/


endef
export BANNER1

# Colors settings
R = $(shell tput -Txterm setaf 1)
G = $(shell tput -Txterm setaf 2)
Y = $(shell tput -Txterm setaf 3)
Z = $(shell tput -Txterm setaf 5)
C = $(shell tput -Txterm setaf 6)
W = $(shell tput -Txterm setaf 7)

# Print settings
ERASE_LINE	=	\033[2K\r

#------------------------------------------------------------------------------#
#                                   TOOLS                                      #
#------------------------------------------------------------------------------#
define HELP
---------------------------------------------------------------
$YTools available :$W
make help		$Y->$W Display tools available
make norm		$Y->$W Run Norminette
make pdf 		$Y->$W Open PDF subject
make rot 		$Y->$W Open rotation informations
---------------------------------------------------------------
endef
export HELP

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	gcc
CFLAGS	=	-g -Wall -Wextra -Werror
#CFLAGS	=	-fsanitize=address

# Remove
RM		=	rm -rf

# Librairies names
NAME		=	miniRT

# Dir. and files names
SRCS_DIR	=	./src/
SRCS_LIST	=	main.c \
				vectors_math1.c \
				vectors_math2.c \
				parsing.c \
				utils1.c \
				parsing_objects.c \
				parsing_scene_info.c \
				parsing_utils1.c \
				parsing_helper.c \
				parsing_error_handling.c \

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJS_DIR	=	./obj/
OBJS_LIST	=	$(patsubst %.c, %.o, $(SRCS_LIST))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))

# Headers
HEADER_DIR	=	./include/
HEADER_LIST	=	minirt.h \

HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_LIST))

# Libft variables
LIBFT_DIR	=	./libft/
LIBFT		=	$(LIBFT_DIR)libft.a

# MLX42 variables
MLX42_DIR	=	./lib/MLX42/build/
MLX42		=	$(MLX42_DIR)libmlx42.a
OPEN_GL		=	-framework Cocoa -framework OpenGL -framework IOKit
GLFW		=	-lglfw -L "/Users/$$USER/.brew/opt/glfw/lib/"

# Evaluator variable
USER		=	$(shell whoami)

#------------------------------------------------------------------------------#
#                                  RULES                                       #
#------------------------------------------------------------------------------#

# Executable creation
all: dir $(NAME)
	@echo $Y"$$BANNER1"$W
	@echo "				$W...powered by $Ygle-roux$W and $Ymacote$W"
	@echo "					$W...evaluated by $Y$(USER)\n\n$W"

#Create directory for *.o files
dir:
	@mkdir -p $(OBJS_DIR)

# Compilation
$(NAME): $(MLX42) $(LIBFT) $(OBJS)
	@echo "$(ERASE_LINE)$W>>>>>>>>>>>>>>>>>>> $YCOMPILATION $Wis $Gdone ✅ $W<<<<<<<<<<<<<<<<<<<<"
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MLX42) $(OPEN_GL) $(GLFW) -o $(NAME)
	@echo "\n-------------- $WIf help is needed, type $Ymake help $W--------------"
	@echo "\n>>>>>>>>>>>>>>>>>>>>>> $YMiniRT $Wis $Gready ✅$W <<<<<<<<<<<<<<<<<<<<<"

$(MLX42):
	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>> $YCONFIGURATION $W<<<<<<<<<<<<<<<<<<<<<<<<\n"
	@echo "****************** Checking for $YBREW $Wupdate *******************\n"
	@brew update
	@if brew search cmake &> /dev/null; then \
		echo "\n***************** $YCMAKE $Wis already $Ginstalled$W ******************\n"; \
	else \
		echo "\n**************** $RInstalling $ZCMAKE please wait$W *****************\n"; \
		brew install cmake > /dev/null; \
	fi
	@if brew list glfw &> /dev/null; then \
		echo "****************** $YGLFW $Wis already $Ginstalled$W ******************\n"; \
	else \
		echo "***************** $RInstalling $ZGLFW please wait$W *****************\n"; \
		brew install glfw &> /dev/null; \
	fi
	@echo "$W------------------------- $Ylibmlx42.a $W--------------------------\n"
	@if [ ! -f "lib/MLX42/build/libmlx42.a" ]; then \
		cmake MLX42 -B $(MLX42_DIR) &> /dev/null && make -C $(MLX42_DIR) -j4; \
	fi
	@echo "\n$W----------------------- $Ymlx42 $Wis $Gdone ✅ $W----------------------\n"
	
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Create all files .o (object) from files .c (source code)
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
	@printf "$(ERASE_LINE) $GCompiling : $Z$(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Remove objects
clean:
	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>>>>> $YCLEANING $W<<<<<<<<<<<<<<<<<<<<<<<<<<"
	@$(RM) $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$W---------------- $(NAME) : $(OBJS_DIR) was $Rdeleted ❌$W----------------"

# Remove executables
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@$(RM) ./lib
	@echo "\n$W-------- All exec. and archives successfully $Rdeleted ❌$W--------\n"
	@echo "$W>>>>>>>>>>>>>>>>>>>>> $YCleaning $Wis $Gdone ✅ $W<<<<<<<<<<<<<<<<<<<<<\n"

# Remove objects and executables and remake
re: fclean
	@$(MAKE) all

# Make and run the program
run: all
	@./$(NAME)

# Display tools available
help:
	@echo "$$HELP"

# Open the subject
pdf:
	@open https://cdn.intra.42.fr/pdf/pdf/80709/fr.subject.pdf

# Open rotation informations
rot:
	@open https://fr.wikipedia.org/wiki/Rotation_vectorielle

# Run norminette
norm :
	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>>>> $YNORMINETTE $W<<<<<<<<<<<<<<<<<<<<<<<<<<$Z\n"
	@norminette $(SRCS) $(HEADER) $(LIBFT_DIR) $(SRCS_B)
	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>> $YNORMINETTE ✅ $W<<<<<<<<<<<<<<<<<<<<<<<<<<"

# Avoids file-target name conflicts
.PHONY: all dir clean fclean re help pdf rot norm run