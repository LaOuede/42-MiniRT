#include "minirt.h"

void	print_cmd_menu1(void)
{
	printf("\n##############################################################\n");
	printf("#                       COMMANDS MENU                        #\n");
	printf("##############################################################\n\n");
	printf("--------------------- Sampling selection ---------------------\n\n");
	printf("Normal sampling : 1\n");
	printf("Super sampling :  2\n\n");
	printf("---------------------- Object selection ----------------------\n\n");
	printf("To select camera :        C\n");
	printf("To select light :         BACKSPACE\n");
	printf("To select an object :     Mouse button left\n");
	printf("------------------------ Translation -------------------------\n\n");
	printf("X_axis : A --- B\n");
	printf("Y_axis : Q --- E\n");
	printf("Z_axis : W --- S\n\n");
	printf("-------------------------- Rotation --------------------------\n\n");
	printf("X_axis : I --- K\n");
	printf("Y_axis : J --- L\n");
	printf("Z_axis : U --- O\n\n");
	printf("-------------------------- Scale -----------------------------\n\n");
	printf("Sphere diameter :   + --- -\n");
	printf("Cylinder height :   H then + --- -\n");
	printf("Cylinder diameter : R then + --- -\n\n");
}

void	print_cmd_menu2(void)
{
	printf("-------------------------- Lights ----------------------------\n\n");
	printf("Change light : SPACE\n");
	printf("Intensity :    + --- -\n");
	printf("--------------------------- Other ----------------------------\n\n");
	printf("To display the commands menu : M\n");
	printf("To quit the program :          ESC\n\n");
	printf("################################################################\n");
}
