// dmoj: coci17c1p3hard

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_USERS 100000
#define MAX_PASSWORD 10
/*
 * These two macros are small helper expressions used to build a power-of-two
 * size and a mask for that size.
 *
 * hashsize(n)  -> 2^n
 * hashmask(n)  -> a bitmask with the lowest n bits set to 1
 *
 * hashsize(n): This macro uses a bitwise left shift (<<) to calculate 2^n.
 * Shifting the binary number 1 to the left by n places is the bitwise
 * equivalent of raising 2 to the power of n.
 *
 * hashmask(n): This macro subtracts 1 from hashsize(n). If n = 3, 2^3 = 8
 * (which is 1000 in binary). Subtracting 1 gives 7 (which is 0111 in binary).
 * This creates a "mask" of exactly n ones, which is incredibly useful for
 * ensuring a number wraps around a specific power-of-two boundary.
 */
#define hashsize(n) ((unsigned long)1 << (n))
#define hashmask(n) (hashsize(n) - 1)

#define NUM_BITS 20

typedef struct password_node {
    char password[MAX_PASSWORD + 1];
    int total;
    struct password_node *next;
} password_node;

/*
 * oaat = "one-at-a-time" hash.
 *
 * Declares the function. It takes three arguments:
 * 1. a pointer to the raw bytes we want to hash (key)
 * 2. the number of bytes to read (len), and
 * 3. the number of bits we want in our final hash output (to fit our hash table size).
 *
 * This function takes:
 *   - key:  a pointer to the input bytes to hash
 *   - len:  how many bytes to read from key
 *   - bits: how many low bits to keep in the final result
 *
 * It returns a hash value that has been mixed and then truncated to the
 * requested number of bits.
 */
unsigned long oaat(char *key, unsigned long len,
                   unsigned long bits) {

    /*
     * hash holds the running hash value.
     * i is the loop counter used to walk over the input bytes.
     */
    unsigned long hash, i;

    /*
     * Start with hash = 0 and process the input one byte at a time.
     *
     * Initializes both hash and i to 0, and loops exactly len times. Because
     * key is a char *, this loop steps through the data exactly one byte
     * (8 bits) at a time.
     *
     * Each iteration:
     *   1. adds the next byte into the running hash
     *   2. mixes the result with a left shift
     *   3. mixes again with a right shift and XOR
     *
     * The prints here are for debugging and show how the hash evolves.
     */
    for (hash = 0, i = 0; i < len; i++) {
        /*
         * Print the current byte and hash value before the byte is mixed in.
         * key[i] is printed as an unsigned byte so the value is shown as 0..255.
         */
        // printf("i = %lu\tkey[%lu] = %hhu\thash = %lu\n", i, i, (unsigned char)key[i], hash);

        /* Add the current input byte into the running hash. */
        hash += key[i];

        /*
         * Shift the hash left by 10 bits and add that shifted value back in.
         * This spreads information from lower bits into higher bits.
         */
        hash += (hash << 10);

        /*
         * Shift the hash right by 6 bits and XOR it with itself.
         * XOR helps scramble the bits so similar inputs do not stay similar.
         */
        hash ^= (hash >> 6);
    }

    /*
     * Final avalanche / mixing stage.
     *
     * After all bytes have been processed, these operations further scramble
     * the bits so that the final result depends on the whole input.
     *
     * After all bytes are read, the hash goes through one final series of shifts,
     * adds, and XORs. This guarantees the "avalanche effect"—meaning that even if
     * only the very last byte of the input changed by a single bit, the final
     * output hash will be completely completely different.
     */
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    /*
     * Keep only the lowest 'bits' bits of the hash.
     *
     * If bits = 17, this masks the result down to a range of 0..(2^17 - 1).
     * That is useful when hashing into a table whose size is a power of 2.
     *
     * Applies a bitwise AND (&) using the hashmask macro we defined at the top.
     * If bits is 17, the mask is 17 ones. This operation neatly truncates the
     * massive hash value so it cleanly fits inside a 2^{17} bucket size, and
     * then returns it.
     */
    return hash & hashmask(bits);
}

password_node *in_hash_table(password_node *hash_table[], char *find) {
    unsigned long password_code;
    password_node *password_ptr;
    password_code = oaat(find, strlen(find), NUM_BITS);
    password_ptr = hash_table[password_code];
    while (password_ptr) {
        if (strcmp(password_ptr->password, find) == 0)
            return password_ptr;
        password_ptr = password_ptr->next;
    }
    return NULL;
}

void add_to_hash_table(password_node *hash_table[], char *find) {
    unsigned long password_code;
    password_node *password_ptr;
    password_ptr = in_hash_table(hash_table, find);
    if (!password_ptr) {        // password not yet in hash table
        password_code = oaat(find, strlen(find), NUM_BITS);
        password_ptr = malloc(sizeof(password_node));
        if (password_ptr == NULL) {
            fprintf(stderr, "memory allocation error\n");
            exit(EXIT_FAILURE);
        }

        strcpy(password_ptr->password, find);
        password_ptr->total = 0;
        password_ptr->next = hash_table[password_code];
        hash_table[password_code] = password_ptr;

    }
    password_ptr->total++;

}

int main(void) {

    static password_node *hash_table[1 << NUM_BITS] = { NULL };
    int num_ops, op, op_type, i, j;
    char password[MAX_PASSWORD + 1], substring[MAX_PASSWORD + 1];
    password_node *password_ptr;

    if (scanf("%d", &num_ops) != 1) {
        fprintf(stderr, "invalid input\n");
        return 1;
    }

    for (op = 0; op < num_ops; op++) {
        if (scanf("%d%s", &op_type, password) != 2) {
            fprintf(stderr, "invalid input\n");
            return 1;
        }

        if (op_type == 1) {     // insert new user passwd into hash table
            for (i = 0; i < strlen(password); i++)
                for (j = i; j < strlen(password); j++) {
                    strncpy(substring, &password[i], j - i + 1);
                    substring[j - i + 1] = '\0';
                    add_to_hash_table(hash_table, substring);
                }

        } else {                // query hash table
            password_ptr = in_hash_table(hash_table, password);
            if (!password_ptr)
                printf("0\n");
            else
                printf("%d\n", password_ptr->total);

        }
    }

    return 0;
}
