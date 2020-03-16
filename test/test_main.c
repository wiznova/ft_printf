#include "ft_printf.h"
#include "gnl/get_next_line.h"

#include <fcntl.h>
#include <unistd.h>

#define STOPPER_INT 151500
#define CASES {0, 5, -7, 13, 1560133635, -2035065302, STOPPER_INT}
// #define STOPPER_STR "STOP"

void	encaps(int *ret, int (*f)(const char *, ...), char *fmt, int arg)
{
	printf("    ");
	fflush(0);
	printf("|");
	fflush(0);
	*ret = f(fmt, arg, arg);
	printf("|\n");
}

int		test_int(char *fmt, int arg)
{
	int			lb;
	int			ft;
	static int	test_co;

	printf("test #%02d --> fmt{%s} arg{%d}\n", test_co, fmt, arg);

	encaps(&lb, &printf, fmt, arg);
	encaps(&ft, &ft_printf, fmt, arg);

	if (ft == lb)
		printf("\e[32m[OK]\e[0m ret_check success\n\n");
	else
	{
		printf("\e[91m[KO]\e[0m your return{%d} is not equal original{%d}\n", ft, lb);
		printf("debug --> ft_printf(\"%s\", %d);\n\n", fmt, arg);
	}
	test_co++;
	return (ft == lb ? 1 : 0);
}

void	ret_check(int ft, int lb, char *fmt, char arg)
{
	if (ft == lb)
		printf("\e[32m[OK]\e[0m ret_check success\n\n");
	else
	{
		printf("\e[91m[KO]\e[0m your return{%d} is not equal original{%d}\n", ft, lb);
		printf("debug --> ft_printf(\"%s\", '%c');\n\n", fmt, arg);
	}
}

int		test_c(char *fmt, char c)
{
	int		ft = 0;
	int		lb = 0;

		printf("line {%s}\n", fmt);
		printf("%-4s |", "my");
		fflush(0);
		ft = ft_printf(fmt, c);
		fflush(0);
		printf("|\n");
		printf("%-4s |", "libc");
		fflush(0);
		lb = printf(fmt, c);
		printf("|\n");
		ret_check(ft, lb, fmt, c);
		free(fmt);
	return (ft == lb ? 1 : 0);
}

int	main(void)
{
	int		fd = 0;
	int		ok = 0;
	int		total = 0;
	char	*line = NULL;

	fd = open("../test_cases/cases_cconv.txt", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		total++;
		ok += test_c(line, 'f');
	}
	printf("%d out of %d correct", ok, total);
	
	// int	ret = 0;
	// printf("|");
	// fflush(0);
	// ret = ft_printf("%013c", 'f');
	
	// printf("|\n");
	return (0);
}

/*
int main(void) //test_int_
{
	int		i = 0;
	int		total = 0;
	int		ok = 0;
	int		fd = 0;
	char 	*line = NULL;

	int		cases_int[] = CASES;
	fd = open("./test_cases.txt", O_RDONLY);

	while (get_next_line(fd, &line) == 1)
	{
		while (cases_int[i] != STOPPER_INT)
		{
			ok += test_int(line, cases_int[i]);
			i++;
		}
		total += i;
		i = 0;
	}

	printf("\e[93m%d/%d correct\e[0m, just %d to fix ;)\n", ok, total, total - ok);
	// ft_printf("%*d\n", 10, 1);
	// printf("%3d\n", 123456);
	// printf("%3s\n", "123456");
	free(line);
	close(fd);
	return (0);
} */

// int		main(void)
// {
// 	ft_printf("%-50.10d\n", 10, 1);
// 	// printf("|.5|\n", 3.142);
// 	return (0);
// }

// %[flags][width].[precision][conversion]

// 123456 3
	// char	*formats[] = {
	// 					"%-2d_%-2d",
	// 					"%0d",
	// 					"%0.0d",
	// 					"%d",
	// 					"Hello%d",
	// 					STOPPER_STR};

	// while (strcmp(formats[j], STOPPER_STR) != 0)
	// {
	// 	while (cases_int[i] != STOPPER_INT)
	// 	{
	// 		if (test_int(formats[j], cases_int[i]) == 1)
	// 			ok++;
	// 		i++;
	// 	}
	// 	total += i;
	// 	i = 0;
	// 	j++;
	// }