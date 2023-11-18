#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdalign.h>
alignas(8) uint8_t buffer[BUFFER_SIZE];

void *mymalloc(size_t size){

    size_t newSize = size + size%8;
    long p = sbrk(0);
    long *request = sbrk(newSize);

    return p;
}

void *mycalloc(size_t nmemb, size_t size)
{
    return NULL;
}

void myfree(void *ptr)
{
}

void *myrealloc(void *ptr, size_t size)
{
    return NULL;
}


/*
 * Enable the code below to enable system allocator support for your allocator.
 * Doing so will make debugging much harder (e.g., using printf may result in
 * infinite loops).
 */
#if 0
void *malloc(size_t size) { return mymalloc(size); }
void *calloc(size_t nmemb, size_t size) { return mycalloc(nmemb, size); }
void *realloc(void *ptr, size_t size) { return myrealloc(ptr, size); }
void free(void *ptr) { myfree(ptr); }
#endif
