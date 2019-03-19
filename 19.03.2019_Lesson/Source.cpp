#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>
#include<cstring>
#include<fstream>

using namespace std;

// 6.	***Описать структуру Mark(название предмета, оценка),
// описать структуру Student(фамилия, группа, успеваемость(массив оценок(Mark)).
// Создать массив студентов и написать программу, позволяющую:
// -динамически изменять размер массива;
// -выводить список отличников(> 75 % отл оценок);
struct Mark {
	char subject[50];
	int grade[2];
};
struct Student {
	char surname[30];
	char group[10];
	Mark marks[2];
	/*struct Mark{
		char subject[30];
		int grade;
	}marks[2];*/

	void print() {
		cout << surname << " " << group << " ";
		for (int i = 0; i < 2; i++)
		{
			cout << marks[i].subject << " ";
			for (int j = 0; j < 2; j++)
				cout << marks[i].grade[j] << " ";
		}
		cout << endl;
	}
	bool otlichniki() {
		int d = 0;
		for (int i = 0; i < 2; i++)
		{
			int k = 0;
			for (int j = 0; j < 2; j++)
			{
				if (marks[i].grade[j] >= 10)
					k++;
			}
			
			if (double(k) / 2 >= 0.75) d++;
			
		}
		if (d >=1) return true;
		else return false;
	}
	bool dvoechniki() {
		int k = 0;
		for (int i = 0; i < 2; i++)
		{
			int k = 0;
			for (int j = 0; j < 2; j++)
			{
				if (marks[i].grade[j] <= 6)
					k++;
			}
			if (double(k) / 5 >= 0.5) return true;
			else return false;
		}
	}
};
struct example {
	int a; //4 B, побайтовое выравнивание - растягивает занимаемую память -> пустые байты, поэтому побитовое сравнение для структур запрещено!
	// поэтому каждое свойство нужно сравнивать по отдельности
	double b; //8 B
	char c; //1 B
	bool cmp(example ex) {
		//if (c == ex.c && a = ex.a && b == ex.b)???
			return true;
	}
};

//7.***Описать структуру Man(Фамилия, Имя, Возраст, Дата рождения).Создать массив, предусмотреть:
//-Вывод информации с сортировкой по фамилии или имени;
//-Вывод списка именинников месяца с указанием даты рождения.
//-Изменение размеров массива при добавлении и удалении записей;
//-Поиск по фамилии и имени;
//-Редактирование записи.

int current_size=0; //глобальная переменная для расширения-сужения динамического массива структур
int buffer_size = 0;

struct Date {
	int day, month, year;
	void print() {
		cout << day << "/" << month << "/" << year << endl;
	}
};
struct Man {
	char name[30];
	char surname[30];
	int age;
	Date date_of_birth;

	void print() {
		cout << name << " " << surname << " " << age <<" ";
		date_of_birth.print();
		cout << endl;
	}
	
};
void add(Man*&ms, Man m) {
	if (buffer_size == 0) // когда изначально буфер равен нулю
	{
		buffer_size = 4;
		ms = new Man[buffer_size];
	}
	else
	{
		if (current_size == buffer_size)
		{
			buffer_size *= 2;
			Man*tmp=new Man[buffer_size]; //выделение памяти на двухкратное количество элементов, т.е. запас
			for (int i = 0; i < current_size; i++)
				tmp[i] = ms[i];
			delete[] ms;
			ms = tmp;
		}
	}
	ms[current_size++] = m; //запись нулевого элемента и добавление текущего размера до 1 и далее по циклу
}
void erase_last(Man*&ms) {
	current_size--;
	if (current_size == 0)
		delete[] ms;
}
void erase_by_name(Man*&ms, const char*name) {
	for (int i = 0; i < current_size; i++)
	{
		if (strcmp(ms[i].name, name) == 0) // если не полное совпадение имени нужно, то использовать strstr
		{
			for (int j = i; j < current_size; j++)
			{
				ms[j] = ms[j + 1];
				i--;
			}
			current_size--;
		}
		
	}
}

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn; cin.get();

		switch (tn)
		{
		case 1:
		{
			ifstream in_file("in.txt");
			Student *s;
			int n;
			in_file >> n;
			s = new Student[n];

			for (int i = 0; i < n; i++)
			{
				in_file.ignore();
				in_file.getline(s[i].surname, 30, '#'); //чтобы не до пробела, а до # считывал
				in_file >> s[i].group;
				for (int j = 0; j < 2; j++)
				{
					in_file >> s[i].marks[i].subject;
						for (int p=0; p<2; p++)
						{
							in_file >> s[i].marks[j].grade[p];
						}
				}
			}
			cout << "Отличники:" << endl;
			for (int i = 0; i < n; i++)
				if (s[i].otlichniki() == true)
					s[i].print();

		/*	for (int i = 0; i < n; i++)
				s[i].print();
			cout << endl;*/
		}
		break;
		case 2:
		{
			//Student s1;
			//cout << sizeof(s1) << endl;

			//example e;
			//cout << sizeof(example) << endl;

			//example e1, e2;
			//if (e1.c == e2.c && e1.a == e2.a && e1.b == e2.b) // т.е. при сравнении структур две структруры равны если равны все их свойства по отдельности
			//	// структуры должны быть одного типа для сравнения
			//	cout << "The same" << endl;
			//// error запрещено!: if(e1==e2)
		}
		break;
		case 3:
		{
			Man*ms=0; //нужно инициализировать через ноль, чтобы прога запустилась
			Man tmp_man;
			char c;
			ifstream in_file("in2.txt");
			if (!in_file)
			{
				cerr << "Enter open error" << endl;
			}
			else
			{
				while (!in_file.eof())
				{
					in_file >> tmp_man.name >> tmp_man.surname >> tmp_man.age >>
						tmp_man.date_of_birth.day >> c
						>> tmp_man.date_of_birth.month >> c
						>> tmp_man.date_of_birth.year;

					add(ms, tmp_man);
				}
			}
			erase_last(ms);
			erase_by_name(ms, "Karina");
			erase_by_name(ms, "Liza");
			for (int i = 0; i < current_size; i++)
				ms[i].print();
		}
		break;
		case 4:
		{

		}
		break;
		case 5:
		{

		}
		break;
		case 6:
		{

		}
		break;
		case 7:
		{

		}
		break;
		case 8:
		{

		}
		break;
		case 9:
		{

		}
		break;
		case 10:
		{

		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}