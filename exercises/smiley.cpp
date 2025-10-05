#include "Simple_window.h"
#include "Graph.h"
using namespace Graph_lib;

// class Circle: {
// private:
// public:
// };

class Smiley: public Circle {
private:
    Lines features;
public:
    Smiley( Point cc, int rr) : Circle (cc, rr ) {
        //M
        features.add(Point(cc.x-10, cc.y+20), Point(cc.x+10, cc.y+20));
        //L.E
        features.add(Point(cc.x-20, cc.y-20), Point(cc.x-10, cc.y-20));
        //R.E
        features.add(Point(cc.x+10, cc.y-20), Point(cc.x+20, cc.y-20));
    }

    void draw_lines() const {
        Circle::draw_lines();
        features.draw_lines();
    }
};

class SmileyHat: public Smiley {
private:
    Rectangle hat;
public:
    SmileyHat(Point cc, int rr) : Smiley(cc, rr), hat(Point(200, 20), 100, 40) {}

    void draw_lines() const {
        Smiley::draw_lines();
        hat.draw_lines();
    }
};
int main() {
    Simple_window win(Point(100,100), 400, 200, "Smiley and SmileyHat");

    Smiley s( Point(100,100), 50 ) ;

    win.attach (s);

    SmileyHat sh( Point(250,100), 50) ;

    win.attach (sh);

    win.wait_for_button();
    return 0;
}
