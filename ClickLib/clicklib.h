#ifndef CLICKLIB_H
#define CLICKLIB_H


#include "clicklib_global.h"
#include <win.h>
//#include <windows.h>
#include <QObject>
#include <QApplication>
#include <QtWidgets>
#include <QGuiApplication>
#include <QPixmap>
#include <QDebug>
#include <errors.h>
#include <time.h>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core.hpp>;
#include <opencv2/highgui.hpp>
#include <QRgb>
#include <QColor>
#include <systemtrey.h>

#define LEFT 0x0002
#define RIGHT 0x0008
#define MIDDLE 0x0020

#define ERR_NO_SCREEN -1
#define ERR_FINISH_MORE_START -2
#define ERR_SEARCH_MORE_REGION -3

#define FIND_ALL 1
#define FIND_MIN 2
#define FIND_MIDDLE 3

/****************************************************/
    const char KEY_A = 'A';
    const char KEY_B = 'B';
    const char KEY_C = 'C';
    const char KEY_D = 'D';
    const char KEY_E = 'E';
    const char KEY_F = 'F';
    const char KEY_G = 'G';
    const char KEY_H = 'H';
    const char KEY_I = 'I';
    const char KEY_J = 'J';
    const char KEY_K = 'K';
    const char KEY_L = 'L';
    const char KEY_M = 'M';
    const char KEY_N = 'N';
    const char KEY_O = 'O';
    const char KEY_P = 'P';
    const char KEY_Q = 'Q';
    const char KEY_R = 'R';
    const char KEY_S = 'S';
    const char KEY_T = 'T';
    const char KEY_U = 'U';
    const char KEY_V = 'V';
    const char KEY_W = 'W';
    const char KEY_X = 'X';
    const char KEY_Y = 'Y';
    const char KEY_Z = 'Z';

    const char KEY_0 = '0';
    const char KEY_1 = '1';
    const char KEY_2 = '2';
    const char KEY_3 = '3';
    const char KEY_4 = '4';
    const char KEY_5 = '5';
    const char KEY_6 = '6';
    const char KEY_7 = '7';
    const char KEY_8 = '8';
    const char KEY_9 = '9';

    const uint KEY_F1 = 0x70;
    const uint KEY_F2 = 0x71;
    const uint KEY_F3 = 0x72;
    const uint KEY_F4 = 0x73;
    const uint KEY_F5 = 0x74;
    const uint KEY_F6 = 0x75;
    const uint KEY_F7 = 0x76;
    const uint KEY_F8 = 0x77;
    const uint KEY_F9 = 0x78;
    const uint KEY_F10 = 0x79;
    const uint KEY_F11 = 0x7A;
    const uint KEY_F12 = 0x7B;

    const uint KEY_SHIFT_LEFT = 0xA0;
    const uint KEY_SHIFT_RIGHT = 0xA1;
    const uint KEY_CTRL_LEFT = 0xA2;
    const uint KEY_CTRL_RIGHT = 0xA3;
    const uint KEY_ALT_LEFT = 0xA4;
    const uint KEY_ALT_RIGHT = 0xA5;
    const uint KEY_MENU = 0x12;

    //const uint KEY_DPAD_CENTER = VK_DPAD_CENTER;
    const uint KEY_DPAD_DOWN = 0x28;
    const uint KEY_DPAD_LEFT = 0x25;
    const uint KEY_DPAD_RIGHT = 0x27;
    const uint KEY_DPAD_UP = 0x26;

    const uint KEY_VOLUME_DOWN = 0xAE;
    const uint KEY_VOLUME_MUTE = 0xAD;
    const uint KEY_VOLUME_UP = 0xAF;

    const uint KEY_SEARCH = 0xAA;
    const uint KEY_HOME = 0xAC;
    const uint KEY_BACK = 0xA6;
    const uint KEY_FORWARD = 0xA7;

    const uint KEY_INSERT = 0x2D;
    const uint KEY_MOVE_END = 0x23;
    const uint KEY_MOVE_HOME = 0x24;
    const uint KEY_PAGE_DOWN = 0x22;
    const uint KEY_PAGE_UP = 0x21;

    const uint KEY_DEL = 0x08;
    const uint KEY_FORWARD_DEL = 0x2E;
    const uint KEY_CLEAR = 0x0C;

    const uint KEY_CAPS_LOCK = 0x14;

    const uint KEY_TAB = 0x09;
    const uint KEY_SPACE = 0x20;
    const uint KEY_ENTER = 0x0D;

    const uint KEY_ESCAPE = 0x1B;

    const uint KEY_SCROLL_LOCK = 0x91;
    const uint KEY_NUM_LOCK = 0x90;

    //const uint KEY_MEDIA_CLOSE = VK_MEDIA_CLOSE;
    //const uint KEY_MEDIA_EJECT = VK_MEDIA_EJECT;
    //const uint KEY_MEDIA_FAST_FORWARD = VK_MEDIA_FAST_FORWARD;
    const uint KEY_MEDIA_NEXT = 0xB0;
    //const uint KEY_MEDIA_PAUSE = VK_MEDIA_PAUSE;
    //const uint KEY_MEDIA_PLAY = VK_MEDIA_PLAY;
    const uint KEY_MEDIA_PLAY_PAUSE = 0xB3;
    const uint KEY_MEDIA_PREVIOUS = 0xB1;
    //const uint KEY_MEDIA_RECORD = VK_MEDIA_RECORD;
    //const uint KEY_MEDIA_REWIND = VK_MEDIA_REWIND;
    const uint KEY_MEDIA_STOP = 0xB2;
    const uint KEY_MUTE = 0xAD;

    //const uint KEY_SOFT_LEFT = VK_LEFT;
    //const uint KEY_SOFT_RIGHT = VK_RIGHT;
    //const uint KEY_ZOOM_IN = VK_ZOOM;
    //const uint KEY_ZOOM_OUT = VK_ZOOM_OUT;

/*
    const uint KEY_CAPTIONS = VK_CAPTIONS;
    const uint KEY_CHANNEL_DOWN = VK_CHANNEL_DOWN;
    const uint KEY_CHANNEL_UP = VK_CHANNEL_UP;

    const uint KEY_CALL = VK_CALL;

    const uint KEY_3D_MODE = VK_3D_MODE;
    const uint KEY_APOSTROPHE = VK_APOSTROPHE;
    const uint KEY_APP_SWITCH = VK_APP_SWITCH;
    const uint KEY_AVR_INPUT = VK_AVR_INPUT;
    const uint KEY_AVR_POWER = VK_AVR_POWER;

    const uint KEY_BACKSLASH = VK_BACKSLASH;
    const uint KEY_BOOKMARK = VK_BOOKMARK;
    const uint KEY_BREAK = VK_BREAK;

    const uint KEY_CONTACTS = VK_CONTACTS;

    const uint KEY_DVR = VK_DVR;
    const uint KEY_ENDCALL = VK_ENDCALL;
    const uint KEY_ENVELOPE = VK_ENVELOPE;
    const uint KEY_FOCUS = VK_FOCUS;
    const uint KEY_FUNCTION = VK_FUNCTION;
    const uint KEY_GUIDE = VK_GUIDE;
    const uint KEY_HEADSETHOOK = VK_HEADSETHOOK;
    const uint KEY_INFO = VK_INFO;
    const uint KEY_MANNER_MODE = VK_MANNER_MODE;
    const uint KEY_META_LEFT = VK_META_LEFT;
    const uint KEY_META_RIGHT = VK_META_RIGHT;
    const uint KEY_MINUS = VK_MINUS;
    const uint KEY_MUSIC = VK_MUSIC;
    const uint KEY_NUM = VK_NUM;

    const uint KEY_NUMPAD_0 = VK_NUMPAD0;
    const uint KEY_NUMPAD_1 = VK_NUMPAD1;
    const uint KEY_NUMPAD_2 = VK_NUMPAD2;
    const uint KEY_NUMPAD_3 = VK_NUMPAD3;
    const uint KEY_NUMPAD_4 = VK_NUMPAD4;
    const uint KEY_NUMPAD_5 = VK_NUMPAD5;
    const uint KEY_NUMPAD_6 = VK_NUMPAD6;
    const uint KEY_NUMPAD_7 = VK_NUMPAD7;
    const uint KEY_NUMPAD_8 = VK_NUMPAD8;
    const uint KEY_NUMPAD_9 = VK_NUMPAD9;
    const uint KEY_NUMPAD_ADD = VK_NUMPAD_ADD;
    const uint KEY_NUMPAD_COMMA = VK_NUMPAD_COMMA;
    const uint KEY_NUMPAD_DIVIDE = VK_NUMPAD_DIVIDE;
    const uint KEY_NUMPAD_DOT = VK_NUMPAD_DOT;
    const uint KEY_NUMPAD_ENTER = VK_NUMPAD_ENTER;
    const uint KEY_NUMPAD_EQUALS = VK_NUMPAD_EQUALS;
    const uint KEY_NUMPAD_LEFT_PAREN = VK_NUMPAD_LEFT_PAREN;
    const uint KEY_NUMPAD_MULTIPLY = VK_NUMPAD_MULTIPLY;
    const uint KEY_NUMPAD_RIGHT_PAREN = VK_NUMPAD_RIGHT_PAREN;
    const uint KEY_NUMPAD_SUBTRACT = VK_NUMPAD_SUBTRACT;

    const uint KEY_PICTSYMBOLS = VK_PICTSYMBOLS;
    const uint KEY_PROG_BLUE = VK_PROG_BLUE;
    const uint KEY_PROG_GREEN = VK_PROG_GREEN;
    const uint KEY_PROG_RED = VK_PROG_RED;
    const uint KEY_PROG_YELLOW = VK_PROG_YELLOW;

    const uint KEY_SETTINGS = VK_SETTINGS;
    const uint KEY_STB_INPUT = VK_STB_INPUT;
    const uint KEY_STB_POWER = VK_STB_POWER;
    const uint KEY_SWITCH_CHARSET = VK_SWITCH_CHARSET;
    const uint KEY_SYM = VK_SYM;
    const uint KEY_SYSRQ = VK_SYSRQ;
    const uint KEY_TV = VK_TV;
    const uint KEY_TV_INPUT = VK_TV_INPUT;
    const uint KEY_TV_POWER = VK_TV_POWER;
    const uint KEY_WINDOW = VK_WINDOW;

    const uint KEY_CAMERA = VK_CAMERA;
    const uint KEY_EXPLORER = VK_EXPLORER;
    const uint KEY_LANGUAGE_SWITCH = VK_LANGUAGE_SWITCH;
    const uint KEY_NOTIFICATION = VK_NOTIFICATION;
    const uint KEY_CALCULATOR = VK_CALCULATOR;
    const uint KEY_CALENDAR = VK_CALENDAR;

    const uint KEY_BUTTON_1 = VK_BUTTON_1;
    const uint KEY_BUTTON_10 = VK_BUTTON_10;
    const uint KEY_BUTTON_11 = VK_BUTTON_11;
    const uint KEY_BUTTON_12 = VK_BUTTON_12;
    const uint KEY_BUTTON_13 = VK_BUTTON_13;
    const uint KEY_BUTTON_14 = VK_BUTTON_14;
    const uint KEY_BUTTON_15 = VK_BUTTON_15;
    const uint KEY_BUTTON_16 = VK_BUTTON_16;
    const uint KEY_BUTTON_2 = VK_BUTTON_2;
    const uint KEY_BUTTON_3 = VK_BUTTON_3;
    const uint KEY_BUTTON_4 = VK_BUTTON_4;
    const uint KEY_BUTTON_5 = VK_BUTTON_5;
    const uint KEY_BUTTON_6 = VK_BUTTON_6;
    const uint KEY_BUTTON_7 = VK_BUTTON_7;
    const uint KEY_BUTTON_8 = VK_BUTTON_8;
    const uint KEY_BUTTON_9 = VK_BUTTON_9;
    const uint KEY_BUTTON_A = VK_BUTTON_A;
    const uint KEY_BUTTON_B = VK_BUTTON_B;
    const uint KEY_BUTTON_C = VK_BUTTON_C;
    const uint KEY_BUTTON_L1 = VK_BUTTON_L1;
    const uint KEY_BUTTON_L2 = VK_BUTTON_L2;
    const uint KEY_BUTTON_MODE = VK_BUTTON_MODE;
    const uint KEY_BUTTON_R1 = VK_BUTTON_R1;
    const uint KEY_BUTTON_R2 = VK_BUTTON_R2;
    const uint KEY_BUTTON_SELECT = VK_BUTTON_SELECT;
    const uint KEY_BUTTON_START = VK_BUTTON_START;
    const uint KEY_BUTTON_THUMBL = VK_BUTTON_THUMBL;
    const uint KEY_BUTTON_THUMBR = VK_BUTTON_THUMBR;
    const uint KEY_BUTTON_X = VK_BUTTON_X;
    const uint KEY_BUTTON_Y = VK_BUTTON_Y;
    const uint KEY_BUTTON_Z = VK_BUTTON_Z;
*/

/*********************************************************************/
    int startTime = 0;
    int stopTime = 0;


   QMap<int, int> makeMap(){
        QMap<int, int> result;
        result[LEFT] = MOUSEEVENTF_LEFTUP;
        result[RIGHT] = MOUSEEVENTF_RIGHTUP;
        result[MIDDLE] = MOUSEEVENTF_MIDDLEUP;
        return result;
    }
    const QMap<int, int> mapMouse1 = makeMap();

    /*INPUT makeInput() {
        INPUT ip;
        ip.type = INPUT_KEYBOARD;
        ip.ki.wScan = 0x45;
        ip.ki.time = 0;
        ip.ki.dwExtraInfo = 0;
    }

    INPUT ip = makeInput();*/

    SystemTrey* st;
extern "C++" {

void startbot();

void sleep(int ms);

void sleep(int ms, int mode);

QString getTitleWin();

HWND getHWND(QString str);

cv::Mat QImageToCvMat( const QImage &inImage, bool inCloneImageData = true );

cv::Mat QPixmapToCvMat( const QPixmap &inPixmap, bool inCloneImageData = true );

void outtext(int x, int y, QString text,
             QString style="{background-color : red; color : blue; font-size:12px}");

void getmouse(int& x, int& y);

int getmouseX();

int getmouseY();

void mousemove(int x, int y, int time=0) ;

void mouse(int cl, int x=0, int y=0,int time=20);

void mousedown(uint cl);

void mousedown(uint cl, int x=0, int y=0);

void mouseup(uint cl);

void mouseup(uint cl, int x=0, int y=0);

void mousedbl(uint cl, int time=60) ;

void mousedbl(uint cl, int x=0, int y=0, int time=10) ;

void mousetransfer(int cl, int xst, int yst, int xfin, int yfin);

void keychar(char key);

void keychard(char key, int time);

void keycharu(char key, int time);

void keypressd(uint key, int time);

void keypressu(uint key, int time);

void key(char key, int time=0);

void key(uint key, int time=0);

void keydown(char key, int time=0);

void keydown(uint key, int time=0);

void keyup(char key, int time=0);

void keyup(uint key, int time=0);

void keyr();

void regkey(uint alt, char key, void (*f)(uint key, char keych, uint mode));

void regkey(uint alt, uint key, void (*f)(uint key, char keych, uint mode));

void unregkey(uint key);

void uregkey(char key);

int getcolor(int x, int y, HWND hwnd=0);

int getcolor(HWND hwnd=0);

int gettime();

void starttimer();

int stoptimer();

bool savescr(QString puth, Win* win=0);

int findimg(int maxFind, cv::Mat mat, QList<QPoint*>& pointsCoincidence,
            int xstart=0, int ystart=0, int xfinish=0, int yfinish=0,
            int rMore0=0, int rLess0=0, int gMore0=0, int gLess0=0, int bMore0=0, int bLess0=0,
            bool show=false, Win* win=0);

int findimgopc(int maxFind, cv::Mat mat, QList<QPoint*>& pointsCoincidence,
            int xstart=0, int ystart=0, int xfinish=0, int yfinish=0,
            int rMore0=0, int rLess0=0, int gMore0=0, int gLess0=0, int bMore0=0, int bLess0=0,
            bool show=false, Win* win=0);

int findpxs( int maxFind, int minFind, QMap<QColor*, int> mapPxs,
            QList<QPoint*>& pointsCoincidence, int wsi, int hsi,
            int xstart=0, int ystart=0, int xfinish=0, int yfinish=0,
            int rMore0=0, int rLess0=0, int gMore0=0, int gLess0=0, int bMore0=0, int bLess0=0,
            int allread=2, bool show=false, Win* win=0);

}

#endif // CLICKLIB_H
