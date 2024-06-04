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
int last(stack*& h) {
	stack* mig = NULL;
	char max = pop(h);
	char x = max;
	int ix = 0;
	push(mig, max);
	int i = 0;
	bool flag = true;

	if (isgl(x)) {
		push(h, x);
		return 0;
	}
	while (h) {//пока h не пуст
		x = pop(h);
		if (isgl(x) && flag) {
			max = x;
			ix = i;
			flag = false;
		}
		push(mig, x);
		i++;
	}
	reverse(mig);
	h = mig;
	return ix;
}

stack* result(stack*& h) {
	int max = last(h);//ищем позицию последней гласной
	stack* mig = NULL;
	char x;
	int i = 0;

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
	int n;
	char x;

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
