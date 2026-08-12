#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int length(char* str) {
    int count = 0;
    while (*(str+count) != '\0') {
        count++;
    }
    return count;
}

void concatenate(char* str1, char* str2, char* con) {
    int i = 0, j=0;
    while(*(str1+i) != '\0') {
        *(con+i) = *(str1+i);
        i++;
    }
    while(*(str2+j) != '\0') {
        *(con+i+j) = *(str2+j);
        j++;
    }
}

void insertSubstr(char* str, char* substr, char* res, int pos) {
    int i = 0, j=0;
    for (; i < pos && str[i] != '\0'; i++) {
        res[i] = str[i];
    }
    while(substr[j] != '\0') {
        res[i+j] = substr[j];
        j++;
    }
    while(str[i] != '\0') {
        res[i+j] = str[i];
        i++;
    }
}

bool deleteSubstr(char* str, char* substr, char* res) {
    int sublen = length(substr);
    int len = length(str);
    int i = 0;
    bool found = false;

    for (; i <= len - sublen; i++) {
        found = true;
        for (int j = 0; j < sublen; j++) {
            if (str[i+j] != substr[j]) {
                found = false;
                break;
            }
        }
        if (found) break;
    }

    if (!found) {
        int k = 0;
        for (; k < len; k++) res[k] = str[k];
        res[k] = '\0';
        return false;
    }

    int res_idx = 0;
    for (int j = 0; j < i; j++) {
        res[res_idx++] = str[j];
    }

    for (int j = i + sublen; j < len; j++) {
        res[res_idx++] = str[j];
    }

    res[res_idx] = '\0';
    return true;
}
    

int main() {
    printf("Enter the main string:\n");
    char str1[100];
    fgets(str1, 100, stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Length of string: %d\n", length(str1));

    printf("Enter string to concatenate:\n");
    char str2[100];
    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = '\0';
    char result[200];
    concatenate(str1, str2, result);
    printf("Concatenated result:\n");
    puts(result);

    memset(result, 0, sizeof(result));
    printf("Enter substring to insert:\n");
    char substr[100];
    fgets(substr, 100, stdin);
    substr[strcspn(substr, "\n")] = '\0';
    printf("Enter index to insert in: ");
    int pos;
    scanf("%d", &pos);
    insertSubstr(str1, substr, result, pos);
    printf("Inserted substring:\n");
    puts(result);

    memset(substr, 0, sizeof(substr));
    memset(result, 65, sizeof(result));
    result[100]='\0';
    printf("Enter substring to delete: \n");
    getchar();
    fgets(substr, 100, stdin);
    substr[strcspn(substr, "\n")] = '\0';
    deleteSubstr(str1, substr, result);
    puts(result);
}
