#include "ft_ls.h"

void set_flags(t_ls *ls, char flag)
{
	if (flag == 'R')
		ls->flags.recursive_flag = 1;
	else if (flag == 'r')
		ls->flags.reverse_flag = 1;
	else if (flag == 't')
		ls->flags.modification_date_sort_flag = 1;
	else if (flag == 'l')
		ls->flags.long_list_flag = 1;
	else if (flag == 'a')
		ls->flags.all_flag = 1;
	else
		perror("Invalid Flag");
}

int parse_args(t_ls *ls, char **argv, int argc)
{
	char *start;

	while (argv++ && argc--)
	{
		if (argv[0][0] != '-')
		{
			ls->argv = argv;
			ls->argc = argc;
			break;
		}
		set_flags(ls, argv[0][1]);
	}
	return (1);
}

void get_arg_dirs(t_ls *ls)
{

}

int open_directories(t_ls *ls)
{
	DIR *dir;
	int i;
	int j;

	i = -1;
	
	if (!ls->argc)
	{
		ls->argv[0] = ".";
		ls->argc++;
	}
	while (++i < ls->argc)
	{
		j = -1;
		dir = opendir(ls->argv[i]);
		while ((ls->dir[i]->dir_entry[++(ls->dir[i]->num_entry)] = readdir(dir)) != 0)
			;
		closedir(dir);
	}
	get_arg_dirs(ls);
	ls->num_entry = i;
	return (0);
}

int main(int argc, char **argv)
{
	t_ls ls;

	if (parse_args(&ls, argv, argc) != 0))
		return (-1);
	if (open_directories(&ls) != 0)
		return (-1);
	ls_sort(ls.from_args, &ls_sort_default);
}
