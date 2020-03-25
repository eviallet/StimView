#ifndef CADENCEMENTDIALOG_H
#define CADENCEMENTDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QCheckBox>

class CadencementDialog : public QDialog {
    Q_OBJECT
public:
    CadencementDialog(QWidget *parent, int clockValue, int prescalerValue, bool cpuValue);
signals:
    void cadencementChangedCPU();
    void cadencementChangedClock(int clk, int prescale);
private:
    QHBoxLayout*clockLayout;
    QComboBox* prescaler;
    QCheckBox* cpu;
    QSpinBox* clock;
};

#endif // CADENCEMENTDIALOG_H
