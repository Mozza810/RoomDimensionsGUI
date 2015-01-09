#include "RoomDimensionsGUI.h"
#include "ui_RoomDimensionsGUI.h"

// Local includes.
#include <QResource>
#include <QDir>

RoomDimensionsGUI::RoomDimensionsGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RoomDimensionsGUI)
{
    ui->setupUi(this);

    QObject::connect(ui->pushButton_area, &QPushButton::clicked, &RoomDimensionsGUI::buttonAreaClicked);
    QObject::connect(ui->pushButton_volume, &QPushButton::clicked, &RoomDimensionsGUI::buttonVolumeClicked);
    QObject::connect(ui->pushButton_paint, &QPushButton::clicked, &RoomDimensionsGUI::buttonPaintClicked);
    QObject::connect(ui->pushButton_cancel_delete, &QPushButton::clicked, &RoomDimensionsGUI::buttonCancelClicked);
    QObject::connect(ui->pushButton_background_colour, &QPushButton::clicked, &RoomDimensionsGUI::populateBackgroundChange);

}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

RoomDimensionsGUI::~RoomDimensionsGUI()
{
    delete ui;
}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

double RoomDimensionsGUI::userInputHeight()
{
    // Get user input for height.
    return ui->line_Edit_Depth->text().toDouble();
}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

double RoomDimensionsGUI::userInputLength()
{
    // Get user input for length.
    return ui->line_Edit_Length->text().toDouble();
}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

double RoomDimensionsGUI::userInputWidth()
{
    // Get user input for width.
    return ui->line_Edit_Width->text().toDouble();
}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

double RoomDimensionsGUI::areaCalculations()
{
    // Getting the user input values.
    double width = userInputWidth();
    double length = userInputLength();
    double area(width * length);

    // Setting double value (area) as QString.
    double valueAreaDouble = area;

    return valueAreaDouble;
}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

double RoomDimensionsGUI::volumeCalculations()
{
    // Getting the user input values.
    double height = userInputHeight();
    double length = userInputLength();
    double width = userInputWidth();

    // Calculating volume
    double volume(height * length * width);

    // Setting double value (volume) as QString.
    double valueVolumeDouble = volume;

return valueVolumeDouble;
}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

double RoomDimensionsGUI::paintCalculations()
{
    // Getting the user input values.
    double height = userInputHeight();
    double width = userInputWidth();

    // Calculating paint needed in gallons from width and height.
    double paint(height * width);
    double paintGallons(paint / 350);
    // Convert paint gallons to liters.
    double paintLiters(paintGallons * 4.54609);

    // Setting double value (paintGallons) as QString.
    double valuePaintDouble = paintLiters;

return valuePaintDouble;
}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

void RoomDimensionsGUI::backgroundColourChange(const QString &file_path)
{
    // Changing backround colour.
    QPixmap bkgnd(file_path);
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
//    this->setAttribute(Qt::WA_TranslucentBackground);
//    this->centralWidget()->set

}
//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

void RoomDimensionsGUI::populateBackgroundChange()
{
    // Iterate over the backgrounds available in the background resource file and fetch their file paths.
    QDirIterator iter(":/backgrounds", QDirIterator::Subdirectories);
    std::vector<QString> background_filepaths;
    while(iter.hasNext())
    {
        iter.next();
        background_filepaths.push_back(iter.filePath());
    }

    // Choose a random background filepath from the vector of QStrings.
    // Look for how to choose a random number from x-y (x is 0; y is the size of the vector)
    int random_number = (qrand() % (background_filepaths.begin() - background_filepaths.end())) + background_filepaths.end();

    // now you have your random number (which is a valid index of "background_filepaths) do background_filepahs.at(NUMBER_YOU_CHOSE)
    background_filepaths.at(random_number);

    // Call backgroundColourChange and pass the string that was chosen.
    backgroundColourChange(background_filepaths);
}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

bool RoomDimensionsGUI::buttonAreaClicked()
{
    // Setting text to outcome and the correct units.
    ui->lineEdit_Outcome->setText(QString::number(areaCalculations()));
    ui->lineEdit_warning->setText("");
    ui->label_Units->setText("cm²");
    ui->pushButton_cancel_delete->isHidden();
    ui->pushButton_delete_area->isHidden();
    return true;

}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

bool RoomDimensionsGUI::buttonVolumeClicked()
{
    // Setting unit text box to volume cm3.
    ui->label_Units->setText("cm³");
    ui->lineEdit_warning->setText("");
    ui->lineEdit_Outcome->setText(QString::number(volumeCalculations()));
    ui->pushButton_cancel_delete->isHidden();
    ui->pushButton_delete_area->isHidden();
    return true;
}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

bool RoomDimensionsGUI::buttonPaintClicked()
{
    // Setting UI text to correct units and setting a warning for user.
    ui->label_Units->setText("Gallons");
    ui->lineEdit_warning->setText("Warning: Actual results may depend on user preferences!");
    ui->lineEdit_Outcome->setText(QString::number(paintCalculations()));
    // Enables buttons needed.
    ui->pushButton_delete_area->setEnabled(true);
    ui->pushButton_delete_area->setEnabled(true);
    ui->pushButton_cancel_delete->setEnabled(true);
    return true;
}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

bool RoomDimensionsGUI::buttonCancelClicked()
{
    // Enables buttons needed.
    ui->pushButton_cancel_delete->setEnabled(false);
    ui->pushButton_delete_area->setEnabled(false);

    ///@note alternative to disabling is hiding
//    ui->pushButton_delete_area->setVisible(); //bool
//    ui->pushButton_delete_area->show();
//    ui->pushButton_delete_area->hide();

    ui->label_Units->setText("");
    ui->lineEdit_warning->setText("");
    ui->lineEdit_Outcome->setText("");
    return true;
}

//------------------------------------------------------------------------------------------------//
