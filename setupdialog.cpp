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

    setValuesChartDefault();

    setLayout(layoutV);

    //connections
    connect(m_savePushButton, SIGNAL(clicked()),SLOT(refreshVectorIntegers()));
    connect(m_cancelPushButton, SIGNAL(clicked()),SLOT(previousValuesChart()));
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

QVector<size_t> SetupDialog::getValuesChart()
{
    return m_vectorIntegers;
}

void SetupDialog::closeEvent(QCloseEvent *event)
{
    previousValuesChart();
}

void SetupDialog::refreshVectorIntegers()
{
    m_vectorIntegers.clear();
    QRegExp rx("(\\d+)");
    QString valuesTextEdit = m_valuesChartTextEdit->toPlainText();
    int pos = 0;
    while ((pos = rx.indexIn(valuesTextEdit, pos)) != -1) {
        m_vectorIntegers.push_back(rx.cap(1).toUInt());
        pos += rx.matchedLength();
    }
    emit valuesChartChanged();
}

void SetupDialog::setValuesChartDefault()
{
    m_vectorIntegers = {10,5,6,3,15,19,26,30,40,23};
    previousValuesChart();
}

void SetupDialog::previousValuesChart()
{
    m_valuesChartTextEdit->clear();
    QString valuesTextEdit ="";
    for(size_t value: m_vectorIntegers)
    {
        valuesTextEdit+=QString::number(value) + " ";
    }

    m_valuesChartTextEdit->setText(valuesTextEdit);
}
