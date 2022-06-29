
#include "RectangleIntersect.h"



Rectangle RectangleIntersect::CreateRectangle(Point2D start)
{
	Rectangle rec;
	rec.lb = start, 
	rec.lt.x = start.x, rec.lt.y = start.y + rec.height,
	rec.rb.x = start.x + rec.length, rec.rb.y = start.y,
	rec.rt.x = start.x + rec.length, rec.rt.y = start.y + rec.height;

	return rec;
}

bool RectangleIntersect::Overlap(Rectangle x, Rectangle y)
{
	if (x.lt.x > y.rb.x || y.lt.x > x.rb.x)
		return false;

	if (x.rb.y > y.lt.y || y.rb.y > y.lt.y)
		return false;

	return true;
}

