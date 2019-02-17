#ifndef FT_ARGP_H
# define FT_ARGP_H

#include "libft.h"

typedef int argp_callback(t_argp);

enum e_argp_opt_type {
	ARGP_OPT_END,
	ARGP_OPT_GROUP,
	ARGP_OPT_BOOL,
	ARGP_OPT_BIT,
	ARGP_OPT_INT,
	ARGP_OPT_FLOAT,
	ARGP_OPT_STR,
};

enum e_argp_opt_flag {
	OPT_NONEG = 1,
};

typedef struct s_argp_opt {
	enum e_argp_opt_type	type;
	const char short_name;
	const char *long_name;
	void *value;
	const char *help;
	argp_callback *callback;
	intptr_t data;
	int flags;
} t_argp_opt;

typedef struct s_argp {
	t_argp_opt *options;
	const char *const *usages;
	int flags;
	const char *desc;
	const char *epilog;
	
	int argc;
	const char **argv;
	const char **out;
	int cpidx;
	const char *optvalue;
} t_argp;

# define OPT_END() {ARGP_OPT_END, 0, NULL, NULL, 0, NULL, 0, 0}
# define OPT_BOOL(...) {ARGP_OPT_BOOL, __VA_ARGS__}
# define OPT_BIT(...) {ARGP_OPT_BIT, __VA_ARGS__}
# define OPT_INT(...) {ARGP_OPT_INT, __VA_ARGS__}
# define OPT_FLOAT(...) {ARGP_OPT_FLOAT, __VA_ARGS__}
# define OPT_STR(...) {ARGP_OPT_STR, __VA_ARGS__}
# define OPT_GROUP(h) {ARGP_OPT_GROUP, 0, NULL, NULL, h, NULL, 0, 0}
# define OPT_HELP() OPT_BOOL('h', "help", NULL, "show this help message and exit", argp_help_cb, 0, 0)

int argp_long_opt(t_argp *self, const t_argp_opt *options);
int argp_short_opt(t_argp *self, const t_argp_opt *options);
int argp_help_cb(t_argp *self, const t_argp_opt *option);
int argp_init(t_argp *self, t_argp_opt *options, const char *const *usages, int flags);
void argp_desc(t_argp *self, const char *desc, const char *epilog);
int argp_parse(t_argp *self, int argc, const char **argv);
void argp_usage(t_argp *self);
int argp_getvalue(t_argp *self, const t_argp_opt *opt, int flags);
void argp_error(t_argp *self, const t_argp_opt *opt, const char *reason, int flags);

#endif