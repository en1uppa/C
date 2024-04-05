#include <stdio.h>
#include <string.h>

// 构建部分匹配表（Next数组）
void getNext(char *pattern, int *next) {
    int i = 0, j = -1;
    next[0] = -1;
    int len = strlen(pattern);
    while (i < len - 1) {
        if (j == -1 || pattern[i] == pattern[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

// KMP算法匹配字符串
int kmp(char *text, char *pattern) {
    int len1 = strlen(text);
    int len2 = strlen(pattern);
    int i = 0, j = 0;
    int next[len2];
    getNext(pattern, next);
    while (i < len1 && j < len2) {
        if (j == -1 || text[i] == pattern[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j == len2) {
        return i - j; // 返回匹配位置
    } else {
        return -1; // 没有匹配到
    }
}

int main() {
    char text[] = "ABABABABCABABABABCABABABABC";
    char pattern[] = "ABABCABAB";
    int position = kmp(text, pattern);
    if (position != -1) {
        printf("Pattern found at position: %d\n", position);
    } else {
        printf("Pattern not found.\n");
    }
    return 0;
}
//以上看不懂