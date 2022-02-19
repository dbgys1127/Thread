#include"Folding.h"
#include"Washercommon.h"
#include <QDebug>

Folding_Thread::Folding_Thread(QObject* parent) :
	QThread(parent)
{

}

void Folding_Thread::run()
{
	int i = 0;
		for (i = 0; i < DataSize + 1; ++i)
		{
			FoldingBytes.acquire();
			fprintf(stderr, "%c", buffer[i % BufferSize]);
			WashingBytes.release();
			if (i % 20 == 0)
				emit BufferFill(UsedBytes.available());
			emit Folding(i);
		}
		fprintf(stderr, "\n");
		emit FinishCount(i);
}