#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[1009] = {0};
    int b[1009] = {0};

    int n;
    int temp;
    int check = 1;

    scanf("%d" , &n);

    int i;

    for (i=0; i<n; ++i){
        scanf("%d" , &temp);
        temp = temp % 69;
        ++a[temp];
    }

    for (i=0; i<n; ++i){
        scanf("%d" , &temp);
        temp = temp % 69;
        ++b[temp];
    }

    for (i=0; i<n; ++i){
        if (a[i] != b[i]){
            check = 0;
            break;
        }
    }
    printf ("%d\n" , check);



    return 0;
}