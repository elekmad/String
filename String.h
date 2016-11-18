#ifndef __STRING_H__
#define __STRING_H__

#include <sys/types.h>

struct String
{
    size_t length;
    size_t size;
    char *data;
};

typedef struct String String;

String *String_new(void);
void String_init(String *self);
void String_finalize(String *self);
void String_free(String *self);
char *const String_get_data(const String *self);
size_t String_get_length(const String *self);
void String_empty(String *self);
char String_get_char_at(const String *self, size_t at);
void String_append_data(String *self, size_t length, const void *data);
void String_append_char_string(String *self, const char *data);
void String_append_char(String *self, char c);
void String_append_String(String *self, const String *other);
void String_compute_char_string(String *self, char **ret);

#endif//__STRING_H__
