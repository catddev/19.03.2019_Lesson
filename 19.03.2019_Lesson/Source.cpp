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
//- Изменение размеров массива при добавлении и удалении записей;
//-Поиск по фамилии и имени;
//-Редактирование записи.
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
	
};


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
				in_file.getline(s[i].surname, 30, '#');
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
			ifstream in_file("in2.txt");

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