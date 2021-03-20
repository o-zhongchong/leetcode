class Record
{
public:
    Record(){}
    int id;
    string startStation;
    string endStation;
    int startTime;
    int endTime;
};

class UndergroundSystem {
public:
    UndergroundSystem(){}
    
    void checkIn(int id, string stationName, int t) 
    {
        if(!onTraval.count(id))
        {
            Record* record = new Record();
            record->id = id;
            record->startStation = stationName;
            record->startTime = t;
            onTraval[id] = record;
        }
    }
    
    void checkOut(int id, string stationName, int t) 
    {
        if(onTraval.count(id))
        {
            Record* record = onTraval[id];
            record->endStation = stationName;
            record->endTime = t;
            
            if(record->endTime >= record->startTime)
            {
                string traval = record->startStation + "-" + record->endStation;
                
                if(travalTime.count(traval))
                {
                    travalTime[traval].push_back(record->endTime  - record->startTime);
                }
                else
                {
                    travalTime[traval] = vector<int>{record->endTime  - record->startTime};
                }
            }
            
            onTraval.erase(id);
            delete record;
        }
    }
    
    double getAverageTime(string startStation, string endStation) 
    {
        string traval = startStation + "-" + endStation;
        
        if(travalTime.count(traval))
        {
            vector<int> timeRecord = travalTime[traval];
            int len = timeRecord.size();
            int sum = 0;
            
            for(int i=0; i<len; ++i)
            {
                sum += timeRecord[i];
            }
            
            return (double)sum / (double)len;
        }
        
        return 0.0;
    }
    
protected:
    unordered_map<int, Record*> onTraval;
    unordered_map<string, vector<int>> travalTime;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */