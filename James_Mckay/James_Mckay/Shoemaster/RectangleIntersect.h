#include "Coords.h"

struct Rectangle
{
	Point2D lb;
	Point2D lt;
	Point2D rb;
	Point2D rt;
	int length = 2;
	int height = 1;
};

class RectangleIntersect
{
public:
	bool Overlap(Rectangle x, Rectangle y);
	Rectangle CreateRectangle(Point2D start);

};
