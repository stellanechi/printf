#include "main.h"

/**
 * str_rev - prints a string in reversal, followed by a new line,
 * @str: pointer to the string to print
 * Return: void
*/

char *str_rev(char *str)
{
	int i;
	int len = 0;
	char c;
	
	if (!str)
		return (NULL);

	while (str[len] != '\0')
	{
		len++;
	}
	for (i = 0; i < (len / 2); i++)
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
	}
	return str;
}

/**
 * _itoa - Convert a string to integer.
 * @i: integer value 
 * @strout: char array string
 * @base: base value
 * Return: first integer found in string
 */

char *_itoa(int i, char *strout, int base)
{
	char *str = strout;
	int digit, sign = 0;
	if (i < 0)
	{
		sign = 1;
		i *= -1;
	}
	while (i)
	{
		digit = i % base;
		*str = (digit > 9) ? ('A' + digit - 10) : '0' + digit;
		i = i / base;
		str++;
	}
	if (sign)
	{
		*str++ = '-';
	}
	*str = '\0';
	str_rev(strout);
	return strout;
}

/**
 * _printf - mimic printf from stdio
 * Description: produces output according to a format
 * write output to stdout, the standard output stream
 * @format: character string composed of zero or more directives
 *
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 * return -1 for incomplete identifier error
 */

int _printf(const char *format, ...)
{
	va_list vl;
	int i = 0, j = 0;
	char buff[100] = {0}, tmp[20];
	char *str_arg;

	va_start(vl, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				/* Convert char */
				case 'c':
					buff[j] = (char)va_arg(vl, int);
					j++;
					break;

					/* Convert decimal */
				case 'd':
					_itoa(va_arg(vl, int), tmp, 10);
					strcpy(&buff[j], tmp);
					j += strlen(tmp);
					break;
					/* Convert hex */
				case 'x':
					_itoa(va_arg(vl, int), tmp, 16);
					strcpy(&buff[j], tmp);
					j += strlen(tmp);
					break;
					/* Convert octal */
				case 'o':
					_itoa(va_arg(vl, int), tmp, 8);
					strcpy(&buff[j], tmp);
					j += strlen(tmp);
					break;
					/* copy string */
				case 's':
					str_arg = va_arg(vl, char *);
					strcpy(&buff[j], str_arg);
					j += strlen(str_arg);
					break;
			}
		}
		else
		{
			buff[j] = format[i];
			j++;
		}
		i++;
	}
	fwrite(buff, j, 1, stdout);
	va_end(vl);
	return j;
}
