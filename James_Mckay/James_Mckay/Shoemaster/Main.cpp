#include <iostream>
#include <string>

#include "RectangleIntersect.h"
#include "LineSegments.h"

void startCoordsInput(Point2D &startPoint, Rectangle &rec);
void clearScreen();

int main()
{
	bool quit = false;
	RectangleIntersect RecInter;
	LineSegments LineInter;
	Point2D startPoint1;
	Point2D startPoint2;
	Point2D p1;
	Point2D q1;
	Point2D p2;
	Point2D q2;
	Rectangle rec1;
	Rectangle rec2;
	while (quit == false)
	{
		std::cout << "1) Rectangle Overlap\n2) Line Intersection\n3) Point Orientation\n6) Quit\n";
		int i = 0;
		std::cin >> i;
		while (std::cin.fail())
		{
			std::cout << "Error please input a number from the menu above.\n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> i;
		}
		//clearScreen();
		switch (i)
		{
		case 1:
			
			startCoordsInput(startPoint1, rec1);
			std::cout << "now for the second rectangle\n";
			startCoordsInput(startPoint2, rec2);
			//startPoint.x = 0, startPoint.y = 0;

			//startPoint2.x = 3, startPoint2.y = 3;

			rec1 = RecInter.CreateRectangle(startPoint1);
			rec2 = RecInter.CreateRectangle(startPoint2);

			if (RecInter.Overlap(rec1, rec2) == true)
			{
				std::cout << "The rectangles do overlap.\n";
			}
			else
			{
				std::cout << "The rectangles do not overlap.\n";
			}
			break;
		case 2:
			std::cout << "input first line segments first coordinates x & y\n";
			std::cout << "please enter 2 intergers\n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> p1.x >> p1.y;
			while (std::cin.fail())
			{
				std::cout << "Error please reinput numbers.\n 2 Numbers should be inputed as intergers.\n";
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cin >> p1.x >> p1.y;
			}

			std::cout << "input first line segments second coordinates x & y\n";
			std::cout << "please enter 2 intergers\n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> q1.x >> q1.y;
			while (std::cin.fail())
			{
				std::cout << "Error please reinput numbers.\n 2 Numbers should be inputed as intergers.\n";
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cin >> q1.x >> q1.y;
			}

			std::cout << "input second line segments first coordinates x & y\n";
			std::cout << "please enter 2 intergers\n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> p2.x >> p2.y;
			while (std::cin.fail())
			{
				std::cout << "Error please reinput numbers.\n 2 Numbers should be inputed as intergers.\n";
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cin >> p2.x >> p2.y;
			}

			std::cout << "input second line segments second coordinates x & y\n";
			std::cout << "please enter 2 intergers\n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> q2.x >> q2.y;
			while (std::cin.fail())
			{
				std::cout << "Error please reinput numbers.\n 2 Numbers should be inputed as intergers.\n";
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cin >> q2.x >> q2.y;
			}

			if (LineInter.doIntersect(p1, q1, p2, q2) == true)
			{
				std::cout << "The lines intersect\n";
			}
			else
			{
				std::cout << "The lines do not intersect\n";
			}

			break;

		case 3:
			std::cout << "input first coordinates x & y\n";
			std::cout << "please enter 2 intergers\n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> p1.x >> p1.y;
			while (std::cin.fail())
			{
				std::cout << "Error please reinput numbers.\n 2 Numbers should be inputed as intergers.\n";
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cin >> p1.x >> p1.y;
			}

			std::cout << "input second coordinates x & y\n";
			std::cout << "please enter 2 intergers\n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> p2.x >> p2.y;
			while (std::cin.fail())
			{
				std::cout << "Error please reinput numbers.\n 2 Numbers should be inputed as intergers.\n";
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cin >> p2.x >> p2.y;
			}

			std::cout << "input third coordinates x & y\n";
			std::cout << "please enter 2 intergers\n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> q1.x >> q1.y;
			while (std::cin.fail())
			{
				std::cout << "Error please reinput numbers.\n 2 Numbers should be inputed as intergers.\n";
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cin >> q1.x >> q1.y;
			}

			switch (LineInter.orientation(p1, p2, q1))
			{
			case 0:  //Colinear 
				std::cout << "The Coordinates are collinear\n";
				break; 
			case 1:  // clockwise
				std::cout << "The Coordinates are clockwise\n";
				break;
			case 2:  // counter-clockwise
				std::cout << "The Coordinates are counter-clockwise\n";
				break;
			}
			break;
		case 6:
			quit = true;

			break;
		default:
			break;
		}
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}

	return 0;
}

void clearScreen()
{
	std::cout << std::string(100, '\n');
}

void startCoordsInput(Point2D &startPoint, Rectangle &rec)
{
	std::cout << "Please input bottom left coords for rectangle.\n Please input 2 intergers x and y\n";
	std::cin.clear();
	std::cin.ignore(256, '\n');
	std::cin >> startPoint.x >> startPoint.y;
	while (std::cin.fail())
	{
		std::cout << "Error please reinput numbers.\n 2 Numbers should be inputed as intergers.\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> startPoint.x >> startPoint.y;
	}
	std::cout << "What is the length.\n";
	std::cin.clear();
	std::cin.ignore(256, '\n');
	std::cin >> rec.length;
	while (std::cin.fail() || rec.length < 1)
	{
		std::cout << "Input needs to be a interger and needs to be above 0.\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> rec.length;
	}
	std::cout << "What is the height.\n";
	std::cin.clear();
	std::cin.ignore(256, '\n');
	std::cin >> rec.height;
	while (std::cin.fail() || rec.height < 1)
	{
		std::cout << "Input needs to be a interger and needs to be above 0.\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> rec.height;
	}
}