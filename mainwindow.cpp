#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    setWindowTitle("StimView");
    QPixmap img;
    img.loadFromData(QByteArray::fromBase64("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"));
    setWindowIcon(img);

    chartView = ui->chart;
    chartView->setChart(new QChart());
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->chart()->layout()->setContentsMargins(0, 0, 0, 0);
    chartView->chart()->setBackgroundRoundness(0);

    bitView = ui->bitView;
    bitView->setChart(new QChart());
    bitView->setRenderHint(QPainter::Antialiasing);
    bitView->chart()->layout()->setContentsMargins(0, 0, 0, 0);
    bitView->chart()->setBackgroundRoundness(0);

    progressBar = ui->progressBar;
    progressBar->setVisible(false);

    zoomMin = ui->zoomMin;
    zoomMax = ui->zoomMax;
    zoomMinY = ui->zoomMinY;
    zoomMaxY = ui->zoomMaxY;

    ui->cursorComboBox->addItems({"Hexa", "Binaire", "Décimal"});
    ui->cursorComboBox->setCurrentIndex(0);

    connect(ui->cursorComboBox, SIGNAL(currentTextChanged(QString)), chartView, SLOT(changeNumRepresentation(QString)));

    connect(ui->zoomBtn, SIGNAL(clicked(bool)), this, SLOT(zoom()));
    connect(ui->unzoomBtn, SIGNAL(clicked(bool)), this, SLOT(zoomOut()));
    connect(ui->actionCharger_un_log, SIGNAL(triggered()), this, SLOT(plotFile()));
}


/// =============================================================================
///                              CLEARING SCREEN
/// =============================================================================

void remove(QLayout* layout){
    QLayoutItem* child;
    while (layout->count() != 0) {
        child = layout->takeAt (0);
        if (child->layout() != 0)
            remove (child->layout());
        else if (child->widget() != 0)
            delete child->widget();
        delete child;
    }
}

void MainWindow::clearScreen() {
    remove(ui->plotEnableLayout);
    remove(ui->bitLayout);

    chartView->chart()->removeAllSeries();
    bitView->chart()->removeAllSeries();

    menuBar()->findChild<QMenu*>("menuAfficher_des_bits")->clear();

    bitMaxY = 1;
    zoomMin->setValue(0);
    ui->groupBox->setEnabled(false);
    zoomMax->setValue(0);
    ui->groupBox_2->setEnabled(false);
    ui->zoomBtn->setEnabled(false);
    ui->unzoomBtn->setEnabled(false);
}


/// =============================================================================
///                                 PLOTTING
/// =============================================================================

void MainWindow::plotFile() {
    clearScreen();

    QStringList stim = loadStimFile();
    if(stim[0][0] == "!") {
        // Erreur
        return;
    }
    QList<QLineSeries*> seriesList = stimToSerie(stim);
    plotSeries(seriesList);

    ui->groupBox->setEnabled(true);
    ui->groupBox_2->setEnabled(true);
    ui->zoomBtn->setEnabled(true);
    ui->unzoomBtn->setEnabled(true);
}

/**
 * Demande à l'utilisateur un fichier à ouvrir.
 * @return un string par ligne, rassemblés dans une QStringList
 */
QStringList MainWindow::loadStimFile() {
    QStringList ret;

    QString fileName = QFileDialog::getOpenFileName(this,tr("Ouvrir un log"), "", tr("Fichiers log (*.log *.txt *.stim)"));
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly)) {
        ret.append("! Erreur d'ouverture du fichier");
        return ret;
    }
    QString data = QString(file.readAll());
    file.close();
    ret = data.replace("\r","").split('\n');
    if(ret.size() == 0)
        ret.append("! Fichier vide");

    return ret;
}

/**
 * Sépare chaque registre présent dans le log et assigne des temps absolus aux changements d'état.
 * Les états héxadécimaux sont convertis en décimal pour être tracés ensuite.
 * @return une waveform QLineSeries par registe rassemblés dans une liste.
 *
 *
 * Fichier de la forme :
 *
        #1
        PINB = 0x01
        TCNT0 = 0x10
        #1
        TCNT0 = 0x11
        #1
        TCNT0 = 0x12
 *
 * #x = cycles CPU depuis le dernier changement d'état
 * YYYY = registre
 * =
 * 0xzz = valeur hexadécimale du registre
 */
QList<QLineSeries*> MainWindow::stimToSerie(QStringList file) {
    /// extraction des registres et des temps relatifs de changements d'état

    /*
     * La liste nommée "regs" est de la forme suivante :
     * regs[0] :
     *      -> "TCNT0"      // nom registre
     *      -> [0]
     *              -> 1    // temps absolu de ce changement
     *              -> 22   // nouvelle valeur du registre
     *      -> [1]
     *              -> 2    // temps absolu
     *              -> 2    // nouvelle valeur du registre à t=2
     * regs[1] :
     *      -> "PIND"
     *      -> [0]
     *              -> 33
     *              -> 120
     *
     * Premier niveau de liste : nom des registres + une liste
     * Cette seconde liste est composée à chaque index de : temps absolu de chgt d'état + valeur de l'état
    */
    QList<QPair<QString, QList<QPair<int, int>>>> regs;
    quint32 absoluteTime = 0;
    maxY = 0;

    progressBar->setVisible(true);

    for(int i=0; i<file.size()-1; i++) {
        int clk = 0, j = i;
        unsigned int hex = 0;
        char* reg = (char*)malloc(10);
        // synchronisation sur le nombre de cycles CPU : #xxx
        if(file[i][0]=="#") {
            sscanf(file[i].toLatin1().data(), "#%d", &clk);
            absoluteTime += clk;
            // pour chaque registre suivant
            j = i+1;
            while(j < file.size() && file[j][0] != "#") {
                sscanf(file[j].toLatin1().data(), "%s = 0x%x", reg, &hex);
                if(hex>maxY)
                    maxY = hex;
                int index = regsContains(regs, QString(reg));
                if(index==-1) {
                    // si c'est un registre non présent dans la liste, on l'ajoute et on instantie la QList
                    //  qui accueillera la QPair(absoluteTime, hex).
                    regs.append(QPair<QString, QList<QPair<int, int>>>(QString(reg), QList<QPair<int, int>>()));
                    index = regs.size()-1;
                }
                regs[index].second.append(QPair<int, int>(absoluteTime, hex));
                j++;
            }
        }
        i = j-1; // sauter tous les registres lus pour tomber sur le prochain "#xxx"

        progressBar->setValue(i*100/file.size());
    }

    maxX = absoluteTime;
    zoomMin->setMaximum(maxX);
    zoomMax->setMaximum(maxX);
    zoomMax->setValue(maxX);
    zoomMinY->setMaximum(maxY);
    zoomMaxY->setMaximum(maxY);
    zoomMaxY->setValue(maxY);
    progressBar->setValue(0);

    /// enfin, il faut traduire les registres en points pour être tracés
    QList<QLineSeries*> list;
    for(int i=0; i<regs.size(); i++) {
        QLineSeries *serie = new QLineSeries();
        serie->setName(regs[i].first);

        for(int j=0; j<regs[i].second.size(); j++) {
            // si le premier point du registre XX débute après 0, on met une valeur constante de manière rétroactive
            //if(serie->count()==0 && regs[i].second[j].first > 0)
            //    serie->append(0, regs[i].second[j].second);

            // ajout du point (x,y) = (absoluteTime, hex)
            serie->append(regs[i].second[j].first, regs[i].second[j].second);

            // si ce n'est pas le dernier point, on ajoute un point de la même valeur au moment
            //  du chgt d'état sivant ; sinon on ne voit pas un "échelon" mais une ligne diagonale
            if(j<regs[i].second.size()-1)
                serie->append(regs[i].second[j+1].first, regs[i].second[j].second);
        }


        list.append(serie);

        progressBar->setValue(i*100/regs.size());
    }

    // pour chaque série, on rajoute un point à t=maxX
    for(QLineSeries *serie : list)
        serie->append(maxX, serie->points().last().y());

    progressBar->setVisible(false);
    progressBar->setValue(0);
    return list;
}

int MainWindow::regsContains(QList<QPair<QString, QList<QPair<int, int>>>> regs, QString reg) {
    for(int i=0; i<regs.size(); i++)
        if(regs[i].first == reg)
            return i;
    return -1;
}

void MainWindow::plotSeries(QList<QLineSeries*> seriesList) {
    QVBoxLayout* plotEnableLayout = ui->plotEnableLayout;
    for(int i=0; i<seriesList.size(); i++) {
        chartView->addSeries(seriesList[i]);

        // ajoute des QCheckBox pour afficher ou masquer les signaux
        QCheckBox* box = new QCheckBox(seriesList[i]->name());
        box->setChecked(true);
        connect(box, SIGNAL(toggled(bool)), this, SLOT(toggleSerie(bool)));
        plotEnableLayout->addWidget(box);

        // ajoute des menus et sous menus pour afficher un signal bit par bit
        QMenu* subMenu = new QMenu(seriesList[i]->name());
        menuBar()->findChild<QMenu*>("menuAfficher_des_bits")->addMenu(subMenu);
        for(int j=0; j<8; j++) {
            QAction* subaction = new QAction(seriesList[i]->name().append("(").append(QString::number(7-j)).append(")"));
            subaction->setCheckable(true);
            connect(subaction, SIGNAL(triggered(bool)), this, SLOT(toggleBit(bool)));
            subMenu->addAction(subaction);
        }
    }
    chartView->chart()->createDefaultAxes();

    ui->plotEnableLayout->addStretch();
}


/// =============================================================================
///                             HIDING SERIES
/// =============================================================================

void MainWindow::toggleSerie(bool toggle) {
    QCheckBox* box = (QCheckBox*)sender();
    QString serie = box->text();

    QList<QAbstractSeries*> list = chartView->chart()->series();
    for(int i=0; i<list.size(); i++) {
        if(list.at(i)->name() == serie) {
            list.at(i)->setVisible(toggle);
            return;
        }
    }
}

void MainWindow::toggleBit(bool unused) {
    QAction* action = (QAction*)sender();
    QString serie_bit = action->text(); // de la formee "TCNT0(7)" ou encorer "PORTB(0)"
    QString serie = serie_bit.left(serie_bit.length()-3); // ne garde que le nom de la série concernée
    int bit = serie_bit.right(2).left(1).toInt(); // garde "0)" puis "0"

    /// si la série existe déjà, la supprimer
    for(int i=0; i<bitView->chart()->series().count(); i++) {
        if(bitView->chart()->series().at(i)->name() == serie_bit) {
            bitView->chart()->removeSeries(bitView->chart()->series().at(i));

            // rabaisser les series se trouvant au dessus
            for(int j=i; j<bitView->chart()->series().count(); j++) {
                QLineSeries* s = (QLineSeries*)bitView->chart()->series().at(j);
                QVector<QPointF> pointsOld = s->pointsVector();
                unsigned long pointsOldSize = pointsOld.size();
                QList<QPointF> pointsNew;
                for(int k=0; k<pointsOldSize; k++) {
                    pointsNew.append(QPointF(pointsOld.at(0).x(), pointsOld.at(0).y()-DIGITAL_SPACING));
                    pointsOld.pop_front();
                }
                s->clear();
                s->append(pointsNew);
            }
            bitMaxY = bitView->chart()->series().count()*DIGITAL_SPACING + 1;
            zoom();
            return;
        }
    }

    double yOffset = bitView->chart()->series().size()*DIGITAL_SPACING;
    bitMaxY = yOffset+1;
    /// sinon, isoler le bit concerné et le tracer
    QList<QAbstractSeries*> list = chartView->chart()->series();
    for(int i=0; i<list.size(); i++) {
        if(list.at(i)->name() == serie) {
            QList<QPointF> points = ((QLineSeries*)list.at(i))->points();
            QList<QPointF> bits;
            for(int j=0; j<points.size(); j++)
                bits.append(QPointF(points.at(j).x(), yOffset+((((int)(points.at(j).y()))&(1<<bit))>>bit))); // isole le bit voulu

            QLineSeries* bitSerie = new QLineSeries();
            bitSerie->append(bits);
            bitSerie->setName(serie_bit);

            bitView->chart()->addSeries(bitSerie);
            bitView->chart()->createDefaultAxes();

            zoom(); // make bitView xAxis the same as chartView

            return;
        }
    }
}

/// =============================================================================
///                                 ZOOMING
/// =============================================================================

void MainWindow::zoom() {
    /// axes X
    QList<QAbstractAxis*> xAxis = chartView->chart()->axes(Qt::Horizontal);
    quint32 min = 0, max = maxX;
    if(zoomMin->value() >= 0 && zoomMin->value() < zoomMax->value())
        min = zoomMin->value();
    if(zoomMax->value() > 0 && zoomMax->value() > zoomMin->value() && zoomMax->value() <= maxX)
        max = zoomMax->value();
    for(int i=0; i<xAxis.size(); i++) {
        xAxis[i]->setMin(min);
        xAxis[i]->setMax(max);
    }
    QList<QAbstractAxis*> xAxisBitView = bitView->chart()->axes(Qt::Horizontal);
    for(int i=0; i<xAxisBitView.size(); i++) {
        xAxisBitView[i]->setMin(min);
        xAxisBitView[i]->setMax(max);
    }

    /// axes Y
    QList<QAbstractAxis*> yAxis = chartView->chart()->axes(Qt::Vertical);
    for(int i=0; i<yAxis.size(); i++) {
        int min = 0, max = maxY;
        if(zoomMinY->value() >= 0 && zoomMinY->value() < zoomMaxY->value())
            min = zoomMinY->value();
        if(zoomMaxY->value() > 0 && zoomMaxY->value() > zoomMinY->value() && zoomMaxY->value() <= maxY)
            max = zoomMaxY->value();
        yAxis[i]->setMin(min);
        yAxis[i]->setMax(max);
    }
    QList<QAbstractAxis*> yAxisBitView = bitView->chart()->axes(Qt::Vertical);
    for(int i=0; i<yAxisBitView.size(); i++) {
        yAxisBitView[i]->setMin(0);
        yAxisBitView[i]->setMax(bitMaxY);
    }
}

void MainWindow::zoomOut() {
    /// axes X
    QList<QAbstractAxis*> xAxis = chartView->chart()->axes(Qt::Horizontal);
    for(int i=0; i<xAxis.size(); i++) {
        xAxis[i]->setMin(0);
        xAxis[i]->setMax(maxX);
    }
    QList<QAbstractAxis*> xAxisBitView = bitView->chart()->axes(Qt::Horizontal);
    for(int i=0; i<xAxisBitView.size(); i++) {
        xAxisBitView[i]->setMin(0);
        xAxisBitView[i]->setMax(maxX);
    }
    zoomMin->setValue(0);
    zoomMax->setValue(maxX);

    /// axes Y
    QList<QAbstractAxis*> yAxis = chartView->chart()->axes(Qt::Vertical);
    for(int i=0; i<yAxis.size(); i++) {
        yAxis[i]->setMin(0);
        yAxis[i]->setMax(maxY);
    }
    QList<QAbstractAxis*> yAxisBitView = bitView->chart()->axes(Qt::Vertical);
    for(int i=0; i<yAxisBitView.size(); i++) {
        yAxisBitView[i]->setMin(0);
        yAxisBitView[i]->setMax(bitMaxY);
    }
    zoomMinY->setValue(0);
    zoomMaxY->setValue(maxY);
}


/// =============================================================================
///                              WINDOW LIFECYCLE
/// =============================================================================

MainWindow::~MainWindow() {
    delete ui;
}
