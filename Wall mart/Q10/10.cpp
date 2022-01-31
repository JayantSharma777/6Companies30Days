#define PI 3.141592653589
class Solution {
public:
    double circle_radius=0;
    double circle_x=0;
    double circle_y=0;
    
    Solution(double radius, double x_center, double y_center) {
        circle_radius=radius;
        circle_x=x_center;
        circle_y=y_center;
    }
//     length,theta
    double uniform()
    {
        return (double)rand()/RAND_MAX;
    }
    
    vector<double> randPoint() {
        double uni=uniform();
        double theta=2*PI*uni;
        double dist=sqrt(uniform());
        double x_p=circle_x+dist*circle_radius*cos(theta);
        double y_p=circle_y+dist*circle_radius*sin(theta);
        return {x_p,y_p};
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
