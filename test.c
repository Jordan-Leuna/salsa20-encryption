#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "salsa20.h"

// Funktion, um einen hexadezimalen String in ein Byte-Array zu konvertieren
void string2hex(const char *str, uint8_t *out) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++) {
        sscanf(&str[2*i], "%2hhx", &out[i]);
    }
}

int main() {
    uint8_t key[32];
    uint8_t plaintext[64];
    uint64_t nonce;

    // Benutzereingabe für den Schlüssel (32 Byte, hexadezimal)
    char key_input[65];
    printf("Geben Sie den Schlüssel (32 Byte, hexadezimal) ein: ");
    fgets(key_input, 65, stdin);
    string2hex(key_input, key);

    // Benutzereingabe für den Nonce (8 Byte, hexadezimal)
    char nonce_input[17];
    printf("Geben Sie den Nonce (8 Byte, hexadezimal) ein: ");
    fgets(nonce_input, 17, stdin);
    sscanf(nonce_input, "%lx", &nonce);

    // Benutzereingabe für den Plaintext (64 Byte, hexadezimal)
    char plaintext_input[129];
    printf("Geben Sie den Plaintext (64 Byte, hexadezimal) ein: ");
    fgets(plaintext_input, 129, stdin);
    string2hex(plaintext_input, plaintext);

    // Salsa20-Encryption (oder Decryption)
    salsa20(plaintext, sizeof(plaintext), key, nonce);

    // Ausgabe des verschlüsselten (oder entschlüsselten) Textes
    printf("Ergebnis (verschlüsselt/entschlüsselt):\n");
    for (int i = 0; i < sizeof(plaintext); ++i) {
        printf("%02X", plaintext[i]);
    }
    printf("\n");

    return 0;
}
