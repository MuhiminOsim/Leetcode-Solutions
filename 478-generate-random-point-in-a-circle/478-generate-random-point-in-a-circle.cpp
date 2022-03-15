class Solution {
public:
    double radius, x_center, y_center;
    
    Solution(double _radius, double _x_center, double _y_center) {
        radius = _radius;
        x_center = _x_center;
        y_center = _y_center;
    }
    
    vector<double> randPoint() {
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> dis(0.0, 1.0);
        double length = sqrt(dis(gen)) * radius;
        double angle = dis(gen) * 2 * M_PI;
        double x = x_center + length * cos(angle);
        double y = y_center + length * sin(angle);
        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */