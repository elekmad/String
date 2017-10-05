#include <String.h>
#include <string.h>
#include <stdio.h>

#define CHAR_STRING_OTHER "foobar"
#define CHAR_STRING_SELF_OK CHAR_STRING_OTHER
#define CHAR_STRING_SELF_OK2 "abc"CHAR_STRING_OTHER
#define CHAR_STRING_SELF_BAD "foo"
#define CHAR_STRING_SELF_BAD2 CHAR_STRING_OTHER"foo"

int main(int argc, char **argv)
{
    int ret = 0;
    String s1;
    String_init(&s1);
    String_append_char_string(&s1, CHAR_STRING_SELF_OK);
    if(String_do_end_with_char_string(&s1, CHAR_STRING_OTHER) != 0)
    {
        ret = -1;
        fprintf(stderr, "char string does not finish with : '%s' <> '%s'\n", String_get_char_string(&s1), CHAR_STRING_OTHER);
    }
    else
    {
        String_set_char_string(&s1, CHAR_STRING_SELF_OK2);
        if(String_do_end_with_char_string(&s1, CHAR_STRING_OTHER) != 0)
        {
            ret = -1;
            fprintf(stderr, "char string does not finish with : '%s' <> '%s'\n", String_get_char_string(&s1), CHAR_STRING_OTHER);
        }
        else
        {
            String_set_char_string(&s1, CHAR_STRING_SELF_BAD);
            if(String_do_end_with_char_string(&s1, CHAR_STRING_OTHER) == 0)
            {
                ret = -1;
                fprintf(stderr, "char string does finish with : '%s' <> '%s'\n", String_get_char_string(&s1), CHAR_STRING_OTHER);
            }
            else
            {
                String_set_char_string(&s1, CHAR_STRING_SELF_BAD2);
                if(String_do_end_with_char_string(&s1, CHAR_STRING_OTHER) == 0)
                {
                    ret = -1;
                    fprintf(stderr, "char string does finish with : '%s' <> '%s'\n", String_get_char_string(&s1), CHAR_STRING_OTHER);
                }
            }
        }
    }
    String_finalize(&s1);
    return ret;
}
