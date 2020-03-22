#include "qcursorview.h"

QCursorView::QCursorView(QWidget* parent = 0) : QtCharts::QChartView(parent) {}


void QCursorView::tooltip(QPointF point, bool state) {
    if(m_tooltip == nullptr)
        m_tooltip = new Callout(chart());
    if(state) {
        QLineSeries* hovered = (QLineSeries*)sender();
        QVector<QPointF> points = hovered->pointsVector();

        int nearestIndex = 0;
        double nearestDist = 1e9;
        for(int i=0; i<points.size(); i++) {
            double dist = sqrt(pow(points[i].x()-point.x(),2)+pow(points[i].y()-point.y(),2));
            if(dist < nearestDist) {
                nearestDist = dist;
                nearestIndex = i;
            }
        }

        int y = points[nearestIndex].y();
        QString nb;
        if(rps=="Hexa")
            nb = QString("h").append(QString::number(y,16));
        else if(rps=="Binaire")
            nb = QString("b").append(QString::number(y,2));
        else // "Décimal"
            nb = QString("d").append(QString::number(y,10));

        m_tooltip->setText(QString("X: %1 \nY: %2 ").arg(round(point.x())).arg(nb));
        m_tooltip->setAnchor(point);
        m_tooltip->setZValue(11);
        m_tooltip->updateGeometry();
        m_tooltip->show();
    } else
        m_tooltip->hide();
}

void QCursorView::addSeries(QtCharts::QLineSeries *series) {
    connect(series, SIGNAL(hovered(QPointF,bool)), this, SLOT(tooltip(QPointF,bool)));
    chart()->addSeries(series);
}

void QCursorView::changeNumRepresentation(QString rps) {
    this->rps = rps;
}
