#include "setupdialog.h"
#include "ui_setupdialog.h"
#include <QHBoxLayout>

SetupDialog::SetupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetupDialog),
    m_valuesChartTextEdit(new QTextEdit()),
    m_savePushButton(new QPushButton("Save")),
    m_cancelPushButton(new QPushButton("Cancel"))
{
    ui->setupUi(this);
    layoutV = new QVBoxLayout;
    layoutH = new QHBoxLayout;
    layoutH->addWidget(m_savePushButton);
    layoutH->addWidget(m_cancelPushButton);

    layoutV->addWidget(m_valuesChartTextEdit);
    layoutV->addLayout(layoutH);

    setLayout(layoutV);
}

SetupDialog::~SetupDialog()
{
    delete ui;
    delete m_valuesChartTextEdit;
    delete m_savePushButton;
    delete m_cancelPushButton;
    delete layoutH;
    delete layoutV;
}

void SetupDialog::setValuesChartDefault()
{

}
