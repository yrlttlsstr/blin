#ifndef _OPER_MAT_H_
#define _OPER_MAT_H_

//создает м-цу
double** create_mat(int size);

//вводим значения эл-тов м-цы
double** input_mat(int& size);

//выводим м-цу
void output_mat(double** mat, int size);

//очистка и удаление м-цы
void clean_mat(double** mat, int size);

//копирование одной м-цы во вторую
void copy_mat(double** mat_from, double** mat_to, int size);

//операция возведения в степень
double** power_mat(double** mat_1, int size, int power);

//создание единичной м-цы
double** create_identity_mat(int size);

//операция умножения м-цы на число
double** multiply_by_num_mat(double** mat_1, int size, double num);

//операция сложения(вычитания)
double** addition_mat(double** mat_1, double** mat_2, int size);

//вычисление выражения  с выводом промежуточных результатов
double** calculator_mat(double** mat, int size);

#endif // _OPER_MAT_H_
