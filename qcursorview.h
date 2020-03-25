/// https://code.qt.io/cgit/qt/qtcharts.git/tree/examples/charts/callout/view.cpp?h=5.14

#ifndef QCURSORVIEW_H
#define QCURSORVIEW_H

#include <QChartView>
#include <QGraphicsSimpleTextItem>
#include <callout.h>
#include <QLineSeries>
#include <math.h>

class QCursorView : public QtCharts::QChartView {
    Q_OBJECT
public:
    QCursorView(QWidget *parent);
public slots:
    void tooltip(QPointF point, bool state);
    void addSeries(QtCharts::QLineSeries* series);
    void changeNumRepresentation(QString);
private:
    Callout *m_tooltip = nullptr;
    QString rps = "Hexa";
};

#endif // QCURSORVIEW_H
