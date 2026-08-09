#ifndef __STRING_H__
#define __STRING_H__

#include <sys/types.h>

struct String ///Structure for easily build reallocatable char strings.
{
    size_t length; ///<Length of the char string contained into data.
    size_t size; ///<Size of data allocated memory.
    char *data; ///<Data allocated memory where char string is contained. At beginning, when length = 0, data = NULL.
};

typedef struct String String;

#include <String.proto.h>


#endif//__STRING_H__
