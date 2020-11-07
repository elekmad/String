#include <String.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define CHAR_STRING_TEST "foobar"

int main(int argc, char **argv)
{
    int ret = 0;
    String s;
    String_init(&s);
    String_append_char_string(&s, CHAR_STRING_TEST);
    if(String_get_length(&s) != strlen(CHAR_STRING_TEST))
    {
        ret = -1;
        fprintf(stderr, "Lengths does not match : %zu <> %zu\n", String_get_length(&s), strlen(CHAR_STRING_TEST));
    }
    else if(String_get_data(&s) == NULL)
    {
        ret = -1;
        fprintf(stderr, "data is null\n");
    }
    else if(strcmp(String_get_char_string(&s), CHAR_STRING_TEST) != 0)
    {
        ret = -1;
        fprintf(stderr, "char string does not match : '%s' <> '%s'\n", String_get_char_string(&s), CHAR_STRING_TEST);
    }
    String_finalize(&s);
    if(ret == 0)
        exit(EXIT_SUCCESS);
    else
        exit(EXIT_FAILURE);

}
