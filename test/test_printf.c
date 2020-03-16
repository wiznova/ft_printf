#include <stdio.h>
#include <stdlib.h>

int		is_only_num(char *s)
{
	int		diff;

	diff = 0;
	while (*s)
	{
		diff = *s - '0';
		if (diff > 9 || diff < 0)
			return (0);
		s++;
	}
	return (1);
}

void	before(char *fmt, char *arg)
{
	printf("printf(\"%s\", %s)\nout -> |", fmt, arg);
	fflush(0);
}

void	after(int ret)
{
	printf("|\n{%d}\n", ret);
	fflush(0);
}

int		contains(char c, char *s)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		i = 1;
	int		ret = 0;

	if (argc < 3)
	{
		printf("Usage: ./printf <test_format_1>  |argument_1| ... <test_format_n> |argument_n|\n");
		return (1);
	}
	else
	{
		while (i < argc)
		{
			before(argv[i], argv[i+1]);
			if (is_only_num(argv[i+1]) == 0)
			{
				if (contains('c', argv[i]))
					ret = printf(argv[i], **(argv + i + 1));
				else
					ret = printf(argv[i], argv[i+1]);
			}
			else
				ret = printf(argv[i], atoi(argv[i+1]));
			after(ret);
			i += 2;
		}
	}
	return (0);
}