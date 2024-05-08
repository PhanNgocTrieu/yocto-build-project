#ifndef DISPLAY_H_
#define DISPLAY_H_

class Rect {
    public:
        Rect(int _t = 0, int _l = 0, int _btm = 0, int _r = 0) 
        : top_(_t)
        , left_(_l)
        , bottom_(_btm)
        , right_(_r)
        {}

    protected:
        int top_;
        int left_;
        int bottom_;
        int right_;
};

#endif