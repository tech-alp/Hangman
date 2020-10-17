#include "mastercontroller.h"
#include <QDebug>

class Mastercontroller::Implemantation {
public:
    Implemantation(Mastercontroller* _masterController)
        : masterController(_masterController) {

    }

    Gamedatamanagement* gamedatamanagement{new Gamedatamanagement};
    Mastercontroller* masterController{nullptr};
    Navigationcontroller* navigationController{new Navigationcontroller};
    QString welcomeMessage = "This is Mastercontroler to Major Enes";
};


Mastercontroller::Mastercontroller(QObject* parent)
    : QObject(parent)
{
    implemantation.reset(new Implemantation(this));
}

Mastercontroller::~Mastercontroller()
{

}

Navigationcontroller* Mastercontroller::navigationController()
{
    return implemantation->navigationController;
}

Gamedatamanagement* Mastercontroller::gamedatamanagement()
{
    return implemantation->gamedatamanagement;
}

void Mastercontroller::setVisibility(bool val) {
    m_visibility = val;
    emit visibilityChanged();
}

bool Mastercontroller::visibility() const{
    return m_visibility;
}

void Mastercontroller::onTryClick(const QChar ch)
{
    implemantation->gamedatamanagement->clearPositionListIndex();
    bool state = implemantation->gamedatamanagement->checkIsWordContainsLetter(ch);
    qDebug() << ch;
    if(state == false) {
        implemantation->gamedatamanagement->getDecreasedRemainingLife();
        qDebug() << "False";
    } else {
        qDebug() << "True";
        implemantation->gamedatamanagement->changeCurrentWord(ch);
        setVisibility(true);
    }
    if(implemantation->gamedatamanagement->remainnigLife() == 0)
    {
        emit visibilityChanged();
        emit navigationController()->goResultPanelView();
    }

    if(implemantation->gamedatamanagement->isThereAnyUnderScore() == false)
    {
        emit implemantation->navigationController->goResultPanelView();
        return;
    }
}

void Mastercontroller::onPlayAgainClick()
{
    m_visibility = false;
    //implemantation->gamedatamanagement->clearPositionListIndex();
    implemantation->gamedatamanagement->createNewWord();

    if(implemantation->gamedatamanagement->remainnigLife()==0) {
        implemantation->gamedatamanagement->setRemainingLife(5);
    }

    emit implemantation->navigationController->goShowAreaView();
    qDebug() << "Play activated";
}








