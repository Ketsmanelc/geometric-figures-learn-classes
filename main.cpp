#include <iostream>
#include <cmath>
#include <cassert>
class Figure
{
    enum Colors
    {
        NONE,
        RED,
        BLUE,
        GREEN
    };
    double center_x = 0;
    double center_y = 0;
    int color = NONE;

public:
    const double PI = 3.141592653589793;
    const double delta = 1.0;
    struct Edges
    {
        double height = 0;
        double weight = 0;
    };
    Edges circumscribedRectangle;
    void setCenter(double in_x,double in_y)
    {
        center_x = in_x;
        center_y = in_y;
    }
    void setColor (int inNumCol)
    {
        assert(inNumCol <= 3);
        color = inNumCol;
    }
};

class Circle: public Figure
{
    double radius = 0;
public:
    void setRadius(double value)
    {
        radius = value;
    }
    double getArea()
    {
        return (PI * radius * radius);
    };

    void getRectangle()
    {
        circumscribedRectangle.height = radius + delta;
        circumscribedRectangle.weight = radius + delta;
    }
};

class Square: public Figure
{
    double edgeLength = 0;
public:
    void setEdgeLength(double value)
    {
        edgeLength = value;
    }
    double getArea()
    {
        return (edgeLength * edgeLength);
    }
    void getRectangle()
    {
        circumscribedRectangle.height = edgeLength + delta;
        circumscribedRectangle.weight = edgeLength + delta;
    }
};

class Triangle: public Figure
{
    double edgeLength = 0;
public:
    void setEdgeLength(double value)
    {
        edgeLength = value;
    }
    double getArea()
    {
        return (sqrt(3.0)/4.0 * edgeLength * edgeLength);
    }
    void getRectangle()
    {
        circumscribedRectangle.weight = edgeLength + delta;
        circumscribedRectangle.height = sqrt(3.0) * edgeLength / 2 + delta;
    }

};

class Rectangle: public Figure
{
    double edgeHeight;
    double edgeWeight;
public:
    void setEdgesLength (double valueHeight, double valueWeight)
    {
        edgeHeight = valueHeight;
        edgeWeight = valueWeight;
    }
    double getArea()
    {
        return (edgeHeight * edgeWeight);
    }
    void getRectangle()
    {
        circumscribedRectangle.height = edgeHeight + delta;
        circumscribedRectangle.weight = edgeWeight + delta;
    }
};


int main() {
    Circle* circle = new Circle;
    Triangle* triangle = new Triangle;
    Square* square = new Square;
    Rectangle* rectangle = new Rectangle;
    std::string figure;
    std::cout << "Choose figure: ";
    std::cin >> figure;
    std::cout << "Enter center coordinates: ";
    double x, y;
    std::cin >> x >> y;
    std::cout << "Enter figures color: ";
    int color = 0;
    std::cin >> color;
    if (figure == "circle")
    {
         circle->setCenter(x, y);
         circle->setColor(color);
         std::cout << "Enter radius: ";
         double radius;
         std::cin >> radius;
         circle->setRadius(radius);
         std::cout << "Figure area: " << circle->getArea() << std::endl;
         circle->getRectangle();
         std::cout << "Circumscribed rectangle: " << circle->circumscribedRectangle.height << " " << circle->circumscribedRectangle.weight << std::endl;;
    }else if (figure == "triangle")
    {
        triangle->setCenter(x, y);
        triangle->setColor(color);
        std::cout << "Enter edge length: ";
        double edge;
        std::cin >> edge;
        triangle->setEdgeLength(edge);
        std::cout << "Figure area: " << triangle->getArea() << std::endl;;
        triangle->getRectangle();
        std::cout << "Circumscribed rectangle: " << triangle->circumscribedRectangle.height << " " << triangle->circumscribedRectangle.weight << std::endl;;
    }else if (figure == "square")
    {
        square->setCenter(x, y);
        square->setColor(color);
        std::cout << "Enter edge length: ";
        double edge;
        std::cin >> edge;
        square->setEdgeLength(edge);
        std::cout << "Figure area: " << square->getArea() << std::endl;;
        square->getRectangle();
        std::cout << "Circumscribed rectangle: " << square->circumscribedRectangle.height << " " << square->circumscribedRectangle.weight << std::endl;;
    }else if (figure == "rectangle")
    {
        rectangle->setCenter(x, y);
        rectangle->setColor(color);
        std::cout << "Enter height: ";
        double height;
        std::cin >> height;
        std::cout << "Enter weight: ";
        double weight;
        std::cin >> weight;
        rectangle->setEdgesLength(height, weight);
        std::cout << "Figure area: " << rectangle->getArea() << std::endl;;
        rectangle->getRectangle();
        std::cout << "Circumscribed rectangle: " << rectangle->circumscribedRectangle.height << " " << rectangle->circumscribedRectangle.weight << std::endl;;
    }


    return 0;
}
