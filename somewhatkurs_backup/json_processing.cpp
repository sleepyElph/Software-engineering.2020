#include "json_processing.h"

Json_processing::Json_processing()
{

}

void Json_processing::AddNewManga(QString copyFromPath, QString Author, QString Prod){
    QDir dir(copyFromPath);
    QDir dirdest(DataTransfer::folderPath);
    dirdest.mkdir(dir.dirName());
    QJsonObject named;
    QJsonObject content;
    content["Автор"]=qUtf8Printable(Author);
    content["Издательство"]=qUtf8Printable(Prod);
    QJsonArray images;
    QString newdirdestPath=DataTransfer::folderPath+"/"+dir.dirName();
    QDir newdirdest(newdirdestPath);
    QStringList filter;
    filter << QLatin1String("*.png");
    filter << QLatin1String("*.jpeg");
    filter << QLatin1String("*.jpg");
    newdirdest.setNameFilters(filter);
    QFileInfoList entries = dir.entryInfoList();
    for(QList<QFileInfo>::iterator it = entries.begin(); it!=entries.end();++it){
      QFileInfo &finfo = *it;
      if(finfo.fileName()=="." || finfo.fileName()=="..") continue;
      if(finfo.isSymLink()) {  continue; }
      if(finfo.isFile() && finfo.isReadable()){
        QFile file(finfo.filePath());
        file.copy(newdirdest.absoluteFilePath(finfo.fileName()));
        images.append(qUtf8Printable(newdirdestPath+"/"+finfo.fileName()));
      }
    }
    content["Файлы"]=images;
    named[qUtf8Printable(dir.dirName())]=content;
    QFile file("test.json");
    file.open(QIODevice::ReadWrite);
    QByteArray saveData = file.readAll();
    QJsonDocument jsonDoc(QJsonDocument::fromJson(saveData));
    QJsonArray wholeDocArr=jsonDoc.array();
    wholeDocArr.append(named);
    QJsonDocument varname(wholeDocArr);
    file.close();
    remove("test.json");
    QFile fileNew("test.json");
    fileNew.open(QIODevice::ReadWrite);
    fileNew.write(varname.toJson());
    fileNew.close();
}

void Json_processing::Inicialization(){
    QFile file("test.json");
    file.open(QIODevice::ReadWrite);
    QByteArray saveData = file.readAll();
    QJsonDocument jsonDoc(QJsonDocument::fromJson(saveData));
    QJsonArray wholeDocArr=jsonDoc.array();
    QVector<int> deleteVect;
    int counter=0;
    for (auto iter1 = wholeDocArr.begin();iter1!=wholeDocArr.end();  ++iter1){
        QJsonObject smth=iter1->toObject();
        for(auto iter = smth.begin();iter!=smth.end();  ++iter){
            bool checker=0;
            QDir dir1(DataTransfer::folderPath);
            for (int i=0;i<dir1.entryInfoList(QDir::AllDirs | QDir::NoDotAndDotDot).count();++i){
                QString dirFile= dir1.entryInfoList(QDir::AllDirs | QDir::NoDotAndDotDot).at(i).absoluteFilePath();
                QDir titleImgDir(dirFile);
                QFileInfoList tempImg= titleImgDir.entryInfoList(QDir::AllDirs | QDir::NoDotDot);
                foreach (const QFileInfo &img, tempImg){
                    QString dirFile1 = img.absoluteFilePath();

                    QDir images(dirFile1);
                    if (iter.key()==images.dirName()){
                        checker=1;
                    }
                }
            }
            if (checker==0){
                deleteVect.push_back(counter);
            }
            counter++;
        }
    }
    for (int i=deleteVect.size()-1;i>=0;i--){
        wholeDocArr.removeAt(deleteVect[i]);
    }
    file.close();
    QJsonDocument varname(wholeDocArr);
    remove("test.json");
    QFile fileNew("test.json");
    fileNew.open(QIODevice::ReadWrite);
    fileNew.write(varname.toJson());
    fileNew.close();
    /*
    QFile fileNew("new.json");
    fileNew.open(QIODevice::ReadWrite);
    fileNew.write(varname.toJson());
    fileNew.close();*/
}

QVector<QString> Json_processing::NameProd(){
    QVector<QString> toui;
    QString namedir;
    if (DataTransfer::reading_state==1){
        QDir images(DataTransfer::first_title_list_path);
        namedir=images.dirName();
    }else{
        if (DataTransfer::reading_state==2){
             QDir images(DataTransfer::second_title_list_path);
             namedir=images.dirName();
        }else{
            if (DataTransfer::reading_state==3){
                QDir images(DataTransfer::third_title_list_path);
                namedir=images.dirName();
            }else{
                if (DataTransfer::reading_state==4){
                    QDir images(DataTransfer::forth_title_list_path);
                    namedir=images.dirName();
            }
        }
    }
    }
    QFile file("test.json");
    file.open(QIODevice::ReadWrite);
    QByteArray saveData = file.readAll();
    QJsonDocument jsonDoc(QJsonDocument::fromJson(saveData));
    QJsonArray wholeDocArr=jsonDoc.array();
    file.close();
    for(auto iter = wholeDocArr.begin();iter!=wholeDocArr.end();  ++iter)
        {
            QJsonObject smth=iter->toObject();
            for(auto iter = smth.begin();iter!=smth.end();  ++iter)
               {
                   if (iter.key()==namedir){
                       QJsonObject newObj=iter->toObject();
                       toui.push_back(newObj["Автор"].toString());
                       toui.push_back(newObj["Издательство"].toString());
                   }
               }
        }
    return toui;
}
