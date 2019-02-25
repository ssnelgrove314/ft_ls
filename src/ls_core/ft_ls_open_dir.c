#include "../../includes/ft_ls.h"

t_stack *ft_ls_open_dir(t_file *arg)
{
	t_stack *dir_contents;
	t_file *tmp;
	struct dirent *tmp_fdirent;

	tmp_fdirent = NULL;
	dir_contents = (t_stack *)ft_memalloc(sizeof(dir_contents));
	stack_init(dir_contents);
	arg->dir = opendir(arg->name);
	while ((tmp_fdirent = readdir(arg->dir)) != NULL)
	{
		tmp = (t_file *)ft_memalloc(sizeof(t_file));
		tmp->fdirent = tmp_fdirent;
		tmp->name = tmp->fdirent->d_name;
		stack_push(dir_contents, tmp);
	}
	stack_push(dir_contents, arg);
	// closedir(arg->dir); This frees fdirent structs
	return (dir_contents);
}