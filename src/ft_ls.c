#include "ft_ls.h"

t_ls_ctx *init_ctx()
{
    t_ls_ctx *ctx;

    if (!(ctx = (t_ls_ctx *)ft_memalloc(sizeof(t_ls_ctx))))
        return (NULL);
    if (!(ctx->args = (t_stack *)ft_memalloc(sizeof(t_stack))))
        return (NULL);
        // ft_ls_error();
    ctx->ls_flags = 0;
    ctx->n = 1;
    stack_init(ctx->args);

    return (ctx);
}

void ft_getopts_ls(t_ls_ctx *ctx, int argc, char **argv)
{
    while (ctx->n < argc && argv[ctx->n][0] == '-' && ft_strlen(argv[ctx->n]) == 2)
    {
        if (argv[ctx->n][1] == 'R')
            ctx->ls_flags |= LS_RECURSE;
        else if (argv[ctx->n][1] == 'r')
            ctx->ls_flags |= LS_REVERSE;
        else if (argv[ctx->n][1] == 't')
            ctx->ls_flags |= LS_MODIFICATION_DATE_SORT;
        else if (argv[ctx->n][1] == 'l')
            ctx->ls_flags |= LS_LONG_LIST;
        else if (argv[ctx->n][1] == 'a')
            ctx->ls_flags |= LS_ALL;
        ctx->n++;
    }
}

void ft_getargs_ls(t_ls_ctx *ctx, int argc, char ***argv)
{
    t_file *tmp;
	char **av;

	av = *argv;
    tmp = NULL;
    while (ctx->n < argc)
    {
        if (!(tmp = (t_file *)ft_memalloc(sizeof(t_file))))
            return ; //error
        tmp->name = ft_strdup(av[ctx->n]);
        stack_push(ctx->args, tmp);
    }
    if (stack_empty(ctx->args))
    {
        if (!(tmp = (t_file *)ft_memalloc(sizeof(t_file))))
            return ; //error
		// getcwd() might work better;
        tmp->name = ft_strdup(".");
        stack_push(ctx->args, tmp);
    }
}

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
	// closedir(arg->dir); This frees fdirent structs
	return (dir_contents);
}

int ft_ls_once(t_ls_ctx *ctx, t_file *arg)
{
	t_stack *contents;
	t_file *cur;

	contents = (t_stack *)ft_memalloc(sizeof(contents));
	cur = (t_file *)ft_memalloc(sizeof(cur));
	if (!arg)
		return (0);
	contents = ft_ls_open_dir(arg);
	// ft_ls_sort(ctx, contents);
	ft_ls_print(ctx, contents);
	return (LS_SUCCESS);
}

int ft_ls_recurse(t_ls_ctx *ctx, t_file *arg)
{
	t_stack *contents;
	t_file *cur;

	contents = (t_stack *)ft_memalloc(sizeof(contents));
	cur = (t_file *)ft_memalloc(sizeof(cur));

	stack_init(contents);
	contents = ft_ls_open_dir(arg);
	// ft_ls_sort(ctx, contents);
	ft_ls_print(ctx, contents);
	while ((cur = stack_pop(contents)) != NULL)
		if (S_ISDIR(cur->fstat->st_mode))
			ft_ls_recurse(ctx, cur);
	return (LS_SUCCESS);
}

int ft_ls(t_ls_ctx *ctx)
{
	t_file *cur;

	cur = NULL;
	if (!ctx || !ctx->args)
		return (LS_ERROR);
    // ft_ls_sort(ctx, ctx->args);
	if (ctx->ls_flags & LS_RECURSE)
		while ((cur = (t_file *)stack_pop(ctx->args)) != NULL)
			ft_ls_recurse(ctx, cur);
	else
		while ((cur = stack_pop(ctx->args)) != NULL)
			ft_ls_once(ctx, cur);
	return (LS_SUCCESS);
}

int ft_ls_print(t_ls_ctx *ctx, t_stack *content)
{
	t_file *cur;

	if (ctx->ls_flags & LS_ALL)
		return 1;
	while ((cur = stack_pop(content)) != NULL)
	{
		printf("%s\n", cur->name);
		// free(cur);
	}
	return (LS_SUCCESS);
}

int main(int argc, char **argv)
{
    t_ls_ctx *ctx;

    ctx = init_ctx();
    ft_getopts_ls(ctx, argc, argv);
    ft_getargs_ls(ctx, argc, &argv);
    return (ft_ls(ctx));
}