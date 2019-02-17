#ifndef FT_GETOPT_LONG_H
# define FT_GETOPT_LONG_H


typedef enum 
{
	NO_ARGUMENT,
	REQUIRED_ARGUMENT,
	OPTIONAL_ARGUMENT,
}		e_getopt_afterflag;

typedef struct s_getopt_option
{
	const char *name;
	int has_arg;
	int *flag;
	int val;
}				t_getopt_option; 

typedef struct		s_avac
{
	int argc;
	char **argv;
}					t_acav;

int ft_getopt(const t_acav *argvargc, const char *optstring);
int ft_getopt_long(t_acav *argvargc, const char *options, t_getopt_option *long_options, int *index);

#endif