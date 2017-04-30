#include "clicklib.h"
#include <QDesktopWidget>

void startbot() {
    st = new SystemTrey();
}

void sleep(int ms) {
    Sleep(ms);
}

void sleep(int ms, int mode) {

}

//for test commit

void getmouse(int& x, int& y) {
    POINT pt;
    GetCursorPos(&pt);
    x=pt.x;
    y=pt.y;
}

int getmouseX() {
    POINT pt;
    GetCursorPos(&pt);
    return pt.x;
}

int getmouseY() {
    POINT pt;
    GetCursorPos(&pt);
    return pt.y;
}

void mousemove(int x, int y, int time) {
  int width= QApplication::desktop()->width();
  int height= QApplication::desktop()->height();
  qDebug() <<"width=" <<width <<"|height=" <<height;
  y = y * (65535 / height);
  x = x * (65535 / width);
  qDebug() <<"x=" <<x <<"y=" <<y;
  mouse_event(MOUSEEVENTF_MOVE| MOUSEEVENTF_ABSOLUTE,x,y,0,time);
}



void mouse(int cl, int x, int y,int time) {
    //mousemove(x, y);
    mouse_event(cl,0,0,0,0);
    sleep(time);
    mouse_event(mapMouse[cl],0,0,0,0);
}

void mousedown(uint cl){
    mouse_event(cl,0,0,0,0);
}

void mousedown(uint cl, int x, int y){
    mousemove(x, y);
    mouse_event(cl,0,0,0,0);
}

void mouseup(uint cl) {
    mouse_event(mapMouse[cl],0,0,0,0);
}

void mouseup(uint cl, int x, int y) {
    mousemove(x, y);
    mouse_event(mapMouse[cl],0,0,0,0);
}

void mousedbl(uint cl, int time) {
    mouse(cl, 0, 0, time);
    mouse(cl, 0, 0, time);
}

void mousedbl(uint cl, int x, int y, int time) {
   // mousemove(x, y);
    mouse(cl, x, y, time);
    mouse(cl, x, y, time);
}

void mousetransfer(int cl, int xst, int yst, int xfin, int yfin) {

}

void keychar(char key) {
    qDebug() <<"key1";
    //getting packet
    short cc = 'A';
    //qDebug() <<"keycharchar=" <<ch;
    qDebug() <<"keycharshort=" <<cc;
  //  std::vector < INPUT > input;
    INPUT in = { 0 };
    in.type = INPUT_KEYBOARD;
    in.ki.wScan = key;
    in.ki.dwFlags = KEYEVENTF_UNICODE;
   // input.push_back(in);
    SendInput(1, &in, sizeof(INPUT));
    in.ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
    SendInput(1, &in, sizeof(INPUT));
    // input.push_back(in);
}

void keychard(char key, int time) {

    INPUT in = { 0 };
    in.type = INPUT_KEYBOARD;
    in.ki.wScan = key;
    in.ki.dwFlags = KEYEVENTF_UNICODE;
    SendInput(1, &in, sizeof(INPUT));
}

void keycharu(char key, int time) {
    INPUT in = { 0 };
    in.type = INPUT_KEYBOARD;
    in.ki.wScan = key;
    in.ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
    SendInput(1, &in, sizeof(INPUT));
    // input.push_back(in);
}

void keypressd(uint key, int time) {
    INPUT in;
    in.type = INPUT_KEYBOARD;
    in.ki.wVk = key;
    in.ki.dwFlags = 0;
    in.ki.dwFlags = time;
    SendInput(1, &in, sizeof(INPUT));
}

void keypressu(uint key, int time) {
    INPUT in;
    in.type = INPUT_KEYBOARD;
    in.ki.wVk = key;
    in.ki.dwFlags = KEYEVENTF_KEYUP;
    in.ki.dwFlags = time;
    SendInput(1, &in, sizeof(INPUT));
}

void key(char key, int time) {
    keycharu(key,time);
    keychard(key,time);
}

void key(uint key, int time) {
    keypressu(key,time);
    keypressd(key,time);

}

void keydown(char key, int time) {
    keychard(key, time);
}

void keydown(uint key, int time) {
    keypressd(key, time);
}

void keyup(char key, int time) {
    keycharu(key, time);
}

void keyup(uint key, int time) {
    keypressu(key, time);
}

void keyr() {
   // keychar();
   // keypress();
}

void regkey(uint alt, char key, void (*f)(uint key, char keych, uint mode)) {
    st->registerKey(alt, key, f);
    //f(2, 'A', 3);
}

void regkey(uint alt, uint key, void (*f)(uint key, char keych, uint mode)) {
    st->registerKey(alt, key, f);
   // f(21, 'B', 4);
}

void unregkey(uint key) {

}

void uregkey(char key) {

}

int getcolor(int x, int y, HWND hwnd) {
  //  HDC hdc = GetDC(st->getHWND()) ;
    /*HWND name = FindWindowA(0,"GetpixelColor");
    HDC dc = GetWindowDC(name);*/
     HDC dc =(hwnd ==0) ? GetDC(NULL/*st->getHWND()*/) : GetDC(hwnd);
    //COLORREF color = GetPixel(dc, x, y);
     int color = GetPixel(dc, x, y);
    //GetPixelFormat(hdc);
    return color;
}

int getcolor(HWND hwnd) {
   // hwnd=(hwnd ==0) ? (HWND)SystemTrey::winId() : hwnd;
    HDC dc =(hwnd ==0) ? GetDC(NULL/*st->getHWND()*/) : GetDC(hwnd);
    int x, y;
    getmouse(x, y);
    int color = GetPixel(dc, x, y);
    return 1;
}

int gettime() {
    return GetTickCount();
}

