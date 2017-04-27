#ifndef CLICKLIB_H
#define CLICKLIB_H

#include "clicklib_global.h"
#include <windows.h>
#include <QObject>
#include <QDebug>
#include <errors.h>
#include <time.h>
#include <systemtrey.h>

#define LEFT 0x0002
#define RIGHT 0x0008
#define MIDDLE 0x0020


/****************************************************/
    const char KEYCODE_A = 'A';
    const char KEYCODE_B = 'B';
    const char KEYCODE_C = 'C';
    const char KEYCODE_D = 'D';
    const char KEYCODE_E = 'E';
    const char KEYCODE_F = 'F';
    const char KEYCODE_G = 'G';
    const char KEYCODE_H = 'H';
    const char KEYCODE_I = 'I';
    const char KEYCODE_J = 'J';
    const char KEYCODE_K = 'K';
    const char KEYCODE_L = 'L';
    const char KEYCODE_M = 'M';
    const char KEYCODE_N = 'N';
    const char KEYCODE_O = 'O';
    const char KEYCODE_P = 'P';
    const char KEYCODE_Q = 'Q';
    const char KEYCODE_R = 'R';
    const char KEYCODE_S = 'S';
    const char KEYCODE_T = 'T';
    const char KEYCODE_U = 'U';
    const char KEYCODE_V = 'V';
    const char KEYCODE_W = 'W';
    const char KEYCODE_X = 'X';
    const char KEYCODE_Y = 'Y';
    const char KEYCODE_Z = 'Z';

    const char KEYCODE_0 = '0';
    const char KEYCODE_1 = '1';
    const char KEYCODE_2 = '2';
    const char KEYCODE_3 = '3';
    const char KEYCODE_4 = '4';
    const char KEYCODE_5 = '5';
    const char KEYCODE_6 = '6';
    const char KEYCODE_7 = '7';
    const char KEYCODE_8 = '8';
    const char KEYCODE_9 = '9';

    const uint KEYCODE_F1 = 0x70;
    const uint KEYCODE_F2 = 0x71;
    const uint KEYCODE_F3 = 0x72;
    const uint KEYCODE_F4 = 0x73;
    const uint KEYCODE_F5 = 0x74;
    const uint KEYCODE_F6 = 0x75;
    const uint KEYCODE_F7 = 0x76;
    const uint KEYCODE_F8 = 0x77;
    const uint KEYCODE_F9 = 0x78;
    const uint KEYCODE_F10 = 0x79;
    const uint KEYCODE_F11 = 0x7A;
    const uint KEYCODE_F12 = 0x7B;

    const uint KEYCODE_SHIFT_LEFT = 0xA0;
    const uint KEYCODE_SHIFT_RIGHT = 0xA1;
    const uint KEYCODE_CTRL_LEFT = 0xA2;
    const uint KEYCODE_CTRL_RIGHT = 0xA3;
    const uint KEYCODE_ALT_LEFT = 0xA4;
    const uint KEYCODE_ALT_RIGHT = 0xA5;
    const uint KEYCODE_MENU = 0x12;

    //const uint KEYCODE_DPAD_CENTER = VK_DPAD_CENTER;
    const uint KEYCODE_DPAD_DOWN = 0x28;
    const uint KEYCODE_DPAD_LEFT = 0x25;
    const uint KEYCODE_DPAD_RIGHT = 0x27;
    const uint KEYCODE_DPAD_UP = 0x26;

    const uint KEYCODE_VOLUME_DOWN = 0xAE;
    const uint KEYCODE_VOLUME_MUTE = 0xAD;
    const uint KEYCODE_VOLUME_UP = 0xAF;

    const uint KEYCODE_SEARCH = 0xAA;
    const uint KEYCODE_HOME = 0xAC;
    const uint KEYCODE_BACK = 0xA6;
    const uint KEYCODE_FORWARD = 0xA7;

    const uint KEYCODE_INSERT = 0x2D;
    const uint KEYCODE_MOVE_END = 0x23;
    const uint KEYCODE_MOVE_HOME = 0x24;
    const uint KEYCODE_PAGE_DOWN = 0x22;
    const uint KEYCODE_PAGE_UP = 0x21;

    const uint KEYCODE_DEL = 0x08;
    const uint KEYCODE_FORWARD_DEL = 0x2E;
    const uint KEYCODE_CLEAR = 0x0C;

    const uint KEYCODE_CAPS_LOCK = 0x14;

    const uint KEYCODE_TAB = 0x09;
    const uint KEYCODE_SPACE = 0x20;
    const uint KEYCODE_ENTER = 0x0D;

    const uint KEYCODE_ESCAPE = 0x1B;

    const uint KEYCODE_SCROLL_LOCK = 0x91;
    const uint KEYCODE_NUM_LOCK = 0x90;

    //const uint KEYCODE_MEDIA_CLOSE = VK_MEDIA_CLOSE;
    //const uint KEYCODE_MEDIA_EJECT = VK_MEDIA_EJECT;
    //const uint KEYCODE_MEDIA_FAST_FORWARD = VK_MEDIA_FAST_FORWARD;
    const uint KEYCODE_MEDIA_NEXT = 0xB0;
    //const uint KEYCODE_MEDIA_PAUSE = VK_MEDIA_PAUSE;
    //const uint KEYCODE_MEDIA_PLAY = VK_MEDIA_PLAY;
    const uint KEYCODE_MEDIA_PLAY_PAUSE = 0xB3;
    const uint KEYCODE_MEDIA_PREVIOUS = 0xB1;
    //const uint KEYCODE_MEDIA_RECORD = VK_MEDIA_RECORD;
    //const uint KEYCODE_MEDIA_REWIND = VK_MEDIA_REWIND;
    const uint KEYCODE_MEDIA_STOP = 0xB2;
    const uint KEYCODE_MUTE = 0xAD;

    //const uint KEYCODE_SOFT_LEFT = VK_LEFT;
    //const uint KEYCODE_SOFT_RIGHT = VK_RIGHT;
    //const uint KEYCODE_ZOOM_IN = VK_ZOOM;
    //const uint KEYCODE_ZOOM_OUT = VK_ZOOM_OUT;

/*
    const uint KEYCODE_CAPTIONS = VK_CAPTIONS;
    const uint KEYCODE_CHANNEL_DOWN = VK_CHANNEL_DOWN;
    const uint KEYCODE_CHANNEL_UP = VK_CHANNEL_UP;

    const uint KEYCODE_CALL = VK_CALL;

    const uint KEYCODE_3D_MODE = VK_3D_MODE;
    const uint KEYCODE_APOSTROPHE = VK_APOSTROPHE;
    const uint KEYCODE_APP_SWITCH = VK_APP_SWITCH;
    const uint KEYCODE_AVR_INPUT = VK_AVR_INPUT;
    const uint KEYCODE_AVR_POWER = VK_AVR_POWER;

    const uint KEYCODE_BACKSLASH = VK_BACKSLASH;
    const uint KEYCODE_BOOKMARK = VK_BOOKMARK;
    const uint KEYCODE_BREAK = VK_BREAK;

    const uint KEYCODE_CONTACTS = VK_CONTACTS;

    const uint KEYCODE_DVR = VK_DVR;
    const uint KEYCODE_ENDCALL = VK_ENDCALL;
    const uint KEYCODE_ENVELOPE = VK_ENVELOPE;
    const uint KEYCODE_FOCUS = VK_FOCUS;
    const uint KEYCODE_FUNCTION = VK_FUNCTION;
    const uint KEYCODE_GUIDE = VK_GUIDE;
    const uint KEYCODE_HEADSETHOOK = VK_HEADSETHOOK;
    const uint KEYCODE_INFO = VK_INFO;
    const uint KEYCODE_MANNER_MODE = VK_MANNER_MODE;
    const uint KEYCODE_META_LEFT = VK_META_LEFT;
    const uint KEYCODE_META_RIGHT = VK_META_RIGHT;
    const uint KEYCODE_MINUS = VK_MINUS;
    const uint KEYCODE_MUSIC = VK_MUSIC;
    const uint KEYCODE_NUM = VK_NUM;

    const uint KEYCODE_NUMPAD_0 = VK_NUMPAD0;
    const uint KEYCODE_NUMPAD_1 = VK_NUMPAD1;
    const uint KEYCODE_NUMPAD_2 = VK_NUMPAD2;
    const uint KEYCODE_NUMPAD_3 = VK_NUMPAD3;
    const uint KEYCODE_NUMPAD_4 = VK_NUMPAD4;
    const uint KEYCODE_NUMPAD_5 = VK_NUMPAD5;
    const uint KEYCODE_NUMPAD_6 = VK_NUMPAD6;
    const uint KEYCODE_NUMPAD_7 = VK_NUMPAD7;
    const uint KEYCODE_NUMPAD_8 = VK_NUMPAD8;
    const uint KEYCODE_NUMPAD_9 = VK_NUMPAD9;
    const uint KEYCODE_NUMPAD_ADD = VK_NUMPAD_ADD;
    const uint KEYCODE_NUMPAD_COMMA = VK_NUMPAD_COMMA;
    const uint KEYCODE_NUMPAD_DIVIDE = VK_NUMPAD_DIVIDE;
    const uint KEYCODE_NUMPAD_DOT = VK_NUMPAD_DOT;
    const uint KEYCODE_NUMPAD_ENTER = VK_NUMPAD_ENTER;
    const uint KEYCODE_NUMPAD_EQUALS = VK_NUMPAD_EQUALS;
    const uint KEYCODE_NUMPAD_LEFT_PAREN = VK_NUMPAD_LEFT_PAREN;
    const uint KEYCODE_NUMPAD_MULTIPLY = VK_NUMPAD_MULTIPLY;
    const uint KEYCODE_NUMPAD_RIGHT_PAREN = VK_NUMPAD_RIGHT_PAREN;
    const uint KEYCODE_NUMPAD_SUBTRACT = VK_NUMPAD_SUBTRACT;

    const uint KEYCODE_PICTSYMBOLS = VK_PICTSYMBOLS;
    const uint KEYCODE_PROG_BLUE = VK_PROG_BLUE;
    const uint KEYCODE_PROG_GREEN = VK_PROG_GREEN;
    const uint KEYCODE_PROG_RED = VK_PROG_RED;
    const uint KEYCODE_PROG_YELLOW = VK_PROG_YELLOW;

    const uint KEYCODE_SETTINGS = VK_SETTINGS;
    const uint KEYCODE_STB_INPUT = VK_STB_INPUT;
    const uint KEYCODE_STB_POWER = VK_STB_POWER;
    const uint KEYCODE_SWITCH_CHARSET = VK_SWITCH_CHARSET;
    const uint KEYCODE_SYM = VK_SYM;
    const uint KEYCODE_SYSRQ = VK_SYSRQ;
    const uint KEYCODE_TV = VK_TV;
    const uint KEYCODE_TV_INPUT = VK_TV_INPUT;
    const uint KEYCODE_TV_POWER = VK_TV_POWER;
    const uint KEYCODE_WINDOW = VK_WINDOW;

    const uint KEYCODE_CAMERA = VK_CAMERA;
    const uint KEYCODE_EXPLORER = VK_EXPLORER;
    const uint KEYCODE_LANGUAGE_SWITCH = VK_LANGUAGE_SWITCH;
    const uint KEYCODE_NOTIFICATION = VK_NOTIFICATION;
    const uint KEYCODE_CALCULATOR = VK_CALCULATOR;
    const uint KEYCODE_CALENDAR = VK_CALENDAR;

    const uint KEYCODE_BUTTON_1 = VK_BUTTON_1;
    const uint KEYCODE_BUTTON_10 = VK_BUTTON_10;
    const uint KEYCODE_BUTTON_11 = VK_BUTTON_11;
    const uint KEYCODE_BUTTON_12 = VK_BUTTON_12;
    const uint KEYCODE_BUTTON_13 = VK_BUTTON_13;
    const uint KEYCODE_BUTTON_14 = VK_BUTTON_14;
    const uint KEYCODE_BUTTON_15 = VK_BUTTON_15;
    const uint KEYCODE_BUTTON_16 = VK_BUTTON_16;
    const uint KEYCODE_BUTTON_2 = VK_BUTTON_2;
    const uint KEYCODE_BUTTON_3 = VK_BUTTON_3;
    const uint KEYCODE_BUTTON_4 = VK_BUTTON_4;
    const uint KEYCODE_BUTTON_5 = VK_BUTTON_5;
    const uint KEYCODE_BUTTON_6 = VK_BUTTON_6;
    const uint KEYCODE_BUTTON_7 = VK_BUTTON_7;
    const uint KEYCODE_BUTTON_8 = VK_BUTTON_8;
    const uint KEYCODE_BUTTON_9 = VK_BUTTON_9;
    const uint KEYCODE_BUTTON_A = VK_BUTTON_A;
    const uint KEYCODE_BUTTON_B = VK_BUTTON_B;
    const uint KEYCODE_BUTTON_C = VK_BUTTON_C;
    const uint KEYCODE_BUTTON_L1 = VK_BUTTON_L1;
    const uint KEYCODE_BUTTON_L2 = VK_BUTTON_L2;
    const uint KEYCODE_BUTTON_MODE = VK_BUTTON_MODE;
    const uint KEYCODE_BUTTON_R1 = VK_BUTTON_R1;
    const uint KEYCODE_BUTTON_R2 = VK_BUTTON_R2;
    const uint KEYCODE_BUTTON_SELECT = VK_BUTTON_SELECT;
    const uint KEYCODE_BUTTON_START = VK_BUTTON_START;
    const uint KEYCODE_BUTTON_THUMBL = VK_BUTTON_THUMBL;
    const uint KEYCODE_BUTTON_THUMBR = VK_BUTTON_THUMBR;
    const uint KEYCODE_BUTTON_X = VK_BUTTON_X;
    const uint KEYCODE_BUTTON_Y = VK_BUTTON_Y;
    const uint KEYCODE_BUTTON_Z = VK_BUTTON_Z;
*/

/*********************************************************************/
    QMap<int, int> makeMap(){
        QMap<int, int> result;
        result[LEFT] = MOUSEEVENTF_LEFTUP;
        result[RIGHT] = MOUSEEVENTF_RIGHTUP;
        result[MIDDLE] = MOUSEEVENTF_MIDDLEUP;
        return result;
    }
    const QMap<int, int> mapMouse = makeMap();

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

void start();

void sleep(int ms);

void sleep(int ms, int mode);

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
}



#endif // CLICKLIB_H
