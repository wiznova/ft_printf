#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

#define ST "STOP"
#define RW 50
#define IS_PREC {"", ".", ST}
#define PREC WIDTHS
#define NUM 1215

#ifndef FLAGS
# define FLAGS {"", "-", "0", ST}
#endif

#ifndef WIDTHS
# define WIDTHS {"", "-17", "-5", "-1", "0", "1", "5", "17", ST}
#endif

typedef struct	sco_set{
	int	fa_co;
	int	wa_co;
	int	p_bool_co; 
	int	pa_co;
}				tco_set;

int		nu_opts_str(char **list, int	start_co)
{
	while (strcmp(list[start_co], ST))
		start_co++;
	return (start_co - 1);
}

void	set_conv(tco_set *set)
{
	char	*fa[] = FLAGS;
	char	*wa[] = WIDTHS;
	char	*p_bool[] = IS_PREC;
	char	*pa[] = PREC;
	char	*s1;
	char	*s2;
	char	*s3;
	char	*s4;
	char	*s5;
	int		fd = 0;

	s1 = ft_strjoin(fa[set->fa_co], wa[set->wa_co]);
	s2 = ft_strjoin(p_bool[set->p_bool_co], pa[set->pa_co]);
	// if (set->p_bool_co == 1)
	s3 = ft_strjoin(s1, s2);
	s4 = ft_strjoin("%", s3);

	printf("-> %sd| [%d]\n", s4, NUM);
	s5 = ft_strjoin(s4, "d\n");

	fd = open("./test_cases.txt", O_RDWR | O_APPEND | O_CREAT);
	if (fd == -1)
		printf("\e[91merror\e[0m\n");
	ft_putstr_fd(s5, fd);
	close(fd);
	
	//printf(s5, NUM);
	//printf("========\n\n");
	
	free(s1);
	free(s2);
	free(s3);
	free(s4);
	free(s5);
}

void	set_prec(tco_set *set)
{
	int temp;

	temp = set->pa_co;
	while (set->pa_co != -1)
	{
		set_conv(set);
		(set->pa_co)--;
	}
	set->pa_co = temp;
}

void	set_prec_b(tco_set *set)
{
	int temp;

	temp = set->p_bool_co;
	while (set->p_bool_co != -1)
	{
		if (set->p_bool_co == 1)
			set_prec(set);
		else
			set_conv(set);
		(set->p_bool_co)--;
	}
	set->p_bool_co = temp;
}

void	set_width(tco_set *set)
{
	int temp;

	temp = set->wa_co;
	while (set->wa_co != -1)
	{
		set_prec_b(set);
		(set->wa_co)--;
	}
	set->wa_co = temp;
}

void	set_fmt(tco_set *set)
{
	while (set->fa_co != -1)
	{
		set_width(set);
		(set->fa_co)--;
	}
}

int 	main(void)
{
	char	*wa[] = WIDTHS;
	char	*pa[] = PREC;
	char	*p_bool[] = IS_PREC;
	char	*fa[] = FLAGS;
	tco_set	set;

	set.fa_co = nu_opts_str(fa, 0);
	set.wa_co = nu_opts_str(wa, 0);
	set.p_bool_co = nu_opts_str(p_bool, 0);
	set.pa_co = nu_opts_str(pa, 0);

	set_fmt(&set);
	return (0);
}