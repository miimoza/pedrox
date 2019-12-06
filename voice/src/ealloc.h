#ifndef EALLOC_H
#define EALLOC_H

#include <stddef.h>

void* emalloc(size_t size);
void* ecalloc(size_t nmemb, size_t size);
void* erealloc(void* ptr, size_t size);

#endif /* EALLOC_H */
