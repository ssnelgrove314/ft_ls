#include "ft_file_and_dir.h"

t_dir *ft_create_dir(const char *name, t_opts *opts)
{
	t_dir *new_dir;
	DIR *tmp_dir;
	dirent tmp_dirent;
	t_file tmp_file;
	stat tmp_stat;

	tmp_dir = opendir(name);	
	new_dir->dir_name = ft_strdup(name);
	new_dir->content_size = -1;
	while ((tmp_dirent = readdir(dir)) != NULL)
	{
		if (tmp_dirent.d_name[0] == '.' && tmp_dirent.d_name[1] == '\0')
			ft_memcpy()
		ft_memcpy(new_dir->contents[++new_dir->content_size]->fdirent, tmp, sizeof(dirent));
		tmp_stat = lstat(new_dir->contents[new_dir->content_size - 1]->fdirent.d_name);
		ft_memcpy(new_dir->contents[new_dir->content_size - 1]->fstat, tmp, sizeof(stat));
	}
	ls->num_entry = i;
	return (0);
}