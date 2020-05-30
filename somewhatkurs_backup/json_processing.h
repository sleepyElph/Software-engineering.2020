#ifndef JSON_PROCESSING_H
#define JSON_PROCESSING_H
#include <QDir>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <qdebug.h>
#include "mainwindow.h"

class Json_processing
{
public:
    Json_processing();
    void AddNewManga(QString copyFromPath, QString Author, QString Prod);
    QVector<QString> NameProd();
    void Inicialization();
private:
    QString name_;
};

#endif // JSON_PROCESSING_H
