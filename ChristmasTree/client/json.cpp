#include "toy.h"
#include  "garland.h"
#include "json.h"

#include <QFile>
#include <QJsonArray>

Json::Json() {
}

void Json::saveJson(QJsonDocument documnt, QString fileName) {
    QFile jsonFile(fileName);
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(documnt.toJson());
}

QJsonDocument Json::loadJson(QString fileName) {
    QFile jsonFile(fileName);
    jsonFile.open(QFile::ReadOnly);
    return QJsonDocument().fromJson(jsonFile.readAll());
}

QList<Decoration*>  Json::parse() {
    QFile file;
    file.setFileName(":/json/json/decorations.json");
    QList<Decoration*>  result;

    if (file.open(QIODevice::ReadOnly)) {
        QJsonParseError  parseError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll(), &parseError);

        QJsonArray toArray = jsonDoc.object()["Toy"].toArray();
        for(const QJsonValue& val: toArray) {
            QJsonObject loopObj = val.toObject();
            auto *toy = new Toy(loopObj);
            result.push_back(toy);
        }

        toArray = jsonDoc.object()["Garland"].toArray();
        for(const QJsonValue& val: toArray) {
            QJsonObject loopObj = val.toObject();
            auto *garland = new Garland (loopObj);
            result.push_back(garland);
        }

    }
    return result;
}

void Json::json_cart(QString keyPerson, QMap <QString, QString> &dataPerson, QString keyBuy, QMap <QString, int> &dataBuy, QString fileName, int price) {

    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    file.close();

    QJsonDocument json = loadJson(fileName);
    QJsonObject GBjsonObj;
    GBjsonObj = json.object();
    QJsonObject jsonObj1;
    QJsonObject jsonObj2;

    for (auto iter =  dataPerson.begin(); iter !=  dataPerson.end(); iter++) {
        jsonObj1.insert(iter.key(), iter.value());
    }

    for (auto iter =  dataBuy.begin(); iter !=  dataBuy.end(); iter++) {
        jsonObj2.insert(iter.key(), iter.value());
    }

    jsonObj2.insert("Итог", price);

    GBjsonObj[keyPerson] = jsonObj1;
    GBjsonObj[keyBuy] = jsonObj2;

    json.setObject(GBjsonObj);
    saveJson(json, fileName);
}
