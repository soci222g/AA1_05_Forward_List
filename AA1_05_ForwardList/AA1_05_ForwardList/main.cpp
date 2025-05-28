#include"ForwardList.h"


int main() { //IsEmpty() & Size() are used inside some of the other functions. exp: popBack()
	ForwardList myList;
	
	myList.PopBack();
	myList.PushBack(3);
	myList.PushFront(5);
	myList.PushBack(7);
	myList.PushBack(2);
	myList.PushBack(2);
	myList.PushBack(15);

	myList.PopFront(); //Destroy first (5)
	myList.PopBack(); //Destroy last (15)

	myList.Insert(6, myList.Size());

	std::cout << myList.Front(); //First element
	std::cout << myList.Back(); //Last element

	myList.Erase(2); //Erases all value 2 elements

	myList.PushBackAverageNode();

	std::cout << myList;

	ForwardList myList2 = myList;
	
	//myList2.PushBack(2);

	if (myList == myList2) {
		std::cout << "Same list"; 
	}
	else {
		std::cout << "Different list";
	}

	//FALTA OPERADOR +
	myList2.PopBack();
	ForwardList myList3;
}