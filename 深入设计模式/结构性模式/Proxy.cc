class Service
{
public:
    Service(){}
    virtual ~Service(){}
    virtual int operation() const = 0;
};

class RealService : public Service
{
public:
    RealService(){}
    virtual ~RealService(){}
    int operation() const
    {
        std::cout<<"RealService: Handling request."<<std::endl;
        return 0;
    }
};

class ProxyService : public Service
{
public:
    ProxyService(){service = new RealService();}
    virtual ~ProxyService(){delete service;}
    
    int operation() const
    {
        std::cout<<"Proxy: Checking a real request."<<std::endl;
        service->operation();
        std::cout<<"Proxy: Logging the detail of request."<<std::endl;
        return 0;
    }
protected:
    Service* service;
};

int main(int argc, char** argv)
{
    Service* proxy = new ProxyService();
    proxy->operation();
    delete proxy;
    return 0;
}