class SubSystem1
{
public:
    SubSystem1(){}
    virtual ~SubSystem1(){}
    int operation1() const {std::cout<<"Subsystem1 Ready"<<std::endl; return 0;}
};

class SubSystem2
{
public:
    SubSystem2(){}
    virtual ~SubSystem2(){}
    int operation1() const {std::cout<<"Subsystem2 Ready"<<std::endl; return 0;}
};

class Facade
{
public:
    Facade()
    {
        sub_system1 = NULL;
        sub_system2 = NULL;
    }
    
    virtual ~Facade()
    {
        delete sub_system1;
        delete sub_system2;
    }
    
    int operation()
    {
        if(sub_system1 == NULL)
        {
            sub_system1 = new SubSystem1();
        }
        
        if(sub_system2 == NULL)
        {
            sub_system2 = new SubSystem2();
        }
        
        sub_system1->operation1();
        sub_system2->operation1();
        
        return 0;
    }
protected:
    SubSystem1* sub_system1;
    SubSystem2* sub_system2;
};

int main(int argc, char** argv)
{
    Facade* facade = new Facade();
    facade->operation();
    delete facade;
    return 0;
}
