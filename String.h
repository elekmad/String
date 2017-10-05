#ifndef __STRING_H__
#define __STRING_H__

#include <sys/types.h>

struct String ///Structure for easily build reallocatable char strings.
{
    size_t length; ///<Length of the char string contained into data.
    size_t size; ///<Size of data allocated memory.
    char *data; ///<Data allocated memory where char string is contained. At beginning, when length = 0, data = NULL.
};

typedef struct String String;

String *String_new(void);
void String_init(String *self);
void String_finalize(String *self);
void String_free(String *self);
const char * String_get_data(const String *self);
const char * String_get_char_string(const String *self);
size_t String_get_length(const String *self);
void String_empty(String *self);
char String_get_char_at(const String *self, size_t at);
void String_append_data(String *self, size_t length, const void *data);
void String_append_char_string(String *self, const char *data);
void String_set_char_string(String *self, const char *data);
void String_append_char(String *self, char c);
void String_append_String(String *self, const String *other);
void String_append_printf(String *self, const char *fmt, ...);
void String_compute_char_string(const String *self, char **ret);
int String_compare_with_other(const String *self, const String *other);
int String_compare_with_char_string(const String *self, const char *other);
int String_do_end_with_other(const String *self, const String *other);

#endif//__STRING_H__
