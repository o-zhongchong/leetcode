class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x = x_center;
        this->y = y_center;
        srand(time(0));
    }
    
    vector<double> randPoint() {
        double theta = 2 * M_PI * ((double)rand() / RAND_MAX);
        double len = sqrt((double)rand() / RAND_MAX) * radius;
        return {x + len * cos(theta), y + len * sin(theta)};
    }
    
protected:
    double radius;
    double x;
    double y;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */