class Iterator
{
public:
    Iterator(){}
    virtual ~Iterator(){}
    virtual char getCurrentElement() = 0;
    virtual int getNext() = 0;
    virtual bool hasMore() = 0;
};

class Container
{
public:
    Container(){}
    virtual ~Container(){}
    virtual Iterator* createIterator() = 0;
};

class ArrayIterator: public Iterator
{
public:
    ArrayIterator(char* element, int length)
    {
        this->element = element;
        this->length = length;
        pos = length - 1;
    }
    
    virtual ~ArrayIterator(){}
    
    virtual char getCurrentElement()
    {
        if(pos >=0 && pos < length)
        {
            return *(element + pos);
        }
        
        return '\0';
    }
    
    virtual int getNext()
    {
        if(pos >=0 && pos < length)
        {
            --pos;
            return 0;
        }
        
        return -1;
    }
    
    virtual bool hasMore()
    {
        if(pos >=0 && pos < length)
        {
            return true;
        }
        
        return false;
    }
    
protected:
    char* element;
    int length;
    int pos;
};

class Array: public Container
{
public:
    Array()
    {
        data = new char[1];
        *data = '\0';
        len = 0;
        free = 0;
    }
    
    virtual ~Array(){delete data;}
    
    int push_back(const char* str, int length)
    {
        if(free < length)
        {
            int total = (len + length) * 2;
            char* new_data = new char[total + 1];
            
            for(int i=0; i<len; ++i)
            {
                new_data[i] = data[i];
            }
            
            new_data[len] = '\0';
            delete data;
            data = new_data;
            free = total - len;
        }
        
        for(int i=0; i<length; ++i)
        {
            data[len+i] = str[i];
        }
        
        len += length;
        free -= length;
        data[len] = '\0';
        
        return 0;
    }
    
    virtual Iterator* createIterator()
    {
        return new ArrayIterator(data, len);
    }
    
protected:
    char* data;
    int len;
    int free;
};

int main(int argc, char** argv)
{
    Array* array = new Array();
    array->push_back("abcdef", 6);
    
    Iterator* it = array->createIterator();
    
    while(it->hasMore())
    {
        std::cout<<it->getCurrentElement();
        it->getNext();
    }
    
    std::cout<<std::endl;
    delete array;
    delete it;
    return 0;
}