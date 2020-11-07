#include <String.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define CHAR_STRING_TEST "foobar"
#define CHAR_STRING_OTHER_OK CHAR_STRING_TEST
#define CHAR_STRING_OTHER_OK2 "abc"CHAR_STRING_TEST
#define CHAR_STRING_OTHER_BAD "foo"
#define CHAR_STRING_OTHER_BAD2 CHAR_STRING_TEST"foo"

int main(int argc, char **argv)
{
    int ret = 0;
    String s1,s2;
    String_init(&s1);
    String_init(&s2);
    String_append_char_string(&s1, CHAR_STRING_TEST);
    String_append_char_string(&s2, CHAR_STRING_OTHER_OK);
    if(String_do_end_with_other(&s2, &s1) != 0)
    {
        ret = -1;
        fprintf(stderr, "char string does not finish with : '%s' <> '%s'\n", String_get_char_string(&s2), String_get_char_string(&s1));
    }
    else
    {
        String_set_char_string(&s2, CHAR_STRING_OTHER_OK2);
        if(String_do_end_with_other(&s2, &s1) != 0)
        {
            ret = -1;
            fprintf(stderr, "char string does not finish with : '%s' <> '%s'\n", String_get_char_string(&s2), String_get_char_string(&s1));
        }
        else
        {
            String_set_char_string(&s2, CHAR_STRING_OTHER_BAD);
            if(String_do_end_with_other(&s2, &s1) == 0)
            {
                ret = -1;
                fprintf(stderr, "char string does finish with : '%s' <> '%s'\n", String_get_char_string(&s2), String_get_char_string(&s1));
            }
            else
            {
                String_set_char_string(&s2, CHAR_STRING_OTHER_BAD2);
                if(String_do_end_with_other(&s2, &s1) == 0)
                {
                    ret = -1;
                    fprintf(stderr, "char string does finish with : '%s' <> '%s'\n", String_get_char_string(&s2), String_get_char_string(&s1));
                }
            }
        }
    }
    String_finalize(&s2);
    String_finalize(&s1);
    if(ret == 0)
        exit(EXIT_SUCCESS);
    else
        exit(EXIT_FAILURE);

}
