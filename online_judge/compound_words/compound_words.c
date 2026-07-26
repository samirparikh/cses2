#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAXLENGTH 100
#define hashsize(n) ((unsigned long)1 << (n))
#define hashmask(n) (hashsize(n) - 1)
#define NUM_BITS 17

typedef struct word_node {
    char *word;
    struct word_node *next;
} word_node;

unsigned long oaat(char *key, unsigned long len,
                   unsigned long bits) {

    unsigned long hash, i;

    for (hash = 0, i = 0; i < len; i++) {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }

    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash & hashmask(bits);
}

int in_hash_table(word_node *hash_table[], char *find,
                  unsigned find_len) {
    unsigned word_code;
    word_node *wordptr;
    word_code = oaat(find, find_len, NUM_BITS);
    wordptr = hash_table[word_code];
    while (wordptr) {
        if ((strlen((wordptr->word)) == find_len) &&
            (strncmp((wordptr->word), find, find_len) == 0))
            return 1;
        wordptr = wordptr->next;
    }
    return 0;
}

void identify_compound_words(char *words[],
                             word_node *hash_table[],
                             int total_words) {
    int i, j, len;
    for (i = 0; i < total_words; i++) {
        len = strlen(words[i]);
        for (j = 1; j < len; j++) {
            if (in_hash_table(hash_table, words[i], j) &&
                in_hash_table(hash_table, &words[i][j], len - j)) {
                printf("%s\n", words[i]);
                break;
            }
        }
    }
}

bool read_line(char *string, int max_length) {
    int ch;
    int length = 0;

    if (max_length <= 0) {
        fprintf(stderr, "max line length must be greater than 0\n");
        return false;
    }

    while ((ch = getchar()) != EOF && ch != '\n') {
        if (length < max_length - 1) {
            string[length++] = (char) ch;
        } else {
            fprintf(stderr, "Input exceeded max length\n");

            /* Consume the rest of the line */
            while (ch != '\n' && ch != EOF) {
                ch = getchar();
            }

            return false;
        }
    }

    /* If we hit EOF before reading anything, signal no more input */
    if (ch == EOF && length == 0) {
        string[0] = '\0';
        return false;
    }

    string[length] = '\0';
    return true;
}

int main(void) {

    /*
     * words is an array of pointers to strings.  Each char * points to the
     * first character of a separately allocated string.
     * +-----+      +---+---+---+---+---+---+
     * | [0] | ---> | a | l | i | e | n |\0 |
     * +-----+      +---+---+---+---+---+---+
     * 
     * +-----+      +---+---+---+---+---+
     * | [1] | ---> | b | o | r | n |\0 |
     * +-----+      +---+---+---+---+---+
     * 
     * +-----+      +---+---+---+---+
     * | [2] | ---> | n | e | w |\0 |
     * +-----+      +---+---+---+---+
     *    .
     *    .
     */
    static char *words[1 << NUM_BITS] = {NULL};
    static word_node *hash_table[1 << NUM_BITS] = {NULL};
    int total = 0;
    char word[MAXLENGTH];
    word_node *wordptr;
    unsigned length, word_code;
    while (read_line(word, MAXLENGTH)) {
        words[total] = malloc(strlen(word) + 1);
        if (words[total] == NULL) {
            fprintf(stderr, "malloc error\n");
            exit(EXIT_FAILURE);
        }
        strcpy(words[total], word);
        wordptr = malloc(sizeof(word_node));
        if (wordptr == NULL) {
            fprintf(stderr, "malloc error\n");
            exit(1);
        }
        length = strlen(word);
        word_code = oaat(word, length, NUM_BITS);
        wordptr->word = words[total];
        wordptr->next = hash_table[word_code];
        hash_table[word_code] = wordptr;
        total++;
    }

    identify_compound_words(words, hash_table, total);

    return 0;
}
