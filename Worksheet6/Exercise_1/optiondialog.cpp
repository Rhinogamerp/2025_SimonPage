#include "optiondialog.h"
#include "ui_optiondialog.h"
#include <QDialogButtonBox>

OptionDialog::OptionDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::OptionDialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox, &QDialogButtonBox::accepted,
            this, &QDialog::accept);

    connect(ui->buttonBox, &QDialogButtonBox::rejected,
            this, &QDialog::reject);
}

OptionDialog::~OptionDialog()
{
    delete ui;
}
