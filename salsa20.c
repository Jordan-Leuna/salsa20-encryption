#include "salsa20.h"
#include <stdio.h>
#include <stdint.h>

// Rotate x to left by n bits
#define R(x,n) (((x) << (n)) | ((x) >> (32-(n))))

// Quarter round operation
#define quarter(a,b,c,d) do {\
    b ^= R(d+a, 7);\
    c ^= R(a+b, 9);\
    d ^= R(b+c, 13);\
    a ^= R(c+d, 18);\
} while (0)

// Salsa20 word transformation
void salsa20_words(uint32_t *out, uint32_t in[16]) {
    uint32_t x[4][4];
    int i;
    for (i = 0; i < 16; ++i) x[i/4][i%4] = in[i];
    for (i = 0; i < 10; ++i) { // 10 double rounds = 20 rounds
        // Column round
        quarter(x[0][0], x[1][0], x[2][0], x[3][0]);
        quarter(x[1][1], x[2][1], x[3][1], x[0][1]);
        quarter(x[2][2], x[3][2], x[0][2], x[1][2]);
        quarter(x[3][3], x[0][3], x[1][3], x[2][3]);
        // Row round
        quarter(x[0][0], x[0][1], x[0][2], x[0][3]);
        quarter(x[1][1], x[1][2], x[1][3], x[1][0]);
        quarter(x[2][2], x[2][3], x[2][0], x[2][1]);
        quarter(x[3][3], x[3][0], x[3][1], x[3][2]);
    }
    for (i = 0; i < 16; ++i) out[i] = x[i/4][i%4] + in[i];
}

// Salsa20 block function to generate a 64-byte keystream
void salsa20_block(uint8_t *out, uint8_t key[32], uint64_t nonce, uint64_t index) {
    static const char c[16] = "expand 32-byte k"; // arbitrary constant
    #define LE(p) ( (p)[0] | ((p)[1]<<8) | ((p)[2]<<16) | ((p)[3]<<24) )
    
    uint32_t in[16] = {
        LE(c), LE(key), LE(key+4), LE(key+8),
        LE(key+12), LE(c+4), (uint32_t)(nonce & 0xFFFFFFFF), (uint32_t)(nonce >> 32),
        (uint32_t)(index & 0xFFFFFFFF), (uint32_t)(index >> 32),
        LE(c+8), LE(key+16), LE(key+20), LE(key+24),
        LE(key+28), LE(c+12)
    };
    
    uint32_t wordout[16];
    salsa20_words(wordout, in);
    
    for (int i = 0; i < 64; ++i) {
        out[i] = (uint8_t)(wordout[i/4] >> (8*(i%4)));
    }
}

// Encrypt/decrypt: XOR the message with the generated keystream
void salsa20(uint8_t *message, uint64_t mlen, uint8_t key[32], uint64_t nonce) {
    uint8_t block[64];
    for (int i = 0; i < mlen; i++) {
        if (i % 64 == 0) salsa20_block(block, key, nonce, i / 64);
        message[i] ^= block[i % 64];
    }
}
