#include "../../includes/ft_ls.h"

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

