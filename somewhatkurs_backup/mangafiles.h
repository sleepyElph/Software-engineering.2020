#ifndef MANGAFILES_H
#define MANGAFILES_H
#include <QPixmap>
#include <QFileDialog>
#include <QDir>
#include "mainwindow.h"

class MangaFiles
{
public:
    MangaFiles();
    QPixmap FirstPage();
    QPixmap PrevPage();
    QPixmap NextPage();
    int GetPage();
    int GetTotalPages();
    std::tuple<QVector<QPixmap>, QVector<QString>> TestVar(const QString folderPath, int start, int required_space);
private:
    int currentPage=0;
    QFileInfoList imagesList;
};

#endif // MANGAFILES_H
