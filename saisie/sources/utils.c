

#define _GNU_SOURCE
#include "utils.h"

/* strlcpy based on OpenBSDs strlcpy */

/* Apple implemented its own strlcpy, and a clash occurs if not protected */
#ifndef Darwin

/*
 * Copy src to string dst of size siz.  At most siz-1 characters
 * will be copied.  Always NUL terminates (unless siz == 0).
 * Returns strlen(src); if retval >= siz, truncation occurred.
 */
size_t
strlcpy(char *dst, const char *src, size_t siz)
{
        char *d = dst;
        const char *s = src;
        size_t n = siz;

        /* Copy as many bytes as will fit */
        if (n != 0 && --n != 0) {
                do {
                        if ((*d++ = *s++) == 0)
                                break;
                } while (--n != 0);
        }

        /* Not enough room in dst, add NUL and traverse rest of src */
        if (n == 0) {
                if (siz != 0)
                        *d = '\0';                /* NUL-terminate dst */
                while (*s++)
                        ;
        }

        return(s - src - 1);        /* count does not include NUL */
}

#endif

