#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ProiectMDS.h"

class ProiectMDS : public QMainWindow
{
    Q_OBJECT

public:
    ProiectMDS(QWidget *parent = Q_NULLPTR);

private:
    Ui::ProiectMDSClass ui;
};
