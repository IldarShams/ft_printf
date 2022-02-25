#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	n;

	n = 0;
	while (*str != '\0' && *str >= 48 && *str < 58)
	{
		n *= 10;
		n += *str - 48;
		str++;
	}
	return (n);
}

int	is_flag(char c)
{
	if (c == '-' ||
	c == '+' ||
	c == ' ' ||
	c == '#' ||
	c == '0')
		return (1);
	return (0);
}

int	get_width(char *str)
{
	str++;
	while (is_flag(*str))
		str++;
	return (ft_atoi(str));
}

int is_specifier(char c)
{
    if (c == 'd' || c == 'i' || c == 's' || c == 'p' 
        || c == 'u' || c == 'x' || c == 'X' || c == '%')
        return (1);
    return (0);
}



int spec_proc(char *s)
{

}

int put_str(char *str)
{
    int n;

    n = 0;
    while (*str)
    {
        n += write(1, str, 1);
        str++;
    }
    return (n);
}

int put_nbr(int i)
{
    int n;
    char c;

    n = 0;
	if (i < 0)
	{
		write(1, "-", 1);
		i = -i;
	}
    if (i / 10 > 0)
    {
        n += put_nbr(i / 10);
    }
    c = i % 10 + 48;
    n += write(1, &c, 1);
    return (n);
}

int put_nbr_base16(int i, int base, char *str)
{
    int n;
    char c;

    n = 0;
    if (i / base > 0)
    {
        n += put_nbr_base16(i / base, base, str);
    }
    c = str[i % base];
    n += write(1, &c, 1);
    return (n);
}

int put_ptr(unsigned long i, int base, char *str)
{
    int n;
    char c;

    n = 0;
    if (i / base > 0)
    {
        n += put_ptr(i / base, base, str);
    }
    else
        write(1, "0x", 2);
    c = str[i % base];
    n += write(1, &c, 1);
    return (n);
}

int ft_printf(const char *str, ...)
{
    int n;
    int i;
    va_list vl;

    va_start(vl, str);
    i = 0;
    n = 0;
    while (str[i] != '\0')
    {
        while (str[i] != '\0' && str[i] != '%')
            n += write(1, &str[i], 1);
        
    }

    va_end(vl);
    return (n);
}

int main()
{
    char *s;

    s = malloc(1);
	printf("%d\n", get_width("%+-10.3d"));
    printf("\n|%+-10.3d|\n", '1');
	put_nbr(-10);
    free(s);
}

//%c: 
//      %10c    width
//      %-10c    minus
// 
//%d
//      %10d    width
//      %-10d   minus
//      %+10d   plus
//      %010d   nil
//      %10.2d  precision
//      
//