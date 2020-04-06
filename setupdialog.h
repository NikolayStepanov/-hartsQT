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
    QVector<size_t> getValuesChart();

protected:
    void closeEvent( QCloseEvent* event ) override;

private:
    void setValuesChartDefault();

private slots:
    void refreshVectorIntegers();
    void previousValuesChart();

signals:
    void valuesChartChanged();

private:
    Ui::SetupDialog *ui;
    QTextEdit *m_valuesChartTextEdit;
    QPushButton *m_savePushButton;
    QPushButton *m_cancelPushButton;
    QVBoxLayout *layoutV;
    QHBoxLayout *layoutH;

    QVector<size_t> m_vectorIntegers;
};

#endif // SETUPDIALOG_H
