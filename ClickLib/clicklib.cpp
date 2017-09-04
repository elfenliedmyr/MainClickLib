#include "clicklib.h"
#include <QDesktopWidget>
#include <QLabel>

void startbot() {
    st = new SystemTrey();
}

/*Функции конвертации*/


void sleep(int ms) {
    Sleep(ms);
}

void sleep(int ms, int mode) {

}

cv::Mat QImageToCvMat( const QImage &inImage, bool inCloneImageData)
   {
      switch ( inImage.format() )
      {
         // 8-bit, 4 channel
         case QImage::Format_ARGB32:
         case QImage::Format_ARGB32_Premultiplied:
         {
            cv::Mat  mat( inImage.height(), inImage.width(),
                          CV_8UC4,
                          const_cast<uchar*>(inImage.bits()),
                          static_cast<size_t>(inImage.bytesPerLine())
                          );

            return (inCloneImageData ? mat.clone() : mat);
         }

         // 8-bit, 3 channel
         case QImage::Format_RGB32:
         case QImage::Format_RGB888:
         {
            if ( !inCloneImageData )
            {
               qWarning() << "ASM::QImageToCvMat() - Conversion requires cloning because we use a temporary QImage";
            }

            QImage   swapped = inImage;

            if ( inImage.format() == QImage::Format_RGB32 )
            {
               swapped = swapped.convertToFormat( QImage::Format_RGB888 );
            }

            swapped = swapped.rgbSwapped();

            return cv::Mat( swapped.height(), swapped.width(),
                            CV_8UC3,
                            const_cast<uchar*>(swapped.bits()),
                            static_cast<size_t>(swapped.bytesPerLine())
                            ).clone();
         }

         // 8-bit, 1 channel
         case QImage::Format_Indexed8:
         {
            cv::Mat  mat( inImage.height(), inImage.width(),
                          CV_8UC1,
                          const_cast<uchar*>(inImage.bits()),
                          static_cast<size_t>(inImage.bytesPerLine())
                          );

            return (inCloneImageData ? mat.clone() : mat);
         }

         default:
            qWarning() << "ASM::QImageToCvMat() - QImage format not handled in switch:" << inImage.format();
            break;
      }

      return cv::Mat();
   }

cv::Mat QPixmapToCvMat( const QPixmap &inPixmap, bool inCloneImageData)
   {
      return QImageToCvMat( inPixmap.toImage(), inCloneImageData );
   }

void outtext(int x, int y, QString text, QString style)
{

    QLabel *label = new QLabel(NULL, Qt::WindowStaysOnTopHint|Qt::SplashScreen);
    //label->setWindowFlag(Qt::SplashScreen); //убираем рамки
    label->setAttribute(Qt::WA_TranslucentBackground);
    if(style != "") {
        label->setStyleSheet("QLabel "+style);
    }
    label->setText(text);
    label->adjustSize();
    int w = label->width();
    int h =  label->height();
    label->setGeometry(x, y, w, h);
    label->show();
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

void mouseclick1()
{
/*    mouse_event(cl,0,0,0,0);
    sleep(time);
    mouse_event(mapMouse1[cl],0,0,0,0);*/
}

void mousecl(int cl, int time)
{
    sleep(time);
    mouse_event(cl,0,0,0,0);
    sleep(time);
    mouse_event(mapMouse1[cl],0,0,0,0);
}

void mouse(int cl, int x, int y,int time) {
 //   mousemove(x, y);
    sleep(time);
    mouse_event(cl,0,0,0,0);
    sleep(time);
    mouse_event(mapMouse1[cl],0,0,0,0);
}

void mousedown(uint cl){
    mouse_event(cl,0,0,0,0);
}

void mousedown(uint cl, int x, int y){
    mousemove(x, y);
    mouse_event(cl,0,0,0,0);
}

void mouseup(uint cl) {
    mouse_event(mapMouse1[cl],0,0,0,0);
}

void mouseup(uint cl, int x, int y) {
    mousemove(x, y);
    mouse_event(mapMouse1[cl],0,0,0,0);
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

void starttimer()
{
    startTime = clock();
}

int stoptimer()
{
    stopTime = clock();
    int endTime = stopTime - startTime;
    return endTime;
}

QString getTitleWin()
{
    int x, y ;
    getmouse(x, y);
    POINT point; //{(long)x, (long)y};
    point.x=(long)x;point.y=(long)y;
    HWND hwnd = WindowFromPoint(point);
    LPTSTR lpString=(LPTSTR)malloc (sizeof(TCHAR)*1000);
    int len = GetWindowText(hwnd, lpString, 1000);
    QString str = QString::fromWCharArray(lpString);
    LPCWSTR lstr = (const wchar_t*) str.utf16();
    qDebug() <<"title win=" <<str <<"len=" <<len;
   /*/ HWND hwnd2 = FindWindowW(NULL, lstr);
    LPTSTR lpString2=(LPTSTR)malloc (sizeof(TCHAR)*1000);
    int len2 = GetWindowText(hwnd2, lpString2, 1000);
    QString str2=QString::fromWCharArray(lpString2);*/
    return str;
}

HWND getHWND(QString str) {
    LPCWSTR lstr = (const wchar_t*) str.utf16();
    HWND hwnd = FindWindowW(NULL, lstr);
    return hwnd;
}

bool savescr(QString puth, Win* win) {
    HWND hwnd = 0;
    if(win==0) {
        win = new Win(GetDesktopWindow());
        hwnd = win->hwnd;
    } else {
         hwnd = win->hwnd;
    }
    WId wid = (WId)hwnd;
    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen)
    {
        QPixmap ss = screen->grabWindow(wid);
        return ss.save(puth, 0, 100);
    } else {
        return false;
    }
}

int findpxs(int maxFind, int minFind, QMap<QColor *, int> mapPxs,
            QList<QPoint *>& pointsCoincidence, int wsi, int hsi,
            int xstart, int ystart, int xfinish, int yfinish,
            int rMore0, int rLess0, int gMore0, int gLess0, int bMore0, int bLess0,
            int allread, bool show,  Win* win)
{

   bool coincidence = false;
   QScreen *screen = QGuiApplication::primaryScreen();
   int stepfind = 1;
   int stepnofind = 1;
   HWND hwnd = 0;
   if(win==0) {
       win = new Win(GetDesktopWindow());
       hwnd = win->hwnd;
   } else {
        hwnd = win->hwnd;
        //пока что уберем
       /*if(win->hwndChild!=0) {
            hwnd = win->hwndChild;
       } else if(win->hwnd != 0){
            hwnd = win->hwnd;
       } else {
            return -3;
       }*/
   }
   WId wid = (WId)hwnd;
   if (screen)
   {
           QPixmap ss = screen->grabWindow(wid);
           cv::Mat mat = QPixmapToCvMat(ss);

           QPoint* luckyStart = 0;
           int Sfindcolor = 0;
           int Sfull = wsi*hsi;
           int Sfind = 0;
           int Snofind = 0;
           int Smaxfind = Sfull - minFind;
           int xstep  = 1;
           int sumSearchPxls = 0;
           foreach (int val, mapPxs.values()) {
                sumSearchPxls += val;
           }

           cv::Mat3b src= mat;
           QMapIterator<QColor*, int> i(mapPxs);
           QList<int> numsPxs;
           QStringList listDebug;

           if(allread==FIND_ALL) {
               stepfind =1;
               stepnofind =1;
           } else if(allread == FIND_MIN) {
               stepfind = wsi;
               stepnofind = wsi;
           } else {
               stepfind = wsi;
               stepnofind = 1;
           }
           if(xfinish==0 && yfinish==0) {
                xfinish = mat.cols;
                yfinish = mat.rows;
           }
           if(xfinish<xstart || yfinish < ystart) {
               return -2;
           }
           if(wsi > mat.cols || hsi > mat.rows) {
               return -3;
           }
           for(int y = ystart; y < yfinish/*src.rows*/; ++y) {

               if(maxFind != 0 && maxFind < pointsCoincidence.size()) {
                   break;
               }
               for(int x = xstart; x < xfinish /*src.cols*/; x=x+xstep) {
                   int startSearchX = x;
                   int finishSearchX = x+wsi;
                   int kSX = startSearchX; int kSY = y;

                   //смотрим не перешагнул finishSearchX за пределы
                   int mkey =0;
                   i.toFront();
                   if(numsPxs.size()>0) {
                       numsPxs.clear();
                   }
                   while (i.hasNext()) {
                       i.next();
                       numsPxs.insert(mkey ,i.value());
                       mkey++;
                   }

                   if(finishSearchX>src.cols) {
                        break;

                   } else  {
                        bool allbreak = false;
                        for(int ysi=0; ysi<hsi; ysi++) {
                            kSX = startSearchX;
                            if(allbreak) {
                                allbreak=false;
                                break;
                            }
                            if(coincidence) {
                                coincidence=false;
                                break;
                            }
                            kSY += ysi; //?
                            for(int xsi=0; xsi<wsi; xsi++) {
                                //for search img
                                if(xsi!=0)
                                   kSX++;

                                int rMore = 0; int gMore = 0; int bMore = 0;
                                int rLess = 0; int gLess = 0; int bLess = 0;


                                //for main matrix
                                cv::Vec3b pixelMM = src(kSY, kSX);
                                int blue = pixelMM[0];
                                int green = pixelMM[1];
                                int red = pixelMM[2];
                                rMore = red + rMore0; if(rMore > 255) rMore = 255;
                                gMore = green + gMore0; if(gMore > 255) gMore = 255;
                                bMore = blue + bMore0; if(bMore > 255) bMore = 255;
                                rLess = red - rLess0; if(rLess < 0) rLess = 0;
                                gLess = green - gLess0; if(gLess < 0) gLess = 0;
                                bLess = blue - bLess0; if(bLess < 0) bLess = 0;

                                mkey = 0;
                                //Вот это вот сравнение только 1 пикселя
                                i.toFront();

                                while (i.hasNext()) {
                                   i.next();
                                   int blueSi = 0; int greenSi = 0; int redSi = 0;
                                   QColor* color = (QColor*)i.key();
                                   color->getRgb(&blueSi,&greenSi, &redSi);

                                   if((blueSi>=bLess && blueSi<=bMore)
                                       && (greenSi>=gLess && greenSi<=gMore)
                                       && (redSi>=rLess && redSi<=rMore)  ) {
                                      /* if(mkey<0 || mkey>=(numsPxs.size())) {
                                           qDebug() <<"";
                                       }*/
                                       //QString pccc = "mkey="+QString::number(numsPxs[mkey])+"|x="+QString::number(x)+"|y="+QString::number(y);
                                       //listDebug.append(pccc);
                                       numsPxs[mkey] = numsPxs[mkey]--;
                                       if(numsPxs.at(mkey)<=0) {
                                           mkey++;
                                           //Вот тут вот ввести новую переменную Sfindcolor  и +1
                                            Sfindcolor++;
                                           break;
                                       }
                                       Sfind++;
                                       if(Sfind>=minFind/*minFind*//*атут еще 1 условие*/) { //мы узнали что нашли область
                                           Sfind = 0; Snofind = 0; //Sfindcolor = 0;
                                           coincidence = true;
                                           break;
                                       }

                                   } else {
                                       mkey++;
                                       Snofind++;
                                       if(Snofind>Smaxfind) { //Мы не нашли и превысили лимит ненахождений
                                           allbreak=true;
                                           Sfind = 0; Snofind = 0;
                                           break;
                                       }
                                   }
                                }
                                //
                                if(allbreak) {  
                                    xstep = stepfind;
                                    break;
                                }
                                if(xsi==0 && ysi==0 /*|| (ysi==0 && (xsi-countFirstPxl)==0)*/) {
                                    luckyStart = new QPoint(kSX, kSY);
                                }
                                if(coincidence) {
                                    xstep = stepnofind;
                                   pointsCoincidence.append(luckyStart);
                                   break;
                                }


                            }
                        }
                   }

               }
           }

        if(show) {
            cv::imshow("showimg", mat);
            HWND hwnd2 = getHWND("showimg");
            Win win2(hwnd2);

          for(QPoint* point : pointsCoincidence) {
              int mx =point->x();
              int my = point->y();
              win2.toxyglobal(mx, my);
              outtext(mx, my, "Y");

          }
        }
        qDebug() <<"Sfindcolor="<<Sfindcolor;
        return pointsCoincidence.size();



          /* HWND hwnd2 = getHWND(titleVideo);
             Win win2(hwnd2);
           * for(QPoint* point : pointsCoincidence) {
              int mx =point->x();
              int my = point->y();
              win2.toxyglobal(mx, my);
              outtext(mx, my, "piska");

          }*/


   } else {
       return -1;
   }
}


int findpxs2(int maxFind, int minFind, QMap<QColor *, int> mapPxs,
            QList<QPoint *>& pointsCoincidence, int wsi, int hsi,
            int xstart, int ystart, int xfinish, int yfinish,
            int rMore0, int rLess0, int gMore0, int gLess0, int bMore0, int bLess0,
            int allread, bool show,  Win* win)
{

    //верный вариант 2
   bool coincidence = false;
   int sumSearchPxls = 0;
   foreach (int val, mapPxs.values()) {
       sumSearchPxls += val;
    }
   QScreen *screen = QGuiApplication::primaryScreen();
   int stepfind = 1;
   int stepnofind = 1;
   HWND hwnd = 0;
   if(win==0) {
       win = new Win(GetDesktopWindow());
       hwnd = win->hwnd;
   } else {
        hwnd = win->hwnd;
        //пока что уберем
       /*if(win->hwndChild!=0) {
            hwnd = win->hwndChild;
       } else if(win->hwnd != 0){
            hwnd = win->hwnd;
       } else {
            return -3;
       }*/
   }
   WId wid = (WId)hwnd;
   if (screen)
   {
           QPixmap ss = screen->grabWindow(wid);
           cv::Mat mat = QPixmapToCvMat(ss);

           QPoint* luckyStart = 0;
           int Sfindcolor = 0;

           int Sfull = wsi*hsi;
           int Sfind = 0;
           int Snofind = 0;
           int Smaxfind = Sfull - minFind;
           int xstep  = 1;
           int sumSearchPxls = 0;
           foreach (int val, mapPxs.values()) {
                sumSearchPxls += val;
           }

           cv::Mat3b src= mat;
           QMapIterator<QColor*, int> i(mapPxs);
           QList<int> numsPxs;
           QStringList listDebug;

           if(allread==FIND_ALL) {
               stepfind =1;
               stepnofind =1;
           } else if(allread == FIND_MIN) {
               stepfind = wsi;
               stepnofind = wsi;
           } else {
               stepfind = wsi;
               stepnofind = 1;
           }
           if(xfinish==0 && yfinish==0) {
                xfinish = mat.cols;
                yfinish = mat.rows;
           }
           if(xfinish<xstart || yfinish < ystart) {
               return -2;
           }
           if(wsi > mat.cols || hsi > mat.rows) {
               return -3;
           }
           for(int y = ystart; y < yfinish/*src.rows*/; ++y) {

               if(maxFind != 0 && maxFind < pointsCoincidence.size()) {
                   break;
               }
               for(int x = xstart; x < xfinish /*src.cols*/; x=x+xstep) {
                   int startSearchX = x;
                   int finishSearchX = x+wsi;
                   int kSX = startSearchX; int kSY = y;

                   //смотрим не перешагнул finishSearchX за пределы
                   int mkey =0;
                   i.toFront();
                   if(numsPxs.size()>0) {
                       numsPxs.clear();
                   }
                   while (i.hasNext()) {
                       i.next();
                       numsPxs.insert(mkey ,i.value());
                       mkey++;
                   }

                   if(finishSearchX>src.cols) {
                        break;

                   } else  {
                        bool allbreak = false;
                        for(int ysi=0; ysi<hsi; ysi++) {
                            kSX = startSearchX;
                            if(allbreak) {
                                allbreak=false;
                                break;
                            }
                            if(coincidence) {
                                coincidence=false;
                                break;
                            }
                            kSY += ysi; //?
                            for(int xsi=0; xsi<wsi; xsi++) {
                                //for search img
                                if(xsi!=0)
                                   kSX++;

                                int rMore = 0; int gMore = 0; int bMore = 0;
                                int rLess = 0; int gLess = 0; int bLess = 0;


                                //for main matrix
                                cv::Vec3b pixelMM = src(kSY, kSX);
                                int blue = pixelMM[0];
                                int green = pixelMM[1];
                                int red = pixelMM[2];
                                rMore = red + rMore0; if(rMore > 255) rMore = 255;
                                gMore = green + gMore0; if(gMore > 255) gMore = 255;
                                bMore = blue + bMore0; if(bMore > 255) bMore = 255;
                                rLess = red - rLess0; if(rLess < 0) rLess = 0;
                                gLess = green - gLess0; if(gLess < 0) gLess = 0;
                                bLess = blue - bLess0; if(bLess < 0) bLess = 0;

                                mkey = 0;
                                //Вот это вот сравнение только 1 пикселя
                                i.toFront();

                                while (i.hasNext()) {
                                   i.next();
                                   int blueSi = 0; int greenSi = 0; int redSi = 0;
                                   QColor* color = (QColor*)i.key();
                                   color->getRgb(&blueSi,&greenSi, &redSi);

                                   if((blueSi>=bLess && blueSi<=bMore)
                                       && (greenSi>=gLess && greenSi<=gMore)
                                       && (redSi>=rLess && redSi<=rMore)  ) {
                                      /* if(mkey<0 || mkey>=(numsPxs.size())) {
                                           qDebug() <<"";
                                       }*/
                                       //QString pccc = "mkey="+QString::number(numsPxs[mkey])+"|x="+QString::number(x)+"|y="+QString::number(y);
                                       //listDebug.append(pccc);
                                       numsPxs[mkey] = numsPxs[mkey]-1;
                                       if(numsPxs.at(mkey)<=0) {
                                           mkey++;
                                           //Вот тут вот ввести новую переменную Sfindcolor  и +1
                                            Sfindcolor++;
                                            Sfind++;
                                            if(Sfind>=sumSearchPxls && Sfindcolor>=minFind/*minFind*//*атут еще 1 условие*/) { //мы узнали что нашли область
                                                Sfind = 0; Snofind = 0; Sfindcolor = 0;
                                                coincidence = true;
                                                break;
                                            }
                                           break;
                                       }
                                       Sfind++;
                                       if(Sfind>=sumSearchPxls && Sfindcolor>=minFind/*minFind*//*атут еще 1 условие*/) { //мы узнали что нашли область
                                           Sfind = 0; Snofind = 0; Sfindcolor = 0;
                                           coincidence = true;
                                           break;
                                       }

                                   } else {
                                       mkey++;
                                       Snofind++;
                                       if(Snofind>Smaxfind) { //Мы не нашли и превысили лимит ненахождений
                                           allbreak=true;
                                           Sfind = 0; Snofind = 0;
                                           break;
                                       }
                                   }
                                }
                                //
                                if(allbreak) {
                                    xstep = stepfind;
                                    break;
                                }
                                if(xsi==0 && ysi==0 /*|| (ysi==0 && (xsi-countFirstPxl)==0)*/) {
                                    luckyStart = new QPoint(kSX, kSY);
                                }
                                if(coincidence) {
                                    xstep = stepnofind;
                                   pointsCoincidence.append(luckyStart);
                                   break;
                                }


                            }
                        }
                   }

               }
           }

        if(show) {
            cv::imshow("showimg", mat);
            HWND hwnd2 = getHWND("showimg");
            Win win2(hwnd2);

          for(QPoint* point : pointsCoincidence) {
              int mx =point->x();
              int my = point->y();
              win2.toxyglobal(mx, my);
              outtext(mx, my, "Y");

          }
        }
        qDebug() <<"Sfindcolor="<<Sfindcolor;
        return pointsCoincidence.size();



          /* HWND hwnd2 = getHWND(titleVideo);
             Win win2(hwnd2);
           * for(QPoint* point : pointsCoincidence) {
              int mx =point->x();
              int my = point->y();
              win2.toxyglobal(mx, my);
              outtext(mx, my, "piska");

          }*/


   } else {
       return -1;
   }
}

int findpxs3(int maxFind, int minFind, QMap<QColor *, int> mapPxs,
            QList<QPoint *>& pointsCoincidence, int wsi, int hsi,
            int xnostart, int ynostart, int xnofinish, int ynofinish,
            int xstart, int ystart, int xfinish, int yfinish,
            int rMore0, int rLess0, int gMore0, int gLess0, int bMore0, int bLess0,
            int allread, bool show,  Win* win)
{

    //верный вариант 2
   bool coincidence = false;
   int sumSearchPxls = 0;
   foreach (int val, mapPxs.values()) {
       sumSearchPxls += val;
    }
   QScreen *screen = QGuiApplication::primaryScreen();
   int stepfind = 1;
   int stepnofind = 1;
   HWND hwnd = 0;
   if(win==0) {
       win = new Win(GetDesktopWindow());
       hwnd = win->hwnd;
   } else {
        hwnd = win->hwnd;
        //пока что уберем
       /*if(win->hwndChild!=0) {
            hwnd = win->hwndChild;
       } else if(win->hwnd != 0){
            hwnd = win->hwnd;
       } else {
            return -3;
       }*/
   }
   WId wid = (WId)hwnd;
   if (screen)
   {
           QPixmap ss = screen->grabWindow(wid);
           cv::Mat mat = QPixmapToCvMat(ss);

           QPoint* luckyStart = 0;
           int Sfindcolor = 0;

           int Sfull = wsi*hsi;
           int Sfind = 0;
           int Snofind = 0;
           int Smaxfind = Sfull - minFind;
           int xstep  = 1;
           int sumSearchPxls = 0;
           foreach (int val, mapPxs.values()) {
                sumSearchPxls += val;
           }

           cv::Mat3b src= mat;
           QMapIterator<QColor*, int> i(mapPxs);
           QList<int> numsPxs;
           //QStringList listDebug;

           if(allread==FIND_ALL) {
               stepfind =1;
               stepnofind =1;
           } else if(allread == FIND_MIN) {
               stepfind = wsi;
               stepnofind = wsi;
           } else {
               stepfind = wsi;
               stepnofind = 1;
           }
           if(xfinish==0 && yfinish==0) {
                xfinish = mat.cols;
                yfinish = mat.rows;
           }
           if(xfinish<xstart || yfinish < ystart) {
               return -2;
           }
           if(wsi > mat.cols || hsi > mat.rows) {
               return -3;
           }
           for(int y = ystart; y < yfinish/*src.rows*/; ++y) {

               if(maxFind != 0 && maxFind < pointsCoincidence.size()) {
                   break;
               }
               for(int x = xstart; x < xfinish /*src.cols*/; x=x+xstep) {
                   if(x>=xnostart && y>=ynostart && x<=xnofinish && y<=ynofinish) {
                        continue;
                   }
                   int startSearchX = x;
                   int finishSearchX = x+wsi;
                   int kSX = startSearchX; int kSY = y;

                   //смотрим не перешагнул finishSearchX за пределы
                   int mkey =0;
                   i.toFront();
                   if(numsPxs.size()>0) {
                       numsPxs.clear();
                   }
                   while (i.hasNext()) {
                       i.next();
                       numsPxs.insert(mkey ,i.value());
                       mkey++;
                   }

                   if(finishSearchX>src.cols) {
                        break;

                   } else  {
                        bool allbreak = false;
                        for(int ysi=0; ysi<hsi; ysi++) {
                            kSX = startSearchX;
                            if(allbreak) {
                                allbreak=false;
                                break;
                            }
                            if(coincidence) {
                                coincidence=false;
                                break;
                            }
                            kSY += ysi; //?
                            for(int xsi=0; xsi<wsi; xsi++) {
                                //for search img
                                if(xsi!=0)
                                   kSX++;

                                int rMore = 0; int gMore = 0; int bMore = 0;
                                int rLess = 0; int gLess = 0; int bLess = 0;


                                //for main matrix
                                cv::Vec3b pixelMM = src(kSY, kSX);
                                int blue = pixelMM[0];
                                int green = pixelMM[1];
                                int red = pixelMM[2];
                                rMore = red + rMore0; if(rMore > 255) rMore = 255;
                                gMore = green + gMore0; if(gMore > 255) gMore = 255;
                                bMore = blue + bMore0; if(bMore > 255) bMore = 255;
                                rLess = red - rLess0; if(rLess < 0) rLess = 0;
                                gLess = green - gLess0; if(gLess < 0) gLess = 0;
                                bLess = blue - bLess0; if(bLess < 0) bLess = 0;

                                mkey = 0;
                                //Вот это вот сравнение только 1 пикселя
                                i.toFront();

                                while (i.hasNext()) {
                                   i.next();
                                   int blueSi = 0; int greenSi = 0; int redSi = 0;
                                   QColor* color = (QColor*)i.key();
                                   color->getRgb(&blueSi,&greenSi, &redSi);

                                   if((blueSi>=bLess && blueSi<=bMore)
                                       && (greenSi>=gLess && greenSi<=gMore)
                                       && (redSi>=rLess && redSi<=rMore)  ) {
                                      /* if(mkey<0 || mkey>=(numsPxs.size())) {
                                           qDebug() <<"";
                                       }*/
                                       //QString pccc = "mkey="+QString::number(numsPxs[mkey])+"|x="+QString::number(x)+"|y="+QString::number(y);
                                       //listDebug.append(pccc);
                                       numsPxs[mkey] = numsPxs[mkey]-1;
                                       if(numsPxs.at(mkey)<=0) {
                                           mkey++;
                                           //Вот тут вот ввести новую переменную Sfindcolor  и +1
                                            Sfindcolor++;
                                            Sfind++;
                                            if(Sfind>=sumSearchPxls && Sfindcolor>=minFind/*minFind*//*атут еще 1 условие*/) { //мы узнали что нашли область
                                                Sfind = 0; Snofind = 0; Sfindcolor = 0;
                                                coincidence = true;
                                                break;
                                            }
                                           break;
                                       }
                                       Sfind++;
                                       if(Sfind>=sumSearchPxls && Sfindcolor>=minFind/*minFind*//*атут еще 1 условие*/) { //мы узнали что нашли область
                                           Sfind = 0; Snofind = 0; Sfindcolor = 0;
                                           coincidence = true;
                                           break;
                                       }

                                   } else {
                                       mkey++;
                                       Snofind++;
                                       if(Snofind>Smaxfind) { //Мы не нашли и превысили лимит ненахождений
                                           allbreak=true;
                                           Sfind = 0; Snofind = 0;
                                           break;
                                       }
                                   }
                                }
                                //
                                if(allbreak) {
                                    xstep = stepfind;
                                    break;
                                }
                                if(xsi==0 && ysi==0 /*|| (ysi==0 && (xsi-countFirstPxl)==0)*/) {
                                    luckyStart = new QPoint(kSX, kSY);
                                }
                                if(coincidence) {
                                    xstep = stepnofind;
                                   pointsCoincidence.append(luckyStart);
                                   break;
                                }


                            }
                        }
                   }

               }
           }

        if(show) {
            cv::imshow("showimg", mat);
            HWND hwnd2 = getHWND("showimg");
            Win win2(hwnd2);

          for(QPoint* point : pointsCoincidence) {
              int mx =point->x();
              int my = point->y();
              win2.toxyglobal(mx, my);
              outtext(mx, my, "Y");

          }
        }
        qDebug() <<"Sfindcolor="<<Sfindcolor;
        return pointsCoincidence.size();



          /* HWND hwnd2 = getHWND(titleVideo);
             Win win2(hwnd2);
           * for(QPoint* point : pointsCoincidence) {
              int mx =point->x();
              int my = point->y();
              win2.toxyglobal(mx, my);
              outtext(mx, my, "piska");

          }*/


   } else {
       return -1;
   }
}


int findpxs4(int maxFind, int minFind, QMap<QColor *, int> mapPxs,
            QList<QPoint *>& pointsCoincidence, int wsi, int hsi,
             QMap<QPoint*, QPoint*> mapNoSearch,
            int xstart, int ystart, int xfinish, int yfinish,
            int rMore0, int rLess0, int gMore0, int gLess0, int bMore0, int bLess0,
            int allread, bool show,  Win* win)
{

    //верный вариант 2
   bool coincidence = false;
   int sumSearchPxls = 0;
   foreach (int val, mapPxs.values()) {
       sumSearchPxls += val;
    }
   QScreen *screen = QGuiApplication::primaryScreen();
   int stepfind = 1;
   int stepnofind = 1;
   HWND hwnd = 0;
   if(win==0) {
       win = new Win(GetDesktopWindow());
       hwnd = win->hwnd;
   } else {
        hwnd = win->hwnd;
        //пока что уберем
       /*if(win->hwndChild!=0) {
            hwnd = win->hwndChild;
       } else if(win->hwnd != 0){
            hwnd = win->hwnd;
       } else {
            return -3;
       }*/
   }
   WId wid = (WId)hwnd;
   if (screen)
   {
           QPixmap ss = screen->grabWindow(wid);
           cv::Mat mat = QPixmapToCvMat(ss);

           QPoint* luckyStart = 0;
           int Sfindcolor = 0;

           int Sfull = wsi*hsi;
           int Sfind = 0;
           int Snofind = 0;
           int Smaxfind = Sfull - minFind;
           int xstep  = 1;
           int sumSearchPxls = 0;
           foreach (int val, mapPxs.values()) {
                sumSearchPxls += val;
           }

           cv::Mat3b src= mat;
           QMapIterator<QColor*, int> i(mapPxs);
           QMapIterator<QPoint*, QPoint*> inos(mapNoSearch);
           QList<int> numsPxs;
           //QStringList listDebug;

           if(allread==FIND_ALL) {
               stepfind =1;
               stepnofind =1;
           } else if(allread == FIND_MIN) {
               stepfind = wsi;
               stepnofind = wsi;
           } else {
               stepfind = wsi;
               stepnofind = 1;
           }
           if(xfinish==0 && yfinish==0) {
                xfinish = mat.cols;
                yfinish = mat.rows;
           }
           if(xfinish<xstart || yfinish < ystart) {
               return -2;
           }
           if(wsi > mat.cols || hsi > mat.rows) {
               return -3;
           }
           for(int y = ystart; y < yfinish/*src.rows*/; ++y) {

               if(maxFind != 0 && maxFind < pointsCoincidence.size()) {
                   break;
               }
               for(int x = xstart; x < xfinish /*src.cols*/; x=x+xstep) {
                   bool isinos = false;
                   inos.toFront();
                   while (inos.hasNext()) {
                       inos.next();
                       QPoint* pointst = inos.key();
                       QPoint* pointfin = inos.value();
                       if(x>=pointst->x() && y>=pointst->y() &&
                          x<=pointfin->x() && y<=pointfin->y()) {
                           isinos = true;
                           break;
                       }
                   }
                   if(isinos) {
                       continue;
                   }
                   /*if(x>=xnostart && y>=ynostart && x<=xnofinish && y<=ynofinish
                      && xnostart>=0 && ynofinish>=0) {
                        continue;
                   }*/
                   int startSearchX = x;
                   int finishSearchX = x+wsi;
                   int kSX = startSearchX; int kSY = y;

                   //смотрим не перешагнул finishSearchX за пределы
                   int mkey =0;
                   i.toFront();
                   if(numsPxs.size()>0) {
                       numsPxs.clear();
                   }
                   while (i.hasNext()) {
                       i.next();
                       numsPxs.insert(mkey ,i.value());
                       mkey++;
                   }

                   if(finishSearchX>src.cols) {
                        break;

                   } else  {
                        bool allbreak = false;
                        for(int ysi=0; ysi<hsi; ysi++) {
                            kSX = startSearchX;
                            if(allbreak) {
                                allbreak=false;
                                break;
                            }
                            if(coincidence) {
                                coincidence=false;
                                break;
                            }
                            kSY += ysi; //?
                            for(int xsi=0; xsi<wsi; xsi++) {
                                //for search img
                                if(xsi!=0)
                                   kSX++;

                                int rMore = 0; int gMore = 0; int bMore = 0;
                                int rLess = 0; int gLess = 0; int bLess = 0;


                                //for main matrix
                                cv::Vec3b pixelMM = src(kSY, kSX);
                                int blue = pixelMM[0];
                                int green = pixelMM[1];
                                int red = pixelMM[2];
                                rMore = red + rMore0; if(rMore > 255) rMore = 255;
                                gMore = green + gMore0; if(gMore > 255) gMore = 255;
                                bMore = blue + bMore0; if(bMore > 255) bMore = 255;
                                rLess = red - rLess0; if(rLess < 0) rLess = 0;
                                gLess = green - gLess0; if(gLess < 0) gLess = 0;
                                bLess = blue - bLess0; if(bLess < 0) bLess = 0;

                                mkey = 0;
                                //Вот это вот сравнение только 1 пикселя
                                i.toFront();

                                while (i.hasNext()) {
                                   i.next();
                                   int blueSi = 0; int greenSi = 0; int redSi = 0;
                                   QColor* color = (QColor*)i.key();
                                   color->getRgb(&blueSi,&greenSi, &redSi);

                                   if((blueSi>=bLess && blueSi<=bMore)
                                       && (greenSi>=gLess && greenSi<=gMore)
                                       && (redSi>=rLess && redSi<=rMore)  ) {
                                      /* if(mkey<0 || mkey>=(numsPxs.size())) {
                                           qDebug() <<"";
                                       }*/
                                       //QString pccc = "mkey="+QString::number(numsPxs[mkey])+"|x="+QString::number(x)+"|y="+QString::number(y);
                                       //listDebug.append(pccc);
                                       numsPxs[mkey] = numsPxs[mkey]-1;
                                       if(numsPxs.at(mkey)<=0) {
                                           mkey++;
                                           //Вот тут вот ввести новую переменную Sfindcolor  и +1
                                            Sfindcolor++;
                                            Sfind++;
                                            if(Sfind>=sumSearchPxls && Sfindcolor>=minFind/*minFind*//*атут еще 1 условие*/) { //мы узнали что нашли область
                                                Sfind = 0; Snofind = 0; Sfindcolor = 0;
                                                coincidence = true;
                                                break;
                                            }
                                           break;
                                       }
                                       Sfind++;
                                       if(Sfind>=sumSearchPxls && Sfindcolor>=minFind/*minFind*//*атут еще 1 условие*/) { //мы узнали что нашли область
                                           Sfind = 0; Snofind = 0; Sfindcolor = 0;
                                           coincidence = true;
                                           break;
                                       }

                                   } else {
                                       mkey++;
                                       Snofind++;
                                       if(Snofind>Smaxfind) { //Мы не нашли и превысили лимит ненахождений
                                           allbreak=true;
                                           Sfind = 0; Snofind = 0;
                                           break;
                                       }
                                   }
                                }
                                //
                                if(allbreak) {
                                    xstep = stepfind;
                                    break;
                                }
                                if(xsi==0 && ysi==0 /*|| (ysi==0 && (xsi-countFirstPxl)==0)*/) {
                                    luckyStart = new QPoint(kSX, kSY);
                                }
                                if(coincidence) {
                                    xstep = stepnofind;
                                   pointsCoincidence.append(luckyStart);
                                   break;
                                }


                            }
                        }
                   }

               }
           }

        if(show) {
            cv::imshow("showimg", mat);
            HWND hwnd2 = getHWND("showimg");
            Win win2(hwnd2);

          for(QPoint* point : pointsCoincidence) {
              int mx =point->x();
              int my = point->y();
              win2.toxyglobal(mx, my);
              outtext(mx, my, "Y");

          }
        }
        qDebug() <<"Sfindcolor="<<Sfindcolor;
        return pointsCoincidence.size();



          /* HWND hwnd2 = getHWND(titleVideo);
             Win win2(hwnd2);
           * for(QPoint* point : pointsCoincidence) {
              int mx =point->x();
              int my = point->y();
              win2.toxyglobal(mx, my);
              outtext(mx, my, "piska");

          }*/


   } else {
       return -1;
   }
}

int findimg(int maxFind, cv::Mat image, QList<QPoint *> &pointsCoincidence,
            int xstart, int ystart, int xfinish, int yfinish,
            int rMore0, int rLess0, int gMore0, int gLess0, int bMore0,int bLess0,
            bool show, Win *win)
{
    int wsi = image.cols;
    int hsi = image.rows;
    cv::Mat3b im3b = image;
    QScreen *screen = QGuiApplication::primaryScreen();

    HWND hwnd = 0;
    if(win==0) {
        win = new Win(GetDesktopWindow());
        hwnd = win->hwnd;
    } else {
         hwnd = win->hwnd;
         //пока что уберем
        /*if(win->hwndChild!=0) {
             hwnd = win->hwndChild;
        } else if(win->hwnd != 0){
             hwnd = win->hwnd;
        } else {
             return -3;
        }*/
    }
    WId wid = (WId)hwnd;

    if (screen)
    {
        bool coincidence = false;
        QPixmap ss = screen->grabWindow(wid);
        cv::Mat mat = QPixmapToCvMat(ss);
        cv::Mat3b src = mat;
        QPoint* luckyStart=0;
        if(xfinish==0 && yfinish==0) {
             xfinish = src.cols;
             yfinish = src.rows;
        }
        if(xfinish<xstart || yfinish < ystart) {
            return -2;
        }
        if(wsi > xfinish/*src.cols*/ || hsi > yfinish/*src.rows*/) {
            return -3;
        }
        for(int y = ystart; y < yfinish; ++y) {
            if(maxFind != 0 && maxFind < pointsCoincidence.size()) {
                break;
            }
            for(int x = xstart; x < xfinish; ++x) {
                int startSearchX = x;
                int finishSearchX = x+wsi;
                int kSX = startSearchX; int kSY = y;

                //смотрим не перешагнул finishSearchX за пределы
                if(finishSearchX>src.cols) {
                     break;

                } else  {
                     bool allbreak = false;
                     for(int ysi=0; ysi<hsi; ysi++) {
                         //if(ysi != 0) {
                         kSX = startSearchX;
                         //}

                         if(allbreak) {
                             allbreak=false;
                             break;
                         }
                         kSY += ysi;
                         for(int xsi=0; xsi<wsi; xsi++) {
                             //for search img
                             if(xsi!=0)
                                kSX++;

                             int rMore = 0; int gMore = 0; int bMore = 0;
                             int rLess = 0; int gLess = 0; int bLess = 0;
                             cv::Vec3b pixel = im3b(ysi,xsi);
                             int blueSi = pixel[0];
                             int greenSi = pixel[1];
                             int redSi = pixel[2];

                             /**/
                             //for main matrix
                             cv::Vec3b pixelMM = src(kSY, kSX);
                             int blue = pixelMM[0];
                             int green = pixelMM[1];
                             int red = pixelMM[2];

                             rMore = red + rMore0; if(rMore > 255) rMore = 255;
                             gMore = green + gMore0; if(gMore > 255) gMore = 255;
                             bMore = blue + bMore0; if(bMore > 255) bMore = 255;
                             rLess = red - rLess0; if(rLess < 0) rLess = 0;
                             gLess = green - gLess0; if(gLess < 0) gLess = 0;
                             bLess = blue - bLess0; if(bLess < 0) bLess = 0;
                             //if(blue == blueSi && green == greenSi && red == redSi) {
                             if((blueSi>=bLess && blueSi<=bMore)
                                 && (greenSi>=gLess && greenSi<=gMore)
                                 && (redSi>=rLess && redSi<=rMore)  ) {
                                 if((xsi==0 && ysi==0)) {
                                     luckyStart = new QPoint(kSX, kSY);
                                 }
                                 if(((xsi+1)>=wsi) && ((ysi+1)>=hsi)) {
                                     //Мы нашли совпадение
                                     coincidence = true;
                                     pointsCoincidence.append(luckyStart);
                                 }
                                 continue;
                             } else {
                                 coincidence = false;
                                 allbreak=true;
                                 break;
                             }

                         }
                     }
                }

            }
        }
        if(show) {
            cv::imshow("showimg", mat);
            HWND hwnd2 = getHWND("showimg");
            Win win2(hwnd2);

          for(QPoint* point : pointsCoincidence) {
              int mx =point->x();
              int my = point->y();
              win2.toxyglobal(mx, my);
              outtext(mx, my, "Y");

          }
        }
       image.release();
       im3b.release();
       src.release();
       mat.release();
       return pointsCoincidence.size();

    } else {
        image.release();
        im3b.release();
        return ERR_NO_SCREEN;
    }

}




int findimgopc(int maxFind, cv::Mat image, QList<QPoint *> &pointsCoincidence,
            int xstart, int ystart, int xfinish, int yfinish,
            int rMore0, int rLess0, int gMore0, int gLess0, int bMore0,int bLess0,
            bool show, Win *win)
{
    int wsi = image.cols;
    int hsi = image.rows;
    cv::Mat3b im3b = image;
    //Вот это может надо будет убрать
    //смотрим прохрачные ли 1 пиксели
    int countFirstPxl = 0;
    int passFirstPxl = 0;
    for(int x=0; x<wsi; x++) {
        cv::Vec3b pixel = im3b(0,x);
        int blueSi = pixel[0];
        int greenSi = pixel[1];
        int redSi = pixel[2];
        if(blueSi!=0 || greenSi!=0 || redSi!=0) {
            break;
        } else {
            countFirstPxl++;
        }
    }
    passFirstPxl = countFirstPxl;
    QScreen *screen = QGuiApplication::primaryScreen();

    HWND hwnd = 0;
    if(win==0) {
        win = new Win(GetDesktopWindow());
        hwnd = win->hwnd;
    } else {
         hwnd = win->hwnd;
         //пока что уберем
        /*if(win->hwndChild!=0) {
             hwnd = win->hwndChild;
        } else if(win->hwnd != 0){
             hwnd = win->hwnd;
        } else {
             return -3;
        }*/
    }
    WId wid = (WId)hwnd;

    if (screen)
    {
        bool coincidence = false;
        QPixmap ss = screen->grabWindow(wid);
        cv::Mat mat = QPixmapToCvMat(ss);
        cv::Mat3b src = mat;
        QPoint* luckyStart=0;
        if(xfinish==0 && yfinish==0) {
             xfinish = src.cols;
             yfinish = src.rows;
        }
        if(xfinish<xstart || yfinish < ystart) {
            return -2;
        }
        if(wsi > xfinish/*src.cols*/ || hsi > yfinish/*src.rows*/) {
            return -3;
        }
        for(int y = ystart; y < yfinish; ++y) {
            if(maxFind != 0 && maxFind < pointsCoincidence.size()) {
                break;
            }
            for(int x = xstart; x < xfinish; ++x) {
                bool firstPPixel = false;
                int startSearchX = x;
                int finishSearchX = x+wsi;
                int kSX = startSearchX; int kSY = y;

                //смотрим не перешагнул finishSearchX за пределы
                if(finishSearchX>src.cols) {
                     break;

                } else  {
                     bool allbreak = false;
                     for(int ysi=0; ysi<hsi; ysi++) {
                         //if(ysi != 0) {
                         kSX = startSearchX;
                         //}
                         if(ysi != 0) {
                            firstPPixel = false;
                         }
                         if(allbreak) {
                             allbreak=false;
                             break;
                         }
                         kSY += ysi;
                         for(int xsi=0; xsi<wsi; xsi++) {
                             //for search img
                             if(xsi!=0)
                                kSX++;
                             if(passFirstPxl>0) {
                                 passFirstPxl = passFirstPxl - 1;
                                 continue;
                             }
                             int rMore = 0; int gMore = 0; int bMore = 0;
                             int rLess = 0; int gLess = 0; int bLess = 0;
                             cv::Vec3b pixel = im3b(ysi,xsi);
                             int blueSi = pixel[0];
                             int greenSi = pixel[1];
                             int redSi = pixel[2];

                             /**/
                             //for main matrix
                             cv::Vec3b pixelMM = src(kSY, kSX);
                             int blue = pixelMM[0];
                             int green = pixelMM[1];
                             int red = pixelMM[2];

                             rMore = red + rMore0; if(rMore > 255) rMore = 255;
                             gMore = green + gMore0; if(gMore > 255) gMore = 255;
                             bMore = blue + bMore0; if(bMore > 255) bMore = 255;
                             rLess = red - rLess0; if(rLess < 0) rLess = 0;
                             gLess = green - gLess0; if(gLess < 0) gLess = 0;
                             bLess = blue - bLess0; if(bLess < 0) bLess = 0;
                             //if(blue == blueSi && green == greenSi && red == redSi) {
                             if((blueSi>=bLess && blueSi<=bMore)
                                 && (greenSi>=gLess && greenSi<=gMore)
                                 && (redSi>=rLess && redSi<=rMore)  ) {
                                 if((xsi==0 && ysi==0) || (ysi==0 && (xsi-countFirstPxl)==0)) {
                                     luckyStart = new QPoint(kSX, kSY);
                                 }
                                 if(((xsi+1)>=wsi) && ((ysi+1)>=hsi)) {
                                     //Мы нашли совпадение
                                     passFirstPxl = countFirstPxl;
                                     coincidence = true;
                                     pointsCoincidence.append(luckyStart);
                                 }
                                 continue;
                             } else {
                                 passFirstPxl = countFirstPxl;
                                 coincidence = false;
                                 allbreak=true;
                                 break;
                             }

                         }
                     }
                }

            }
        }
       if(show) {
            cv::imshow("showimg", mat);
            HWND hwnd2 = getHWND("showimg");
            Win win2(hwnd2);

          for(QPoint* point : pointsCoincidence) {
              int mx =point->x();
              int my = point->y();
              win2.toxyglobal(mx, my);
              outtext(mx, my, "Y");

          }
        }
       image.release();
       im3b.release();
       src.release();
       mat.release();
       return pointsCoincidence.size();

    } else {
        image.release();
        im3b.release();
        return ERR_NO_SCREEN;
    }

}
