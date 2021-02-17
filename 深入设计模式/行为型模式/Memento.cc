class Snapshot
{
public:
    Snapshot(int state){this->state = state;}
    virtual ~Snapshot(){}
    
    int getState()
    {
        return this->state;
    }
    
protected:
    int state;
};

class Editor
{
public:
    Editor(){}
    virtual ~Editor(){}
    
    int setState(int val)
    {
        this->state = val;
        return 0;
    }
    
    int getState()
    {
        return this->state;
    }
    
    int restore(Snapshot* snapshot)
    {
        this->state = snapshot->getState();
        return 0;
    }
    
    Snapshot* createSnapshot()
    {
        return new Snapshot(this->state);
    }
    
protected:
    int state;
};

class CareTaker
{
public:
    CareTaker(Editor* editor){this->editor = editor;}
    virtual ~CareTaker()
    {
        while(!snapshots.empty())
        {
            delete snapshots.top();
            snapshots.pop();
        }
    }
    
    int backup()
    {
        snapshots.push(editor->createSnapshot());
        return 0;
    }
    
    int restore()
    {
        if(snapshots.empty())
        {
            return 1;
        }
        
        Snapshot* current = snapshots.top();
        snapshots.pop();
        editor->restore(current);
        delete current;
        return 0;
    }
    
protected:
    stack<Snapshot*> snapshots;
    Editor* editor;
};

int main(int argc, char** argv)
{
    Editor* editor = new Editor();
    CareTaker* careTaker = new CareTaker(editor);
    
    editor->setState(0);
    careTaker->backup();
    editor->setState(1);
    careTaker->backup();
    editor->setState(2);
    
    careTaker->restore();
    careTaker->restore();
    
    std::cout<<editor->getState()<<std::endl;
    
    delete careTaker;
    delete editor;
    
    return 0;
}

