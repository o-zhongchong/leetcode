class Shape
{
public:
    Shape(){}
    virtual ~Shape(){}
    
    virtual Shape* clone()
    {
        return new Shape();
    }
    
    virtual int draw() const
    {
        return 0;
    }
};

class Rectangle: public Shape
{
public:
    Rectangle(int x, int y):width(x),height(y){}
    virtual ~Rectangle(){}
    
    int draw() const
    {
        std::cout<<"Rectangle: x="<<width<<" y="<<height<<std::endl;
        return 0;
    }
    
    Shape* clone()
    {
        Rectangle* rectangle = new Rectangle(this->width, this->height);
        return rectangle;
    }
    
protected:
    int width;
    int height;
};

class Circle: public Shape
{
public:
    Circle(int x):radius(x){}
    virtual ~Circle(){}
    
    int draw() const
    {
        std::cout<<"Circle: radius="<<radius<<std::endl;
        return 0;
    }
    
    Shape* clone()
    {
        Circle* circle = new Circle(this->radius);
        return circle;
    }
    
protected:
    int radius;
};

int main(int argc, char** argv)
{
    Shape* shape1 = new Circle(5);
    Shape* shape2 = shape1->clone();
    shape2->draw();
    delete shape1;
    delete shape2;
    return 0;
}
