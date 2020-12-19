#include <iostream>
#include <stdarg.h>
using namespace std;

void demo(int count, ...) {
	int res = 0;
	for (int* ptr = &count; count > 0; count--) {
		res += *(++ptr);
	}
	cout << "Result = " << res << endl;
}

void demo2(int count, ...) {
	int res = 0;
	va_list list;
	va_start(list, count);		//открываем указатель

	for (int i = 0; i < count; i++) {
		res += va_arg(list, int);		//взятие значения типа int
	}
	va_end(list);		//закрываем указатель
	cout << "Result = " << res << endl;
}

bool isAvailableFormat(char symb) {
	//доступные форматы
	const char availableFormats[] = { 'd', 's', 'f' };

	for (int i = 0; i < strlen(availableFormats); i++) {
		if (availableFormats[i] == symb) {
			return true;
		}
	}
	return false;
}

void customPrintf(const char* format, ...) {
	va_list list;
	va_start(list, format);		//открываем указатель

	for (char* tmp = (char*)format; *tmp; tmp++) {
		//cout << tmp << endl;
		if (*tmp == '%') {
			//переход к следующему символу
			tmp++;
			//формат доступен
			if (isAvailableFormat(*tmp)) {
				switch (*tmp) {
				case 'd': {
					cout << va_arg(list, int);
					break;
				}
				case 's': {
					cout << va_arg(list, char*);
					break;
				}
				case 'f': {
					cout << va_arg(list, double);
					break;
				}
				}
			}
			else {
				cout << *(tmp - 1) << *tmp;
			}
		}
		else {
			cout << *tmp;
		}
	}
	va_end(list);		//закрываем указатель
}


int main() {

	printf("Value = %d Hello %s %s Float value = %g\n", 100, "world", "!!!", 100.35);
	//demo(5, 10, 20, 30, 40, 50);
	//demo2(5, 10, 20, 30, 40, 50);
	customPrintf("%Value = %d H%el%lo %s %s Float value = %f\n", 100, "world", "!!!", 100.35);

	return 0;
}