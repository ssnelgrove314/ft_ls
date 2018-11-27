#include "ft_ls.h"

void ft_error(char *error)
{
	ft_printf("%s\n", error);
	exit(1);
}

char *strmode(mode_t mode)
{
	int i;
	const char chars[] = "rwxrwxrwx";
	char *buf;

	i = -1;
	buf = ft_strnew(10);
	while (++i < 9)
		buf[i] = (mode & (1 << (8 - i))) ? chars[i] : '-';
	buf[9] = '\0';
	return (buf);
}

int ft_ls_print(t_ls_opts *opts, t_stack *content)
{
	t_file *tmp;

	tmp = NULL;
	if (opts->all_flag)
		return (-1);
	while ((tmp = (t_file *)stack_pop(content)) != NULL)
	{
		printf("%s\n", tmp->name);
		free(tmp);
	}
	return (LS_SUCCESS);
}

void ft_ls_get_date(t_file *arg)
{
	if (lstat(arg->name, arg->fstat))
		ft_error("lstat error");
}

void ft_ls_get_long_list(t_file *arg)
{
	if (lstat(arg->name, arg->fstat))
		ft_error("lstat error");
	arg->fgroup = getgrgid(arg->fstat->st_gid);
	arg->fpasswd = getpwuid(arg->fstat->st_uid);
}

void ft_ls_extra(t_ls_opts *opts, t_file *arg)
{
	if (opts->long_list_flag)
		ft_ls_get_long_list(arg);
	else if (opts->modification_date_sort_flag)
		ft_ls_get_date(arg);
}

t_stack *ft_ls_open_dir(t_ls_opts *opts, t_file *arg)
{
	t_stack *dir_contents;
	t_file tmp;
	t_file *tmp_ptr;

	dir_contents = (t_stack *)ft_memalloc(sizeof(dir_contents));
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

	contents = (t_stack *)ft_memalloc(sizeof(contents));
	cur = (t_file *)ft_memalloc(sizeof(cur));
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

	contents = (t_stack *)ft_memalloc(sizeof(contents));
	cur = (t_file *)ft_memalloc(sizeof(cur));
	if (!arg)
		return (0);
	stack_init(contents, LS_STACK_SIZE);
	contents = ft_ls_open_dir(opts, arg);
	ft_ls_sort(opts, contents);
	ft_ls_print(opts, contents);
	while ((cur = stack_pop(contents)) != NULL)
		if (S_ISDIR(cur->fstat->st_mode))
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
	
	args = (t_stack *)ft_memalloc(sizeof(args));
	opts = (t_ls_opts *)ft_memalloc(sizeof(t_ls_opts));
	stack_init(args, argc);
	ft_getopts_ls(opts, &argc, argv);
	ft_getargs_ls(args, &argc, argv);
	return (ft_ls(opts, args));
}