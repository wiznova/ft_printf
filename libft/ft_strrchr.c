/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 18:29:31 by skhalil        #+#    #+#                */
/*   Updated: 2019/11/10 18:41:08 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*ret;
	char	letter;
	int		co;

	letter = (char)c;
	i = 0;
	co = 0;
	while (str[i] != '\0')
	{
		if (str[i] == letter)
			co = i;
		i++;
	}
	if (letter == '\0')
		return ((char *)&str[i]);
	if (co == 0 && str[co] != letter)
		return (0);
	ret = (char *)&str[co];
	return (ret);
}
