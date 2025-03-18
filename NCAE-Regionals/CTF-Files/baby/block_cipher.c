#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint8_t key = 0x11;
// TODO: implement a decryption function. Shouldn't be too hard, right?
 

void encrypt(unsigned char* plaintext) {
    unsigned char iv[8] = "18273645";
    uint8_t block_len = 8;
    uint8_t plain_len = strlen(plaintext);

    for (int i = 0; i < plain_len-3; i += block_len) {
        // step 1
        uint64_t block = 0;
        memcpy(&block, plaintext + i, block_len);
        block = (block << key | block >> (64 - key)) & 0xffffffffffffffff;
        unsigned char *temp = (char *)&block;
        memcpy(plaintext + i, &block, block_len);

        // step 2
        for (int j = 0; j < block_len; j++) {
            plaintext[i + j] ^= iv[j];
            iv[j] = plaintext[i + j];
        }
    }
}

int main() {
    // note: this is not the flag. The flag is when you decrypt the ciphertext
    // second note: the x's are padding and should not be submitted as part of the flag
    unsigned char plaintext[] = "c2ctf{there's a real flag on prod}xxxxxxxx";
    encrypt((char *)plaintext);
    for (int i = 0; i < strlen(plaintext); i++) {
        printf("%02x", plaintext[i]);
    }
}