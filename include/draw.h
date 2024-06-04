#ifndef DRAW_H
#define DRAW_H

#include <string>
#include "constants.h"

void draw_circle(unsigned char* image, int width, int height, int cx, int cy, int radius, unsigned char r, unsigned char g, unsigned char b);
void draw_line(unsigned char* image, int width, int height, int x0, int y0, int x1, int y1, unsigned char r, unsigned char g, unsigned char b);
void draw_text(unsigned char* image, int width, int height, int x, int y, const std::string& text, unsigned char r, unsigned char g, unsigned char b);

#endif // DRAW_H

