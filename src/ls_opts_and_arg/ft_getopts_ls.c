#include "../../includes/ft_ls.h"

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