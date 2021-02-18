class Command
{
public:
    Command(){}
    virtual ~Command(){}
    virtual int execute() = 0;
};

class Button
{
public:
    Button(Command* cmd){this->command = cmd;}
    virtual ~Button(){}
    
    int onClick()
    {
        command->execute();
        return 0;
    }
protected:
    Command* command;
};

class Shortcut
{
public:
    Shortcut(Command* cmd){this->command = cmd;}
    virtual ~Shortcut(){}
    
    int onClick()
    {
        command->execute();
        return 0;
    }
protected:
    Command* command;
};

class OpenCommand: public Command
{
public:
    OpenCommand(){}
    virtual ~OpenCommand(){}
    
    virtual int execute()
    {
        std::cout<<"execute open command"<<std::endl;
        return 0;
    }
};

int main(int argc, char** argv)
{
    Command* cmd = new OpenCommand();
    Button* btn = new Button(cmd);
    Shortcut* shortcut = new Shortcut(cmd);
    btn->onClick();
    shortcut->onClick();
    delete btn;
    delete shortcut;
    delete cmd;
    return 0;
}