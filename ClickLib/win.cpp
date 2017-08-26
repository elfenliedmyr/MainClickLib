#include "win.h"
#include <QDebug>

Win::Win(HWND hwnd) : hwnd(hwnd)
{
    if(hwnd!=0) {
        RECT r = getRect();
        POINT point;
        point.x = r.left;
        point.y = r.top;
        hwndChild = ChildWindowFromPoint(hwnd, point);
        qDebug() <<"lalala";
    }
}

void Win::toxyglobal(int& x, int& y)
{
    RECT r = getRect();
    x = r.left + x;
    y = r.top + y;
}

int Win::toxglobal(int x)
{
    return 0;
}

int Win::toyglobal(int y)
{
    return 0;
}

RECT Win::getRect()
{
    RECT r;
    GetWindowRect(hwnd, &r);
    return r;
}
