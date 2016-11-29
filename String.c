#include <string.h>
#include <String.h>
#include <stdlib.h>

String *String_new(void)
{
    String *ret = calloc(sizeof(String), 1);
    return ret;
}

void String_init(String *self)
{
    memset(self, 0, sizeof(String));
}

void String_finalize(String *self)
{
    if(self->data != NULL)
        free(self->data);
}

void String_free(String *self)
{
    String_finalize(self);
    free(self);
}

static void String_resize(String *self, size_t newsize)
{
    if(self->size < newsize)
        self->data = realloc(self->data, newsize);
    self->size = newsize;
}

/*
 * @return This function return data directly, be careful, return NULL  when len = 0;
 */
char * const String_get_data(const String *self)
{
    return self->data;
}

/*
 * @return This function return "" when len = 0 for char_string compatibility.
 */
char * const String_get_char_string(const String *self)
{
    return self->length > 0 ? self->data : "";
}

size_t String_get_length(const String *self)
{
    return self->length;
}

static void String_set_length(String *self, size_t new_length)
{
    if(self->size <= new_length)
        return;
    self->length = new_length;
    self->data[self->length] = '\0';//For char_strings compatibility
}

void String_empty(String *self)
{
    String_set_length(self, 0);
}

char String_get_char_at(const String *self, size_t at)
{
    if(String_get_length(self) < at)
        return '\0';
    return String_get_data(self)[at];
}

void String_append_data(String *self, size_t length, const void *data)
{
    size_t new_length = self->length + length + 1;//+1 for '\0' for char_strings
    if(self->size < new_length)
        String_resize(self, new_length);
    memcpy(self->data + self->length, data, length);
    String_set_length(self, new_length - 1);
}

void String_append_char_string(String *self, const char *data)
{
    String_append_data(self, strlen(data), data);
}

void String_set_char_string(String *self, const char *data)
{
    String_empty(self);
    String_append_char_string(self, data);
}

void String_append_char(String *self, char c)
{
    String_append_data(self, 1, &c);
}

void String_append_String(String *self, const String *other)
{
    String_append_data(self, String_get_length(other), String_get_data(other));
}

void String_compute_char_string(String *self, char **ret)
{
    *ret = malloc(sizeof(char) * (String_get_length(self) + 1));
    memcpy(*ret, String_get_data(self), String_get_length(self));
    (*ret)[String_get_length(self)] = '\0';
}
