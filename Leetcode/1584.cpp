class Edge
{
public:
    Edge(int i, int j, int dist):x(i),y(j),distance(dist){};
    bool operator < (const Edge& edge) const
    {
        return this->distance < edge.distance;
    }
    
    int distance;
    int x,y;
};

int find(int* ds, int x)
{
    return ds[x] == x ? x : ds[x] = find(ds, ds[x]);
}

int merge(int* ds, int x, int y)
{
    int fx = find(ds, x);
    int fy = find(ds, y);
    
    if(fx != fy)
    {
        ds[fx] = fy;
        return 1;
    }
    
    return 0;
}

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Edge> myedge;
        int* ds = new int[n];
        int min_cost = 0;
        
        for(int i=0; i<n; ++i)
        {
            ds[i] = i;
        }
        
        for(int i=0; i<n; ++i)
        {
            for(int j=1; j<n; ++j)
            {
                
                if(i < j)
                {
                    int dist = abs(points[i][0]-points[j][0]) 
                        + abs(points[i][1]-points[j][1]);
                    myedge.push_back(Edge(i,j,dist));
                }
            }
        }
        
        sort(myedge.begin(), myedge.end());
        
        for(auto e : myedge)
        {
            if(merge(ds, e.x, e.y))
            {
                min_cost += e.distance;
            }
        }
        
        return min_cost;
    }
};