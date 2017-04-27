#ifndef SYSTEMTREY_H
#define SYSTEMTREY_H
#include <QLabel>
#include <windows.h>
class QSystemTrayIcon;
class QMenu;

class SystemTrey  : public QLabel {
    Q_OBJECT
    struct typeKeys {
        uint alt;
        uint key;
        char keych;
        void (*f)(uint key, char keych, uint mode);
    };
private:
    QSystemTrayIcon* m_ptrayIcon;
    QMenu*           m_ptrayIconMenu;
public:
    QList<typeKeys> keysList;
    SystemTrey(QWidget* pwgt = 0);
    bool nativeEvent(const QByteArray & eventType, void * message, long * result);
    void registerKey(uint alt, char key, void (*f)(uint key, char keych, uint mode));
    void registerKey(uint alt, uint key, void (*f)(uint key, char keych, uint mode));
    bool unregisterKey(uint key);
    bool unregisterKey(char key);
    HWND getHWND();
};

#endif // SYSTEMTREY_H
