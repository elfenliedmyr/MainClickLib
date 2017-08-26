#ifndef WIN_H
#define WIN_H
#include <QObject>
#include <windows.h>

class Win
{
    public:
        Win(HWND hwnd);
        HWND hwnd = 0;
        HWND hwndChild =0;
        int toxglobal(int x);
        int toyglobal(int y);
        void toxyglobal(int& x, int& y);
        RECT getRect();

    private:
        int k;
};

#endif // WIN_H
