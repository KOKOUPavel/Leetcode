#include <stdlib.h>
#include <string.h>

int compa_char(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

typedef struct {
    char* word;
    char* sorted;
} Node;

int compa_node(const void* a, const void* b) {
    return strcmp(((Node*)a)->sorted, ((Node*)b)->sorted);
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    
    Node* arr = malloc(sizeof(Node) * strsSize);

    for (int i = 0; i < strsSize; i++) {
        arr[i].word = strs[i];

        arr[i].sorted = strdup(strs[i]);
        qsort(arr[i].sorted, strlen(arr[i].sorted), sizeof(char), compa_char);
    }

    qsort(arr, strsSize, sizeof(Node), compa_node);

    int groups = 0;
    for (int i = 0; i < strsSize; i++) {
        if (i == 0 || strcmp(arr[i].sorted, arr[i - 1].sorted) != 0) {
            groups++;
        }
    }

    char*** result = malloc(sizeof(char**) * groups);
    *returnColumnSizes = malloc(sizeof(int) * groups);

    int i = 0, g = 0;

    while (i < strsSize) {
        int j = i;

        while (j < strsSize && strcmp(arr[i].sorted, arr[j].sorted) == 0) {
            j++;
        }

        int size = j - i;

        result[g] = malloc(sizeof(char*) * size);
        (*returnColumnSizes)[g] = size;

        for (int k = 0; k < size; k++) {
            result[g][k] = arr[i + k].word;
        }

        g++;
        i = j;
    }

    *returnSize = groups;

    for (int i = 0; i < strsSize; i++) {
        free(arr[i].sorted);
    }
    free(arr);

    return result;
}
