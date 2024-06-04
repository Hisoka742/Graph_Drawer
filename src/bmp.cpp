#include "bmp.h"
#include <fstream>

void saveBMP(const char* filename, unsigned char* data, int width, int height) {
    std::ofstream file(filename, std::ios::out | std::ios::binary);

    // BMP header
    unsigned char fileHeader[14] = {
        'B', 'M',           // Magic number
        0, 0, 0, 0,         // File size in bytes
        0, 0, 0, 0,         // Reserved
        54, 0, 0, 0         // Offset to image data
    };
    unsigned char infoHeader[40] = {
        40, 0, 0, 0,        // Header size
        0, 0, 0, 0,         // Image width
        0, 0, 0, 0,         // Image height
        1, 0,               // Number of color planes
        24, 0,              // Bits per pixel
        0, 0, 0, 0,         // Compression
        0, 0, 0, 0,         // Image size (can be 0 for uncompressed)
        0, 0, 0, 0,         // Horizontal resolution
        0, 0, 0, 0,         // Vertical resolution
        0, 0, 0, 0,         // Colors in color table
        0, 0, 0, 0          // Important color count
    };

    int fileSize = 54 + 3 * width * height;
    fileHeader[2] = (unsigned char)(fileSize);
    fileHeader[3] = (unsigned char)(fileSize >> 8);
    fileHeader[4] = (unsigned char)(fileSize >> 16);
    fileHeader[5] = (unsigned char)(fileSize >> 24);

    int w = width;
    int h = height;
    infoHeader[4] = (unsigned char)(w);
    infoHeader[5] = (unsigned char)(w >> 8);
    infoHeader[6] = (unsigned char)(w >> 16);
    infoHeader[7] = (unsigned char)(w >> 24);
    infoHeader[8] = (unsigned char)(h);
    infoHeader[9] = (unsigned char)(h >> 8);
    infoHeader[10] = (unsigned char)(h >> 16);
    infoHeader[11] = (unsigned char)(h >> 24);

    file.write(reinterpret_cast<const char*>(fileHeader), sizeof(fileHeader));
    file.write(reinterpret_cast<const char*>(infoHeader), sizeof(infoHeader));
    file.write(reinterpret_cast<const char*>(data), 3 * width * height);
    file.close();
}
