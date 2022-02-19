#include "Dry.h"
#include"Washercommon.h"
#include <QDebug>

Dry_Thread::Dry_Thread(QObject* parent) :
	QThread(parent)
{

}

void Dry_Thread::run()
{
		for (int i = 0; i < DataSize + 1; ++i)
		{
			DryBytes.acquire();
			fprintf(stderr, "%c", buffer[i % BufferSize]);
			FoldingBytes.release();
			if (i % 20 == 0)
				emit BufferFill(FoldingBytes.available());
			emit Dry(i);

		}
		fprintf(stderr, "\n");
}