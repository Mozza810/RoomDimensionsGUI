#include "dialoUserSettings.h"
#include "ui_dialoUserSettings.h"

dialoUserSettings::dialoUserSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialoUserSettings)
{
    ui->setupUi(this);
}

dialoUserSettings::~dialoUserSettings()
{
    delete ui;
}
