#include "../../includes/ft_ls.h"

void ft_getargs_ls(t_ls_ctx *ctx, int argc, char ***argv)
{
    t_file *tmp;
	char **av;
	int i;

	i = argc;
	av = *argv;
    tmp = NULL;
	if (i + 1 > ctx->n) // more than one arg?
		ctx->ls_flags |= LS_MORE_THAN_ONE_ARG;
    while (i > ctx->n)
    {
        if (!(tmp = (t_file *)ft_memalloc(sizeof(t_file))))
            return ; //error
        tmp->name = ft_strdup(av[ctx->n]);
        stack_push(ctx->args, tmp);
		i--;
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