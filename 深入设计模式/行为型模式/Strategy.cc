class RouteStrategy
{
public:
    RouteStrategy(){}
    virtual ~RouteStrategy(){}
    virtual int buildRoute() = 0;
};

class Navigator
{
public:
    Navigator(RouteStrategy* route_strategy)
    {
        this->route_strategy = route_strategy;
    }
    
    virtual ~Navigator(){}
    
    int buildRoute()
    {
        return route_strategy->buildRoute();
    }
    
protected:
    RouteStrategy* route_strategy;
};

class RoadStrategy: public RouteStrategy
{
public:
    RoadStrategy(){}
    virtual ~RoadStrategy(){}
    
    virtual int buildRoute()
    {
        std::cout<<"build road route"<<std::endl;
        return 0;
    }
};

class WalkingStrategy: public RouteStrategy
{
public:
    WalkingStrategy(){}
    virtual ~WalkingStrategy(){}
    
    virtual int buildRoute()
    {
        std::cout<<"build walking route"<<std::endl;
        return 0;
    }
};

class PublicTransportStrategy: public RouteStrategy
{
public:
    PublicTransportStrategy(){}
    virtual ~PublicTransportStrategy(){}
    
    virtual int buildRoute()
    {
        std::cout<<"build public transport route"<<std::endl;
        return 0;
    }
};

int main(int argc, char** argv)
{
    RouteStrategy* strategy = new WalkingStrategy();
    Navigator* navigator = new Navigator(strategy);
    navigator->buildRoute();
    delete strategy;
    delete navigator;
    return 0;
}
