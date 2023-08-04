
#include "minirt.h"


//atoi with floats
float ft_atof(char *str)
{
	int	i;
	int	is_negative;
	float	resultat;

	if (!str)
		return (0);
	is_negative = 0;
	resultat = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		is_negative = ++i;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		resultat *= 10.0f;
		resultat += (str[i] - 48);
		i++;
	}
	if (str[i] && str[i] != '.' && str[i] != '\n')
		return(-1);
	
	if (str[i++] == '.')
	{
		str = &str[i];
		i = 0;
		while (str[i] && str[i] >= '0' && str[i] <= '9')
		{
			resultat *= 10.0f;
			resultat += (str[i] - 48);
			i++;
		}
		while (i--)
			resultat /= 10.0f;
	}
	if (is_negative)
		resultat *= -1.0f;
	return (resultat);
}

//atoi with floats
double ft_atod(char *str)
{
	int	i;
	int	is_negative;
	double	resultat;

	if (!str)
		return (0);
	is_negative = 0;
	resultat = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		is_negative = ++i;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		resultat *= 10.0f;
		resultat += (str[i] - 48);
		i++;
	}
	if (str[i] && str[i] != '.' && str[i] != '\n')
		return(-2);
	
	if (str[i++] == '.')
	{
		str = &str[i];
		i = 0;
		while (str[i] && str[i] >= '0' && str[i] <= '9')
		{
			resultat *= 10.0f;
			resultat += (str[i] - 48);
			i++;
		}
		while (i--)
			resultat /= 10.0f;
	}
	if (is_negative)
		resultat *= -1.0f;
	return (resultat);
}

/*
Checks :
	- if the <file.rt> is valid / exist,
	- if the extension is .rt,
	- if .rt is a file and not a directory,
	- if the file can be opened.
*/
void	check_file_validity(char *file)
{
	int		fd;
	char	*check_file;

	check_file = NULL;
	check_file = ft_strrchr(file, '.');
	if (!check_file)
		ft_putstr_fd("Usage : ./miniRT <file.rt> : File is invalid\n", STDERR_FILENO);
	else if (ft_strcmp(check_file, ".rt") != 0)
		ft_putstr_fd("Usage : ./fdf <map.fdf> : File has an invalid extension\n", STDERR_FILENO);
	else
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
		ft_putstr_fd("Usage : ./fdf <map.fdf> : File can't be opened OR File doesn't exist\n", STDERR_FILENO);
	}
}

//Helper in main.c/main() to check if the input to 
//the program is valid
void check_args_validity(int argc)
{
	if (argc != 2)
	{
		perror("Invalid args.\n");
		exit(EXIT_SUCCESS);//exit failure?
	}
}

void free_minirt(void)
{
	t_minirt *minirt;

	minirt = get_minirt();
	ft_lstclear(&minirt->objects);
	ft_lstclear(&minirt->lights);
	free(minirt);
}
