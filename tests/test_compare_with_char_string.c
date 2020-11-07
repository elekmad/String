#include <String.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define CHAR_STRING_TEST "foobar"
#define CHAR_STRING_OTHER_OK CHAR_STRING_TEST
#define CHAR_STRING_OTHER_BAD "abc"CHAR_STRING_TEST

int main(int argc, char **argv)
{
    int ret = 0;
    String s;
    String_init(&s);
    String_append_char_string(&s, CHAR_STRING_TEST);
    if(String_compare_with_char_string(&s, CHAR_STRING_OTHER_OK) != 0)
    {
        ret = -1;
        fprintf(stderr, "char string does not match : '%s' <> '%s'\n", String_get_char_string(&s), CHAR_STRING_OTHER_OK);
    }
    else
    {
        if(String_compare_with_char_string(&s, CHAR_STRING_OTHER_BAD) == 0)
        {
            ret = -1;
            fprintf(stderr, "char string does match : '%s' <> '%s'\n", String_get_char_string(&s), CHAR_STRING_OTHER_BAD);
        }
    }
    String_finalize(&s);
    if(ret == 0)
        exit(EXIT_SUCCESS);
    else
        exit(EXIT_FAILURE);

}
