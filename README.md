# README for Salsa20 Encryption/Decryption Program

## Overview
This program implements the Salsa20 stream cipher for encryption and decryption. It takes user input for a 32-byte encryption key, an 8-byte nonce, and a 64-byte plaintext. The program then encrypts or decrypts the plaintext using the Salsa20 algorithm and outputs the result in hexadecimal format.

The program uses the Salsa20 algorithm, which is a fast and secure stream cipher that operates on 64-byte blocks of data, using a 256-bit key and a 64-bit nonce.

## Features
- User input for encryption key (32 bytes in hexadecimal format).
- User input for nonce (8 bytes in hexadecimal format).
- User input for plaintext (64 bytes in hexadecimal format).
- Encrypts or decrypts the plaintext using Salsa20.
- Outputs the encrypted or decrypted text in hexadecimal format.

## How It Works
1. **Input**:
    - **Key**: The program prompts the user to input a 32-byte key in hexadecimal format.
    - **Nonce**: The program prompts the user to input an 8-byte nonce in hexadecimal format.
    - **Plaintext**: The program prompts the user to input a 64-byte plaintext in hexadecimal format.

2. **Salsa20 Algorithm**:
    - The Salsa20 algorithm takes the provided key and nonce, performs the Salsa20 encryption/decryption process, and modifies the plaintext in place.

3. **Output**:
    - The program outputs the resulting encrypted or decrypted text in hexadecimal format.

## File Structure
- **salsa20.h**: Header file for the Salsa20 encryption/decryption functions (assumed to be implemented in a separate file).
- **salsa20.c**: Source file containing the Salsa20 encryption/decryption implementation.
- **test.c**: The file containing the `main` function for handling user input and invoking the Salsa20 algorithm.
- **Makefile**: Build automation script for compiling and linking the program.

## Dependencies
- **C Standard Library**: Used for input/output operations, memory management, and string manipulation.
- **salsa20.h**: Header file defining the Salsa20 encryption/decryption functions (assumed to be provided).

## Potential Improvements
1. **Error Handling**: The program currently assumes valid input. It could be enhanced to check input validity (e.g., ensure correct key length and plaintext size).
2. **Support for Larger Data**: Currently, the program works with 64 bytes of plaintext. It could be extended to support encryption of larger data by breaking it into smaller blocks.

## License
This program is free to use and modify. Please cite the Salsa20 algorithm if using this code in other projects.

## How to Compile and Run

### 1. Ensure You Have a C Compiler Installed

Make sure you have a C compiler installed on your system (e.g GCC).

### 2. Prepare Your Files

Create a directory and place the following files in it:
- `salsa20.c` (contains the Salsa20 encryption/decryption implementation).
- `salsa20.h` (header file for Salsa20 functions).
- `test.c` (the main program file that interacts with the user).
- `Makefile` (build automation script).

### 3. Open Terminal/Command Prompt

Navigate to the directory where the source files are located by opening a terminal or command prompt.

### 4. Compile the Program

Use the following command to compile the program with the Makefile:

```bash
make // first command
Once the program is successfully compiled, you can run it with:./salsa20_test //second command 
