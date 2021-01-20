typedef int SLDataType;

//#define N 100 
/*typedef struct seqList {
	SLDataType array[N];  //定长数组
	size_t size;           //有效元素的个数
}seqList;*/

typedef struct seqList {
	SLDataType* data;     //指向动态开辟的空间
	size_t size;           //有效元素的个数
	size_t capacity;        //动态申请的空间的大小，即容量空间的大小
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