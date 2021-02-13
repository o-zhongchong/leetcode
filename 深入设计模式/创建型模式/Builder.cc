class Builder
{
public:
    Builder(){}
    virtual ~Builder(){}
    virtual int buildWalls() = 0;
    virtual int buildDoors() = 0;
    virtual int buildWindows() = 0;
    virtual int buildRoof() = 0;
};

class HouseBuilder: public Builder
{
public:
    HouseBuilder(){}
    virtual ~HouseBuilder(){}
    int buildWalls(){std::cout<<"build walls"<<std::endl;return 0;}
    int buildDoors(){std::cout<<"build doors"<<std::endl;return 0;}
    int buildWindows(){std::cout<<"build windows"<<std::endl;return 0;}
    int buildRoof(){std::cout<<"build roof"<<std::endl;return 0;}
};

int main(int argc, char** argv)
{
    HouseBuilder* builder = new HouseBuilder();
    builder->buildWalls();
    builder->buildDoors();
    builder->buildWindows();
    builder->buildRoof();
    return 0;
}