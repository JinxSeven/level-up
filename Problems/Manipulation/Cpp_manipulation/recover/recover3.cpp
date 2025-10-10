#include <iostream>
#include <cstdio>
#include <cstdint>

constexpr int DATA_BLOCK = 512;
constexpr int FILE_SIZE = 8;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Too many arguments\n";
        std::cout << "Usage: ./recover FILE\n";
        return 1;
    }

    FILE *raw = fopen(argv[1], "r");
    if (raw == nullptr) {
        std::cout << "Error opening file " << argv[1] << std::endl;
        return 2;
    }

    FILE *img = nullptr;
    int fileCount = 0;
    char fileName[FILE_SIZE];
    uint8_t buffer[DATA_BLOCK];

    while (fread(buffer, sizeof(uint8_t), DATA_BLOCK, raw) == DATA_BLOCK) {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 &&
            buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {

            if (img != nullptr) {
                fclose(img);
            }

            std::sprintf(fileName, "%03i.jpg", fileCount);
            img = fopen(fileName, "wb");
            fileCount++;

            if (img != nullptr) {
                fwrite(buffer, sizeof(uint8_t), DATA_BLOCK, img);
            }
        }
        if (img != nullptr) {
            fclose(img);
        }
    }

    fclose(raw);
    return 0;
}
