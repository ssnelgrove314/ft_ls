#ifndef FT_LS_H
# define FT_LS_H

# include "../libs/libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <sys/types.h>

# define LS_SUCCESS 1
# define LS_ERROR 0
# define LS_STACK_SIZE 1024

typedef enum
{
	LS_RECURSE = 1 << 0,
	LS_REVERSE = 1 << 1,
	LS_MODIFICATION_DATE_SORT = 1 << 2,
	LS_LONG_LIST = 1 << 3,
	LS_ALL = 1 << 4,
	LS_MORE_THAN_ONE_ARG = 1 << 5
}e_ls_flags;

typedef struct s_file{
	char *name;
	DIR *dir;
	struct dirent *fdirent;
	struct group *fgroup;
	struct stat *fstat;
	struct passwd *fpasswd;
} t_file;

typedef struct s_ls_ctx
{
    int ls_flags;
    t_stack *args;
    int n;
	char print_dir_flag;
}               t_ls_ctx;

/*
** ls_opts_and_arg
*/
void ft_getopts_ls(t_ls_ctx *ctx, int argc, char **argv);
void ft_getargs_ls(t_ls_ctx *ctx, int argc, char ***argv);

/*
** ls_core
*/
int ft_ls(t_ls_ctx *ctx);
int ft_ls_once(t_ls_ctx *ctx, t_file *arg);
int ft_ls_recurse(t_ls_ctx *ctx, t_file *arg);
t_stack *ft_ls_open_dir(t_file *arg);

/*
** ls_sorting_fuctions
*/
void ft_ls_sort(t_ls_ctx *ctx, t_stack *content);

/*
** ls_printing
*/
int ft_ls_print(t_ls_ctx *ctx, t_stack *content);
void ft_error(char *error);
char *ft_strmode(mode_t mode);

#endif