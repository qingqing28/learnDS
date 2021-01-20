typedef int SLDataType;

//#define N 100 
/*typedef struct seqList {
	SLDataType array[N];  //��������
	size_t size;           //��ЧԪ�صĸ���
}seqList;*/

typedef struct seqList {
	SLDataType* data;     //ָ��̬���ٵĿռ�
	size_t size;           //��ЧԪ�صĸ���
	size_t capacity;        //��̬����Ŀռ�Ĵ�С���������ռ�Ĵ�С
}seqList;

void initSeqList(seqList* s1);
void printSeqList(seqList* s1);
void checkCapacity(seqList* s1);
void pushBack(seqList* s1, SLDataType val);
void popBack(seqList* s1);
void pushFront(seqList* s1, SLDataType val);
void popFront(seqList* s1);
void insert(seqList* s1, int pos, SLDataType val);
void erase(seqList* s1, int pos);
int empty(seqList* s1);
int size(seqList* s1);
int findIdx(seqList* s1, SLDataType val);
int getIdx(seqList* s1, int pos);
void destroySeqList(seqList* s1);