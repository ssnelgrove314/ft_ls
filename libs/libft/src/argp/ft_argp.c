#include "ft_argp.h"

int argp_init(t_argp *self, t_argp_opt *options, const char *const *usages, int flags)
{
	ft_memset(self, 0, sizeof(*self));
	self->options = options;
	self->usages = usages;
	self->flags = flags;
	self->desc = NULL;
	self->epilog = NULL;
	return (0);
}

int argp_short_opt(t_argp *self, const t_argp_opt *options)
{
	while (options->type != ARGP_OPT_END)
	{
		if (options->short_name == *self->optvalue)
		{
			self->optvalue = self->optvalue[1] ? self->optvalue + 1 : NULL;
			return (argp_getvalue(self, options, 0));
		}
		options++;
	}
	return (-2);
}
int argp_help_cb(t_argp *self, const t_argp_opt *option);
void argp_desc(t_argp *self, const char *desc, const char *epilog);
int argp_parse(t_argp *self, int argc, const char **argv);
void argp_usage(t_argp *self);