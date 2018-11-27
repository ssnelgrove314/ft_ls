#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <sys/types.h>
# include "libft.h"
# include "stack.h"

typedef struct s_flags{
	u_int16_t	recursive_flag : 1;
	u_int16_t	reverse_flag : 1;
	u_int16_t	modification_date_sort_flag : 1;
	u_int16_t	long_list_flag : 1;
	u_int16_t	all_flag : 1;
} t_flags;

typedef struct s_file{
	struct dirent *fdirent;
	struct group *fgroup;
	struct stat *fstat;
	struct passwd *fpasswd;
} t_file;

typedef struct s_dir{
	char *dir_name;
	t_file *thisdir; //optional
	t_file **contents;
	size_t cont_size;
} t_dir;

typedef struct s_ls{
	t_stack *dirs;
	t_flags flags;
} t_ls;

void get_stack_from_args(int argc, char **argv, t_ls *ls);
void open_dir_lst(t_list **dir_list);
void open_and_read_dir(t_dir **dir);
void sort_dir(t_ls *ls, t_dir **dir);
void print_dir_contents(t_ls *ls, t_dir **dir);
void add_directories_to_list(t_list **head, t_dir **sorted_dir);

#endif