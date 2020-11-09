#ifndef JSON_H
#define JSON_H

#include <decoration.h>

#include <QJsonObject>
#include <QJsonDocument>
#include <QList>

/**
 * @brief Работы с форматом JSON
 */
class Json {
public:
    Json();

    /**
     * @param documnt
     * @param fileName
     */
    void saveJson(QJsonDocument documnt, QString fileName);

    /**
     * @brief Загружает JSON файл (открывает и читает его)
     * @param fileName
     * @return
     */
    QJsonDocument loadJson(QString fileName);

    /**
     * @brief parse
     * @param jsonObject
     * @return
     */
    QList<Decoration*> parse();

    /**
     * @brief Создает заполненный JSON файл
     * @param keyPerson
     * @param dataPerson
     * @param keyBuy
     * @param dataBuy
     * @param fileName
     * @param price
     */
    void json_cart(QString keyPerson,
                   QMap<QString, QString> &dataPerson,
                   QString keyBuy,
                   QMap<QString, int> &dataBuy,
                   QString fileName,
                   int price
                   );
};

#endif // JSON_H
