#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <malloc.h>
using namespace std;

#define MaxWidth 4
#define MaxHeight 999

//ОПРЕДЕЛЕНИЕ ГЛОБАЛЬНОГО СТАТИЧЕСКОГО ДВУМЕРНОГО МАССИВА
int Array[MaxHeight][MaxWidth];

//ОПЕРЕДЕЛЕНИЕ ГЛОБАЛЬНОГО ДИНАМИЧЕСКОГО МАССИВА
int** DynamicArray;

//ПРОТОТИПЫ ФУНКЦИЙ:
void Interface_Main();
void Interface_Task1();
void Interface_Task1_InputArray();
void Interface_Task2();
void Interface_Task2_InputArray();
void Interface_Task3();
void Interface_Task3_InputArray();

int InputController(int Max_Variants, int Min_Variants);
//ЗАДАНИЕ 1
void Task1_InputArrayByHand(int Array[][MaxWidth], int Height, int Width);
void Task1_InputArrayByRand(int Array[][MaxWidth], int Height, int Width);
void Task1_AverageGradeOfStudents(int Array[][MaxWidth], int Height, int Width);
void Task1_OutputArray(int Array[][MaxWidth], int Height, int Width);
void Task1_AverageGradeForChosenDiscipline(int Array[][MaxWidth], int Height, int Width, int Dis_Num);
void Task1_AverageGradeOfGrope(int Array[][MaxWidth], int Height, int Width);
void Task1_StudentsSort(int Array[][MaxWidth], int Height, int Width);
void Task1_AverageGradeArray(double* AverageGrade, int Array[][MaxWidth], int Height, int Width);
//ЗАДАНИЕ 2
int** Task2_CreateDynamicArray(int Height, int Width);
void Task2_InputArrayByHand(int** DynamicArray, int Height, int Width);
void Task2_InputArrayByRand(int** DynamicArray, int Height, int Width);
void Task2_OutputArray(int** DynamicArray, int Height, int Width);
int Task2_RemoveOutsiders(int** DynamicArray, int Height, int Width);
void Task2_AverageGradeArray(double* AverageGrade, int** DynamicArray, int Height, int Width);
//ЗАДАНИЕ 3
int** Task3_CreateDynamicArray(int Height);
void Task3_InputArrayByHand(int** DynamicArray, int Height);
void Task3_InputArrayByRand(int** DynamicArray, int Height);
void Task3_OutputArray(int** DynamicArray, int Height);
void Task3_MaxElementInTaskArea(int** DynamicArray, int Height);

int main()
{
	system("cls");
	setlocale(LC_CTYPE, "RUS");
	int step;
	int Height;
	int Height_Controller1 = 0;
	int Height_Controller2 = 0;
	int Height_Controller3 = 0;

	while (true)
	{
		Interface_Main();
		int Step_MaxVariants = 4;
		int Step_MinVariants = 1;
		int Array_MinIndex = 1;
		step = InputController(Step_MaxVariants, Step_MinVariants);

/*____________________________________________________________________________________________*/

		//ЗАДАНИЕ 1 И ИЖЕ С НИМ
		if (step == 1)
		{
			while (true)
			{
				system("cls");
				Interface_Task1();
				Step_MaxVariants = 7;
				step = InputController(Step_MaxVariants, Step_MinVariants);

				//ВВОД КОЛИЧЕСТВА СТУДЕНТОВ В КОНТЕКСТЕ ЗАДАНИЯ 1
				if (step == 1)
				{
					while (true)
					{
						system("cls");
						cout << "Введите количество студентов: " << endl;
						Height = InputController(MaxHeight, Array_MinIndex);
						Interface_Task1_InputArray();
						Step_MaxVariants = 3;
						step = InputController(Step_MaxVariants, Step_MinVariants);
						Height_Controller1 = 1;

						//ВЫЗОВ ПРОЦЕДУРЫ РУЧНОГО ЗАПОЛНЕНИЯ
						if (step == 1)
						{
							Task1_InputArrayByHand(Array, Height, MaxWidth);
							step = 0;
							break;
						}

						//ВЫЗОВ ПРОЦЕДУРЫ АВТОЗАПОЛНЕНИЯ СЛУЧАЙНЫМИ ЧИСЛАМИ
						else if (step == 2)
						{
							Task1_InputArrayByRand(Array, Height, MaxWidth);
							step = 0;
							break;
						}

						//ВЫХОД В МЕНЮ ЗАДАНИЯ
						else if (step == 3)
						{
							Height_Controller1 = 0;
							step = 0;
							break;
						}
					}					    
				}

			    //ВЫВОД МАССИВА В КОНТЕКСТЕ ЗАДАНИЯ 1
				if (step == 2)
				{
					if (Height_Controller1 == 0)
					{
						system("cls");
						cout << "Массив не был введён!" << endl;
						system("pause");
					}
					else
					{
						Task1_OutputArray(Array, Height, MaxWidth);
					}			
				}

				//ВЫВОД ОДНОМЕРНОГО МАССИВА СРЕДНЕГО БАЛЛА КАЖДОГО СТУДЕНТА
				else if (step == 3)
				{
					if (Height_Controller1 == 0)
					{
						system("cls");
						cout << "Массив не был введён!" << endl;
						system("pause");
					}
					else
					{
						Task1_AverageGradeOfStudents(Array, Height, MaxWidth);
					}
				}

				//ОПРЕДЕЛИТЬ СРЕДНИЙ БАЛЛ ГРУППЫ ПО ДИСЦИПЛИНЕ С ЗАДАННЫМ НОМЕРОМ
				else if (step == 4)
				{
					if (Height_Controller1 == 0)
					{
						system("cls");
						cout << "Массив не был введён!" << endl;
						system("pause");
					}
					else
					{
						system("cls");
						cout << "Введите номер дисциплины: " << endl;
						int Max_Dis = 4;
						int Min_Dis = 1;
						int Dis_Num = InputController(Max_Dis, Min_Dis);
						Task1_AverageGradeForChosenDiscipline(Array, Height, MaxWidth, Dis_Num);
					}
				}

				//ОПРЕДЕЛИТЬ СРЕДНИЙ БАЛЛ ГРУППЫ
				else if (step == 5)
				{
					if (Height_Controller1 == 0)
					{
						system("cls");
						cout << "Массив не был введён!" << endl;
						system("pause");
					}
					else
					{
						Task1_AverageGradeOfGrope(Array, Height, MaxWidth);
					}
				}

				//ОТСОРТИРОВАТЬ ПО СРЕДНЕМУ БАЛЛУ
				else if (step == 6)
				{
					if (Height_Controller1 == 0)
					{
						system("cls");
						cout << "Массив не был введён!" << endl;
						system("pause");
					}
					else
					{
						Task1_StudentsSort(Array, Height, MaxWidth);
					}
				}

				//ВЫХОД В ГЛАВНОЕ МЕНЮ
				else if (step == 7)
				{
					Height_Controller1 = 0;
					step = 0;
					break;
				}
			}
		}

/*____________________________________________________________________________________________*/

        //ЗАДАНИЕ 2 И ИЖЕ С НИМ
		else if (step == 2)
		{
			while (true)
			{
				system("cls");
				Interface_Task2();
				Step_MaxVariants = 4;
				step = InputController(Step_MaxVariants, Step_MinVariants);

				//ВВОД КОЛИЧЕСТВА СТУДЕНТОВ В КОНТЕКСТЕ ЗАДАНИЯ 2
				if (step == 1)
				{
					while (true)
					{
						system("cls");
						cout << "Введите количество студентов: " << endl;
						Height = InputController(MaxHeight, Array_MinIndex);
						DynamicArray = Task2_CreateDynamicArray(Height, MaxWidth);
						Interface_Task1_InputArray();
						Step_MaxVariants = 3;
						step = InputController(Step_MaxVariants, Step_MinVariants);
						Height_Controller2 = 1;

						//ВЫЗОВ ПРОЦЕДУРЫ РУЧНОГО ЗАПОЛНЕНИЯ
						if (step == 1)
						{
							Task2_InputArrayByHand(DynamicArray, Height, MaxWidth);
							step = 0;
							break;
						}

						//ВЫЗОВ ПРОЦЕДУРЫ АВТОЗАПОЛНЕНИЯ СЛУЧАЙНЫМИ ЧИСЛАМИ
						else if (step == 2)
						{
							Task2_InputArrayByRand(DynamicArray, Height, MaxWidth);
							step = 0;
							break;
						} 

						//ВЫХОД В МЕНЮ ЗАДАНИЯ
						else if (step == 3)
						{
							Height_Controller1 = 0;
							step = 0;
							break;
						}
					}
				}

				//ВЫВОД МАССИВА В КОНТЕКСТЕ ЗАДАНИЯ 2
				else if (step == 2)
				{
					if (Height_Controller2 == 0)
					{
						system("cls");
						cout << "Массив не был введён!" << endl;
						system("pause");
					}
					else
					{
						Task2_OutputArray(DynamicArray, Height, MaxWidth);
					}
				}

				//УДАЛИТЬ СТУДЕНТОВ С ВСЕМИ НЕУДАМИ
				else if (step == 3)
				{
					if (Height_Controller2 == 0)
					{
						system("cls");
						cout << "Массив не был введён!" << endl;
						system("pause");
					}
					else
					{
						Height = Task2_RemoveOutsiders(DynamicArray,Height,MaxWidth);
						Task2_OutputArray(DynamicArray, Height, MaxWidth);
					}
				}

				//ВЫХОД В ГЛАВНОЕ МЕНЮ
				else if (step == 4) 
				{
					if (Height_Controller2 == 1)
					{
						for (int i = 0; i < Height; i++)
							delete[] DynamicArray[i];
						delete DynamicArray;
					}				
					step = 0;
					Height_Controller2 = 0;
					break;
				}
			}
		}

/*____________________________________________________________________________________________*/

        //ЗАДАНИЕ 3 И ИЖЕ С НИМ
		else if (step == 3)
		{
			while (true)
			{
				system("cls");
				Interface_Task3();
				Step_MaxVariants = 4;
				step = InputController(Step_MaxVariants, Step_MinVariants);

				//ЗАПОЛНЕНИЕ МАТРИЦЫ В КОНТЕКСТЕ ЗАДАНИЯ 3
				if (step == 1)
				{
					while (true)
					{
						system("cls");
						cout << "Введите сторону квадратной матрицы: " << endl;
						Height = InputController(MaxHeight, Array_MinIndex);
						DynamicArray = Task3_CreateDynamicArray(Height);
						Interface_Task1_InputArray();
						Step_MaxVariants = 3;
						step = InputController(Step_MaxVariants, Step_MinVariants);
						Height_Controller3 = 1;

						//ВЫЗОВ ПРОЦЕДУРЫ РУЧНОГО ЗАПОЛНЕНИЯ
						if (step == 1)
						{
							Task3_InputArrayByHand(DynamicArray, Height);
							step = 0;
							break;
						}

						//ВЫЗОВ ПРОЦЕДУРЫ АВТОЗАПОЛНЕНИЯ СЛУЧАЙНЫМИ ЧИСЛАМИ
						else if (step == 2)
						{
							Task3_InputArrayByRand(DynamicArray, Height);
							step = 0;
							break;
						}

						//ВЫХОД В МЕНЮ ЗАДАНИЯ
						else if (step == 3)
						{
							Height_Controller3 = 0;
							step = 0;
							break;
						}
					}					
				}

				//ВЫВОД МАТРИЦЫ В КОНТЕКСТЕ ЗАДАНИЯ 3
				if (step == 2)
				{
					if (Height_Controller3 == 0)
					{
						system("cls");
						cout << "Матрица не была заполнена!" << endl;
						system("pause");
					}
					else
					{
						system("cls");
						Task3_OutputArray(DynamicArray, Height);
					}
				}

				//НАЙТИ НАИБОЛЬШЕЕ ЗНАЧЕНИЕ (МЕНЬШЕ ЛИБО РАВНО ГЛАВНОЙ ИЛИ ПОБОЧНОЙ ДИАГОНАЛИ)
				if (step == 3)
				{
					if (Height_Controller3 == 0)
					{
						system("cls");
						cout << "Матрица не была заполнена!" << endl;
						system("pause");
					}
					else
					{
						system("cls");
						Task3_MaxElementInTaskArea(DynamicArray, Height);
					}
				}

				//ВЫХОД В ГЛАВНОЕ МЕНЮ
				if (step == 4)
				{
					if (Height_Controller3 == 1)
					{
						for (int i = 0; i < Height; i++)
							delete[] DynamicArray[i];
						delete DynamicArray;
					}
					step = 0;
					Height_Controller3 = 0;
					break;
				}
			}
		}

/*____________________________________________________________________________________________*/

        //ВЫХОД ИЗ ПРОГРАММЫ
		else if (step == 4)
		{
			system("cls");
			cout << "Выход из программы осуществлен!" << endl;
			system("pause");
			break;
		}
	}
}

//ОПИСАНИЕ ФУНКЦИЙ ИНТЕРФЕЙСА:

void Interface_Main()
{
	system("cls");
	cout << "Лабораторная работа №2: Вариант 14" << endl;
	cout << "Выберите действие:" << endl;
	cout << "1. Задание 1;" << endl;
	cout << "2. Задание 2;" << endl;
	cout << "3. Задание 3;" << endl;
	cout << "4. Выход из программы." << endl;	
}

void Interface_Task1()
{
	system("cls");
	cout << "Выбрано Задание 1." << endl;
	cout << "Выберите действие:" << endl;
	cout << "1. Ввод количества студентов(Пересоздание массива)." << endl;
	cout << "2. Вывод массива." << endl;
	cout << "3. Сформировать массив, содержащий средний балл каждого студента." << endl;
	cout << "4. Определить средний балл группы по дисциплине с заданным номером." << endl;
	cout << "5. Определить средний балл по группе." << endl;
	cout << "6. Отсортировать массив по среднему баллу студента." << endl;
	cout << "7. Вернуться к выбору задания." << endl;
}

void Interface_Task1_InputArray()
{
	system("cls");
	cout << "Выберите способ заполнения массива: " << endl;
	cout << "1. Ввод вручную." << endl;
	cout << "2. Автозаполнение случайными числами." << endl;
	cout << "3. Вернуться к выбору подзадания." << endl;
}

void Interface_Task2()
{
	cout << "Выбрано Задание 2." << endl;
	cout << "Выберите действие:" << endl;
	cout << "1. Ввод количества студентов(Пересоздание массива)." << endl;
	cout << "2. Вывод массива." << endl;
	cout << "3. Удалить студентов, имеющих по всем дисциплинам оценку 2." << endl;
	cout << "4. Вернуться к выбору задания." << endl;
}

void Interface_Task2_InputArray()
{
	system("cls");
	cout << "Выберите способ заполнения массива: " << endl;
	cout << "1. Ввод вручную." << endl;
	cout << "2. Автозаполнение случайными числами." << endl;
	cout << "3. Вернуться к выбору подзадания." << endl;
}

void Interface_Task3()
{
	cout << "Выбрано Задание 3." << endl;
	cout << "Выберите действие:" << endl;
	cout << "1. Ввод cтороны квадратной матрицы(Создание массива)." << endl;
	cout << "2. Вывод матрицы на экран." << endl;
	cout << "3. Найти наибольшее из значений элементов, расположенных в заштрихованной части матрицы." << endl;
	cout << "4. Вернуться к выбору задания." << endl;
}

void Interface_Task3_InputArray()
{
	system("cls");
	cout << "Выберите способ заполнения матрицы: " << endl;
	cout << "1. Ввод вручную." << endl;
	cout << "2. Автозаполнение случайными числами." << endl;
	cout << "3. Вернуться к выбору подзадания." << endl;
}

//ОПИСАНИЕ ФУНКЦИЙ:

int InputController(int Max_Variants, int Min_Variants)
{
	cout << ">>> ";
	int Input_Value;
	while (!(cin >> Input_Value) || Input_Value < Min_Variants || Input_Value > Max_Variants)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Вы ввели некорректное значение!" << endl;
		cout << "Повторите ввод." << endl;
		cout << ">>> ";
	}
	return Input_Value;
}

void Task1_InputArrayByHand(int Array[][MaxWidth], int Height, int Width)
{
	system("cls");
	cout << "Массив: " << endl;
	cout << endl;
	cout << "Дисциплины № 1 2 3 4" << endl;
	cout << "--------------------" << endl;
	for (int i = 0; i < Height; i++)
	{
		if (i < 9)
		{
			cout << "Студент 00" << i + 1 << ": ";
		}
		else if (i < 99)
		{
			cout << "Студент 0" << i + 1 << ": ";
		}
		else
		{
			cout << "Студент " << i + 1 << ": ";
		}
		for (int j = 0; j < Width; j++)
		{
			while (!(cin >> Array[i][j]) || Array[i][j] < 2 || Array[i][j] > 5)
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Ввведена некорректная оценка!" << endl;
				cout << "Повторите ввод." << endl;
				if (i < 9)
				{
					cout << "Студент 00" << i + 1 << ": ";
				}
				else if (i < 99)
				{
					cout << "Студент 0" << i + 1 << ": ";
				}
				else
				{
					cout << "Студент " << i + 1 << ": ";
				}
			}
		}
	}
	cout << "--------------------" << endl;
	cout << "Ввод массива окончен!" << endl;
	system("pause");
}

void Task1_InputArrayByRand(int Array[][MaxWidth], int Height, int Width)
{
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			Array[i][j] = rand() % 4 + 2;
		}
	}
	system("cls");
	cout << "Массив был успешно заполнен случайными числами!" << endl;
	system("pause");
}

void Task1_OutputArray(int Array[][MaxWidth], int Height, int Width)
{
	system("cls");
	cout << "Массив: " << endl;
	cout << "Дисциплины № 1 2 3 4" << endl;
	cout << "--------------------" << endl;
	for (int i = 0; i < Height; i++)
	{
		if (i < 9)
		{
			cout << "Студент 00" << i + 1 << ": ";
		}
		else if (i < 99)
		{
			cout << "Студент 0" << i + 1 << ": ";
		}
		else
		{
			cout << "Студент " << i + 1 << ": ";
		}
		
		for (int j = 0; j < Width; j++)	
			cout << Array[i][j] << " ";
			
		cout << endl;
	}
	cout << "--------------------";
	cout << endl;
	cout << "Вывод массива окончен!" << endl; 
	system("pause");
}

void Task1_AverageGradeOfStudents(int Array[][MaxWidth], int Height, int Width)
{
	system("cls");
	cout << "Средний балл каждого студента: " << endl;
	cout << endl;
	double Current_Sum = 0;
	double *AverageGrade = new double[Height];
	Task1_AverageGradeArray(AverageGrade, Array, Height, Width);
	for (int i = 0; i < Height; i++)
	{
		if (i < 9)
		{
			cout << "Студент 00" << i + 1 << ": " << AverageGrade[i] << endl;
		}

		else if (i < 99)
		{
			cout << "Студент 0" << i + 1 << ": " << AverageGrade[i] << endl;
		}

		else
		{
			cout << "Студент " << i + 1 << ": " << AverageGrade[i] << endl;
		}
		Current_Sum = 0;
	}
	cout << endl;
	cout << "Ввод массива окончен!" << endl;
	system("pause");
	delete AverageGrade;
}

void Task1_AverageGradeForChosenDiscipline(int Array[][MaxWidth], int Height, int Width, int Dis_Num)
{
	double Current_Sum = 0;
	double AverageGrade = 0;
	for (int i = 0; i < Height; i++)
	{
		Current_Sum += Array[i][Dis_Num - 1];
	}
	AverageGrade = Current_Sum / Height;
	system("cls");
	cout << "Средний балл группы по дисциплине №" << Dis_Num << ": " << AverageGrade << endl;
	system("pause");
}

void Task1_AverageGradeOfGrope(int Array[][MaxWidth], int Height, int Width)
{
	double Current_Sum = 0;
	double Global_Sum = 0;
	double AverageGrade = 0;
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			Current_Sum += Array[i][j];
		}
		Global_Sum += Current_Sum;
		Current_Sum = 0;
	}
	AverageGrade = (Global_Sum / (Height * Width));
	system("cls");
	cout << "Средний балл группы: " << AverageGrade << endl;
	system("pause");
}

void Task1_StudentsSort(int Array[][MaxWidth], int Height, int Width)
{
	int temp;
	double *AverageGrade = new double[Height];
	Task1_AverageGradeArray(AverageGrade, Array, Height, Width);
	for (int k = 0; k < Height; k++)
	{
		for (int i = 0; i < Height - 1; i++)
		{
		    if (AverageGrade[i] > AverageGrade[i + 1])
			{
				for (int j = 0; j < Width; j++)
				{
					temp = Array[i][j];
					Array[i][j] = Array[i + 1][j];
					Array[i + 1][j] = temp;
					Task1_AverageGradeArray(AverageGrade, Array, Height, Width);
				}
			}
		}
	}
	delete AverageGrade;
	Task1_OutputArray(Array, Height, Width);
}

void Task1_AverageGradeArray(double* AverageGrade, int Array[][MaxWidth],  int Height, int Width)
{
	double Current_Sum = 0;
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			Current_Sum += Array[i][j];
		}
		AverageGrade[i] = Current_Sum / Width;
		Current_Sum = 0;
	}
}

int** Task2_CreateDynamicArray(int Height, int Width)
{
	int ** DynamicArray = new int*[Height];

	for (int i = 0; i < Height; i++)
	{
		DynamicArray[i] = new int[Width];
	}
	return(DynamicArray);
}

void Task2_InputArrayByHand(int** DynamicArray, int Height, int Width)
{
	system("cls");
	cout << "Массив: " << endl;
	cout << endl;
	cout << "Дисциплины № 1 2 3 4" << endl;
	cout << "--------------------" << endl;
	for (int i = 0; i < Height; i++)
	{
		if (i < 9)
		{
			cout << "Студент 00" << i + 1 << ": ";
		}
		else if (i < 99)
		{
			cout << "Студент 0" << i + 1 << ": ";
		}
		else
		{
			cout << "Студент " << i + 1 << ": ";
		}
		for (int j = 0; j < Width; j++)
		{
			while (!(cin >> DynamicArray[i][j]) || DynamicArray[i][j] < 2 || DynamicArray[i][j] > 5)
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Ввведена некорректная оценка!" << endl;
				cout << "Повторите ввод." << endl;
				if (i < 9)
				{
					cout << "Студент 00" << i + 1 << ": ";
				}
				else if (i < 99)
				{
					cout << "Студент 0" << i + 1 << ": ";
				}
				else
				{
					cout << "Студент " << i + 1 << ": ";
				}
			}
		}
	}
	cout << "--------------------" << endl;
	cout << "Ввод массива окончен!" << endl;
	system("pause");
}

void Task2_InputArrayByRand(int** DynamicArray, int Height, int Width)
{
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			DynamicArray[i][j] = rand() % 4 + 2;
		}
	}
	system("cls");
	cout << "Массив был успешно заполнен случайными числами!" << endl;
	system("pause");
}

void Task2_OutputArray(int** DynamicArray, int Height, int Width)
{
	system("cls");
	cout << "Динамический массив: " << endl;
	cout << "Дисциплины № 1 2 3 4" << endl;
	cout << "--------------------" << endl;
	for (int i = 0; i < Height; i++)
	{
		if (i < 9)
		{
			cout << "Студент 00" << i + 1 << ": ";
		}
		else if (i < 99)
		{
			cout << "Студент 0" << i + 1 << ": ";
		}
		else
		{
			cout << "Студент " << i + 1 << ": ";
		}

		for (int j = 0; j < Width; j++)
			cout << DynamicArray[i][j] << " ";

		cout << endl;
	}
	cout << "--------------------";
	cout << endl;
	cout << "Вывод динамического массива окончен!" << endl;
	system("pause");
}

int Task2_RemoveOutsiders(int** DynamicArray, int Height, int Width)
{
	int temp;
	int Sub_Height = 0;
	double *AverageGrade = new double[Height];
	Task2_AverageGradeArray(AverageGrade, DynamicArray, Height, Width);
	for (int i = 0; i < Height; i++)
	{
		if (AverageGrade[i] != 2)
			Sub_Height++;
	}

	for (int k = 0; k < Height; k++)
	{
		for (int i = 0; i < Height - 1; i++)
		{
			if (AverageGrade[i] == 2 && AverageGrade[i + 1] != 2)
			{
				for (int j = 0; j < Width; j++)
				{
					temp = DynamicArray[i][j];
					DynamicArray[i][j] = DynamicArray[i + 1][j];
					DynamicArray[i + 1][j] = temp;
					Task2_AverageGradeArray(AverageGrade, DynamicArray, Height, Width);
				}
			}
		}
	}
	for (int i = Sub_Height; i < Height; i++)
		delete[] DynamicArray[i];
	delete AverageGrade;
	return Sub_Height;
}

void Task2_AverageGradeArray(double* AverageGrade, int** DynamicArray, int Height, int Width)
{
	double Current_Sum = 0;
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			Current_Sum += DynamicArray[i][j];
		}
		AverageGrade[i] = Current_Sum / Width;
		Current_Sum = 0;
	}
}

int** Task3_CreateDynamicArray(int Height)
{
	int ** DynamicArray = new int*[Height];

	for (int i = 0; i < Height; i++)
	{
		DynamicArray[i] = new int[Height];
	}
	return(DynamicArray);
}

void Task3_InputArrayByHand(int** DynamicArray, int Height)
{
	system("cls");
	cout << "*В матрицу следует построчно вводить двузначные значения элементов*" << endl;
	cout << endl;
	cout << "Матрица: " << endl;
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			while (!(cin >> DynamicArray[i][j]) || DynamicArray[i][j] < 10 || DynamicArray[i][j] > 99)
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Ввведено недопустимое значение элемента!" << endl;
				cout << "Повторите ввод." << endl;
			}
		}
	}
	cout << "Ввод матрицы окончен!" << endl;
	system("pause");
}

void Task3_InputArrayByRand(int** DynamicArray, int Height)
{
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			DynamicArray[i][j] = rand() % 89 + 10;
		}
	}
	system("cls");
	cout << "Матрица была успешно заполнена случайными числами!" << endl;
	system("pause");
}

void Task3_OutputArray(int** DynamicArray, int Height)
{
	cout << "Матрица: " << endl;
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Height; j++)
			cout << DynamicArray[i][j] << " ";

		cout << endl;
	}
	cout << "Вывод матрицы окончен!" << endl;
	system("pause");
}

void Task3_MaxElementInTaskArea(int** DynamicArray, int Height)
{
	int Max = 0;
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			if ((i >= j) || (i + j >= Height - 1))
				if (Max < DynamicArray[i][j])
					Max = DynamicArray[i][j];
		}
	}
	cout << "Наибольший элемент матрицы в заштрихованной области: " << Max << endl;
	Task3_OutputArray(DynamicArray, Height);
}