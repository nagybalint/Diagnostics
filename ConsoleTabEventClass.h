#ifndef CONSOLETABEVENTCLASS_H
#define CONSOLETABEVENTCLASS_H

#include <QObject>
#include <QString>
#include <QQuickItem>
#include <QQmlApplicationEngine>
/**
 * @brief ConsoleTabEventClass -
 * Console fülhöz tartozó eseményeket kezelő osztály, qml-hez kapcsolódik, és kezeli az eseményeit
 * @bug Az osztály nem kezeli helyesen a beérkező ESCAPE karaktereket.
 */
class ConsoleTabEventClass : public QObject
{
    Q_OBJECT

public:

    /**
     * @brief ConsoleTabEventClass - konsruktor, csatlakozik a szükséges qml oldali változókhoz
     * @param context - qml kontextus, a változók eléréséhez
     */
    ConsoleTabEventClass(QQmlContext &context);
    ~ConsoleTabEventClass() = default;

signals:

    /**
     * @brief commandAvailable - Érvényes utasítás esetén jelez
     * @param cmd - bejövő utasítás
     */
    void commandAvailable(QString& cmd);

public slots:
    /**
     * @brief consoleTextArrived - Console felöl érkező szöveg kezelése
     * @param text - beérkezett szöveg
     */
    void consoleTextArrived(QString text);

    /**
     * @brief consoleKeyPressed - Speciális billenytű lenyomásának kezelése
     * @param key - billenyű azanosítására segédváltozó
     */
    void consoleKeyPressed(int key);

    /**
     * @brief listChanged - Megváltozott lista kezelése
     */
    void listChanged();

    /**
     * @brief addToListView - String hozzáadása a listához
     * @param string - Eltárolandó string
     */
    void addToListView(QString& string);

private:

    /**
     * @brief qmlContext - Kontextus a qml adatok frissiítéséhez
     */
    QQmlContext &qmlContext;

    /**
     * @brief dataList - Consolba kiírandó szövegek listája
     */
    QStringList dataList;

    /**
     * @brief historyList - Előző parancsokat tároló lista
     */
    QStringList historyList;

    /**
     * @brief historyCurrent - Segédváltozó console előzményekhez
     */
    int historyCurrent;
};

#endif // CONSOLETABEVENTCLASS_H
