#include <unistd.h>

char	*ft_strchrr(char *str, int size, char c)
{
	if (size < 0)
		return (0);
	while (*str && size--)
	{
		if (*str == c)
			break;
		str++;
	}
	if (*str == c)
		return (str);
	return (0);
}

char	*ft_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			break;
		str++;
	}
	if (*str == c)
		return (str);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int inter(char *s1, char *s2)
{
	int size;
	char buf[512];
	int count;
	int i;

	i = 0;
	count = 0;
	size = 0;
	while (*s2)
	{
		if (ft_strchr(s1, *s2) && !ft_strchrr(buf, count, *s2))
		{
			buf[size] = *s2;
			size++;
		}
		s2++;
	}
	count = -1;
	while (size > 0 && s1[i])
	{
		if (!ft_strchrr(s1, count, s1[i]))
		{
			ft_putchar(s1[i]);
			size--;
		}
		count++;
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	char *str = "nothing";
	char *str1 = "This sentence hides nothing";
	inter(str, str1);
	write(1, "\n", 1);
	return (0);
}
