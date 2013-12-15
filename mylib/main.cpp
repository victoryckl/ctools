#include "_log.h"


extern "C" {
	void testBinSearch(void);
	void testRandNumber(void);
	void testShift(void);
	void testWordSort2(void);
	void testTime(void);
	void testGetString(void);
	void testSetBitVecC(void);
	void testRandMN(void);
	void test_string_convert(void);
	void test_ChangeTHEX2CPTR(void);
	int getopt_main (int argc, char **argv);
};

void testSetArray(void);
void testSetList(void);
void testSetBST(void);
void testSetBitVec(void);
void WordSort1(void);

int main(int argc, char * argv[])
{
//	getopt_main(argc, argv);
//	test_ChangeTHEX2CPTR();
//	test_string_convert();
//	testRandMN();
//	testSetBitVecC();
//	testGetString();
 	testLog();
// 	testBinSearch();
// 	testRandNumber();
// 	testShift();
//	testSetArray();
// 	testSetList();
// 	testSetBST();
// 	testSetBitVec();
//	WordSort1();
//	testWordSort2();
//	testTime();
	return 0;
}
