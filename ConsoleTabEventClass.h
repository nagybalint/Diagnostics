#ifndef CONSOLETABEVENTCLASS_H
#define CONSOLETABEVENTCLASS_H

#include <QObject>
#include <QString>
#include <QQuickItem>
#include <QQmlApplicationEngine>

class ConsoleTabEventClass : public QObject
{
    Q_OBJECT
public:
    ConsoleTabEventClass(QQmlContext &context);

    void addToList(QString string);
    void setTextInput(QList<QObject*> object);

signals:



public slots:
    void consoleTextArrived(QString text);
    void listChanged();

private:
    QQmlContext &qmlContext;
    QQuickItem *textInput;
    QString text;
    QStringList dataList;
};

#endif // CONSOLETABEVENTCLASS_H
