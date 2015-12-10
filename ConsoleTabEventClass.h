#ifndef CONSOLETABEVENTCLASS_H
#define CONSOLETABEVENTCLASS_H

#include <QObject>
#include <QString>
#include <QQuickItem>
#include <QQmlApplicationEngine>
/**
 * @brief ConsoleTabEventClass -
 * Console fülhöz tartozó események kezelője
 *
 */
class ConsoleTabEventClass : public QObject
{
    Q_OBJECT

public:
    ConsoleTabEventClass(QQmlContext &context);
    ~ConsoleTabEventClass() = default;

signals:

    /** @brief Érvényes utasítás esetén jelez*/
    void commandAvailable(QString& cmd);

public slots:
    /** @brief Console felöl érkező szöveg kezelése*/
    void consoleTextArrived(QString text);

    /** @brief Speciális billenytű lenyomásának kezelése */
    void consoleKeyPressed(int key);

    /** @brief Megváltozott lista kezelése*/
    void listChanged();

    /** @brief Elem hozzáadása a listához*/
    void addToListView(QString& string);

private:

    /** @brief Context a qml adatok frissiítéséhez*/
    QQmlContext &qmlContext;

    /** @brief Consolba kiírandó szövegek listája*/
    QStringList dataList;

    /** @brife előző parancsokat tároló lista*/
    QStringList historyList;

    /** @brief Segédváltozó console előzményekhez*/
    int historyCurrent;
};

#endif // CONSOLETABEVENTCLASS_H
