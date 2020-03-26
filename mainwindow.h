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
#include <QMessageBox>
#include <qcursorview.h>
#include <cadencementdialog.h>

#define DIGITAL_SPACING 1.25
#define PREF_FILE "prefs.cfg"

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
    void changeClock(int, int);
    void setCPUCyclesView();
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
    qreal convertCPUtoCLK(qreal x);
    qreal convertCLKtoCPU(qreal x);
    qreal convertCLKtoCLK(qreal x, int newClock, int newPrescaler);
    void showCadencementDialog();
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

    quint64 minX, maxX, maxY;
    double bitMaxY = 1;

    int clock = 16;
    int prescaler = 1;
    bool cpu = true;

    int incr = 0;

    bool fileLoaded = false;
};

#endif // MAINWINDOW_H
