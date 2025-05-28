#include"ForwardList.h"

//nullo de inicio
ForwardList::ForwardList() {
	m_size = 0;
	m_first = new Node();
	m_last = new Node();
}

//elimina elementos
ForwardList::~ForwardList() {
	if (m_last->m_next == nullptr) {
		m_size = NULL;
		m_last = nullptr;
		m_first = nullptr;
		return;
	}


	while (Size() > 0) {
		PopBack();
	}
	m_size = NULL;
}

void ForwardList::PushBack(int value) {
	

	//nodo temporal del elemento entrado
	Node* temNode = new Node();
	temNode->m_value = value;
	//en caso de que este vacio la lisa el primero i el ultimo son el mismo
	if (IsEmpty()) {
		m_first = temNode;
		m_last = temNode;
	}
	else {
		//nodo temporal del ultimo elemento
		Node* LastNode = m_last;

		//asiganmos el ultimo nodo al nodo que hemos entrado
		m_last = temNode;
		//el ultimo nodo pasa a tener un puntedo hacia el antiguo ultimo nodo
		m_last->m_next = LastNode;


	}

	m_size++; //aumenta el tamanyo
}

void ForwardList::PushFront(int value) {

	//nodo temporal del elemento entrado
	Node* temNode = new Node();
	temNode->m_value = value;
	//si esta vacio los dos son next
	if (IsEmpty()) {
		m_first = temNode;
		m_last = temNode;
	}
	else {
		//cogemos el nodo antiguo
		Node* OldFirst = m_first;
		//le asignamos el nuevo
		m_first = temNode;
		//signamos el next del antigo al nuevo nodo creado

		OldFirst->m_next = m_first;

	}
	m_size++;
}

void ForwardList::PopBack() {
	
	
	//en caso de que este vacio cortamos ejecucion
	if (IsEmpty()) {
		return;
	}
	else {
		// nos guardamos la poenultima poscion
		Node* tempNode = m_last->m_next;

		//elimionar la antigua ultima posicion posicion
		delete m_last;

			//metemos el ulimo valor como el de alante (asi se salta el penultimo este)
		m_last = tempNode;
	}




	m_size--; //reduce el tamanyo

	if (m_size == 0) {
		m_last = nullptr;
		m_first = nullptr;
	}
}

void ForwardList::PopFront() {

	//en caso de que este vacio cortamos ejecucion
	if (IsEmpty()) {
		return;
	}
	else {
		//una forma de pasar el segundo al primero

		Node* it = m_last;

		//fem un for para encontrar el segundo
		for (int i = Size(); i > 0; i--) {

			int nextValuse = it->m_next->m_value;

			if (nextValuse == m_first->m_value) {
				delete m_first;
				m_first = it;
				m_first->m_next = nullptr;
				m_size--;
				return;
			}
			it = it->m_next;
			
		}

		
	}
}

int ForwardList::Front()const {
	if (IsEmpty()) {
		return -999999999; //return de error
	}
	else 
	{
		return m_first->m_value;
	}

}
int ForwardList::Back()const {
	if (IsEmpty()) {
		return  -999999999;//reurn de error;
	}
	else 
	{
		return m_last->m_value;
	}
}
int ForwardList::Size()const {
	return m_size;
}

void ForwardList::Erase(int value) {
	if (Back() == value) {
		PopBack(); //si el primer valor es igual eliminalo
		return;
	}

	Node* it = m_last;
	for (int i = Size(); i > 0; --i) {
		//si es el ultimo valor no lo ejecutes
		if (it->m_next->m_next == nullptr) {
			//en caso de que sea el primero mira si el valor es el mismo
			if (it->m_value == value) {
				PopFront();
			}
			return;
		}

		while (it->m_next->m_value == value) {
			//metemos el sigiente como valor del sigiente
			it->m_next = it->m_next->m_next;
			m_size--;
		}
		it = it->m_next;
		//si el ultimo valor es el primero, acavalo porque ya lo hemos comprovado en esta iteracion
		if (it->m_next == nullptr) {
			return;
		}
	}
}

void ForwardList::Insert(int value, int position) {
	//miramos si posicion existe si no termina el proceso
	if (position > Size() || position < 0) {
		return;
	}
	
	//si es el primero i el ultimo usamos las funciones ya existentes
	if (position == Size()) {
		PushBack(value);
		return;
	}
	else if (position == 0) {
		PushFront(value);
		return;
	}

	Node* it = m_last;

	Node* next = m_last->m_next;

	Node* NewNode = new Node();
	NewNode->m_value = value;
	//fem un for para encontrar el segundo
	for (int i = Size(); i > 0; i--) {
			
		//si coinciden la posicon entonces anyade su valor i acava la funcion
		if (i == position) {
			it->m_next = NewNode;
			NewNode->m_next = next;
			m_size++;
			return;
		}
		it = it->m_next;
		next = next->m_next;
		
	}


}

void ForwardList::PushBackAverageNode() {
	int avarageValue = 0;
	Node* it = m_last;
	//sumem tot els valors
	for (int i = Size(); i > 0; i--) {
		avarageValue += it->m_value;
		//break perque no sobrapasi la iteracio ja que ja hem comptabilitzat el ultim(primer)
		if (it->m_next == nullptr) {
			break;
		}
		else {
			it = it->m_next;
		}
	}
	//dividim tots els velor per els somats
	avarageValue = avarageValue / Size();

	PushBack(avarageValue);
}
//echo
bool ForwardList::IsEmpty()const {
	//si es mas pequena o igual a 0 esta vacia (true) 
	if (m_size <= 0) {
		return true;
	}
	//si es mayor que 0 entronces es false
	else {
		return false;
	}

}

bool operator==(const ForwardList& l1, const ForwardList& l2) {
	if (l1.m_size != l2.m_size) {
		return false;
	}

	ForwardList::Node* itL1 = l1.m_last;
	ForwardList::Node* itL2 = l2.m_last;

	while (itL1 != nullptr && itL2 != nullptr) {
		if (itL1->m_value != itL2->m_value) {
			return false;
		}
		itL1 = itL1->m_next;
		itL2 = itL2->m_next;
	}

	return true;
}

ForwardList ForwardList::operator+(const ForwardList& l) {
	ForwardList result;

	Node* it = m_last;
	while (it != nullptr) {
		
		result.PushFront(it->m_value); 
		it = it->m_next;
	}
	
	Node* it2 = l.m_last;
	while (it2 != nullptr) {
		result.PushFront(it2->m_value);
		it2 = it2->m_next;
	}

	return result;
}

std::ostream& operator<<(std::ostream& o, const ForwardList& l) { //Printea lists del revés
	ForwardList::Node* it = l.m_last;
	while (it != nullptr) {
		o << it->m_value;
		if (it->m_next != nullptr) {
			o << ", ";
		}
		
		it = it->m_next;
	}
	return o;
}