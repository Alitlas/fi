#include<iostream>

using namespace std;

struct stack {//описани стекa
	int inf;
	stack* next;
};

void push(stack*& h, int x) {//добавление элемента в стек
	stack* r = new stack;
	r->inf = x;
	r->next = h;
	h = r;
}
int pop(stack*& h) {//удаление элемента из стекa
	int i = h->inf;
	stack* r = h;
	h = h->next;
	delete r;
	return i;
}

void reverse(stack*& h) {//переворачиваем стек
	stack* obr = NULL;
	while (h) {
		push(obr, pop(h));
	}
	h = obr;
}

bool isgl(char a) {
	string str("aeiouy");
	return str.find(a) != string::npos;
}
stack* result(stack*& h) {
	int max = fmax(h);//ищем максимальный элемент
	int min = fmin(h);//ищем минимальный элемент
	stack* mig = NULL;
	int x;

	while (h) {
		x = pop(h);
		if (x == max) {
			push(mig, min);
		}
		push(mig, x);
	}
	return (mig); //возвращаем temp как результат функции
}

int main() {
	stack* h = NULL;
	int n, x;

	cout << "Size = ";
	cin >> n;
	cout << "Input element: ";
	for (int i = 0; i < n; i++) {
		cin >> x;
		push(h, x);
	}

	h = result(h);
	while (h) {
		cout << pop(h) << " ";
	}
}