#include "ealloc.h"

#include <err.h>
#include <stdlib.h>

#include "error.h"

void* emalloc(size_t size)
{
    void* p = malloc(size);
    if (p == NULL)
        err(MEMORY_ERROR, "Cannot allocate memory");
    return p;
}

void* ecalloc(size_t nmemb, size_t size)
{
    void* p = calloc(nmemb, size);
    if (p == NULL)
        err(MEMORY_ERROR, "Cannot allocate memory");
    return p;
}

void* erealloc(void* ptr, size_t size)
{
    void* p = realloc(ptr, size);
    if (p == NULL)
        err(MEMORY_ERROR, "Cannot allocate memory");
    return p;
}
