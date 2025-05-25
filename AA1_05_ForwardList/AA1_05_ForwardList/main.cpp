#include"ForwardList.h"

int main() {

	ForwardList myList;
	myList.PopBack();
	myList.PushBack(3);

	myList.PushFront(5);
	myList.PushBack(7);
	myList.PushBack(2);

	myList.Insert(6, myList.Size());

	myList.PushBackAverageNode();
}