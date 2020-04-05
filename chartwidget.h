#ifndef CHARTWIDGET_H
#define CHARTWIDGET_H

#include <QWidget>

class ChartWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ChartWidget(QWidget *parent = nullptr, QVector<size_t> vector = {});

signals:

protected:
    void paintEvent(QPaintEvent *pEvent) override;
    void resizeEvent(QResizeEvent *pEvent) override;

private:
    QPixmap m_pixmap;
    QVector<size_t> m_vectorIntegers;
};

#endif // CHARTWIDGET_H
