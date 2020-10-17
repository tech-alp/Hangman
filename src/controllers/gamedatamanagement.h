#ifndef GAMEDATAMANAGEMENT_H
#define GAMEDATAMANAGEMENT_H

#include <QObject>
#include <QString>
#include <QVector>
#include <qrandom.h>
#include <QDebug>

class Gamedatamanagement: public QObject
{
    Q_OBJECT
    Q_PROPERTY(int remainningLife READ remainnigLife NOTIFY remainnigLifeChanged)
    Q_PROPERTY(QString currentWord READ getCurrentWord NOTIFY currentWordChanged)

public:
    explicit Gamedatamanagement(QObject* parent = nullptr);

    QString getCurrentWord();

    int remainnigLife() const;

    void setRemainingLife(int remain);

    void clearPositionListIndex();

    bool checkIsWordContainsLetter(QChar ch);

    QVector<int> getPositionListIndex();

    int getDecreasedRemainingLife();

    bool isThereAnyUnderScore();

    void changeCurrentWord(QChar letter);

    void createNewWord();

    Q_INVOKABLE void random() const {qDebug() << qrand()%10;}


signals:
    void remainnigLifeChanged();
    void currentWordChanged();
private:
    QString wordList[10] = {"kaplan","arslan","kedi","kopek","ayi",
                                "ınek","kurbaga","okuz","karinca","keci"};
    QString chosenWord;
    QString currentWordArray;
    int m_remainnigLife;
    QVector<int> positionListIndex;
};

#endif // GAMEDATAMANAGEMENT_H
