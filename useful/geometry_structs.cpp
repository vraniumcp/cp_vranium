struct Rect{
    int x1,x2,y1,y2; // lower left and upper right corners
    int area(){
        return (x2-x1)*(y2-y1);
    }
};

int interection(Rect a, Rect b){
    int x_intersection = max(0,min(a.x2,b.x2) - max(a.x1,b.x1));
    int y_intersection = max(0,min(a.y2,b.y2) - max(a.y1,b.y1));
    return x_intersection*y_intersection;
}