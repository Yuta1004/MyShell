#ifndef MY_VECTOR_H
#define MY_VECTOR_H

typedef struct Vector Vector;
struct Vector{
    void **data;
    int capacity;
    int len;
};

Vector *vec_new(int capacity);
Vector *vec_cpy(Vector *vec, int first, int last);
void *vec_push(Vector *vec, void *item);
void *vec_pop(Vector *vec);
void *vec_get(Vector *vec, int idx);
int vec_find(Vector *vec, void* target);
int vec_remove(Vector *vec, int target_idx);
void vec_add_capacity(Vector *vec, int size);
void vec_free(Vector *free);

#endif // !MY_VECTOR_H