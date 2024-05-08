#ifndef RECT_H
#define RECT_H

class Rect {
    public:
        Rect(int _x, int _y, int _w, int _h);

    protected:
        int m_x;
        int m_y;
        int m_w;
        int m_h;
};

#endif // RECT_H