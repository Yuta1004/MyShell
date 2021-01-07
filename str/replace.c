#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *  # 文字列中に存在する特定の文字列を別の文字列で置換する
 * ## Params
 * - char* raw_str : 元の文字列
 * - char* target_str : 置換対象文字列
 * - char* rep_str : 置換文字列
 * - int n : 置換回数
 * ## Returns
 * - char* : 置換結果
 */
char *replace(char *raw_str, char *target_str, char *rep_str, int n) {
    int len_raw_str = strlen(raw_str);
    int len_target_str = strlen(target_str);
    int len_rep_str = strlen(rep_str);
    char *res_str = calloc(len_raw_str+len_rep_str*n+1, 1);
    char *res_str_cp = res_str;

    int idx, cnt = 0;
    for(idx = 0; *(raw_str+idx) != '\0' && cnt < n; ++ idx) {
        if(strncmp(raw_str+idx, target_str, len_target_str)){
            *res_str = *(raw_str+idx);
            ++ res_str;
            continue;
        }
        sprintf(res_str, "%s%s", rep_str, raw_str+idx+len_target_str);
        idx += len_target_str-1;
        res_str += len_rep_str;
        ++ cnt;
    }

    return res_str_cp;
}
