#include "memory.h"

char *itoa(int val, char *dst) {
    if (val < 0) {
        *dst = '-';
        dst++;
        val = -val;
    }

    int rev = 0;

    while (val != 0) {
        rev = rev * 10 + val % 10;
        val /= 10;
    }
    while (rev != 0) {
        *dst = rev % 10 + '0';
        dst++;
        rev /= 10;
    }
    *dst = '\0';

    return dst;
}

char *memcpy(char *src, char *dst, int num) {
    for (int i = 0; i < num; ++i) {
        dst[i] = src[i];
    }

    return dst;
}
char *memset(char *src, char c, int num) {
    for (int i = 0; i < num; ++i) {
        src[i] = c;
    }

    return src;
}
