#ifndef CANVAS_H
#define CANVAS_H

#include <inttypes.h>

typedef unsigned char Byte;
typedef int32_t Color;

typedef struct {
  uint16_t x, y;
} Point;

typedef struct {
  uint16_t width, height, pitch;
  Color* pixels;
} Canvas;

Canvas* canvas_create(int16_t width, int16_t height);
void canvas_draw_pixel(const Canvas* canvas, Color color, Point point);
void canvas_draw_line(const Canvas* canvas, Color color, Point start, Point end);
void canvas_destroy(Canvas* canvas);

inline Color rgb(Byte r, Byte g, Byte b) {
  return (r << 16) | (g << 8) | b;
}

inline Color rgba(Byte r, Byte g, Byte b, Byte a) {
  return (a << 24) | (r << 16) | (g << 8) | b;
}

#endif
