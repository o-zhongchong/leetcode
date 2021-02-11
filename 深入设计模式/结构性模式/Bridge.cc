class Color
{
public:
    Color(){}
    virtual ~Color(){}
    virtual int filling() const = 0;
};

class Red: public Color
{
public:
    Red(){}
    virtual ~Red(){}
    
    int filling() const
    {
        std::cout<<"Filling red color success"<<std::endl;
        return 0;
    }
};

class Blue: public Color
{
public:
    Blue(){}
    virtual ~Blue(){}
    
    int filling() const
    {
        std::cout<<"Filling blue color success"<<std::endl;
        return 0;
    }
};

class Shape
{
public:
    Shape(){}
    virtual ~Shape(){}
    virtual int draw() const = 0;
protected:
    Color* color;
};

class Circle: public Shape
{
public:
    Circle(Color* color = NULL){this->color = color;}
    virtual ~Circle(){}
    
    int draw() const
    {
        std::cout<<"Draw a circle success"<<std::endl;
        
        if(this->color != NULL)
        {
            this->color->filling();
        }
        
        return 0;
    }
};

class Square: public Shape
{
public:
    Square(Color* color = NULL){this->color = color;}
    virtual ~Square(){}
    
    int draw() const
    {
        std::cout<<"Draw a square success"<<std::endl;
        
        if(this->color != NULL)
        {
            this->color->filling();
        }
        
        return 0;
    }
};

int main(int argc, char** argv)
{
    Color* color = new Blue();
    Shape* shape = new Square(color);
    shape->draw();
    delete color;
    delete shape;
    return 0;
}
