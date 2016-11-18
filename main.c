#include <String.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    String test;
    String_init(&test);
    String_append_string(&test, "foobar");
    char *ret;
    String_compute_string(&test, &ret);
    printf("%.*s %s\n", (int)String_get_length(&test), String_get_data(&test), ret);
    free(ret);
    exit(0);
}