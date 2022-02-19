#include<QThread>
#include<QTime>

class Washing_Thread : public QThread
{
	Q_OBJECT

public:
	explicit Washing_Thread(QObject* parent = 0);
	void run();

signals:
	void BufferFill(int bcount);
	void Washing(int count);

public slots:
};
