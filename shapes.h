#ifndef SHAPES_H_INCLUDED
#define SHAPES_H_INCLUDED

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position p1;
    Position p2;
} Line;

static char symbol = '*';
static int trace = 0;

void setPosition(Position * p, int x, int y);

void setSymbol(char s);
char getSymbol();

float getSlope(Position *source, Position *target);

void drawSymbolXY(int x, int y);
void clearSymbolXY(int x, int y);

void drawSymbol(Position * point);
void clearSymbol(Position * point);

void enableTrace();
void disableTrace();
int isTraceEnabled();
int isTraceDisabled();

void moveToPosition(int x2, int y2);
void moveToPositionByX(int x1, int y1, int x2, int y2);
void moveToPositionByY(int x1, int y1, int x2, int y2);

void showDots(Position *source, Position *target, int speed);



#endif // SHAPES_H_INCLUDED
