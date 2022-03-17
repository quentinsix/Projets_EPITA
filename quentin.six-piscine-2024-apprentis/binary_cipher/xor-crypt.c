#include <stddef.h>
#include <stdio.h>

void my_xor_crypt(void *data, size_t data_len, const void *key, size_t key_len)
{
    char *d = data;
    const char *k = key;
    for (size_t i = 0; i < data_len; i++)
        d[i] = d[i] ^ k[i % key_len];
}
