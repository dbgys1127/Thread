#include <QtWidgets/QDialog>
#include"Washing.h"
#include"Dry.h"
#include"Folding.h"
#include<QSemaphore>

namespace Ui
{
    class KYHThreadWash;
}
class KYHThreadWash : public QDialog
{
    Q_OBJECT

public:
    explicit KYHThreadWash(QWidget* parent = 0);
    ~KYHThreadWash();

public slots:
    void Buffer_Value(int);
    void Washing_Value(int);
    void Dry_Value(int);
    void Folding_Value(int);


private slots:
    void pushButton_Start();
    void pushButton_Close();
    void Folding_finished(int);

private:
    Ui::KYHThreadWash *ui;
    Washing_Thread* Washing_Thr;
    Dry_Thread* Dry_Thr;
    Folding_Thread* Folding_Thr;
};
