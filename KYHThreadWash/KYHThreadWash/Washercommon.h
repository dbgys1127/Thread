#include<Qsemaphore>
#include"Washerconstants.h"

extern char buffer[BufferSize];
extern QSemaphore WashingBytes;
extern QSemaphore DryBytes;
extern QSemaphore FoldingBytes;
extern QSemaphore UsedBytes;
