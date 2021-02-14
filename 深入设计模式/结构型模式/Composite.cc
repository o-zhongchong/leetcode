class Goods
{
public:
    Goods(){}
    virtual ~Goods(){}
    virtual int getPrice() const = 0;
};

class Product: public Goods
{
public:
    Product(int price){this->price = price;}
    virtual ~Product(){}
    
    int getPrice() const
    {
        return price;
    }
    
protected:
    int price;
};

class Box: public Goods
{
public:
    Box(){}
    virtual ~Box(){}
    
    int addProduct(Product* product)
    {
        products.push_back(product);
        return 0;
    }
    
    int addBox(Box* box)
    {
        boxes.push_back(box);
        return 0;
    }
    
    int getPrice() const
    {
        int sum = 0;
        
        for(int i=0; i<(int)products.size(); ++i)
        {
            sum += products[i]->getPrice();
        }
        
        for(int i=0; i<(int)boxes.size(); ++i)
        {
            sum += boxes[i]->getPrice();
        }
        
        return sum;
    }
    
protected:
    vector<Product*> products;
    vector<Box*> boxes;
};

int main(int argc, char** argv)
{
    Product* product1 = new Product(10);
    Product* product2 = new Product(20);
    Product* product3 = new Product(30);
    Box* small_box = new Box();
    Box* medium_box = new Box();
    Box* large_box = new Box();
    
    small_box->addProduct(product1);
    medium_box->addProduct(product2);
    large_box->addProduct(product3);
    large_box->addBox(small_box);
    large_box->addBox(medium_box);
    
    int price = large_box->getPrice();
    std::cout<<"total price is: "<<price<<std::endl;
    return 0;
}