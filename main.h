#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
/**
*struct handle - struct to handle char
*@sp_f: handle some char
*@f: the function associated
*/
typedef struct handle
{
	char sp_f;
	int (*f)(va_list);
} handle_s_t;

int _printf(const char *format, ...);

/* Task 1: Conversion specifiers - %d, %i */
void print_integer(va_list args);

/* Task 2: Custom conversion specifier %b */
void print_binary(unsigned int n);

/* Task 3: Custom conversion specifier %b */
void print_binary(va_list args);

/* Task 4: Local buffer usage */
void print_with_buffer(const char *format, va_list args);

/* Task 5: Custom conversion specifier %S */
void print_non_printable_string(const char *str);

/* Task 6: Conversion specifier %p */
void print_address(const void *p);


/* Task 7: Handle flag characters: +, space, # */
void print_with_flags(va_list args);

/* Task 8: Handle length modifiers: l, h */
void print_with_length_modifiers(va_list args);

/* Task 9: Handle field width */
void print_with_field_width(va_list args);

/* Task 10: Handle precision */
void print_with_precision(va_list args);

/* Task 11: Handle the 0 flag character */
void print_with_zero_flag(va_list args);

/* Task 12: Handle the - flag character */
void print_with_minus_flag(va_list args);
/* Task 13: Custom conversion specifier %r */
void print_reversed_string(const char *str);

/* Task 14: Custom conversion specifier %R */
void print_rot13_string(const char *str);

#endif
