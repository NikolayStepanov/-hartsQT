#include "chartwidget.h"
#include <QtCharts/QtCharts>

ChartWidget::ChartWidget(QWidget *parent, QVector<size_t> vector) : QWidget(parent),
    m_vectorIntegers(vector)
{
}

void ChartWidget::setValuesChart(QVector<size_t> vector)
{
    m_vectorIntegers = vector;
    drawChart();
}

void ChartWidget::drawChart()
{
    m_pixmap.fill(Qt::white);

    size_t heightPixmap = m_pixmap.height();
    size_t widthPixmap = m_pixmap.width();

    double textHeightMax = heightPixmap * 0.1;
    double maxHeightColumn = heightPixmap * 0.9;
    size_t widthColumn =0;
    if(m_vectorIntegers.size()!=0)
    {
        widthColumn = widthPixmap / m_vectorIntegers.size();
    }

    size_t maxValVector = *std::max_element(m_vectorIntegers.begin(), m_vectorIntegers.end());
    double columnProportionWidth = maxHeightColumn/maxValVector;

    QPainter painter(&m_pixmap);
    QBrush brush(Qt::blue, Qt::SolidPattern);
    QPen pen(Qt::black);
    pen.setWidth(3);

    painter.setPen(pen);
    painter.setBrush(brush);

    int xCol = 0;
    int yCol = maxHeightColumn;

    for(size_t value: m_vectorIntegers)
    {

        //Сolumn
        int heightCol = value*columnProportionWidth;
        painter.drawRect(xCol,yCol-heightCol, widthColumn, heightCol);


        //Text
        QRect r(xCol, yCol, widthColumn,textHeightMax);
        painter.setFont(QFont("Times", (textHeightMax/3), QFont::Normal));
        painter.drawText(r, Qt::AlignCenter | Qt::TextWordWrap,  QString::number(value));

        xCol+=widthColumn;

    }
}

void ChartWidget::paintEvent(QPaintEvent *pEvent)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,m_pixmap);
}

void ChartWidget::resizeEvent(QResizeEvent *pEvent)
{
    m_pixmap = QPixmap(pEvent->size());
    drawChart();
}
