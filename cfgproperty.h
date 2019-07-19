#ifndef CFGPROPERTY_H
#define CFGPROPERTY_H

#include <QDebug>
#include <QFile>
#include <QObject>

class CfgProperty : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString cfgValue READ getCfgValue WRITE setCfgValue)
    Q_PROPERTY(int select_num READ getSelectNum WRITE setSelectNum)
public:
    CfgProperty(QObject *parent = nullptr);
    QString getCfgValue();
    void setCfgValue(QString str);


    int getSelectNum() const;
    void setSelectNum(int value);
public slots:
    void SaveCfgFile();
private:
    int select_num;
    QStringList batch;
    QStringList subdivisions;
    QStringList width;
    QStringList height;
    QStringList channels;
    QStringList momentum;
    QStringList decay;
    QStringList angle;
    QStringList saturation;
    QStringList exposure;
    QStringList hue;
    QStringList learning_rate;
    QStringList burn_in;
    QStringList max_batches;
    QStringList policy;
    QStringList steps;
    QStringList scales;
};

#endif // CFGPROPERTY_H
