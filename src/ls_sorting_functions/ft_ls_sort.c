#include "../../includes/ft_ls.h"

int ls_cmp_modification_date_sort(void *a, void *b)
{
    VAR(t_file *, afile, (t_file *)a);
    VAR(t_file *, bfile, (t_file *)b);
    char *astr;
    char *bstr;

    astr = afile->name;
    bstr = bfile->name;
    return (ft_strcmp(astr, bstr));
}

int ls_default_cmp(void *a, void *b)
{
    VAR(t_file *, afile, (t_file *)a);
    VAR(t_file *, bfile, (t_file *)b);
    char *astr;
    char *bstr;

    astr = afile->name;
    bstr = bfile->name;
    return (ft_strcmp(astr, bstr));
}

void ft_ls_sort(t_ls_ctx *ctx, t_stack *content)
{
    if (ctx->ls_flags & LS_MODIFICATION_DATE_SORT)
        ft_mergesort(&(content->head), ls_cmp_modification_date_sort);
    else
        ft_mergesort(&(content->head), ls_default_cmp);
}