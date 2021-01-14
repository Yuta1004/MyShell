#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include "../vector/vector.h"

char* __get_str_n(char* str, size_t n);

/**
 *  # 文字列を指定文字で分割する
 * ## Params
 * - char* raw_str : 分割する文字列
 * - char target : 指定文字
 * ## Returns
 * - Vector* : 分割結果
 */
Vector* split(char *raw_str, char target) {
    Vector *vec = vec_new(5);

    size_t size = 0, padding = 0;
    char *now_ptr = raw_str;
    while(*now_ptr == target) {
        ++ now_ptr;
    }
    while(*now_ptr) {
        if(*now_ptr == target) {
            if(*(now_ptr+1) != target) {
                vec_push(vec, __get_str_n(now_ptr-size-padding, size));
                size = -1;
                padding = 0;
            } else {
                -- size;
                ++ padding;
            }
        }
        ++ size;
        ++ now_ptr;
    }
    if(size != 0) {
        vec_push(vec, __get_str_n(now_ptr-size, size));
    }

    return vec;
}

char* __get_str_n(char* str, size_t n) {
    char *str_n = malloc(n+1);
    strncpy(str_n, str, n);
    str_n[n] = '\0';
    return str_n;
}