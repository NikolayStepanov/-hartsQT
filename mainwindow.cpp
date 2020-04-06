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
    m_setupDialog = new SetupDialog();

    //Menu
    QMenu *pMenuFile = menuBar()->addMenu(tr("&File"));
    QMenu *pMenuEdit = menuBar()->addMenu(tr("&Edit"));
    QMenu *pMenuHelp = menuBar()->addMenu(tr("&Help"));

    QAction *pActionExit = pMenuFile->addAction(tr("&Exit"),this, SLOT(close()),QKeySequence::Quit);
    QAction *pActionEdit = pMenuEdit->addAction(tr("&Setting"),this, SLOT(openSetupDialog()),QKeySequence::fromString("R"));
    QAction *pActionAbout = pMenuHelp->addAction(tr("&About"),this, SLOT(openAboutProgram()),QKeySequence::HelpContents);

    QVector<size_t>vectorIntegers = m_setupDialog->getValuesChart();

    m_chart1 = new ChartWidget(this,vectorIntegers);
    std::sort(vectorIntegers.begin(),vectorIntegers.end());
    m_chart2 = new ChartWidget(this,vectorIntegers);

    QVBoxLayout *layoutV = new QVBoxLayout;
    layoutV->addWidget(m_chart1);
    layoutV->addWidget(m_chart2);


    QWidget *window = new QWidget();
    window->setLayout(layoutV);

    setCentralWidget(window);

    //connections
    connect(m_setupDialog, SIGNAL(valuesChartChanged()),this,SLOT(refreshChartWidgets()));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_chart1;
    delete m_chart2;
    delete m_setupDialog;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    m_setupDialog->close();
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
    m_setupDialog->show();
}

void MainWindow::refreshChartWidgets()
{
    QVector<size_t> vector = m_setupDialog->getValuesChart();
    m_chart1->setValuesChart(vector);
    std::sort(vector.begin(),vector.end());
    m_chart2->setValuesChart(vector);
    m_chart1->update();
    m_chart2->update();
}

