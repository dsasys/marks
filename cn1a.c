#include <stdio.h>
#include <string.h>

#define MAX_FRAMES 10
#define MAX_FRAMESIZE 256


int countbits(const char *frame) {
    return strlen(frame) * 8;
}


void receiverframes(const char *frame) {
    printf("The frame received is: %s\n", frame);
}

int main() {
    char frames[MAX_FRAMES][MAX_FRAMESIZE];
    int framecount = 0;

    printf("Enter up to %d frames, each of maximum %d characters:\n", MAX_FRAMES, MAX_FRAMESIZE);

    while (framecount < MAX_FRAMES && fgets(frames[framecount], sizeof(frames[framecount]), stdin)) {
        
        frames[framecount][strcspn(frames[framecount], "\n")] = '\0';

        
        if (strlen(frames[framecount]) == 0) {
            break;
        }

        framecount++;
    }

    for (int i = 0; i < framecount; i++) {
        int bitcount = countbits(frames[i]);

        printf("Total number of bits in frame %d = %d\n", i + 1, bitcount);
        receiverframes(frames[i]);
    }

    return 0;
}

