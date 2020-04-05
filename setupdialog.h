#ifndef SETUPDIALOG_H
#define SETUPDIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QLayout>
#include <QPushButton>

namespace Ui {
class SetupDialog;
}

class SetupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetupDialog(QWidget *parent = nullptr);
    ~SetupDialog();
    void setValuesChartDefault();

private:
    Ui::SetupDialog *ui;
    QTextEdit *m_valuesChartTextEdit;
    QPushButton *m_savePushButton;
    QPushButton *m_cancelPushButton;
    QVBoxLayout *layoutV;
    QHBoxLayout *layoutH;
};

#endif // SETUPDIALOG_H
