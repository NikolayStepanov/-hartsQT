#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <setupdialog.h>
#include <chartwidget.h>

#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent( QCloseEvent* event ) override;

public slots:
    void openAboutProgram();
    void openSetupDialog();
    void refreshChartWidgets();

private:
    Ui::MainWindow *ui;
    SetupDialog * m_setupDialog;
    ChartWidget * m_chart1;
    ChartWidget * m_chart2;
};
#endif // MAINWINDOW_H
