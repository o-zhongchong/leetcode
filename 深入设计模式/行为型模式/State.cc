class State
{
public:
    State(){}
    virtual ~State(){}
    virtual int render() = 0;
    virtual int publish() = 0;
};

class Draft: public State
{
public:
    Draft(){}
    virtual ~Draft(){}
    
    virtual int render()
    {
        return 0;
    }
    
    virtual int publish()
    {
        std::cout<<"draft state, change state to moderation"<<std::endl;
        return 0;
    }
};

class Moderation: public State
{
public:
    Moderation(){}
    virtual ~Moderation(){}
    
    virtual int render()
    {
        std::cout<<"moderation state, change state to draft"<<std::endl;
        return 0;
    }
    
    virtual int publish()
    {
        std::cout<<"moderation state, change state to published"<<std::endl;
        return 0;
    }
};

class Published: public State
{
public:
    Published(){}
    virtual ~Published(){}
    
    virtual int render()
    {
        std::cout<<"published state, change state to draft"<<std::endl;
        return 0;
    }
    
    virtual int publish()
    {
        std::cout<<"published state, state change finished"<<std::endl;
        return 0;
    }
};

class Document
{
public:
    Document(){}
    virtual ~Document(){}
    
    int render()
    {
        return state->render();
    }
    
    int publish()
    {
        return state->publish();
    }
    
    int changeState(State* state)
    {
        this->state = state;
        return 0;
    }
    
protected:
    State* state;
};

int main(int argc, char** argv)
{
    Document* doc = new Document();
    State* state1 = new Draft();
    State* state2 = new Moderation();
    State* state3 = new Published();
    doc->changeState(state1);
    doc->publish();
    doc->changeState(state2);
    doc->publish();
    doc->changeState(state3);
    doc->publish();
    delete doc;
    delete state1;
    delete state2;
    delete state3;
    return 0;
}

