class DataMiner
{
public:
    DataMiner(){}
    virtual ~DataMiner(){}
    
    virtual int openFile()
    {
        std::cout<<"open file success"<<std::endl;
        return 0;
    }
    
    virtual int extractData() = 0;
    virtual int parseData() = 0;
    
    virtual int analyzeData()
    {
        std::cout<<"analyze data success"<<std::endl;
        return 0;
    }
    
    virtual int sendReport()
    {
        std::cout<<"send report success"<<std::endl;
        return 0;
    }
};

class PDFDataMiner: public DataMiner
{
public:
    PDFDataMiner(){}
    virtual ~PDFDataMiner(){}
    
    virtual int extractData()
    {
        std::cout<<"extra data success"<<std::endl;
        return 0;
    }
    
    virtual int parseData()
    {
        std::cout<<"parse data success"<<std::endl;
        return 0;
    }
};

int main(int argc, char** argv)
{
    DataMiner* dataMiner = new PDFDataMiner();
    dataMiner->openFile();
    dataMiner->extractData();
    dataMiner->parseData();
    dataMiner->analyzeData();
    dataMiner->sendReport();
    delete dataMiner;
    return 0;
}
