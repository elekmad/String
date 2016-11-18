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
}

char * const String_get_data(const String *self)
{
    return self->data;
}

size_t String_get_length(const String *self)
{
    return self->length;
}

void String_append_data(String *self, size_t length, const void *data)
{
    if(self->size < self->length + length)
        String_resize(self, self->length + length);
    memcpy(self->data + self->length, data, length);
    self->length += length;
}

void String_append_string(String *self, const char *data)
{
    String_append_data(self, strlen(data), data);
}

void String_append_char(String *self, char c)
{
    String_append_data(self, 1, &c);
}

void String_append_String(String *self, const String *other)
{
    String_append_data(self, String_get_length(other), String_get_data(other));
}

void String_compute_string(String *self, char **ret)
{
    *ret = malloc(sizeof(char) * (String_get_length(self) + 1));
    memcpy(*ret, String_get_data(self), String_get_length(self));
    (*ret)[String_get_length(self)] = '\0';
}
