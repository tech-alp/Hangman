#include "gamedatamanagement.h"

Gamedatamanagement::Gamedatamanagement(QObject* parent) : QObject(parent),
            chosenWord{wordList[qrand()%10]}, m_remainnigLife{5}
{
    currentWordArray = "";
    positionListIndex.clear();
    for(int i = 0; i < chosenWord.size(); ++i) {
        currentWordArray += "_";
    }
}

QString Gamedatamanagement::getCurrentWord() {
    QString str;
    for(int i = 0; i < currentWordArray.size(); i++) {
        str += ' ';
        str += currentWordArray[i];
    }
    qDebug() << chosenWord;
    return str;
}

int Gamedatamanagement::remainnigLife() const {
    return m_remainnigLife;
}

void Gamedatamanagement::setRemainingLife(int remain) {
    m_remainnigLife = remain;
    emit remainnigLifeChanged();
}

void Gamedatamanagement::clearPositionListIndex() {
    positionListIndex.clear();
}

bool Gamedatamanagement::checkIsWordContainsLetter(QChar ch) {
    bool flag = false;
    for(int index = 0; index < chosenWord.size(); ++index) {
        if(chosenWord[index] == ch) {
            qDebug() << chosenWord[index];
            positionListIndex.push_back(index);
            flag = true;
        }
    }
    return flag;
}

QVector<int> Gamedatamanagement::getPositionListIndex() {
    return positionListIndex;
}

int Gamedatamanagement::getDecreasedRemainingLife()
{
    m_remainnigLife -= 1;
    emit remainnigLifeChanged();
    return m_remainnigLife;
}

bool Gamedatamanagement::isThereAnyUnderScore() {
    return currentWordArray.contains('_');
}

void Gamedatamanagement::changeCurrentWord(QChar letter) {
    for(int i = 0; i < positionListIndex.size(); ++i) {
        currentWordArray[positionListIndex[i]] = letter;
    }
    emit currentWordChanged();
}

void Gamedatamanagement::createNewWord() {
    chosenWord.clear();
    chosenWord = wordList[qrand()%10];
    currentWordArray = "";
    positionListIndex.clear();
    for(int i = 0; i < chosenWord.size(); ++i) {
        currentWordArray += "_";
    }
    emit currentWordChanged();
}



