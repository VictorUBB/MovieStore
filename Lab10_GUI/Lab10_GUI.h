#pragma once

#include <QtWidgets/QWidget>
#include "ui_Lab10_GUI.h"

class Lab10_GUI : public QWidget
{
    Q_OBJECT

public:
    Lab10_GUI(QWidget *parent = Q_NULLPTR);

private:
    Ui::Lab10_GUIClass ui;
};
