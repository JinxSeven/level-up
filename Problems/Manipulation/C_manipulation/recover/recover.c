#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define DATA_BLOCK 512
#define FILE_SIZE 8

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Too many arguments\n");
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    FILE *raw = fopen(argv[1], "r");

    if (raw == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 2;
    }

    FILE *img = NULL;
    int fileCount = 0;
    char fileName[FILE_SIZE];
    uint8_t buffer[DATA_BLOCK];

    while (fread(buffer, sizeof(uint8_t), DATA_BLOCK, raw) == DATA_BLOCK) {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && 
        buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
            if (img != NULL) {
                fclose(img);
            }

            sprintf(fileName, "%03i.jpg", fileCount);
            img = fopen(fileName, "wb");
            fileCount++;            
        }

        if (img != NULL) {
            fwrite(buffer, sizeof(uint8_t), DATA_BLOCK, img);
        }
    }
    
    if (img != NULL) {
        fclose(img);
    }

    fclose(raw);
    return 0;
}
