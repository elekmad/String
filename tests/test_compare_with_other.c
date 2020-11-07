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
    String s,o;
    String_init(&s);
    String_init(&o);
    String_append_char_string(&s, CHAR_STRING_TEST);
    String_append_char_string(&o, CHAR_STRING_OTHER_OK);
    if(String_compare_with_other(&s, &o) != 0)
    {
        ret = -1;
        fprintf(stderr, "char string does not match : '%s' <> '%s'\n", String_get_char_string(&s), String_get_char_string(&o));
    }
    else
    {
        String_set_char_string(&o, CHAR_STRING_OTHER_BAD);
        if(String_compare_with_other(&s, &o) == 0)
        {
            ret = -1;
            fprintf(stderr, "char string does match : '%s' <> '%s'\n", String_get_char_string(&s), String_get_char_string(&o));
        }
    }
    String_finalize(&o);
    String_finalize(&s);
    if(ret == 0)
        exit(EXIT_SUCCESS);
    else
        exit(EXIT_FAILURE);

}
