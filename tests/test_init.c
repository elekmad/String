#include <String.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int ret = 0;
    String s;
    String_init(&s);
    if(String_get_length(&s) != 0)
    {
        ret = -1;
        fprintf(stderr, "Lengths is not 0 : %zu\n", String_get_length(&s));
    }
    else if(String_get_data(&s) != NULL)
    {
        ret = -1;
        fprintf(stderr, "data is not null\n");
    }
    else if(strcmp(String_get_char_string(&s), "") != 0)
    {
        ret = -1;
        fprintf(stderr, "char string should be empty : '%s'\n", String_get_char_string(&s));
    }
    String_finalize(&s);
    if(ret == 0)
        exit(EXIT_SUCCESS);
    else
        exit(EXIT_FAILURE);

}
