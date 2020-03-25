#include "cadencementdialog.h"

CadencementDialog::CadencementDialog(QWidget* parent = nullptr, int clockValue = 16, int prescalerValue = 1, bool cpuValue = true) : QDialog(parent) {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    clockLayout = new QHBoxLayout();
    clock = new QSpinBox(this);
    clock->setValue(clockValue);
    clock->setMaximum(64);
    clock->setMinimum(1);
    clockLayout->addWidget(clock);
    clockLayout->addWidget(new QLabel("MHz", this));

    prescaler = new QComboBox(this);
    prescaler->addItems({"1", "8", "64", "256", "1024"});
    prescaler->setCurrentText(QString::number(prescalerValue));

    QHBoxLayout* btnLayout = new QHBoxLayout();
    QPushButton* cancel = new QPushButton("Annuler", this);
    cancel->setFlat(true);
    QPushButton* ok = new QPushButton("Valider", this);
    btnLayout->addWidget(cancel);
    btnLayout->addWidget(ok);

    cpu = new QCheckBox("Cycles CPU", this);
    connect(cpu, &QCheckBox::toggled, [&] (bool state) {
        clock->setEnabled(!state);
        prescaler->setEnabled(!state);
    });
    cpu->setChecked(cpuValue);
    clock->setEnabled(!cpuValue);
    prescaler->setEnabled(!cpuValue);

    mainLayout->addLayout(clockLayout);
    mainLayout->addWidget(prescaler);
    mainLayout->addWidget(cpu);
    mainLayout->addLayout(btnLayout);
    setLayout(mainLayout);


    connect(cancel, &QPushButton::clicked, [&] {
        reject();
    });
    connect(ok, &QPushButton::clicked, [&] {
        if(cpu->isChecked())
            emit(cadencementChangedCPU());
        else
            emit(cadencementChangedClock(clock->value(), prescaler->currentText().toInt()));
        accept();
    });
}

