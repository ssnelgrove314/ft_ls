# include "ft_getopt_long.h"
# include "../../libft.h"

int opterr;
int optind;
int optopt;
char *optarg;
static char *optcursor = NULL;

//https://github.com/kimgr/getopt_port/blob/master/getopt.c
int no_more_optchars(void)
{
	optcursor = NULL;
	return (-1);
}

int ft_getopt(const t_acav *avc, const char *optstring)
{
	int optchar;
	const char *optdecl;

	optchar = -1;
	optdecl = NULL;
	optarg = NULL;
	opterr = 0;
	optopt = 0;
	if (optind >= avc->argc)
		return (no_more_optchars());
	if (avc->argv[optind] == NULL)
		return (no_more_optchars());
	if (*(avc->argv[optind]) != '-')
		return (no_more_optchars());
	if (ft_strcmp(avc->argv[optind], "-") == 0)
		return (no_more_optchars());
	if (ft_strcmp(avc->argv[optind], "--") == 0)
	{
		++optind;
		return (no_more_optchars());
	}	
	if (optcursor == NULL || *optcursor == '\0')
		optcursor = avc->argv[optind] + 1;
	optchar = *optcursor;
	optopt = optchar;
	optdecl = ft_strchr(optstring, optchar);
	if(optdecl)
	{
		if (optdecl[1] == ':')
		{
			optarg = ++optcursor;
			if (*optarg == '\0')
			{
				if (optdecl[2] != ':')
				{
					if (++optind < avc->argc)
						optarg = avc->argv[optind];
					else
					{
						optarg = NULL;
						optchar = (optstring[0] == ':') ? ':' : '?';
					}
				}
				else
					optarg = NULL;
			}
			optcursor = NULL;
		}
	}
	else
		optchar = '?';
	if (optcursor == NULL || *++optcursor == '\0')
		++optind;
	return optchar;
}

// int ft_getopt_long(t_acav *avc, const char *options, t_getopt_option *long_options, int *index)
// {
// 	return (0);
// }