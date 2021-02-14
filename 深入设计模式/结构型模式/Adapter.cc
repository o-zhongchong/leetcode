class Service
{
public:
    Service(){}
    virtual ~Service(){}
    
    int serviceMethod() const
    {
        std::cout<<"real service work"<<std::endl;
        return 0;
    }
};

class ServiceAdapter
{
public:
    ServiceAdapter(){service = new Service();}
    virtual ~ServiceAdapter(){delete service;}
    
    int adapterMethod() const
    {
        std::cout<<"invoke adapterMethod success"<<std::endl;
        service->serviceMethod();
        return 0;
    }
    
protected:
    Service* service;
};

int main(int argc, char** argv)
{
    ServiceAdapter* adapter = new ServiceAdapter();
    adapter->adapterMethod();
    delete adapter;
    return 0;
}