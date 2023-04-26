#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

#define BUFFER_SIZE 1024

/*in _printf.c*/
int _printf(const char *format, ...);
int _putchar(char c);
/*in handle_conversion.c*/
int handle_conversion(const char *format, int *i, va_list inputs);
int handle_conversion2(const char *format, int *i, va_list inputs);
int handle_conversion3(const char *format, int *i, va_list inputs);
/*in handle_task0.c*/
int _print_str(va_list inputs);
/*in handle_task1.c*/
int _print_int(int nr);
/*int _print_int_width(int nr, int width, char char_pad);*/
/*in handle_task2.c*/
int _print_bin(va_list inputs);
/*in handle_task3.c*/
int _print_hex(va_list inputs);
int _print_hex_small(va_list inputs);
int _print_oct(va_list inputs);
int _print_ud(va_list inputs);
/*in handle_task7.c */
int _print_plus(const char *format, int *i, va_list inputs);
int _print_space(const char *format, int *i, va_list inputs);
int _print_zeros(const char *format, int *i, va_list inputs);
/*in handle_task13.c*/
int _print_str_rev(va_list inputs);
/*in handle_task14.c*/
int _print_rot13(va_list inputs);
/*in handle_task5.c*/
int _print_npc(va_list inputs);
/*in handle_task6.c*/
int _print_ptr(va_list inputs);
/*in handle_task8.c*/
int _print_long(va_list inputs);
int _print_short(va_list inputs);
int handle_conversion_l_h(const char *format, int *i, va_list inputs);
/*in handle_task9.c*/
int _print_int_width(int nr, int width);
/*in handle_task11.c*/
int print_00(const char *str, int width);
int print_0(const char *str, int width);
/*int _check_next_flag(const char *format, int *i, va_list inputs);*/
/*int _print_int_with_flags(va_list inputs, int has_plus, int has_space,*/
/*int has_hash, int has_minus, int has_zero, int length);*/

#endif
