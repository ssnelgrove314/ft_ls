#include <sys/stat.h>
#include <stdbool.h>
#include <stdio.h>

enum class { CLASS_OWNER, CLASS_GROUP, CLASS_OTHER };
enum permission { PERMISSION_READ, PERMISSION_WRITE, PERMISSION_EXECUTE };
const mode_t EMPTY_MODE = 0;
mode_t perm(enum class c, enum permission p) { return 1 << ((3-p) + (2-c)*3); }
bool mode_contains(mode_t mode, enum class c, enum permission p) { return mode & perm(c, p); }
mode_t mode_add(mode_t mode, enum class c, enum permission p) { return mode | perm(c, p); }
mode_t mode_rm(mode_t mode, enum class c, enum permission p) { return mode & ~perm(c, p); }

// buf must have at least 10 bytes
void strmode(mode_t mode, char * buf) {
  const char chars[] = "rwxrwxrwx";
  for (size_t i = 0; i < 9; i++) {
    buf[i] = (mode & (1 << (8-i))) ? chars[i] : '-';
  }
  buf[9] = '\0';
}

int main(void) {
  char buf[10];
  mode_t examples[] = { 0755, 0666, 0777, 0700, 0100, 01, 02, 03, 04, 05, 06, 07 };
  size_t num_examples = sizeof(examples) / sizeof(examples[0]);
  for (size_t i = 0; i < num_examples; i++) {
    strmode(examples[i], buf);
    printf("%04o is %s\n", examples[i], buf);
  }
  return 0;
}
// #include "ft_ls.h"
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <time.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/sysmacros.h>



// int	main(int argc, char *argv[])
// {
// 	struct stat sb;

// 	if (argc != 2) {
// 		fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
// 		exit(EXIT_FAILURE);
// 	}

// 	if (lstat(argv[1], &sb) == -1) {
// 		perror("lstat");
// 		exit(EXIT_FAILURE);
// 	}

// 	printf("ID of containing device:  [%lx,%lx]\n",
// 		(long) major(sb.st_dev), (long) minor(sb.st_dev));

// 	printf("File type:                ");

// 	switch (sb.st_mode & S_IFMT) {
// 	case S_IFBLK:  printf("block device\n");            break;
// 	case S_IFCHR:  printf("character device\n");        break;
// 	case S_IFDIR:  printf("directory\n");               break;
// 	case S_IFIFO:  printf("FIFO/pipe\n");               break;
// 	case S_IFLNK:  printf("symlink\n");                 break;
// 	case S_IFREG:  printf("regular file\n");            break;
// 	case S_IFSOCK: printf("socket\n");                  break;
// 	default:       printf("unknown?\n");                break;
// 	}

// 	printf("%o\n", (sb.st_mode));
// 	switch (sb.st_mode & S_IRWXU) {
// 		case S_IRUSR: printf("user read perms\n");
// 		case S_IWUSR: printf("user write perms\n");
// 		case S_IXUSR: printf("user execute perms\n");
// 	}

// 	printf("I-node number:            %ld\n", (long) sb.st_ino);

// 	printf("Mode:                     %lo (octal)\n",
// 			(unsigned long) sb.st_mode);

// 	printf("Link count:               %ld\n", (long) sb.st_nlink);
// 	printf("Ownership:                UID=%ld   GID=%ld\n",
// 			(long) sb.st_uid, (long) sb.st_gid);

// 	printf("Preferred I/O block size: %ld bytes\n",
// 			(long) sb.st_blksize);
// 	printf("File size:                %lld bytes\n",
// 			(long long) sb.st_size);
// 	printf("Blocks allocated:         %lld\n",
// 			(long long) sb.st_blocks);

// 	printf("Last status change:       %s", ctime(&sb.st_ctime));
// 	printf("Last file access:         %s", ctime(&sb.st_atime));
// 	printf("Last file modification:   %s", ctime(&sb.st_mtime));

// 	exit(EXIT_SUCCESS);
// }