class Component;

class Controller
{
public:
    Controller(){}
    virtual ~Controller(){}
    virtual int notify(Component* sender, std::string event) = 0;
};

class Component
{
public:
    Component(Controller* controller){this->controller = controller;}
    virtual ~Component(){}
protected:
    Controller* controller;
};

class Button: public Component
{
public:
    Button(Controller* controller):Component(controller){}
    virtual ~Button(){}
    
    int click()
    {
        controller->notify(this, "sender click message");
        return 0;
    }
};

class TextFiled: public Component
{
public:
    TextFiled(Controller* controller):Component(controller){}
    virtual ~TextFiled(){}
    
    int draw()
    {
        std::cout<<text<<std::endl;
        return 0;
    }
    
    int setText(std::string text)
    {
        this->text = text;
        return 0;
    }
    
protected:
    std::string text;
};

class Dialog: public Controller
{
public:
    Dialog()
    {
        button = new Button(this);
        textFiled = new TextFiled(this);
    }
    
    virtual ~Dialog()
    {
        delete button;
        delete textFiled;
    }
    
    virtual int notify(Component* sender, std::string event)
    {
        if(sender == button)
        {
            std::cout<<event<<std::endl;
            textFiled->setText("get click message");
        }
        
        return 0;
    }
    
    Button* getButton()
    {
        return button;
    }
    
    TextFiled* getTextFiled()
    {
        return textFiled;
    }
    
protected:
    Button* button;
    TextFiled* textFiled;
};

int main(int argc, char** argv)
{
    Dialog* dialog = new Dialog();
    dialog->getButton()->click();
    dialog->getTextFiled()->draw();
    delete dialog;
    return 0;
}
