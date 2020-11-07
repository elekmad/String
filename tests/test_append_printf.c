#include <String.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define xstr(s) str(s)
#define str(s) #s
#define CHAR_STRING_TEST "foobar"
#define NUMBER 42
#define EXPECTED_RESULT "coincoin="CHAR_STRING_TEST" * "xstr(NUMBER)

int main(int argc, char **argv)
{
    int ret = 0;
    String s;
    String_init(&s);
    String_append_printf(&s, "coincoin=%s * %d", CHAR_STRING_TEST, NUMBER);
    if(String_get_length(&s) != strlen(EXPECTED_RESULT))
    {
        ret = -1;
        fprintf(stderr, "Lengths does not match : %zu <> %zu\n", String_get_length(&s), strlen(EXPECTED_RESULT));
    }
    else if(String_get_data(&s) == NULL)
    {
        ret = -1;
        fprintf(stderr, "data is null\n");
    }
    else if(strcmp(String_get_char_string(&s), EXPECTED_RESULT) != 0)
    {
        ret = -1;
        fprintf(stderr, "char string does not match : '%s' <> '%s'\n", String_get_char_string(&s), EXPECTED_RESULT);
    }
    else
        fprintf(stderr, "%.*s\n", (int)String_get_length(&s), String_get_char_string(&s));
    String_finalize(&s);
    if(ret == 0)
        exit(EXIT_SUCCESS);
    else
        exit(EXIT_FAILURE);

}
