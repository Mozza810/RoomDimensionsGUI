#ifndef ROOMDIMENSIONSGUI_H
#define ROOMDIMENSIONSGUI_H

#include <QMainWindow>
#include <QPalette>


namespace Ui {
class RoomDimensionsGUI;
}

class RoomDimensionsGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit RoomDimensionsGUI(QWidget *parent = 0);

     /**
      * Destructor.
      */
    ~RoomDimensionsGUI();

private:
    Ui::RoomDimensionsGUI *ui;

    /**
     * Gets user input from GUI.
     * @return double
     */
    double userInputHeight();

    /**
     * Gets user input from GUI.
     * @return double
     */
    double userInputLength();

    /**
     * Gets user input from GUI.
     * @return double
     */
    double userInputWidth();

    /**
     * This is where calculations occur for area.
     * @return double
     */
    double areaCalculations(QString valueAreaString);

    /**
     * This is where calculations occur for volume.
     * @return double
     */
    double volumeCalculations(QString valueVolumeString);

    /**
     * This is where calculations occur for amount of paint required.
     * @return double
     */
    double paintCalculations(QString valuePaintString);

public slots:

    /**
     * This triggers signal area button clicked.
     */
    bool buttonAreaClicked(QString &valueAreaString);

    /**
     * This triggers signal volume button clicked.
     */
    bool buttonVolumeClicked(QString &valueVolumeString);

    /**
     * This triggers signal paint button clicked.
     */
    bool buttonPaintClicked(QString &valuePaintString);

    /**
     * This changes the background colour for users.
     */
    bool backgroundColourChange();

};

#endif // ROOMDIMENSIONSGUI_H
