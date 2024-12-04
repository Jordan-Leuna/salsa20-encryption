#ifndef SALSA20_H
#define SALSA20_H

#include <stdint.h>

void salsa20_block(uint8_t *out, uint8_t key[32], uint64_t nonce, uint64_t index);
void salsa20(uint8_t *message, uint64_t mlen, uint8_t key[32], uint64_t nonce);

#endif
