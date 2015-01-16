#ifndef DIALOUSERSETTINGS_H
#define DIALOUSERSETTINGS_H

#include <QDialog>

namespace Ui {
class dialoUserSettings;
}

class dialoUserSettings : public QDialog
{
    Q_OBJECT

public:
    explicit dialoUserSettings(QWidget *parent = 0);
    ~dialoUserSettings();

private:
    Ui::dialoUserSettings *ui;
};

#endif // DIALOUSERSETTINGS_H
