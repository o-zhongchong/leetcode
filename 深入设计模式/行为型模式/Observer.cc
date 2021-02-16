class Subscriber
{
public:
    Subscriber(){}
    virtual ~Subscriber(){}
    
    int update()
    {
        std::cout<<"get notify success"<<std::endl;
        return 0;
    }
};

class Publisher
{
public:
    Publisher(){}
    virtual ~Publisher(){}
    
    int addSubscriber(Subscriber* subscriber)
    {
        subscribers.push_back(subscriber);
        return 0;
    }
    
    int removeSubscriber(Subscriber* subscriber)
    {
        int len = (int)subscribers.size();
        
        for(int i=0; i<len; ++i)
        {
            if(subscribers[i] == subscriber)
            {
                subscribers.erase(subscribers.begin() + i);
                --i;
                --len;
            }
        }
        
        return 0;
    }
    
    int notifySubscriber()
    {
        int len = (int)subscribers.size();
        
        for(int i=0; i<len; ++i)
        {
            subscribers[i]->update();
        }
        
        return 0;
    }
    
protected:
    vector<Subscriber*> subscribers;
};

int main(int argc, char** argv)
{
    Publisher* publisher = new Publisher();
    Subscriber* subscriber1 = new Subscriber();
    Subscriber* subscriber2 = new Subscriber();
    publisher->addSubscriber(subscriber1);
    publisher->addSubscriber(subscriber2);
    publisher->notifySubscriber();
    publisher->removeSubscriber(subscriber1);
    publisher->removeSubscriber(subscriber2);
    delete subscriber1;
    delete subscriber2;
    delete publisher;
    return 0;
}