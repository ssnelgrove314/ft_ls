#include "ft_ls.h"
void ft_ls_get_date(t_file *arg)
{
	if (lstat(arg->name, arg->fstat))
		ft_error("lstat error");
}

void ft_ls_get_long_list(t_ls_opts *opts, t_file *arg)
{
	if (lstat(arg->name, arg->fstat))
		ft_error("lstat error");
	arg->fgroup = getgrgid(arg->fstat->st_gid);
	arg->fpasswd = getpwuid(arg->fstat->st_uid);
}

void ft_ls_extra(t_ls_opts *opts, t_file *arg)
{
	if (opts->long_list_flag)
		ft_ls_get_long_list(opts, arg);
	else if (opts->modification_date_sort_flag)
		ft_ls_get_date(arg);
}

t_stack *ft_ls_open_dir(t_ls_opts *opts, t_file *arg)
{
	t_stack *dir_contents;
	t_file tmp;
	t_file *tmp_ptr;

	stack_init(dir_contents, LS_STACK_SIZE);
	arg->dir = opendir(arg->name);
	while ((tmp.fdirent = readdir(arg->dir)) != NULL)
	{
		ft_ls_extra(opts, &tmp);
		if (!opts->all_flag)
		{
			if (ft_strcmp(tmp.name, ".") || ft_strcmp(tmp.name, ".."))
				continue ;
		}
		else if(tmp.name)
		{
			tmp_ptr = (t_file *)ft_memalloc(sizeof(tmp_ptr));
			ft_memcpy(tmp_ptr, &tmp, sizeof(tmp));
			stack_push(dir_contents, tmp_ptr);
		}
	}
	closedir(arg->dir);
	return (dir_contents);
}

int ft_ls_once(t_ls_opts *opts, t_file *arg)
{
	t_stack *contents;
	t_file *cur;

	cur = NULL;
	if (!arg)
		return (0);
	stack_init(contents, LS_STACK_SIZE);
	contents = ft_ls_open_dir(opts, arg);
	ft_ls_sort(opts, contents);
	ft_ls_print(opts, contents);
	return (LS_SUCCESS);
}

int ft_ls_recurse(t_ls_opts *opts, t_file *arg)
{
	t_stack *contents;
	t_file *cur;

	cur = NULL;
	if (!arg)
		return (0);
	stack_init(contents, LS_STACK_SIZE);
	contents = ft_ls_open_dir(opts, arg);
	ft_ls_sort(opts, contents);
	ft_ls_print(opts, contents);
	while ((cur = stack_pop(contents)) != NULL)
		if (is_dir(cur))
			ft_ls_recurse(opts, cur);
	return (LS_SUCCESS);
}

int ft_ls(t_ls_opts *opts, t_stack *args)
{
	t_file *cur;

	cur = NULL;
	if (!opts || !args)
		return (LS_ERROR);
	if (opts->recursive_flag)
		while ((cur = stack_pop(args)) != NULL)
			ft_ls_recurse(opts, cur);
	else
		while ((cur = stack_pop(args)) != NULL)
			ft_ls_once(opts, cur);
	return (LS_SUCCESS);
}

int main(int argc, char **argv)
{
	t_ls_opts *opts;
	t_stack *args;
	
	opts = (t_ls_opts *)ft_memalloc(sizeof(t_ls_opts));
	stack_init(args, argc);
	ft_getopts_ls(opts);
	ft_getargs_ls(args);
	return (ft_ls(opts, args));
}