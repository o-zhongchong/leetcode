class Singleton
{
public:
    virtual ~Singleton(){}
    
    int method()
    {
        std::cout<<"I'm unique object"<<std::endl;
        return 0;
    }
    
    static Singleton* getInstance()
    {
        if(instance == NULL)
        {
            instance = new Singleton();
        }
        
        return instance;
    }
    
protected:
    Singleton(){}
    static Singleton* instance;
};

Singleton* Singleton::instance = NULL;

int main(int argc, char** argv)
{
    Singleton* singleton = Singleton::getInstance();
    singleton->method();
    return 0;
}
