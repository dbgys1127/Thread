#include<QThread>
#include<QTime>

class Folding_Thread : public QThread
{
	Q_OBJECT

public:
	explicit Folding_Thread(QObject* parent = 0);
	void run();

signals:
	void BufferFill(int dcount);
	void Folding(int count);
	void FinishCount(int Value);

public slots:

};
