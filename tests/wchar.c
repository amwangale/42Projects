#include <unistd.h>
#include <stdio.h>
#include <wchar.h>

/*
void	ft_putwchar(wchar_t c);

void	ft_putwstr(wchar_t *str)
{
	while (*str)
	{
		ft_putwchar(*str);
		str++;
	}
}
*/


int		main(void)
{
	char un = 206;
	char deux = 177;
	write(1, &un, 1);
	write(1, &deux, 1);

	/*
	int	ret;

	wchar_t	a = L'é';
	wchar_t	b = L'א';
	wchar_t	c = L'您';
	wchar_t	d = L'好';
	wchar_t e = L'α';
//	wchar_t	e[] = L"двуй";

	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
	printf("%d\n", d);
	printf("%d\n", e);

	ret = printf("%S\n", L"Test");
	printf("%d", ret);
	*/
}
