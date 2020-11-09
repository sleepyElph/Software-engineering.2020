#include "mangafiles.h"

MangaFiles::MangaFiles()
{

}

QPixmap MangaFiles::FirstPage(){
    QStringList filter;
    filter << QLatin1String("*.png");
    filter << QLatin1String("*.jpeg");
    filter << QLatin1String("*.jpg");
    if (DataTransfer::reading_state==1){
        QDir images(DataTransfer::first_title_list_path);
        images.setNameFilters(filter);
        imagesList= images.entryInfoList(QDir::Files);
    }else{
        if (DataTransfer::reading_state==2){
             QDir images(DataTransfer::second_title_list_path);
             images.setNameFilters(filter);
             imagesList= images.entryInfoList(QDir::Files);
        }else{
            if (DataTransfer::reading_state==3){
                QDir images(DataTransfer::third_title_list_path);
                images.setNameFilters(filter);
                imagesList= images.entryInfoList(QDir::Files);
            }else{
                if (DataTransfer::reading_state==4){
                    QDir images(DataTransfer::forth_title_list_path);
                    images.setNameFilters(filter);
                    imagesList= images.entryInfoList(QDir::Files);
                }
            }
        }
    }
    if( imagesList.count()!=0){
    QFileInfo now=imagesList.at(currentPage);
    QString imageFile1 = now.absoluteFilePath();
    QPixmap p3(imageFile1);
    return p3;
    }else{
        return QPixmap();
    }
}

std::tuple<QVector<QPixmap>,QVector<QString>> MangaFiles::TestVar(const QString folderPath, int start, int required_space){
    int counter=0;
    QDir dir(folderPath);
    QVector<QPixmap> PixVect;
    QVector<QString> StrVect;
    for (int i=start;i<(start+required_space);i++){
        QString dirFile= dir.entryInfoList(QDir::AllDirs | QDir::NoDotAndDotDot).at(i).absoluteFilePath();
        QDir titleImgDir(dirFile);
        QFileInfoList tempImg= titleImgDir.entryInfoList(QDir::AllDirs | QDir::NoDotDot);
        foreach (const QFileInfo &img, tempImg){                                //алгоритм обхода директорий с фотками(то есть самих тайтлов)
            QString dirFile1 = img.absoluteFilePath();

            QDir images(dirFile1);

            if (counter==0){                                                        //тут загрузка тайтлов в ячейки меню
                DataTransfer::first_title_list_path=dirFile1;
                StrVect.push_back(images.dirName());
                int c=0;
                QFileInfoList imagesList= images.entryInfoList(QDir::Files);
                foreach (const QFileInfo &imageInfo, imagesList){                   //алгоритм обхода фоток
                    QString actImage=imageInfo.absoluteFilePath();
                    if (c==0){
                        PixVect.push_back(actImage);
                    } else break;
                    c++;
                }
            }
            if (counter==1){
                DataTransfer::second_title_list_path=dirFile1;
                StrVect.push_back(images.dirName());
                int c=0;
                QFileInfoList imagesList= images.entryInfoList(QDir::Files);
                foreach (const QFileInfo &imageInfo, imagesList){    //алгоритм обхода фоток
                    QString actImage=imageInfo.absoluteFilePath();
                    if (c==0){
                        PixVect.push_back(actImage);} else break;
                    c++;
                }
            }
            if (counter==2){
                DataTransfer::third_title_list_path=dirFile1;
                StrVect.push_back(images.dirName());
                int c=0;
                QFileInfoList imagesList= images.entryInfoList(QDir::Files);
                foreach (const QFileInfo &imageInfo, imagesList){    //алгоритм обхода фоток
                    QString actImage=imageInfo.absoluteFilePath();
                    if (c==0){PixVect.push_back(actImage);} else break;
                    c++;
                }
            }
            if (counter==3){
                DataTransfer::forth_title_list_path=dirFile1;
                StrVect.push_back(images.dirName());
                int c=0;
                QFileInfoList imagesList= images.entryInfoList(QDir::Files);
                foreach (const QFileInfo &imageInfo, imagesList){    //алгоритм обхода фоток
                    QString actImage=imageInfo.absoluteFilePath();
                    if (c==0){PixVect.push_back(actImage);} else break;
                    c++;
                }
            }
            if (counter>=4){
                break;
            }
            counter++;
        }
    }
    return std::tuple<QVector<QPixmap>,QVector<QString>>(PixVect,StrVect);
}

QPixmap MangaFiles::NextPage(){
    if (currentPage<imagesList.size()-1){
        currentPage++;
        QFileInfo now=imagesList.at(currentPage);
        QString imageFile1 = now.absoluteFilePath();
        QPixmap p3(imageFile1);
        return  p3;
    }
    else{
        return QPixmap();
    }
}

int MangaFiles::GetPage(){
    return  currentPage;
}

int MangaFiles::GetTotalPages(){
    return imagesList.size();
}

QPixmap MangaFiles::PrevPage(){
    if (currentPage>0){
        currentPage=currentPage-1;
        QFileInfo now=imagesList.at(currentPage);
        QString imageFile1 = now.absoluteFilePath();
        QPixmap p3(imageFile1);
        return p3;}
    else{
        return QPixmap();
    }
}
