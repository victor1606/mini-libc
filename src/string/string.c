// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
    return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	long unsigned int i = 0;
    while (source[i] != '\0' && i < len) {
        destination[i] = source[i];
        i++;
    }

	for (; i < len; i++) {
        destination[i] = '\0';
    }

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	int destination_length = strlen(destination);

    int i = 0;
    while (source[i] != '\0') {
        destination[destination_length + i] = source[i];
        i++;
    }
    destination[destination_length + i] = '\0';
    
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	int destination_length = strlen(destination);

    long unsigned int i = 0;
    while (source[i] != '\0' && i < len) {
        destination[destination_length + i] = source[i];
        i++;
    }
    destination[destination_length + i] = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	int i = 0;
	while (i < len1 || i < len2) {
		if (str1[i] > str2[i]) {
			return  1;
		} else if (str1[i] < str2[i]) {
			return  -1;
		}
		i++;
	}
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	unsigned int len1 = strlen(str1);
	unsigned int len2 = strlen(str2);

	long unsigned int i = 0;
	while ((i < len1 || i < len2) && i < len) {
		if (str1[i] > str2[i]) {
			return  1;
		} else if (str1[i] < str2[i]) {
			return  -1;
		}
		i++;
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	int i = 0;

	while(str[i] != '\0') {
		if (str[i] == c) {
			return (char *)str + i;
		}
		i++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	int i = strlen(str) - 1;

	while(str[i] != '\0') {
		if (str[i] == c) {
			return (char *)str + i;
		}
		i--;
	}
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	int len_needle = strlen(needle);

	while (*haystack != '\0') {
		if (*haystack == *needle) {
			if (strncmp(haystack, needle, len_needle) == 0) {
				return (char *)haystack;
			}
		}
		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	int len_needle = strlen(needle);
	int len_haystack = strlen(haystack);


	int i = 0;

	while (i < len_haystack) {
		if (*(haystack + len_haystack - i - len_needle) == *needle) {
			if (strncmp(haystack + len_haystack - i - len_needle, needle, len_needle) == 0) {
				return (char *)haystack + len_haystack - i - len_needle;
			}
		}
		haystack--;
		i++;
	}

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *d = destination;
	const char *s = source;

	for (unsigned long int i = 0; i < num; ++i) {
		*(d + i) = *(s + i);
	}

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *d = destination;
    const char *s = source;

	if (d > s) {
		for (unsigned long int i = 0; i < num; ++i) {
			d[num - i - 1] = s[num - i - 1];
		}
	} else {
		for (unsigned long int i = 0; i < num; ++i) {
			d[i] = s[i];
		}
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const char *a1 = ptr1;
	const char *a2 = ptr2;

	for (unsigned long int i = 0; i < num; ++i) {
		if (a1[i] > a2[i]) {
			return 1;
		} else if (a1[i] < a2[i]) {
			return -1;
		}
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *s = source;

	for (unsigned long int i = 0; i < num; ++i) {
		s[i] = (char)value;
	}

	return source;
}
