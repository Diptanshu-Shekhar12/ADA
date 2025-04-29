
#include <stdio.h>
#include <string.h>

void patternMatch(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i+j] != pattern[j])
                break;
        }
        if (j == m)
            printf("Pattern found at index %d\n", i);
    }
}

int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";
    patternMatch(text, pattern);
    return 0;
}
