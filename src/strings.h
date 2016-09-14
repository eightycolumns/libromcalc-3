#ifndef STRINGS_H
#define STRINGS_H

#include <stdbool.h>
#include <stddef.h>

bool is_empty_string(const char *string);
char *substring(char *dest, const char *src, size_t n);
char *to_uppercase(char *string);

#endif
