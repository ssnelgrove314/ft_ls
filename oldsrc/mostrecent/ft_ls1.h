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
}e_ls_flags;

typedef struct s_ls_opts{
	u_int16_t	recursive_flag : 1;
	u_int16_t	reverse_flag : 1;
	u_int16_t	modification_date_sort_flag : 1;
	u_int16_t	long_list_flag : 1;
	u_int16_t	all_flag : 1;
} t_ls_opts;

typedef struct s_file{
	char *name;
	DIR *dir;
	struct dirent *fdirent;
	struct group *fgroup;
	struct stat *fstat;
	struct passwd *fpasswd;
} t_file;

int ft_getopts_ls(t_ls_opts *opts, int *argc, char **argv);
int ft_getargs_ls(t_stack *args, int *argc, char **argv);
int ft_ls(t_ls_opts *opts, t_stack *args);
int ft_ls_once(t_ls_opts *opts, t_file *arg);
int ft_ls_recurse(t_ls_opts *opts, t_file *arg);
t_stack *ft_ls_open_dir(t_ls_opts *opts, t_file *arg);
void ft_ls_sort(t_ls_opts *opts, t_stack *content);
int ft_ls_print(t_ls_opts *opts, t_stack *content);
void ft_error(char *error);
char *ft_strmode(mode_t mode);

#endif