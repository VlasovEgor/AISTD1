#include "pch.h"
#include "CppUnitTest.h"
#include "..//AISTD1.2/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AistdTest
{
	TEST_CLASS(AistdTest)
	{
	public:
		
		List<int>* test1;
		List<int>* test2;
		TEST_METHOD_INITIALIZE(setUp)
		{
			test1 = new List<int>();
			test2 = new List<int>();
		}
		TEST_METHOD_CLEANUP(cleanUp)
		{
			delete test1;
			delete test2;
		}
		TEST_METHOD(push_back_first)
		{
			test1->push_back(0);
			test1->push_back(1);
			Assert::IsTrue(test1->at(1)==1);
		}
		TEST_METHOD(push_back_zero)
		{
			test1->push_back(1);
			Assert::IsTrue(test1->at(0)== 1);
		}
		TEST_METHOD(push_front_first)
		{
			test1->push_front(2);
			test1->push_front(0);
			Assert::IsTrue(test1->at(0)== 0);
		}
		TEST_METHOD(push_front_zero)
		{
			test1->push_back(2);
			test1->push_front(1);
	
			Assert::IsTrue(test1->at(0) == 1);
		}
		TEST_METHOD(pop_back_first)
		{
			test1->push_back(1);
			test1->push_back(2);
			test1->push_back(3);
			test1->pop_back();
			Assert::IsTrue((int)test1->GetSize() == 2);
		}
		TEST_METHOD(pop_back_zero)
		{
			test1->push_back(1);
			test1->pop_back();
			Assert::IsTrue((int)test1->GetSize() == 0);
		}
		TEST_METHOD(pop_front_first)
		{
			test1->push_back(1);
			test1->push_back(2);
			test1->push_back(3);
			test1->pop_front();
			Assert::IsTrue((int)test1->GetSize() == 2);
		}
		TEST_METHOD(pop_front_zero)
		{
			test1->push_back(1);
			test1->pop_front();
			Assert::IsTrue((int)test1->GetSize() == 0);
		}
		TEST_METHOD(insert_first)
		{
			test1->push_back(1);
			test1->push_back(2);
			test1->push_back(3);
			test1->insert(7, 1); // 0 10 1 2
			Assert::IsTrue(test1->at(1) == 7);
		}
		
		TEST_METHOD(insertelem_last)
		{
			test1->push_back(1);
			test1->push_back(2);
			test1->push_back(3);
			test1->push_back(4);
			test1->push_back(5);
			test1->insert(10, (int)test1->GetSize() - 1);
			Assert::IsTrue(test1->at((int)test1->GetSize() - 1) == 10);
		}
		TEST_METHOD(at_first)
		{
			test1->push_back(0);
			test1->push_back(1);
			test1->push_back(2);
			test1->push_back(3);
			Assert::IsTrue(test1->at(1) == 1);
		}
		TEST_METHOD(at_second)
		{
			test1->push_back(0);
			test1->push_back(1);
			test1->push_back(2);
			test1->push_back(3);
			Assert::IsTrue(test1->at(2) == 2);
		}
		TEST_METHOD(removeAt_first)
		{
			test1->push_back(0);
			test1->push_back(1);
			test1->push_back(2);
			test1->push_back(3);
			test1->removeAt(1);
			Assert::IsTrue((int)test1->GetSize() == 3);
		}
		TEST_METHOD(removeAt_mid)
		{
			test1->push_back(0);
			test1->push_back(1);
			test1->push_back(2);
			test1->push_back(3);
			test1->push_back(4);
			test1->removeAt(2);
			Assert::IsTrue((int)test1->GetSize() == 4);
		}
		TEST_METHOD(removeAt_last)
		{
			test1->push_back(0);
			test1->push_back(1);
			test1->push_back(2);
			test1->removeAt((int)test1->GetSize() - 1);
			Assert::IsTrue((int)test1->GetSize() == 2);
		}
		TEST_METHOD(size_zero)
		{
			test1->push_back(1);
			test1->removeAt(0);
			Assert::IsTrue((int)test1->GetSize() == 0);
		}
		TEST_METHOD(size_third)
		{
			test1->push_back(0);
			test1->push_back(1);
			test1->push_back(2);
			Assert::IsTrue((int)test1->GetSize() == 3);
		}
		TEST_METHOD(clear)
		{
			test1->push_back(0);
			test1->push_back(1);
			test1->push_back(2);
			test1->clear();
			Assert::IsTrue((int)test1->GetSize() == 0);
		}
		TEST_METHOD(set_first)
		{
			test1->push_back(0);
			test1->push_back(1);
			test1->push_back(2);
			test1->Set(0, 10);
			Assert::IsTrue(test1->at(0) == 10);
		}
		TEST_METHOD(set_second)
		{
			test1->push_back(0);
			test1->push_back(1);
			test1->push_back(2);
			test1->Set(1, 10);
			Assert::IsTrue(test1->at(1) == 10);
		}
		
		TEST_METHOD(set_last)
		{
			test1->push_back(0);
			test1->push_back(1);
			test1->push_back(2);
			test1->Set((int)test1->GetSize() - 1, 10);
			Assert::IsTrue(test1->at((int)test1->GetSize() - 1) == 10);
		}
		TEST_METHOD(isEmptyFalse)
		{
			test1->push_back(0);
			test1->push_back(1);
			test1->push_back(2);
			
		}
		TEST_METHOD(isEmptyTrue)
		{
			test1->push_back(0);
			test1->push_back(1);
			test1->push_back(2);
			test1->clear();
			
		}
		TEST_METHOD(InsertFrontList)
		{
			test1->push_back(1);
			test1->push_back(2);
			test1->push_back(3);
			test2->push_front(4);
			test2->push_back(5);
			test2->push_back(6);
			test1->InsertList(*test2, 0);
			Assert::IsTrue((int)test1->GetSize() == 6);
		}
		TEST_METHOD(InsertMidList)
		{
			test1->push_back(1);
			test1->push_back(2);
			test1->push_back(3);
			test2->push_front(4);
			test2->push_back(5);
			test2->push_back(6);
			test1->InsertList(*test2, 1);
			Assert::IsTrue((int)test1->GetSize() == 6);
		}
		TEST_METHOD(InsertBackList)
		{
			test1->push_back(1);
			test1->push_back(2);
			test1->push_back(3);
			test2->push_front(4);
			test2->push_back(5);
			test2->push_back(6);
			test1->InsertList(*test2, (int)test1->GetSize() - 1);
			Assert::IsTrue((int)test1->GetSize()== 6);
		}
	};
}
