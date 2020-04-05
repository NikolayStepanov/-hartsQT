#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>
#include <QVBoxLayout>

#include <QtCharts/QChart>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Setup Dialog
    setupDialog = new SetupDialog();

    //Menu
    QMenu *pMenuFile = menuBar()->addMenu(tr("&File"));
    QMenu *pMenuEdit = menuBar()->addMenu(tr("&Edit"));
    QMenu *pMenuHelp = menuBar()->addMenu(tr("&Help"));

    QAction *pActionExit = pMenuFile->addAction(tr("&Exit"),this, SLOT(close()),QKeySequence::Quit);
    QAction *pActionEdit = pMenuEdit->addAction(tr("&Setting"),this, SLOT(openSetupDialog()),QKeySequence::fromString("R"));
    QAction *pActionAbout = pMenuHelp->addAction(tr("&About"),this, SLOT(openAboutProgram()),QKeySequence::HelpContents);

    QVector<size_t>vectorIntegers ={1,4,2,7,8,2,4,10};
    m_chart1 = new ChartWidget(this,vectorIntegers);
    std::sort(vectorIntegers.begin(),vectorIntegers.end());
    m_chart2 = new ChartWidget(this,vectorIntegers);
    QVBoxLayout *layoutV = new QVBoxLayout;
    layoutV->addWidget(m_chart1);
    layoutV->addWidget(m_chart2);


    QWidget *window = new QWidget();
    window->setLayout(layoutV);

    setCentralWidget(window);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *pEvent)
{

}

void MainWindow::resizeEvent(QResizeEvent *pEvent)
{

}

void MainWindow::openAboutProgram()
{
    QString aboutMessage = "Для заданного массива целых неотрицательных чисел нарисовать две столбиковых диаграммы, "
                           "расположенных одна под другой, с длинами столбиков, пропорциональными значениям "
                           "соответствующих элементов. Длина максимального столбика должна быть равна некоторому "
                           "значению, например, 1 / 3 высоты окна (кроме случая всех нулевых значений). Под столбиками "
                           "необходимо вывести подписи со значениями элементов. Верхняя столбиковая диаграмма строится "
                           "по исходному массиву, нижняя - по отсортированному в порядке возрастания элементов.";

    QMessageBox::about(this, tr("About the program"), aboutMessage);
}

void MainWindow::openSetupDialog()
{
    setupDialog->show();
}

