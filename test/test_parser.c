
#define STOPPER_INT 151500
#define CASES {0, 5, -7, 13, 1560133635, -2035065302, STOPPER_INT}
#include "gnl/get_next_line.h"

#include <fcntl.h>
#include <unistd.h>
#include "ft_printf.h"

void		test_parser(char *line, t_format_specs *sp)
{
	format_spec_parser(sp);
	printf("\n%-8s{%s}\n", "fmt", line);
	printf("%-8s%d\n", "just" ,sp->just);
	printf("%-8s%d\n", "is_pad", sp->is_pad);
	printf("%-8s%d\n", "pad", sp->pad);
	printf("%-8s|%c|\n", "pad_ch", sp->pad_ch);
	printf("%-8s%d\n", "is_prec", sp->is_prec);
	printf("%-8s%d\n", "prec", sp->prec);
	printf("%-8s%c\n", "conv", sp->conv);
	printf("========\n\n");
}

void		test_parser_call(char *spec)
{
    char			line[50];
	void			*args = NULL;
	t_format_specs	sp;

	initialize_sp(&sp, (va_list *)&args, (char *)line);

	ft_strlcpy(line, spec, 50);
	sp.fmt = line;
	test_parser(line, &sp);
}

int			main(void)
{
	test_parser_call("%-.1982999999999s");
	return (0);
}