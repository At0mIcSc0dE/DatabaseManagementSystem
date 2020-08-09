#include "Application.h"

size_t totalAllocs = 0;
void* operator new(size_t size)
{
	totalAllocs += size;
	return malloc(size);
}

void operator delete(void* data, size_t size)
{
	free(data);
	totalAllocs -= size;
}


int main()
{
	QRD_LOG_CLEAR();
	Application app("C:\\dev\\ProgramFiles\\DBMS\\DB.dbs");
	app.Run();

}