class Notifier
{
public:
    Notifier(){}
    virtual ~Notifier(){}
    
    virtual int sendMsg(std::string msg) const
    {
        std::cout<<"Send Message Success"<<std::endl;
        return 0;
    }
};

class SmsDecorator : public Notifier
{
public:
    SmsDecorator(Notifier* notifier)
    {
        this->notifier = notifier;
    }
    
    virtual ~SmsDecorator(){}
    
    int sendMsg(std::string msg) const
    {
        std::cout<<"[SMS] "<<msg<<std::endl;
        notifier->sendMsg(msg);
        return 0;
    }
    
protected:
    Notifier* notifier;
};

class WxDecorator : public Notifier
{
public:
    WxDecorator(Notifier* notifier)
    {
        this->notifier = notifier;
    }
    
    virtual ~WxDecorator(){}
    
    int sendMsg(std::string msg) const
    {
        std::cout<<"[WX] "<<msg<<std::endl;
        notifier->sendMsg(msg);
        return 0;
    }
    
protected:
    Notifier* notifier;
};

class MailDecorator : public Notifier
{
public:
    MailDecorator(Notifier* notifier)
    {
        this->notifier = notifier;
    }
    
    virtual ~MailDecorator(){}
    
    int sendMsg(std::string msg) const
    {
        std::cout<<"[MAIL] "<<msg<<std::endl;
        notifier->sendMsg(msg);
        return 0;
    }
    
protected:
    Notifier* notifier;
};

int main()
{
    Notifier* notifier1 = new Notifier();
    Notifier* notifier2 = new SmsDecorator(notifier1);
    Notifier* notifier3 = new WxDecorator(notifier2);
    Notifier* notifier4 = new MailDecorator(notifier3);
    notifier4->sendMsg("hello world");
    return 0;
}