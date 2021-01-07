#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

/**
 *  # Vectorを初期化する
 * ## Params
 * - int capacity: 初期化サイズ
 */
Vector* vec_new(int capacity){
    Vector *vec = (Vector*)malloc(sizeof(Vector));
    vec->data = (void**)malloc(sizeof(void*) * capacity);
    vec->capacity = capacity;
    vec->len = 0;
    return vec;
}

/**
 *  # Vectorをコピーする(ハード)
 * ## Params
 * - Vector *vec: 対象Vector
 * - int first: 区間の左端
 * - int last: 区間の右端
 * ## Returns
 * - Vector*: コピーされたVector、失敗した場合はNULL
 * ## Others
 * 区間の指定方法に注意すること => [first last)
 */
Vector *vec_cpy(Vector* vec, int first, int last) {
    if(first < 0 || last > vec->len) {
        return NULL;
    }
    Vector *newer_vec = (Vector*)malloc(sizeof(Vector));
    newer_vec->data = (void**)malloc(sizeof(void*) * vec->capacity);
    newer_vec->capacity = vec->capacity;
    newer_vec->len = last-first;
    memcpy(newer_vec->data, vec->data+first, sizeof(void*) * (last-first));
    return newer_vec;
}

/**
 *  # Vectorに値を追加する
 * ## Params
 * - Vector *vec: 対象Vector
 * - void *item: 追加する要素
 * ## Returns
 * - void*: 追加した要素
 */
void *vec_push(Vector *vec, void* item) {
    if(vec->len >= vec->capacity) {
        vec_add_capacity(vec, 10);
    }
    vec->data[vec->len] = item;
    ++ vec->len;
    return item;
}

/**
 *  # Vectorから値をpopする
 * ## Params
 * - Vector *vec: 対象Vector
 * ## Returns
 * - void*: popしたデータ、ただしVectorの長さが0のときNULL
 */
void *vec_pop(Vector *vec) {
    if(vec->len <= 0) {
        return NULL;
    }
    return vec->data[--vec->len];
}

/**
 *  # Vectorの指定要素を取得する
 * ## Params
 * - Vector *vec: 対象Vector
 * - int idx: 要素指定
 * ## Returns
 * - void*: 指定したデータ、ただしidxが管理範囲外の場合NULL
 */
void *vec_get(Vector *vec, int idx) {
    if(idx < 0 || vec->len <= idx){
        return NULL;
    }
    return vec->data[idx];
}

/**
 *  # Vectorから値を検索する
 * ## Params
 * - Vector *vec: 対象Vector
 * - void *target: 検索する値
 * ## Returns
 * - int: 値がVector内に存在するときその場所、存在しないとき-1
 */
int vec_find(Vector *vec, void* target) {
    int idx;
    for(idx = 0; idx < vec->len; ++ idx) {
        if(vec->data[idx] == target)
            return idx;
    }
    return -1;
}

/**
 *  # Vectorから任意の要素を削除する
 * ## Params
 * - Vector *vec: 対象Vector
 * - int target_idx: 要素指定
 * ## Returns
 * - int: 削除に成功した場合0、そうでない場合1
 */
int vec_remove(Vector *vec, int target_idx) {
    if(target_idx < 0 || vec->len <= target_idx){
        return -1;
    }
    free(vec->data[target_idx]);
    int idx;
    for(idx = target_idx; idx < vec->len-1; ++ idx) {
        vec->data[idx] = vec->data[idx+1];
    }
    -- vec->len;
    return 0;
}

/**
 *  # Vectorサイズを拡張する
 * ## Params
 * - Vector *vec: 対象Vector
 * - int size: 拡張サイズ
 */
void vec_add_capacity(Vector *vec, int size) {
    int new_capacity = vec->capacity + size;
    void **new_data = (void**)malloc(sizeof(void*) * new_capacity);
    int idx;
    for(idx = 0; idx < vec->capacity; ++ idx) {
        new_data[idx] = vec->data[idx];
    }
    free(vec->data);
    vec->capacity = new_capacity;
    vec->data = new_data;
}

/**
 *  # Vectorを開放する
 */
void vec_free(Vector *vec) {
    free(vec->data);
    free(vec);
}
