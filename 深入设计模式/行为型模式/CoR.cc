class Handler
{
public:
    Handler(){next = NULL;}
    virtual ~Handler(){}
    
    int setNext(Handler* handler)
    {
        next = handler;
        return 0;
    }
    
    virtual int handle() = 0;
    
protected:
    Handler* next;
};

class AuthHandler: public Handler
{
public:
    AuthHandler(){}
    virtual ~AuthHandler(){}
    
    virtual int handle()
    {
        std::cout<<"step1: user authentication"<<std::endl;
        
        if(next != NULL)
        {
            next->handle();
        }
        
        return 0;
    }
};

class VerifyRequest: public Handler
{
public:
    VerifyRequest(){}
    virtual ~VerifyRequest(){}
    
    virtual int handle()
    {
        std::cout<<"step2: verifying the validity of request data"<<std::endl;
        
        if(next != NULL)
        {
            next->handle();
        }
        
        return 0;
    }
};

class HandleRequest: public Handler
{
public:
    HandleRequest(){}
    virtual ~HandleRequest(){}
    
    virtual int handle()
    {
        std::cout<<"step3: handling request finally"<<std::endl;
        
        if(next != NULL)
        {
            next->handle();
        }
        
        return 0;
    }
};

int main(int argc, char** argv)
{
    Handler* handler1 = new AuthHandler();
    Handler* handler2 = new VerifyRequest();
    Handler* handler3 = new HandleRequest();
    handler1->setNext(handler2);
    handler2->setNext(handler3);
    handler1->handle();
    delete handler1;
    delete handler2;
    delete handler3;
    return 0;
}