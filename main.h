#ifndef MAIN_H
#define MAIN_H
int _printf(const char *format, ...);
int format_c(char);
int format_s(char *);
int format_d(int);
int format_b(unsigned int);
int format_u(unsigned int n);
char *_buffer(char *);
void _reset_buffer(char *);
#endif
