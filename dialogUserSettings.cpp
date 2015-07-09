#include "dialogUserSettings.h"
#include "ui_dialogUserSettings.h"

dialogUserSettings::dialogUserSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogUserSettings)
{
    ui->setupUi(this);
}

dialogUserSettings::~dialogUserSettings()
{
    delete ui;
}
