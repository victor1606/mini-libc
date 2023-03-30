// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *ptr = mmap(NULL, size, PROT_WRITE | PROT_READ, MAP_ANONYMOUS | MAP_PRIVATE, 0, 0);
	
	if(ptr) {
		mem_list_add(ptr, size);
	} else {
		ptr = NULL;
	}

	return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *ptr = mmap(NULL, size, PROT_WRITE | PROT_READ, MAP_ANONYMOUS | MAP_PRIVATE, 0, 0);
	
	if(ptr) {
		memset(ptr, 0, nmemb * size);
		mem_list_add(ptr, size);
	} else {
		ptr = NULL;
	}
	
	return ptr;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	munmap(ptr, mem_list_find(ptr)->len);
	mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	unsigned int old_size = mem_list_find(ptr)->len;
	void *new_ptr = mremap(ptr, old_size, size, MREMAP_MAYMOVE);

	return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	return realloc(ptr, nmemb * size);
}
