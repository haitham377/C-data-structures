#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#define vec_at(v, i, t) (*(t*)((uint8_t*)(v)->data + ((i) * (v)->element_size)))

typedef struct {
    void *data;
    size_t size;
    size_t alloc;
    size_t element_size; 
} vector;

void initialize(vector *v, size_t element_size, size_t n) {
    v -> data = NULL;
    v -> element_size = element_size;
    v -> alloc = n;
    v -> size = 0;

    if (n > 0) {
        v -> data = malloc(n * element_size);
        if (v -> data == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
    }
}

void push_back(vector *v, void *x) {
    if (v -> size == v -> alloc) {
        size_t new_cap;
        if (v -> size == 0) new_cap = 1;
        else new_cap = v -> size * 2;

        v -> data = realloc(v -> data, new_cap * v -> element_size);
        if (v -> data == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        v -> alloc = new_cap;
    }

    uint8_t *back = (uint8_t *) v -> data + (v -> size) * (v -> element_size);

    memcpy(back, x, v -> element_size);

    v -> size++;
}

void pop_back(vector *v) {
    if (v -> size > 0) v -> size--;
}

void* back(vector *v) {
    if (v -> size > 0) return ((uint8_t*) v -> data + (v -> size - 1) * v -> element_size);
    return NULL;
}

void free_vec(vector *v) {
    free(v -> data);
    v -> data = NULL;

    v -> size = 0;
    v -> alloc = 0;
}
