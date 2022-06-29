#pragma once
#include <iostream>
#include "Coords.h"


class LineSegments
{
	bool onSegment(Point2D p, Point2D q, Point2D r)
	{
		if (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
			q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y))
		{
			return true;
		}

		return false;
	}

	
public:
	bool doIntersect(Point2D p1, Point2D q1, Point2D p2, Point2D q2)
	{

		int o1 = orientation(p1, q1, p2);
		int o2 = orientation(p1, q1, q2);
		int o3 = orientation(p2, q2, p1);
		int o4 = orientation(p2, q2, q1);

		if (o1 != o2 && o3 != o4)  // if the intersect and are not collinear this will return true
		{
			return true;
		}

		if (o1 == 0 && onSegment(p1, p2, q1)) 
			return true;

		if (o1 == 0 && onSegment(p1, q2, q1))
			return true;

		if (o1 == 0 && onSegment(p2, p1, q2))
			return true;

		if (o1 == 0 && onSegment(p2, q1, q2))
			return true;

		return false; //no intersection points
	}

	int orientation(Point2D p, Point2D q, Point2D r)
	{
		int ori = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

		if (ori == 0) return 0; // the points are collinear

		return (ori > 0) ? 1 : 2; //if the point are clockwise (1) or counter-clockwise (2)
	}
};

