/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H
    #define FNV_PRIME 16777619u
    #define OFFSET_BASIC 2166136261u

typedef struct ht_content_s {
    char *key;
    char *value;
    int hash_key;
    struct ht_content_s *next;
} ht_content_t;

typedef struct hashtable_s {
    ht_content_t **content;
    int len;
    int (*hash_function)(char *, int);
} hashtable_t;


// Hash function
int hash(char *key, int len);

// Create & destroy table
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);

// Handle table
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);

// Tools
int my_strlen(char const *str);
int my_putstr(char const *str);
void my_putchar(char c);
int mini_printf(const char *format, ...);
int my_put_nbr(int nb);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(const char *src);
char *my_strcpy(char *dest, char const *src);
#endif /* HASHTABLE_H */
