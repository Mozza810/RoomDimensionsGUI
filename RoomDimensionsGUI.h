#ifndef ROOMDIMENSIONSGUI_H
#define ROOMDIMENSIONSGUI_H

// Local includes.
#include <QMainWindow>
#include <QPalette>
#include <QDirIterator>
#include <QPixmap>

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
     * @return double.
     */
    double userInputHeight();

    /**
     * Gets user input from GUI.
     * @return double.
     */
    double userInputLength();

    /**
     * Gets user input from GUI.
     * @return double.
     */
    double userInputWidth();

    /**
     * This is where calculations occur for area.
     * @return double.
     */
    double areaCalculations();

    /**
     * This is where calculations occur for volume.
     * @return double.
     */
    double volumeCalculations();

    /**
     * This is where calculations occur for amount of paint required.
     * @return double.
     */
    double paintCalculations();

    /**
     * This calculates the area to delete from a wall.
     * @return double.
     */
    double deleteCalculations();

    /**
     * This calculates the outcome in lineEdit to add new coat.
     * @return double.
     */
    double paintCoatCalculations();

    /**
     * This calculates the outcome in lineEdit to delete a coat.
     * @return double.
     */
    double paintCoatDeleteCalculations();

private slots:

    /**
     * This triggers signal area button clicked.
     * Return bool.
     */
    bool buttonAreaClicked();

    /**
     * This triggers signal volume button clicked.
     * Return bool.
     */
    bool buttonVolumeClicked();

    /**
     * This triggers signal paint button clicked.
     * Return bool.
     */
    bool buttonPaintClicked();

    /**
     * When cancel clicked buttons deactivated resets.
     * Return bool.
     */
    bool buttonCancelClicked();

    /**
     * When delete clicked sets text and gets value from calculations.
     * @return bool.
     */
    bool buttonAreaDeleteClicked();

    /**
     * When this is clicked it adds new coat of paint to wall.
     * @return bool.
     */
    bool buttonCoatAddClicked();

    /**
     * When this is clicked it deletes a coat from the wall.
     * @return bool.
     */
    bool buttonCoatDeleteClicked();

    /**
     * This fetches file paths for backgrounds and iterates through them.
     */
    void populateBackgroundChange();

    /**
     * This changes the background colour for users.
     */
    void backgroundColourChange(const QString &file_path);

};

#endif // ROOMDIMENSIONSGUI_H
