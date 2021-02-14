class Circle;
class Rectangle;

class Visitor
{
public:
    Visitor(){}
    virtual ~Visitor(){}
    virtual int visitCircle(Circle* circle) = 0;
    virtual int visitRectangle(Rectangle* rectangle) = 0;
};

class Shape
{
public:
    Shape(){}
    virtual ~Shape(){}
    virtual int accept(Visitor* visitor) = 0;
};

class Circle: public Shape
{
public:
    Circle(){}
    virtual ~Circle(){}
    
    virtual int accept(Visitor* visitor)
    {
        visitor->visitCircle(this);
        return 0;
    }
};

class Rectangle: public Shape
{
public:
    Rectangle(){}
    virtual ~Rectangle(){}
    
    virtual int accept(Visitor* visitor)
    {
        visitor->visitRectangle(this);
        return 0;
    }
};

class XMLExportVisitor: public Visitor
{
public:
    XMLExportVisitor(){}
    virtual ~XMLExportVisitor(){}
    
    virtual int visitCircle(Circle* circle)
    {
        std::cout<<"Export circle to xml file"<<std::endl;
        return 0;
    }
    
    virtual int visitRectangle(Rectangle* rectangle)
    {
        std::cout<<"Export rectangle to xml file"<<std::endl;
        return 0;
    }
};

int main(int argc, char** argv)
{
    Visitor* visitor = new XMLExportVisitor();
    Shape* shape = new Circle();
    shape->accept(visitor);
    delete shape;
    delete visitor;
    return 0;
}
