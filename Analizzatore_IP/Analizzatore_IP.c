#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MyLib.h"

int main(){
    char ipD[16];
    int ip32b = 0;

    printf("Inserire un indirizzo IP nel formato dotted decimal: ");
    fgets(ipD, sizeof(ipD), stdin);
    printf("%u\n", ip_uint32(ipD));

    return 0;
}