#include <string.h>

void * memset(void *s, int c, size_t n)
{
	unsigned char *buf = (unsigned char *) s;
	size_t i;
	for (i = 0; i < n; i++) {
		buf[i] = (unsigned char) c;
	}
	
	return s;
}
