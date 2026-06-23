/* Write a program to Compress a string */

#include <stdio.h>
#include <string.h>

void compressString(char* src, char* dest) {
    int i = 0;
    int j = 0;
    int len = strlen(src);
    while (i < len) {
        dest[j++] = src[i];
        int count = 1;
        while (i + 1 < len && src[i] == src[i + 1]) {
            count++;
            i++;
        }
        int written = sprintf(&dest[j], "%d", count);
        j += written;
        i++;
    }
    dest[j] = '\0';
}

int main() {
    char input[500];
    char compressed[1000]; 
    printf("Enter a string to compress: ");
    scanf("%499s", input);
    compressString(input, compressed);
    printf("\nOriginal String:   %s\n", input);
    printf("Compressed String: %s\n", compressed);
    if (strlen(compressed) >= strlen(input)) {
        printf("Note: Compression did not reduce the string size.\n");
    }
    return 0;
}
