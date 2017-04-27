#include "systemtrey.h"
#include <QAction>
#include <QtWidgets>
//#include <clicklib.h>

SystemTrey::SystemTrey(QWidget* pwgt /*=0*/) : QLabel("<H1>Application Window</H1>", pwgt)
{
    RegisterHotKey((HWND)SystemTrey::winId(), 0, 0, 'A');
    RegisterHotKey((HWND)SystemTrey::winId(), 102, MOD_ALT, VK_F2);
    RegisterHotKey((HWND)SystemTrey::winId(), 103, MOD_ALT, VK_F3);
    RegisterHotKey((HWND)SystemTrey::winId(), 104, MOD_ALT, VK_F4);
    RegisterHotKey((HWND)SystemTrey::winId(), 105, MOD_ALT, VK_F5);
    UnregisterHotKey((HWND)SystemTrey::winId(),105);
     setWindowTitle("Click Lib");
     QString strPixmapName = ":/images/img1.bmp" ;
     QAction* pactQuit = new QAction("&Quit", this);
     connect(pactQuit, SIGNAL(triggered()), qApp, SLOT(quit()));
     m_ptrayIconMenu = new QMenu(this);
     m_ptrayIconMenu->addAction(pactQuit);
     m_ptrayIcon = new QSystemTrayIcon(this);
     m_ptrayIcon->setContextMenu(m_ptrayIconMenu);
     m_ptrayIcon->setToolTip("System Tray");
     m_ptrayIcon->setIcon(QPixmap(strPixmapName));
     m_ptrayIcon->show();
}



bool SystemTrey::nativeEvent(const QByteArray & eventType, void * message, long * result){
    Q_UNUSED(result);
    Q_UNUSED(eventType);
    MSG* msg = reinterpret_cast<MSG*>(message);
    if(msg->message!=WM_HOTKEY)return false;
    int sizek = keysList.size();
    if(sizek>0 && msg->wParam<sizek) {
        typeKeys keys = keysList.at((int)msg->wParam);
        keys.f(keys.key,keys.keych, keys.alt);
        /* qDebug() <<"wParam=" <<msg->wParam <<"|lParam=" <<msg->lParam <<"\n"
                 <<"keych=" <<keys.keych <<"|mode=" <<keys.alt <<"|key=" <<keys.key;*/
    }

   /* switch(msg->wParam){
    case 0: // Alt-F1 - запуск бота
        qDebug() <<"Its's working create";

        //bot.run();
        return true;
    case 102: // Alt-F2 - inx++
       // if(inx<points_cnt-1)inx++;
        qDebug() <<"Its's working create";
        return true;
    case 103: // Alt-F3 - Проверить точку inx
        qDebug() <<"Its's working create";
       // bot.move_to(inx);
        return true;
    case 104: // Alt-F4 - Запомнить точку inx
        qDebug() <<"Its's working create";
       // GetCursorPos(&bot.point[inx]);
        return true;
    case 105: // Alt-F5 - Вывести в консоль массив координат
        qDebug() <<"Its's working create";*/
       /* for(int i=0;i<points_cnt;i++){
            std::cout << "{" << bot.point[i].x << "," << bot.point[i].y << "}, //" << i << std::endl;
        }*/
        return true;
  //  }
}

void SystemTrey::registerKey(uint alt, char key, void (*f)(uint key, char keych, uint mode))
{
    typeKeys keys;
    keys.alt = alt;
    keys.keych = key;
    keys.key = 0;
    keys.f = f;
    int sizek = keysList.size();
    keysList.insert(sizek, keys);
    RegisterHotKey((HWND)SystemTrey::winId(), sizek, alt, key);
}

void SystemTrey::registerKey(uint alt, uint key, void (*f)(uint key, char keych, uint mode))
{
    typeKeys keys;
    keys.alt = alt;
   // keys.keych = '';
    keys.key = key;
    keys.f = f;
    int sizek = keysList.size();
    keysList.insert(sizek, keys);
    RegisterHotKey((HWND)SystemTrey::winId(), sizek, alt, key);
}

bool SystemTrey::unregisterKey(uint key)
{
    int sizek = keysList.size();
    uint keyid=0;
    for(int i=0; i<sizek; i++) {
        if(keysList.at(i).key==key) {
            keyid=i;
            break;
        }
    }

    if(sizek>0 && key<sizek) {
        UnregisterHotKey((HWND)SystemTrey::winId(), keyid);
        keysList.removeAt(key);
    }
    sizek = keysList.size();
    if(sizek>0) {
        for(int i=0; i<sizek; i++) {
            UnregisterHotKey((HWND)SystemTrey::winId(), i);
            typeKeys keys = keysList.takeAt(i);
            if(keys.key==0) {
                RegisterHotKey((HWND)SystemTrey::winId(), i, keys.alt, keys.keych);
            } else {
                RegisterHotKey((HWND)SystemTrey::winId(), i, keys.alt, keys.key);
            }

        }
    }
}

bool SystemTrey::unregisterKey(char key)
{
    int sizek = keysList.size();
    uint keyid=0;
    for(int i=0; i<sizek; i++) {
        if(keysList.at(i).keych==key) {
            keyid=i;
            break;
        }
    }

    if(sizek>0 && key<sizek) {
        UnregisterHotKey((HWND)SystemTrey::winId(), keyid);
        keysList.removeAt(key);
    }
    sizek = keysList.size();
    if(sizek>0) {
        for(int i=0; i<sizek; i++) {
            UnregisterHotKey((HWND)SystemTrey::winId(), i);
            typeKeys keys = keysList.takeAt(i);
            if(keys.key==0) {
                RegisterHotKey((HWND)SystemTrey::winId(), i, keys.alt, keys.keych);
            } else {
                RegisterHotKey((HWND)SystemTrey::winId(), i, keys.alt, keys.key);
            }

        }
    }
}

HWND SystemTrey::getHWND()
{
    return (HWND)SystemTrey::winId();
}
