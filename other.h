
//ѕрототипы функций, используемых в данном задании :
//void VarArgs(int arg1, ...);

void Sort(char* pcFirst, int nNumber, int size,
void(*Swap)(void*, void*), int(*Compare)(void*, void*));
void SwapInt(void* p1, void* p2);
int CmpInt(void* p1, void* p2);

void SwapDouble(void* p1, void* p2);
int CmpDouble(void* p1, void* p2);

void SwapStr(void* p1, void* p2);

int CmpStr(void* p1, void* p2);

//задание 1
const int row=3;
const int col=3;
void printArray(int ar[][col], int Row);
void printArray(int** ar, int row, int col);


//задание 2
bool isLeepYear(int);

int DayOfYear(int dd, int mm, int yy, int(*nDayTab)[12]);

void DayOfMonth(int yy, int day, int(*nDayTab)[12], int &returnDay, int &returnMonth);

//задание 3

void VarArgs(int first, ...);

void VarArgs2(int first, ...);

//задание 4

double Sum(double a, double b);

double Sub(double a, double b);

double Mul(double a, double b);

double Div(double a, double b);

//задание 6



const char* getString1();

const char* getString2();

const char* getString3();

//задание 7

void ArAdd(int*& Ar, int& size, int num);

void PrintAr(const int* Ar, int size);

//задание 8

int sum(int N);
int count(int Num);
void recPrint(const char* ch);
void recPrintRevers(const char* ch);