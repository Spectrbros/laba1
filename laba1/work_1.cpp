	#include <iostream>

	using namespace std;

	int main() {
		setlocale(0, "");
		{
			// ������� 1
			cout << "\033[31m" << "������� 1:\n" << "\033[0m" << endl;
			cout << "��� int = " << sizeof(int) << " ����" << endl;
			cout << "��� short int = " << sizeof(short int) << " ����" << endl;
			cout << "��� long int = " << sizeof(long int) << " ����" << endl;
			cout << "��� float = " << sizeof(float) << " ����" << endl;
			cout << "��� double = " << sizeof(double) << " ����" << endl;
			cout << "��� long double = " << sizeof(long double) << " ����" << endl;
			cout << "��� char = " << sizeof(char) << " ����" << endl;
			cout << "��� bool = " << sizeof(bool) << " ����" << endl;
			cout << "\n" << endl;
		}
		{
			// ������� 2
			cout << "\033[31m" << "������� 2:\n" << "\033[0m" << endl;
			cout << "������� ���� �����: ";
			int num;
			cin >> num;
			int bit = sizeof(int) * 8;
			unsigned int mask = 1 << (bit - 1);
			cout << "���� ����� � �������� �������������:" << endl;
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
			cout  << " ����     �������� �������" << "\033[0m" << endl;
			cout << "\n" << endl;
		}
		{
			// ������� 3
			cout << "\033[31m" << "������� 3:\n" << "\033[0m" << endl;
			union {
				unsigned int tool;
				float num;
			};
			cout << "������� ���� �����: ";
			cin >> num;
			int bit = sizeof(float) * 8;
			unsigned int mask = 1 << (bit - 1);
			cout << "���� ����� � �������� �������������:" << endl;
			cout << "  ";
			for (int i = 0; i < bit; i++) {
				if (tool & (mask >> i)) {
					cout << "1";
				}
				else {
					cout << "0";
				}
				if (i == 0) cout << "  ";      // ����
				else if (i == 8) cout << "  "; // �������
			}
			cout << "\033[32m" << "\n |_||________||_______________________|" << endl;
			cout << " ���� �������          ��������" << "\033[0m" << endl;
			cout << "\n" << endl;
		}
		{
			// ������� 4
			cout << "\033[31m" << "������� 4:\n" << "\033[0m" << endl;

			cout << "������� ���� �����: ";
			double temp;
			cin >> temp;
			union {
				unsigned int tool[2];
				double num;
			}memory;
			memory.num = temp;
			int bit = sizeof(int) * 8;
			unsigned int mask1part = 1 << (bit - 1);
			cout << "���� ����� � �������� �������������:" << endl;
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
			cout << " ����  �������                         ��������\n" << "\033[0m";
			cout << "\n\n" << endl;
		}
		{
			// ������� 5
			cout << "\033[31m" << "������� 5:\n" << "\033[0m" << endl;
			cout << "�������� ��� ������ ��� �����:" << endl
				<< "��� short int (-32 768 ... 32 767) - 1" << endl
				<< "��� long int (-2 147 483 648 ... 2 147 483 647) - 2" << endl
				<< "��� float (�1.2e-38 ... �3.4e+38) - 3" << endl
				<< "��� double (�2.3e-308 ... �1.7e+308) - 4" << endl;
			int choice;
			cin >> choice;
			switch (choice) {  //����� ��������� �������������
				case 1: {
					cout << "������� ���� ����� ���� short int: " << endl;
					short int num;
					cin >> num;
					int bit = sizeof(short int) * 8;
					unsigned short int mask = 1 << (bit - 1);
					cout << "\n";
					cout << "���� ����� � �������� �������������:" << endl;
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
					cout << "����� ��� �� ������ �������� (���� �����, ������� � 1)?: " << endl;
					int bitNum;  //����� ���� ��� ������
					cin >> bitNum;
					cout << "\n";
					cout << "�� ����� �������� �������� (0 ��� 1)?: " << endl;
					int bitValue;  //�������� ��
					cin >> bitValue;
					cout << "\n";
					cout << "����� �����:" << endl;
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
					cout << "����� ����� � �������� �������������:" << endl;
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
					cout << "������� ���� ����� ���� long int: " << endl;
					long int num;
					cin >> num;
					int bit = sizeof(long int) * 8;
					unsigned long int mask = 1 << (bit - 1);
					cout << "\n";
					cout << "���� ����� � �������� �������������:" << endl;
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
					cout << "����� ��� �� ������ �������� (���� �����, ������� � 1)?: " << endl;
					int bitNum;  //����� ���� ��� ������
					cin >> bitNum;
					cout << "\n";
					cout << "�� ����� �������� �������� (0 ��� 1)?: " << endl;
					int bitValue;  //�������� ��
					cin >> bitValue;
					cout << "\n";
					cout << "����� �����:" << endl;
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
					cout << "����� ����� � �������� �������������:" << endl;
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
					cout << "������� ���� ����� ���� float: " << endl;
					cin >> num;
					int bit = sizeof(float) * 8;
					unsigned int mask = 1 << (bit - 1);
					cout << "\n";
					cout << "���� ����� � �������� �������������:" << endl;
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
					cout << "����� ��� �� ������ �������� (���� �����, ������� � 1)?: " << endl;
					int bitNum;  //����� ���� ��� ������
					cin >> bitNum;
					cout << "\n";
					cout << "�� ����� �������� �������� (0 ��� 1)?: " << endl;
					int bitValue;  //�������� ��
					cin >> bitValue;
					cout << "\n";
					cout << "����� �����:" << endl;
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
					cout << "����� ����� � �������� �������������:" << endl;
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
					cout << "������� ���� ����� ���� double: " << endl;
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
					cout << "����� ��� �� ������ �������� (���� �����, ������� � 1)?: " << endl;
					int bitNum;  //����� ���� ��� ������
					cin >> bitNum;
					cout << "�� ����� �������� �������� (0 ��� 1)?: " << endl;
					int bitValue;  //�������� ��
					cin >> bitValue;
					cout << "\n";
					cout << "����� �����:" << endl;
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
					cout << "����� ����� � �������� �������������:" << endl;
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
			// ��� (������� 2)
			cout << "\033[31m" << "��� (������� 2):\n" << "\033[0m" << endl;
			cout << "������� ���� �����: ";
			int num;
			cin >> num;
			unsigned int numDouble = num << 1;  //����� ����� �� 1 ����������� ������� ������ �� 1 
			cout << "��������� �����: ";//��-�� ���� ����� ���������� � 2 ���� ������
			cout << "\033[32m" << numDouble << "\033[0m" << endl;
		}
		return 0;
	}