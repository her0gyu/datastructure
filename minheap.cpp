#include <iostream>
#include <vector>

template <class T>
class Heap {
private:
	vector <T> list;
	void bubble_up();
	void bubble_down();
	void swap(int child, int parent);
	int get_left_child(int parent);
	int get_right_child(int parent);
	int get_parent(int child);

public:
	Heap();
	~Heap();
	void insert(T value);
	T remove();
	int get_size();
};

template <class T>
Heap<T> :: Heap() {

}

template <class T>
int Heap<T> :: get_size() {
	return list.size();
}

template <class T>
void Heap<T>::swap(int child, int parent) {
	T temp;
	temp = list[child];
	list[child] = list[parent];
	list[parent] = temp;
}

template <class T>
int Heap<T>::get_parent(int child) {
	if(child % 2 == 0)
		return (child / 2) - 1;
	else
		return child / 2;
}

template <class T>
int Heap<T>::get_left_child(int parent) {
	return 2*parent+1;
}

template <class T>
int Heap<T>::get_right_child(int parent) {
	return 2*parent + 2;
}

template <class T>
void Heap<T>::insert(T value) {
	list.push_back(value);
	bubble_up();
}

template <class T>
void Heap<T>::bubble_up() {
	int child = list.size() - 1;
	int parent = get_parent(child);

	while(list[child] > list[parent] && child >= 0 && parent >= 0) {
		swap(child, parent);
		child = parent;
		parent = get_parent(child);
	}
}

template <class T>
T Heap<T>::remove() {
	int child = list.size() - 1;
	swap(child, 0);

	T value = list.back();
	list.pop_back();

	bubble_down();
	return value;
}

template <class T>
void Heap<T>::bubble_down() {
	int parent = 0;

	while(1) {
		int left = get_left_child(parent);
		int right = get_right_child(parent);
		int length = list.size();
		int largest = parent;

		if(left < length && list[left] > list[largest])
			largest = left;

		if(right < length && list[right] > list[largest])
			largest = right;

		if(largest != parent) {
			swap(largest, parent);
		} else
			break;
	}
}
