#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineSeries>
#include <QChart>
#include <QChartView>
#include <QFileDialog>
#include <QFile>
#include <QDebug>
#include <QList>
#include <QCheckBox>
#include <QProgressBar>
#include <QSpinBox>
#include <QValueAxis>
#include <QGraphicsLayout>
#include <qcursorview.h>

#define DIGITAL_SPACING 1.25

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void plotFile();
private slots:
    void clearScreen();
    QStringList loadStimFile();
    QList<QtCharts::QLineSeries *> stimToSerie(QStringList file);
    void plotSeries(QList<QtCharts::QLineSeries *> seriesList);
    int regsContains(QList<QPair<QString, QList<QPair<int, int>>>> regs, QString reg);
    void toggleSerie(bool toggle);
    void toggleBit(bool toggle);
    void zoom();
    void zoomOut();
private:
    Ui::MainWindow *ui;
    QCursorView* chartView;
    QtCharts::QChartView* bitView;
    QProgressBar *progressBar;
    QSpinBox *zoomMin;
    QSpinBox *zoomMax;
    QSpinBox *zoomMinY;
    QSpinBox *zoomMaxY;
    QList<QtCharts::QLineSeries*> *series;

    quint32 maxX, maxY;
    double bitMaxY = 1;
};

#endif // MAINWINDOW_H
