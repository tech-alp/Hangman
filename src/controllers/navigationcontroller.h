#ifndef NAVIGATIONCONTROLLER_H
#define NAVIGATIONCONTROLLER_H

#include <QObject>

class Navigationcontroller : public QObject
{
    Q_OBJECT
public:
    explicit Navigationcontroller(QObject *parent = nullptr): QObject(parent)
    {
    }
signals:
    void goResultPanelView();
    void goShowAreaView();
};

#endif // NAVIGATIONCONTROLLER_H
