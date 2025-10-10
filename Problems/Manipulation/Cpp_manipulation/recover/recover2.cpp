#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cstdio>


constexpr int DATA_BLOCK = 512;
constexpr int LENGTH = 8;

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        std::cerr << "Wrong usage!\n";
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "rb");

    if (!inputFile) {
        std::cerr << "Unable to open file!\n";
        return 2;
    }

    FILE *image = nullptr;
    uint8_t tmpBuffer[DATA_BLOCK];
    char fileName[LENGTH];
    unsigned count = 0;

    while (fread(tmpBuffer, sizeof(uint8_t), DATA_BLOCK, inputFile) == DATA_BLOCK) {
        if (tmpBuffer[0] == 0xff && tmpBuffer[1] == 0xd8 && tmpBuffer[2] == 0xff && (tmpBuffer[3] & 0xf0) == 0xe0) {
            if (image != nullptr) {
                fclose(image);
            }

            sprintf(fileName, "%03i.jpg", count);
            image = fopen(fileName, "wb");
            count++;

            if (image != nullptr) {
                fwrite(tmpBuffer, sizeof(uint8_t), DATA_BLOCK, image);
            }
        }
    }

    fclose(inputFile);

    if (image != nullptr) {
        fclose(image);
    }

    return 0;
}
