#include "ft_ls.h"

#define MAX_SIZE 2000

void get_list_from_args(int argc, char **argv, t_ls *ls)
{
	t_dir *dir;
	stack_init(ls->dirs, MAX_SIZE);
	while (--argc)
	{
		dir = (t_dir *)ft_memalloc(sizeof(t_dir))
		dir->dir_name = argv[argc];
		stack_push(ls->dirs, (void *)dir);
	}
	ls_sort(&ls);
}