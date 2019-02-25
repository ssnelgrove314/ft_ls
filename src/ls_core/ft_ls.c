#include "../../includes/ft_ls.h"

t_ls_ctx *init_ctx()
{
    t_ls_ctx *ctx;

    if (!(ctx = (t_ls_ctx *)ft_memalloc(sizeof(t_ls_ctx))))
        return (NULL);
    if (!(ctx->args = (t_stack *)ft_memalloc(sizeof(t_stack))))
        return (NULL);
    ctx->ls_flags = 0;
    ctx->n = 1;
    stack_init(ctx->args);
    return (ctx);
}

int ft_ls_once(t_ls_ctx *ctx, t_file *arg)
{
	t_stack *contents;
	t_file *cur;

	contents = (t_stack *)ft_memalloc(sizeof(contents));
	cur = (t_file *)ft_memalloc(sizeof(cur));
	if (!arg)
		return (0);
	if (ctx->ls_flags & LS_MORE_THAN_ONE_ARG)
		printf("%s:\n", arg->name);
	contents = ft_ls_open_dir(arg);
	ft_ls_sort(ctx, contents);
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

	ctx->print_dir_flag = (ctx->args->size == 1 ? 1 : 0);
	cur = NULL;
	if (!ctx || !ctx->args)
		return (LS_ERROR);
    // ft_ls_sort(ctx, ctx->args);
	if (ctx->ls_flags & LS_RECURSE)
		while ((cur = (t_file *)stack_pop(ctx->args)) != NULL)
			ft_ls_recurse(ctx, cur);
	else
	{
		while ((cur = stack_pop(ctx->args)) != NULL)
		// print dir names here? dir:\ncontents
			ft_ls_once(ctx, cur);
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