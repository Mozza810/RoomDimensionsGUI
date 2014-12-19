#include "RoomDimensionsGUI.h"
#include "ui_RoomDimensionsGUI.h"

#include <QResource>
#include <QDir>

RoomDimensionsGUI::RoomDimensionsGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RoomDimensionsGUI)
{
    ui->setupUi(this);

    connect(ui->pushButton_area, SIGNAL(clicked()), SLOT(buttonAreaClicked(QString &valueAreaString)));
    connect(ui->pushButton_volume, SIGNAL(clicked()), SLOT(buttonVolumeClicked(QString &valueVolumeString)));
    connect(ui->pushButton_paint, SIGNAL(clicked()), SLOT(buttonPaintClicked(QString &valuePaintString)));
    connect(ui->pushButton_background_colour, SIGNAL(clicked()), SLOT(backgroundColourChange()));
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

double RoomDimensionsGUI::areaCalculations(QString valueAreaString)
{
    // Getting the user input values.
    double width = userInputWidth();
    double length = userInputLength();
    double area(width * length);

    // Setting double value (area) as QString.
    double valueAreaDouble = area;
    valueAreaString = QString::number(area);

return valueAreaDouble;
}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

double RoomDimensionsGUI::volumeCalculations(QString valueVolumeString)
{
    // Getting the user input values.
    double height = userInputHeight();
    double length = userInputLength();
    double width = userInputWidth();

    // Calculating volume
    double volume(height * length * width);

    // Setting double value (volume) as QString.
    double valueVolumeDouble = volume;
    valueVolumeString = QString::number(volume);

return valueVolumeDouble;
}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

double RoomDimensionsGUI::paintCalculations(QString valuePaintString)
{
    // Getting the user input values.
    double height = userInputHeight();
    double width = userInputWidth();

    // Calculating paint needed in gallons from width and height.
    double paint(height * width);
    double paintGallons(paint / 350);

    // Setting double value (paintGallons) as QString.
    double valuePaintDouble = paintGallons;
    valuePaintString = QString::number(paintGallons);

return valuePaintDouble;
}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

bool RoomDimensionsGUI::backgroundColourChange()
{   
    // Changing backround colour.
    QPixmap bkgnd("C:/Users/jmorris/Workspace/RoomDimensionsGUI/backgrounds/background1.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette); 

//    QDir backgrounds[] = {
//    // Set path for pictures called backgrounds
//    background1(QDir("C:/Users/jmorris/Workspace/RoomDimensionsGUI/backgrounds/background1.png")),
//    background2(QDir("C:/Users/jmorris/Workspace/RoomDimensionsGUI/backgrounds/background1.png")),
//    background3(QDir("C:/Users/jmorris/Workspace/RoomDimensionsGUI/backgrounds/background1.png")),
//    background4(QDir("C:/Users/jmorris/Workspace/RoomDimensionsGUI/backgrounds/background1.png")),
//    background5(QDir("C:/Users/jmorris/Workspace/RoomDimensionsGUI/backgrounds/background1.png")),
//    background6(QDir("C:/Users/jmorris/Workspace/RoomDimensionsGUI/backgrounds/background1.png")),
//    background7(QDir("C:/Users/jmorris/Workspace/RoomDimensionsGUI/backgrounds/background1.png")),
//    background8(QDir("C:/Users/jmorris/Workspace/RoomDimensionsGUI/backgrounds/background1.png")),
//    background9(QDir("C:/Users/jmorris/Workspace/RoomDimensionsGUI/backgrounds/background1.png")),
//    background10(QDir("C:/Users/jmorris/Workspace/RoomDimensionsGUI/backgrounds/background1.png")),
//    background11(QDir("C:/Users/jmorris/Workspace/RoomDimensionsGUI/backgrounds/background1.png")),
//    };

//    for (background : backgrounds)
//    {

//    }

    return true;
}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

bool RoomDimensionsGUI::buttonAreaClicked(QString &valueAreaString)
{
    // Emit signal for UI push button is clicked.
    emit ui->pushButton_area->clicked();

    // Setting text to outcome and the correct units.
    ui->lineEdit_Outcome->setText(valueAreaString);
    ui->lineEdit_Warning->setText("");
    ui->label_Units->setText("cm2");
    return true;

}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

bool RoomDimensionsGUI::buttonVolumeClicked(QString &valueVolumeString)
{
    // Emit signal for UI push button is clicked.
    emit ui->pushButton_volume->clicked();

    // Setting unit text box to volume cm3.
    ui->label_Units->setText("cm3");
    ui->lineEdit_Warning->setText("");
    ui->lineEdit_Outcome->setText(valueVolumeString);
    return true;
}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

bool RoomDimensionsGUI::buttonPaintClicked(QString &valuePaintString)
{
    // Emit signal for UI push button is clicked.
    emit ui->pushButton_paint->clicked();

    // Setting UI text to correct units and setting a warning for user.
    ui->label_Units->setText("Gallons");
    ui->lineEdit_Warning->setText("Warning: Actual results may depend on user preferences!");
    ui->lineEdit_Outcome->setText(valuePaintString);
    return true;
}

//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//
