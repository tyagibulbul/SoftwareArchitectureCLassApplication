
#include "CppUnitTest.h"
#include "..\Core\LinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CoreUnitTest
{
	TEST_CLASS(ArrayBasedLinkedListTests)
	{
	public:
		

		TEST_METHOD(EmptyList_IsCreated_ReturnsEmpty)
		{
			ArrayBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());
			Assert::AreEqual(std::string(""), linkedList.toString());

		}

		TEST_METHOD(EmptyList_CallingClear_ReturnsEmpty)
		{
			ArrayBasedLinkedList linkedList;
			linkedList.clear();
			Assert::IsTrue(linkedList.isEmpty());
		}

		TEST_METHOD(EmptyList_AddingSingleValueThenClear_ReturnsEmpty)
		{
			PointerBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());
			Assert::IsTrue(linkedList.add(1));


			linkedList.clear();
			Assert::IsTrue(linkedList.isEmpty());
		}

		TEST_METHOD(EmptyList_AddingSingleValue_ReturnsNotEmpty)
		{
			PointerBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());
			Assert::IsTrue(linkedList.add(1));

			Assert::IsFalse(linkedList.isEmpty());

			Assert::AreEqual(std::string("1"), linkedList.toString());
		}


	};

	TEST_CLASS(PointerBasedLinkedListTests)
	{
	public:

		TEST_METHOD(EmptyList_CallingClear_ReturnsEmpty)
		{
			PointerBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());

			Assert::AreEqual(std::string(""), linkedList.toString());

			linkedList.clear();
			Assert::IsTrue(linkedList.isEmpty());
		}
	};

}
