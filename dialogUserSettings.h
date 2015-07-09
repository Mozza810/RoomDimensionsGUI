#ifndef DIALOGUSERSETTINGS_H
#define DIALOGUSERSETTINGS_H

#include <QDialog>

namespace Ui {
class dialogUserSettings;
}

class dialogUserSettings : public QDialog
{
    Q_OBJECT

public:
    explicit dialogUserSettings(QWidget *parent = 0);
    ~dialogUserSettings();

private:
    Ui::dialogUserSettings *ui;
};

#endif // DIALOGUSERSETTINGS_H
