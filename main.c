#include <String.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    String test;
    String_init(&test);
    String_append_char_string(&test, "foobar");
    char *ret;
    String_compute_char_string(&test, &ret);
    printf("'%.*s' '%s' '%s'\n", (int)String_get_length(&test), String_get_data(&test), ret, String_get_data(&test));
    free(ret);
    exit(0);
}
