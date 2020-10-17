#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H

#include <QObject>
#include "gamedatamanagement.h"
#include "navigationcontroller.h"

class Mastercontroller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool visibility READ visibility NOTIFY visibilityChanged);
    Q_PROPERTY(Navigationcontroller* ui_navigationController READ navigationController CONSTANT)
    Q_PROPERTY(Gamedatamanagement* ui_gamedatamanagement READ gamedatamanagement CONSTANT)
public:
    explicit Mastercontroller(QObject* parent = nullptr);
    ~Mastercontroller();
    Navigationcontroller* navigationController();
    Gamedatamanagement* gamedatamanagement();
    void setVisibility(bool val);
    bool visibility() const;

public slots:
    void onTryClick(const QChar ch);
    void onPlayAgainClick();
    //void onExitClick();
signals:
    void visibilityChanged();

private:
    class Implemantation;
    QScopedPointer<Implemantation> implemantation;
    bool m_visibility = false;

};

#endif // MASTERCONTROLLER_H
