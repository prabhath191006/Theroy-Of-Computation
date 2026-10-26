#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, len;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    if (str[0] == 'a' && str[len - 1] == 'a') {
        printf("String Accepted");
    } else {
        printf("String Rejected");
    }

    return 0;
}
