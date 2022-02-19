#include "Washing.h"
#include "Washercommon.h"
#include <QDebug>

Washing_Thread::Washing_Thread(QObject* parent) :
	QThread(parent)
{

}

void Washing_Thread::run()
{
	qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
	for (int i = 0; i < DataSize+1; ++i)
	{
		WashingBytes.acquire();
		buffer[i % BufferSize] = "ACGT"[(int)qrand() % 4];
		DryBytes.release();
		if (i % 20 == 0)
			emit BufferFill(DryBytes.available());
		emit Washing(i);
	}
}