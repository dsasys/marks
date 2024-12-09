#include <stdio.h>
#include <string.h>

#define MAX 100


void xor(char *dividend, const char *generator) {
    for (int i = 0; generator[i] != '\0'; i++) {
        dividend[i] = (dividend[i] == generator[i]) ? '0' : '1';
    }
}


void compute(const char *data, const char *generator, char *crc) {
    char temp[MAX];
    strcpy(temp, data);
    strcat(temp, "0000"); 

    int gen_len = strlen(generator);

    for (int i = 0; temp[i + gen_len - 1] != '\0'; i++) {
        if (temp[i] == '1')
         { 
            xor(temp + i, generator);
        }
    }

    strcpy(crc, temp + strlen(data));
}


int verify(const char *received, const char *generator) {
    char crc[MAX];
    compute(received, generator, crc);
    return strcmp(crc, "0000") == 0;  
}

int main() {
    char data[MAX];
    char generator[MAX];
    char crc[MAX];
    char transmitted[MAX];

    printf("Enter the data: ");
    scanf("%s", data);

    printf("Enter the generator: ");
    scanf("%s", generator);

    compute(data, generator, crc);

    printf("CRC is: %s\n", crc);

    strcpy(transmitted, data);
    strcat(transmitted, crc);

    printf("Transmitted data is: %s\n", transmitted);

    printf("Enter received data: ");
    scanf("%s", transmitted);

    if (verify(transmitted, generator)) {
        printf("No errors detected.\n");
    } else {
        printf("Error detected in received data.\n");
    }

    return 0;
}

