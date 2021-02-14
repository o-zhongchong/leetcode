class TreeType
{
public:
    TreeType(std::string name, std::string color)
    {
        this->name = name;
        this->color = color;
    }
    
    virtual ~TreeType(){}
    std::string name;
    std::string color;
};

class Tree
{
public:
    Tree(int x, int y, TreeType* type)
    {
        this->x = x;
        this->y = y;
        this->type = type;
    }
    
    virtual ~Tree(){}
    int x;
    int y;
    TreeType* type;
};

class Forest
{
public:
    Forest(){}
    
    virtual ~Forest(){}
    
    int plantTree(int x, int y, TreeType* type)
    {
        trees.push_back(Tree(x, y, type));
        return 0;
    }
    
    int draw()
    {
        int len = trees.size();
        
        for(int i=0; i<len; ++i)
        {
            std::cout<<trees[i].x<<" "<<trees[i].y<<" ";
            std::cout<<trees[i].type->name<<" "<<trees[i].type->color<<std::endl;
        }
        
        return 0;
    }
    
    std::vector<Tree> trees;
};

int main(int argc, char** argv)
{
    Forest* forest = new Forest();
    TreeType* ning_tiao = new TreeType("柠条", "绿色");
    TreeType* zhang_zi_song = new TreeType("樟子松", "绿色");
    forest->plantTree(5, 5, ning_tiao);
    forest->plantTree(0, 1, zhang_zi_song);
    forest->draw();
    delete ning_tiao;
    delete zhang_zi_song;
    delete forest;
    return 0;
}