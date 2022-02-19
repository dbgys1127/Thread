#include<QThread>
#include<QTime>

class Dry_Thread : public QThread
{
	Q_OBJECT

public:
	explicit Dry_Thread(QObject* parent = 0);
	void run();

signals:
	void BufferFill(int ccount);
	void Dry(int count);

public slots:
};
