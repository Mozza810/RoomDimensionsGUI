#include "RoomDimensionsGUI.h"
#include "ui_RoomDimensionsGUI.h"

// Local includes.
#include <QResource>
#include <QDir>
#include <QPalette>
#include <QDesktopWidget>

RoomDimensionsGUI::RoomDimensionsGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RoomDimensionsGUI)
{
    ui->setupUi(this);

    // Set coat buttons to not visible at beginning of program.
    ui->pushButton_Coat_Paint->setVisible(false);
    ui->pushButton_Delete_Coat_Paint->setVisible(false);

    // QObject Connects.
    QObject::connect(ui->pushButton_Area, &QPushButton::clicked, this, &RoomDimensionsGUI::buttonAreaClicked);
    QObject::connect(ui->pushButton_Volume, &QPushButton::clicked, this, &RoomDimensionsGUI::buttonVolumeClicked);
    QObject::connect(ui->pushButton_Paint, &QPushButton::clicked, this, &RoomDimensionsGUI::buttonPaintClicked);
    QObject::connect(ui->pushButton_Cancel_Delete, &QPushButton::clicked, this, &RoomDimensionsGUI::buttonCancelClicked);
    QObject::connect(ui->actionChange_background, &QAction::triggered, this, &RoomDimensionsGUI::populateBackgroundChange);
    QObject::connect(ui->pushButton_Delete_Area, &QPushButton::clicked, this, &RoomDimensionsGUI::buttonAreaDeleteClicked);
    QObject::connect(ui->pushButton_Coat_Paint, &QPushButton::clicked, this, &RoomDimensionsGUI::buttonCoatAddClicked);
    QObject::connect(ui->pushButton_Delete_Coat_Paint, &QPushButton::clicked, this, &RoomDimensionsGUI::buttonCoatDeleteClicked);

    // Data validation.
    ui->line_Edit_Depth->setValidator(new QDoubleValidator(0, 1000, 2, this));
    ui->line_Edit_Width->setValidator(new QDoubleValidator(0, 1000, 2, this));
    ui->line_Edit_Length->setValidator(new QDoubleValidator(0, 1000, 2, this));
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
    double paintCoverage(10*10);
    double paintLitres(paint / paintCoverage);
    double valuePaintDouble(paintLitres*10);

return valuePaintDouble;
}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

double RoomDimensionsGUI::deleteCalculations()
{
    // Getting the user input.
    double height = userInputHeight();
    double width = userInputWidth();

    // Calculating the paint needed to delete from current value in box.
    double paint(height * width);
    double paintCoverage(10*10);
    double paintLitres(paint / paintCoverage);
    double valuePaintDeleteDouble(paintLitres*10);
    double valueDeletedFrom(ui->lineEdit_Outcome->text().toDouble());
    // Delete the value given from the outcome.
    double valueAreaDeletedDouble(valueDeletedFrom - valuePaintDeleteDouble);

return valueAreaDeletedDouble;
}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

double RoomDimensionsGUI::paintCoatCalculations()
{
    // Getting user input values.
    double height = userInputHeight();
    double width = userInputWidth();
    // Calculating paint needed in gallons from width and height.
    double paint(height * width);
    double paintCoverage(10*10);
    double paintLitres(paint / paintCoverage);
    double valuePaintCoatDouble(paintLitres*10);
    // Multiply this by two
    double valueCoatDouble(valuePaintCoatDouble + valuePaintCoatDouble);

return valueCoatDouble;
}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

double RoomDimensionsGUI::paintCoatDeleteCalculations()
{
    // Getting user input values.
    double height = userInputHeight();
    double width = userInputWidth();
    // Calculating paint needed in gallons from width and height.
    double paint(height * width);
    double paintCoverage(10*10);
    double paintLitres(paint / paintCoverage);
    double CoatDeleteDouble(paintLitres*10);
    // Remove This from initial value
    double valueCoatDeleteDouble(CoatDeleteDouble - CoatDeleteDouble);

return valueCoatDeleteDouble;
}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

void RoomDimensionsGUI::backgroundColourChange(const QString &file_path)
{
    // Changing backround colour.
    QPixmap bkgnd(file_path);
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);

    // QPalette used to set background colour.
    QPalette background = palette();

    // Load the file path given as QPixmap.
    QPixmap pixmap1(file_path);

    // Resizes image if larger than screen size.
    QDesktopWidget* desktopWidget = QApplication::desktop();
    QRect rect = desktopWidget->availableGeometry();
    QSize size(rect.width() , rect.height());

    // Resize as per your requirement.
    QPixmap pixmap(pixmap1.scaled(size));

    // Set the background to the outcome randomized.
    background.setBrush(QPalette::Background,  pixmap);
    setPalette(background);

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
    int random_number = qrand() % background_filepaths.size();

    // now you have your random number (which is a valid index of "background_filepaths) do background_filepahs.at(NUMBER_YOU_CHOSE)
    background_filepaths.at(random_number);

    // Call backgroundColourChange and pass the string that was chosen.
    backgroundColourChange(background_filepaths.at(random_number));
}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

bool RoomDimensionsGUI::buttonAreaClicked()
{
    // Setting text to outcome and the correct units.
    ui->lineEdit_warning->setText("");
    ui->label_Units->setText("cm²");
    ui->lineEdit_Outcome->setText(QString::number(areaCalculations()));
    ui->pushButton_Delete_Area->setEnabled(false);
    ui->pushButton_Cancel_Delete->setEnabled(false);
    ui->pushButton_Coat_Paint->setVisible(false);
    ui->pushButton_Delete_Coat_Paint->setVisible(false);
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
    ui->pushButton_Delete_Area->setEnabled(false);
    ui->pushButton_Cancel_Delete->setEnabled(false);
    ui->pushButton_Coat_Paint->setVisible(false);
    ui->pushButton_Delete_Coat_Paint->setVisible(false);
    return true;
}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

bool RoomDimensionsGUI::buttonPaintClicked()
{
    // Setting UI text to correct units and setting a warning for user.
    ui->label_Units->setText("Litres");
    ui->lineEdit_warning->setText("Warning: Actual results may depend on user preferences! (Coverage = 10cm²).");
    ui->lineEdit_Outcome->setText(QString::number(paintCalculations()));
    // Enables buttons needed.
    ui->pushButton_Delete_Area->setEnabled(true);
    ui->pushButton_Cancel_Delete->setEnabled(true);
    ui->pushButton_Delete_Area->setVisible(true);
    ui->pushButton_Coat_Paint->setVisible(true);
    ui->pushButton_Delete_Coat_Paint->setVisible(true);
    return true;
}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

bool RoomDimensionsGUI::buttonCancelClicked()
{
    // Enables buttons needed.
    ui->pushButton_Cancel_Delete->setEnabled(false);
    ui->pushButton_Delete_Area->setEnabled(false);
    ui->pushButton_Coat_Paint->setVisible(false);
    ui->pushButton_Delete_Coat_Paint->setVisible(false);

    ///@note alternative to disabling is hiding
//    ui->pushButton_Delete_Area->setVisible(); //bool
//    ui->pushButton_Delete_Area->show();
//    ui->pushButton_Delete_Area->hide();

    ui->label_Units->setText("");
    ui->lineEdit_warning->setText("");

    return true;
}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

bool RoomDimensionsGUI::buttonAreaDeleteClicked()
{
    // Setting UI text to correct units and setting a warning for user.
    ui->label_Units->setText("Litres");
    ui->lineEdit_warning->setText("You removed a wall/area from the value.");
    ui->lineEdit_Outcome->setText(QString::number(deleteCalculations()));
    // Enables buttons needed.
    ui->pushButton_Delete_Area->setEnabled(true);
    ui->pushButton_Cancel_Delete->setEnabled(true);
    ui->pushButton_Coat_Paint->setVisible(true);
    ui->pushButton_Delete_Coat_Paint->setVisible(true);
    return true;
}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

bool RoomDimensionsGUI::buttonCoatAddClicked()
{
    // Setting UI text to correct units and setting a warning for user.
    ui->label_Units->setText("Litres");
    ui->lineEdit_warning->setText("You added another coat to the wall/area.");
    ui->lineEdit_Outcome->setText(QString::number(paintCoatCalculations()));
    // Enables buttons needed.
    ui->pushButton_Delete_Area->setEnabled(true);
    ui->pushButton_Cancel_Delete->setEnabled(true);
    ui->pushButton_Coat_Paint->setVisible(true);
    ui->pushButton_Delete_Coat_Paint->setVisible(true);
    return true;
}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

bool RoomDimensionsGUI::buttonCoatDeleteClicked()
{

    // Setting UI text to correct units and setting a warning for user.
    ui->label_Units->setText("Litres");
    ui->lineEdit_warning->setText("You deleted another coat from the wall/area.");
    ui->lineEdit_Outcome->setText(QString::number(paintCoatCalculations()));
    // Enables buttons needed.
    ui->pushButton_Delete_Area->setEnabled(true);
    ui->pushButton_Cancel_Delete->setEnabled(true);
    ui->pushButton_Coat_Paint->setVisible(true);
    ui->pushButton_Delete_Coat_Paint->setVisible(true);
    return true;
}

//------------------------------------------------------------------------------------------------//
