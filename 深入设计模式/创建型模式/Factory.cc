class ProductA
{
public:
    ProductA(){}
    virtual ~ProductA(){}
};

class ProductB
{
public:
    ProductB(){}
    virtual ~ProductB(){}
};

class ProductA1: public ProductA
{
public:
    ProductA1(){std::cout<<"create ProductA1 success"<<std::endl;}
    virtual ~ProductA1(){}
};

class ProductA2: public ProductA
{
public:
    ProductA2(){std::cout<<"create ProductA2 success"<<std::endl;}
    virtual ~ProductA2(){}
};

class ProductB1: public ProductB
{
public:
    ProductB1(){std::cout<<"create ProductB1 success"<<std::endl;}
    virtual ~ProductB1(){}
};

class ProductB2: public ProductB
{
public:
    ProductB2(){std::cout<<"create ProductB2 success"<<std::endl;}
    virtual ~ProductB2(){}
};

class Factory
{
public:
    Factory(){}
    virtual ~Factory(){}
    virtual ProductA* createProductA() = 0;
    virtual ProductB* createProductB() = 0;
};

class Factory1: public Factory
{
public:
    Factory1(){}
    virtual ~Factory1(){}
    ProductA* createProductA(){return new ProductA1();}
    ProductB* createProductB(){return new ProductB2();}
};

class Factory2: public Factory
{
public:
    Factory2(){}
    virtual ~Factory2(){}
    ProductA* createProductA(){return new ProductA2();}
    ProductB* createProductB(){return new ProductB1();}
};

int main(int argc, char** argv)
{
    Factory* factory = new Factory1();
    ProductA* product1 = factory->createProductA();
    ProductB* product2 = factory->createProductB();
    delete factory;
    delete product1;
    delete product2;
    return 0;
}