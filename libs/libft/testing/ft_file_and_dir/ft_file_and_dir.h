#ifndef FT_FILE_AND_DIR_H
# define FT_FILE_AND_DIR_H

# include <dirent.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include "libft.h"
# include <sys/types.h>
# include "stack.h"

#define FT_IS_DIR(tfile)(S_ISDIR(tfile->fstat->st_mode) ? 1 : 0)
#define FT_IS_REG(tfile)(S_ISREG (tfile->fstat->st_mode) ? 1 : 0)
#define FT_IS_CHR(tfile)(S_ISCHR(tfile->fstat->st_mode) ? 1 : 0)
#define FT_IS_BLK(tfile)(S_ISBLK(tfile->fstat->st_mode) ? 1 : 0)
#define FT_IS_FIFO(tfile)(S_ISFIFO(tfile->fstat->st_mode) ? 1 : 0)
#define FT_IS_LNK(tfile)(S_ISLNK(tfile->fstat->st_mode) ? 1 : 0)
#define FT_IS_SOCK(tfile)(S_ISSOCK(tfile->fstat->st_mode) ? 1 : 0)

typedef struct s_opts
{
	u_int16_t	recursive_flag : 1;
	u_int16_t	reverse_flag : 1;
	u_int16_t	modification_date_sort_flag : 1;
	u_int16_t	long_list_flag : 1;
	u_int16_t	all_flag : 1;
}				t_opts;

typedef struct	s_file
{
	char *filename;
	struct dirent fdirent;
	struct group fgroup;
	struct stat fstat;
	struct passwd fpasswd;
}				t_file;

typedef struct s_dir
{
	char *dir_name;
	t_dir parent;
	t_file thisdir; //optional
	t_file **contents;
	size_t cont_size;
	t_dir **subdirs;
} t_dir;

t_dir *ft_create_dir(const char *name, t_opts *opts);
int dive_dirs(t_dir *dir, t_opts opts, void (*fnc)(t_dir *));

void fill_files_info(t_dir *dir);
void ft_sort_dir(t_dir *dir, int (*cmp)(const void *, const void *));

void print_dir_contents(t_dir *dir);
void print_dir_contents_long(t_dir *dir);
void print_file_digest(t_file *files);


#endif