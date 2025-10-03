	#include <iostream>

	using namespace std;

	int main() {
		setlocale(0, "");
		{
			// Задание 1
			cout << "\033[31m" << "Задание 1:\n" << "\033[0m" << endl;
			cout << "Тип int = " << sizeof(int) << " байт" << endl;
			cout << "Тип short int = " << sizeof(short int) << " байт" << endl;
			cout << "Тип long int = " << sizeof(long int) << " байт" << endl;
			cout << "Тип float = " << sizeof(float) << " байт" << endl;
			cout << "Тип double = " << sizeof(double) << " байт" << endl;
			cout << "Тип long double = " << sizeof(long double) << " байт" << endl;
			cout << "Тип char = " << sizeof(char) << " байт" << endl;
			cout << "Тип bool = " << sizeof(bool) << " байт" << endl;
			cout << "\n" << endl;
		}
		{
			// Задание 2
			cout << "\033[31m" << "Задание 2:\n" << "\033[0m" << endl;
			cout << "Введите ваше число: ";
			int num;
			cin >> num;
			int bit = sizeof(int) * 8;
			unsigned int mask = 1 << (bit - 1);
			cout << "Ваше число в двоичном представлении:" << endl;
			cout << "  ";
			for (int i = 0; i < bit; i++) {
				if (i % 8 == 0 and i != 0)
					cout << " ";
				if (num & (mask >> i)) {
					cout << "1";
				}
				else {
					cout << "0";
				}
				if (i == 0) {
					cout << "  ";
				}
			}
			cout << "\033[32m" << "\n |_||__________________________________|" << endl;
			cout  << " Знак     Значащие разряды" << "\033[0m" << endl;
			cout << "\n" << endl;
		}
		{
			// Задание 3
			cout << "\033[31m" << "Задание 3:\n" << "\033[0m" << endl;
			union {
				unsigned int tool;
				float num;
			};
			cout << "Введите ваше число: ";
			cin >> num;
			int bit = sizeof(float) * 8;
			unsigned int mask = 1 << (bit - 1);
			cout << "Ваше число в двоичном представлении:" << endl;
			cout << "  ";
			for (int i = 0; i < bit; i++) {
				if (tool & (mask >> i)) {
					cout << "1";
				}
				else {
					cout << "0";
				}
				if (i == 0) cout << "  ";      // знак
				else if (i == 8) cout << "  "; // порядок
			}
			cout << "\033[32m" << "\n |_||________||_______________________|" << endl;
			cout << " Знак Порядок          Мантисса" << "\033[0m" << endl;
			cout << "\n" << endl;
		}
		{
			// Задание 4
			cout << "\033[31m" << "Задание 4:\n" << "\033[0m" << endl;

			cout << "Введите ваше число: ";
			double temp;
			cin >> temp;
			union {
				unsigned int tool[2];
				double num;
			}memory;
			memory.num = temp;
			int bit = sizeof(int) * 8;
			unsigned int mask1part = 1 << (bit - 1);
			cout << "Ваше число в двоичном представлении:" << endl;
			cout << "  ";
			for (int i = 0; i < bit; ++i) {
				if (memory.tool[1] & (mask1part >> i)) {
					cout << "1";
				}
				else {
					cout << "0";
				}
				if (i == 0)
					cout << "  ";
				if (i == 11)
					cout << "  ";
			}
			unsigned int mask2part = 1 << (bit - 1);
			for (int i = 0; i < bit; ++i) {
				if (memory.tool[0] & (mask2part >> i)) {
					cout << "1";
				}
				else {
					cout << "0";
				}
			}
			cout << "\033[32m" << "\n |_||___________||____________________________________________________|\n";
			cout << " Знак  Порядок                         Мантисса\n" << "\033[0m";
			cout << "\n\n" << endl;
		}
		{
			// Задание 5
			cout << "\033[31m" << "Задание 5:\n" << "\033[0m" << endl;
			cout << "Выберите тип данных для ввода:" << endl
				<< "Тип short int (-32 768 ... 32 767) - 1" << endl
				<< "Тип long int (-2 147 483 648 ... 2 147 483 647) - 2" << endl
				<< "Тип float (±1.2e-38 ... ±3.4e+38) - 3" << endl
				<< "Тип double (±2.3e-308 ... ±1.7e+308) - 4" << endl;
			int choice;
			cin >> choice;
			switch (choice) {  //вывод двоичного представления
				case 1: {
					cout << "Введите ваше число типа short int: " << endl;
					short int num;
					cin >> num;
					int bit = sizeof(short int) * 8;
					unsigned short int mask = 1 << (bit - 1);
					cout << "\n";
					cout << "Ваше число в двоичном представлении:" << endl;
					for (int i = 0; i < bit; i++) {
						if (i % 8 == 0 and i != 0)
							cout << " ";
						if (num & (mask >> i)) {
							cout << "1";
						}
						else {
							cout << "0";
						}
					}
					cout << "\n";
					cout << "Какой бит вы хотите заменить (счёт слева, начиная с 1)?: " << endl;
					int bitNum;  //номер бита для замены
					cin >> bitNum;
					cout << "\n";
					cout << "На какое значение изменить (0 или 1)?: " << endl;
					int bitValue;  //заменить на
					cin >> bitValue;
					cout << "\n";
					cout << "Новое число:" << endl;
					unsigned int maskChange = 1 << (bit - bitNum);
					if (bitValue == 1) {
						num = num | maskChange;
						cout << num << endl;
					}
					if (bitValue == 0) {
						num = num & (~maskChange);
						cout << num << endl;
					}
					cout << "\n";
					cout << "Новое число в двоичном представлении:" << endl;
					for (int i = 0; i < bit; i++) {
						if (i % 8 == 0 and i != 0)
							cout << " ";
						if (num & (mask >> i)) {
							cout << "1";
						}
						else {
							cout << "0";
						}
					}
					cout << "\n" << endl;
					break;
				}
				case 2: {
					cout << "Введите ваше число типа long int: " << endl;
					long int num;
					cin >> num;
					int bit = sizeof(long int) * 8;
					unsigned long int mask = 1 << (bit - 1);
					cout << "\n";
					cout << "Ваше число в двоичном представлении:" << endl;
					for (int i = 0; i < bit; i++) {
						if (i % 8 == 0 and i != 0)
							cout << " ";
						if (num & (mask >> i)) {
							cout << "1";
						}
						else {
							cout << "0";
						}
					}
					cout << "\n";
					cout << "Какой бит вы хотите заменить (счёт слева, начиная с 1)?: " << endl;
					int bitNum;  //номер бита для замены
					cin >> bitNum;
					cout << "\n";
					cout << "На какое значение изменить (0 или 1)?: " << endl;
					int bitValue;  //заменить на
					cin >> bitValue;
					cout << "\n";
					cout << "Новое число:" << endl;
					unsigned int maskChange = 1 << (bit - bitNum);
					if (bitValue == 1) {
						num = num | maskChange;
						cout << num << endl;
					}
					if (bitValue == 0) {
						num = num & (~maskChange);
						cout << num << endl;
					}
					cout << "\n";
					cout << "Новое число в двоичном представлении:" << endl;
					for (int i = 0; i < bit; i++) {
						if (i % 8 == 0 and i != 0)
							cout << " ";
						if (num & (mask >> i)) {
							cout << "1";
						}
						else {
							cout << "0";
						}
					}
					cout << "\n" << endl;
					break;
				}
				case 3: {
					union {
						unsigned int tool;
						float num;
					};
					cout << "\n";
					cout << "Введите ваше число типа float: " << endl;
					cin >> num;
					int bit = sizeof(float) * 8;
					unsigned int mask = 1 << (bit - 1);
					cout << "\n";
					cout << "Ваше число в двоичном представлении:" << endl;
					for (int i = 0; i < bit; i++) {
						if ((i % 8 == 0 and i != 0))
							cout << " ";
						if (tool & (mask >> i)) {
							cout << "1";
						}
						else {
							cout << "0";
						}
					}
					cout << "\n";
					cout << "Какой бит вы хотите заменить (счёт слева, начиная с 1)?: " << endl;
					int bitNum;  //номер бита для замены
					cin >> bitNum;
					cout << "\n";
					cout << "На какое значение изменить (0 или 1)?: " << endl;
					int bitValue;  //заменить на
					cin >> bitValue;
					cout << "\n";
					cout << "Новое число:" << endl;
					unsigned int maskChange = 1 << (bit - bitNum);
					if (bitValue == 1) {
						tool = tool | maskChange;
						cout << num << endl;
					}
					if (bitValue == 0) {
						tool = tool & (~maskChange);
						cout << num << endl;
					}
					cout << "\n";
					cout << "Новое число в двоичном представлении:" << endl;
					for (int i = 0; i < bit; i++) {
						if ((i % 8 == 0 and i != 0))
							cout << " ";
						if (tool & (mask >> i)) {
							cout << "1";
						}
						else {
							cout << "0";
						}
					}
					cout << "\n" << endl;
					break;
				}
				case 4: {
					cout << "Введите ваше число типа double: " << endl;
					double temp;
					cin >> temp;
					union {
						unsigned int tool[2];
						double num;
					}memory;
					memory.num = temp;
					int bit = sizeof(int) * 8;
					unsigned int mask1part = 1 << (bit - 1);
					for (int i = 0; i < bit; ++i) {
						if (i % 8 == 0 and i != 0)
							cout << " ";
						if (memory.tool[1] & (mask1part >> i)) {
							cout << "1";
						}
						else {
							cout << "0";
						}
					}
					unsigned int mask2part = 1 << (bit - 1);
					for (int i = 0; i < bit; ++i) {
						if (i % 8 == 0)
							cout << " ";
						if (memory.tool[0] & (mask2part >> i)) {
							cout << "1";
						}
						else {
							cout << "0";
						}
					}
					cout << "\n";
					cout << "Какой бит вы хотите заменить (счёт слева, начиная с 1)?: " << endl;
					int bitNum;  //номер бита для замены
					cin >> bitNum;
					cout << "На какое значение изменить (0 или 1)?: " << endl;
					int bitValue;  //заменить на
					cin >> bitValue;
					cout << "\n";
					cout << "Новое число:" << endl;
					if (bitNum < 32) {
						unsigned int maskChange = 1 << (bit - bitNum);
						if (bitValue == 1) {
							memory.tool[1] = memory.tool[1] | maskChange;
							cout << memory.num << endl;
						}
						if (bitValue == 0) {
							memory.tool[1] = memory.tool[1] & (~maskChange);
							cout << memory.num << endl;
						}
					}
					if (bitNum > 32) {
						bitNum = bitNum - 32;
						unsigned int maskChange = 1 << (bit - bitNum);
						if (bitValue == 1) {
							memory.tool[1] = memory.tool[1] | maskChange;
							cout << memory.num << endl;
						}
						if (bitValue == 0) {
							memory.tool[1] = memory.tool[1] & (~maskChange);
							cout << memory.num << endl;
						}
					}
					cout << "Новое число в двоичном представлении:" << endl;
					for (int i = 0; i < bit; ++i) {
						if (i % 8 == 0 and i != 0)
							cout << " ";
						if (memory.tool[1] & (mask1part >> i)) {
							cout << "1";
						}
						else {
							cout << "0";
						}
					}
					for (int i = 0; i < bit; ++i) {
						if (i % 8 == 0)
							cout << " ";
						if (memory.tool[0] & (mask2part >> i)) {
							cout << "1";
						}
						else {
							cout << "0";
						}
					}
					cout << "\n" << endl;
					break;
				}
			}
		}
		{
			// ИДЗ (задание 2)
			cout << "\033[31m" << "ИДЗ (задание 2):\n" << "\033[0m" << endl;
			cout << "Введите ваше число: ";
			int num;
			cin >> num;
			unsigned int numDouble = num << 1;  //сдвиг влево на 1 увеличивает степени двойки на 1 
			cout << "Удвоенное число: ";//из-за чего число становится в 2 раза больше
			cout << "\033[32m" << numDouble << "\033[0m" << endl;
		}
		return 0;
	}