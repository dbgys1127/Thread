#include "KYHThreadWash.h"
#include"ui_KYHThreadWash.h"
#include"Washerconstants.h"
#include "qmessagebox.h"

char buffer[BufferSize];
QSemaphore WashingBytes(BufferSize);
QSemaphore DryBytes;
QSemaphore FoldingBytes;
QSemaphore UsedBytes;


KYHThreadWash::KYHThreadWash(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::KYHThreadWash)
{
    ui->setupUi(this);
    ui->progressBar_Washingtime->setRange(0, DataSize);
    ui->progressBar_Drytime->setRange(0, DataSize);
    ui->progressBar_Foldingtime->setRange(0, DataSize);
    ui->progressBar_Buffer->setRange(0, BufferSize);
    ui->pushButton_Close->setEnabled(false);

    Washing_Thr = new Washing_Thread(this);
    Dry_Thr = new Dry_Thread(this);
    Folding_Thr = new Folding_Thread(this);

    connect(Washing_Thr, SIGNAL(BufferFill(int)), this, SLOT(Buffer_Value(int)));
    connect(Dry_Thr, SIGNAL(BufferFill(int)), this, SLOT(Buffer_Value(int)));
    connect(Folding_Thr, SIGNAL(BufferFill(int)), this, SLOT(Buffer_Value(int)));

    connect(Washing_Thr, SIGNAL(Washing(int)), this, SLOT(Washing_Value(int)));
    connect(Dry_Thr, SIGNAL(Dry(int)), this, SLOT(Dry_Value(int)));
    connect(Folding_Thr, SIGNAL(Folding(int)), this, SLOT(Folding_Value(int)));

    connect(Washing_Thr, SIGNAL(finished()), Washing_Thr, SLOT(deleteLater()));
    connect(Dry_Thr, SIGNAL(finished()), Dry_Thr, SLOT(deleteLater()));
    connect(Folding_Thr, SIGNAL(finished()), Folding_Thr, SLOT(deleteLater()));

    connect(Folding_Thr, SIGNAL(FinishCount(int)), this, SLOT(Folding_finished(int)));

    connect(ui->pushButton_Start, &QPushButton::clicked, this, &KYHThreadWash::pushButton_Start);
    connect(ui->pushButton_Close, &QPushButton::clicked, this, &KYHThreadWash::pushButton_Close);
    //////////
}

void KYHThreadWash::Folding_finished(int value)
{
    if (Folding_Thr->isFinished() == true)
    {
        ui->pushButton_Close->setEnabled(true);
        QMessageBox msgBox;
        msgBox.setDefaultButton(QMessageBox::information(this, "Finished all Laundry", "Finished your Laundry!  Thank you for your using!"));
    }
}

KYHThreadWash::~KYHThreadWash()
{
    delete ui;
}

void KYHThreadWash::Buffer_Value(int bCount)
{
    ui->progressBar_Buffer->setValue(bCount);
}

void KYHThreadWash::Washing_Value(int wCount)
{
    ui->progressBar_Washingtime->setValue(wCount);
}

void KYHThreadWash::Dry_Value(int dCount)
{
    ui->progressBar_Drytime->setValue(dCount);
}

void KYHThreadWash::Folding_Value(int fCount)
{
    ui->progressBar_Foldingtime->setValue(fCount);
}

void KYHThreadWash::pushButton_Start()
{
        ui->pushButton_Start->setEnabled(false);

        Washing_Thr->start();
        Dry_Thr->start();
        Folding_Thr->start();
}
void KYHThreadWash::pushButton_Close()
{
    close();
}

