#ifndef SHAPES_H_INCLUDED
#define SHAPES_H_INCLUDED

typedef struct {
    int x;
    int y;
    char symbol;
} Point;

typedef struct {
    Point p1;
    Point p2
} Line;

void drawPoint(Point point);
void clearPoint(Point point);

#endif // SHAPES_H_INCLUDED
