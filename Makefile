
#------------------------------------------------------------------------------#
#                          BANNER & COLOR SETTINGS                             #
#------------------------------------------------------------------------------#

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
CFLAGS	=	-g -Wall -Wextra -Werror -flto -Ofast -march=native -funroll-loops -finline-functions -ftree-vectorize -ffast-math #-fsanitize=thread
#CFLAGS	=	-g -fsanitize=address

# Remove
RM		=	rm -rf

# Librairies names
NAME		=	miniRT

# Dir. and files names
SRCS_DIR	=	./src/
SRCS_LIST	=	colors/colors.c \
				colors/colors_transformations.c \
				hooks/camera_rotation.c \
				hooks/camera_translation.c \
				hooks/cone_rotation.c \
				hooks/cylinder_rotation.c \
				hooks/light_translation.c \
				hooks/keys_cam_light.c \
				hooks/keys_general.c \
				hooks/keys_move.c \
				hooks/keys_objects.c \
				hooks/mouse.c \
				hooks/mouse_utils.c \
				hooks/object_translation.c \
				hooks/plane_rotation.c \
				intersections/hit_cylinder.c \
				intersections/hit_plane.c \
				intersections/hit_sphere.c \
				intersections/hit_cone.c \
				main.c \
				materials/load_materials.c \
				materials/no_material.c \
				materials/moon.c \
				materials/earth.c \
				materials/water.c \
				materials/sun.c \
				matrices/matrices_init.c \
				matrices/matrices_math.c \
				matrices/matrices_transformations.c \
				parsing/parsing.c \
				parsing/object_error.c \
				parsing/parsing_error_helper.c \
				parsing/object_error_types.c \
				parsing/object_error_utils.c \
				parsing/parsing_error_handling.c \
				parsing/parsing_helper.c \
				parsing/parsing_objects.c \
				parsing/parsing_scene_info.c \
				parsing/parsing_utils1.c \
				ray_generation/ray_launcher.c \
				ray_generation/find_closest_hit.c \
				ray_generation/shading.c \
				ray_generation/reflexions.c \
				textures/texture.c \
				textures/normal_map.c \
				textures/uv_mapping.c \
				utils/get_object_info.c \
				utils/get_object_info2.c \
				utils/get_light_info.c \
				utils/utils_ato.c \
				utils/utils_free.c \
				utils/utils_image.c \
				utils/utils_menu.c \
				utils/utils_parsing.c \
				vectors/vectors_math1.c \
				vectors/vectors_math2.c \
				vectors/vectors_math3.c \
				vectors/object_normal_vec.c \

# 
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJS_DIR	=	./obj/
OBJS_LIST	=	$(patsubst %.c, %.o, $(SRCS_LIST))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))

# Headers
HEADER_DIR	=	./include/
HEADER_LIST	=	minirt.h
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

# Includes
INCLUDE		= -I$(HEADER_DIR) -I$(LIBFT_DIR) -I$(MLX42_DIR)/include

#------------------------------------------------------------------------------#
#                                  RULES                                       #
#------------------------------------------------------------------------------#

# Executable creation
all: dir $(NAME)

#Create directory for *.o files
dir:
	@mkdir -p $(OBJS_DIR) $(OBJS_DIR)parsing \
	$(OBJS_DIR)vectors $(OBJS_DIR)matrices $(OBJS_DIR)colors \
	$(OBJS_DIR)intersections $(OBJS_DIR)utils $(OBJS_DIR)ray_generation \
	$(OBJS_DIR)hooks $(OBJS_DIR)materials $(OBJS_DIR)textures

# Compilation
$(NAME): $(MLX42) $(LIBFT) $(OBJS)
	@echo "$(ERASE_LINE)$W>>>>>>>>>>>>>>>>>> $YCONFIGURATION $Wis $Gdone ✅ $W<<<<<<<<<<<<<<<<<<<"
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MLX42) $(OPEN_GL) $(GLFW) -o $(NAME) $(INCLUDE)
	@echo "\n-------------- $WIf help is needed, type $Ymake help $W--------------"
	@echo "\n>>>>>>>>>>>>>>>>>>>>>> $YMiniRT $Wis $Gready ✅$W <<<<<<<<<<<<<<<<<<<<<\n"

$(MLX42):
	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>> $YCONFIGURATION $W<<<<<<<<<<<<<<<<<<<<<<<<\n"
	@echo "------------------- Checking for $YBREW $Wupdate ------------------\n"
	@brew update
	@if brew search cmake &> /dev/null; then \
		echo "\n------------------ $YCMAKE $Wis already $Ginstalled$W -----------------\n"; \
	else \
		echo "\n**************** $RInstalling $ZCMAKE please wait$W *****************\n"; \
		brew install cmake > /dev/null; \
	fi
	@if brew list glfw &> /dev/null; then \
		echo "------------------ $YGLFW $Wis already $Ginstalled$W ------------------\n"; \
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
	@printf "$(ERASE_LINE) $YCompiling : $W$(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

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

# Open intersection informations
int:
	@open https://hugi.scene.org/online/hugi24/coding%20graphics%20chris%20dragan%20raytracing%20shapes.htm

# Run norminette
norm :
	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>>>> $YNORMINETTE $W<<<<<<<<<<<<<<<<<<<<<<<<<<$Z\n"
	@norminette $(SRCS) $(HEADER) $(LIBFT_DIR) $(SRCS_B)
	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>> $YNORMINETTE ✅ $W<<<<<<<<<<<<<<<<<<<<<<<<<<"

# Avoids file-target name conflicts
.PHONY: all dir clean fclean re help pdf rot norm run int