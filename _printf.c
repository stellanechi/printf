#include "main.h"

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
	int printed_chars;
	conver_t f_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent}
	};
	va_list list_arg;

	if (format == NULL)
		return (-1);

	va_start(list_arg, format);
	/*Calling parser function*/
	printed_chars = parser(format, f_list, list_arg);
	va_end(list_arg);
	return (printed_chars);
}
