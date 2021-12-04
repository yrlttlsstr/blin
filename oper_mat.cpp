#include <iostream>
#include <iomanip>
#include "oper_mat.h"
#include "check_input.h"

using namespace std;

//������� �-��
double** create_mat(int size)
{
	double** mat = new double*[size];

	for (int i = 0; i < size; i++)
	{
		mat[i] = new double[size];
	}

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			mat[i][j] = 0;

	return mat;
}

//���������� �������� ��-��� �-��
double** input_mat(int& size)
{
	cout << "������� ������ �-��: ";
	cin >> size;
	check_input_int(size);

	double** mat = create_mat(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			cout << "������� ��-� �-�� c ������� [" << i << "][" << j << "]: ";
			cin >> mat[i][j];
			check_input_double(mat[i][j]);
		}

	return mat;
}

//������� �-��
void output_mat(double** mat, int size)
{
	cout << "\n";

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << setw(10) << mat[i][j] << " ";
		cout << "\n";
	}
}

//������� � �������� �-��
void clean_mat(double** mat, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			mat[i][j] = 0;
		delete[] mat[i];
	}

	delete[] mat;
}

//����������� ����� �-�� �� ������
void copy_mat(double** mat_from, double** mat_to, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			mat_to[i][j] = mat_from[i][j];
}

//�������� ���������� � �������
double** power_mat(double** mat_1, int size, int power)
{
	double** mat_2 = create_mat(size);
	copy_mat(mat_1, mat_2, size);

	for (int i = 0; i < (power - 1); i++)
	{
		double** res_mat = create_mat(size);

		for (int j = 0; j < size; j++)
			for (int h = 0; h < size; h++)
				for (int k = 0; k < size; k++)
					res_mat[j][h] += mat_1[j][k] * mat_2[k][h];

		copy_mat(res_mat, mat_2, size);
		clean_mat(res_mat, size);
	}

	return mat_2;
}

//�������� ��������� �-��
double** create_identity_mat(int size)
{
	double** identity_mat = create_mat(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (i == j)
				identity_mat[i][j] = 1.0;
			else
				identity_mat[i][j] = 0;

	return identity_mat;
}

//�������� ��������� �-�� �� �����
double** multiply_by_num_mat(double** mat_1, int size, double num)
{
	double** res_mat = create_mat(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			res_mat[i][j] = mat_1[i][j] * num;

	return res_mat;
}

//�������� ��������(���������)
double** addition_mat(double** mat_1, double** mat_2, int size)
{
	double** res_mat = create_mat(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			res_mat[i][j] = mat_1[i][j] + mat_2[i][j];

	return res_mat;
}

//���������� ��������� f(x)=x^3-10x^2+7x-12 � ������� ������������� �����������
double** calculator_mat(double** x, int size)
{
	double** mat_1 = create_mat(size); //������� ���������� ��� ��������� ���������
	double** mat_2 = create_mat(size);
	double** additional_mat = create_mat(size); //������� �������������� �-�� ��� ��������������
	double** res = create_mat(size); //������� �-�� ��� ����������
	double** identity_mat = create_identity_mat(size); //�������� ��������� �-��

	cout << "\nx^3: ";
	mat_1 = power_mat(x, size, 3);
	output_mat(mat_1, size);

	cout << "\nx^2: ";
	mat_2 = power_mat(x, size, 2);
	output_mat(mat_2, size);

	cout << "\n(x^2)*(-10): ";
	copy_mat(mat_2, additional_mat, size);
	clean_mat(mat_2, size);
	mat_2 = create_mat(size);
	mat_2 = multiply_by_num_mat(additional_mat, size, -10.0);
	output_mat(mat_2, size);

	cout << "\n(x^3)-10*(x^2): ";
	res = addition_mat(mat_1, mat_2, size);
	output_mat(res, size);

	cout << "\n7*x: ";
	clean_mat(mat_2, size);
	mat_2 = create_mat(size);
	mat_2 = multiply_by_num_mat(x, size, 7.0);
	output_mat(mat_2, size);

	cout << "\n(x^3)-10*(x^2)+7x: ";
	clean_mat(mat_1, size);
	mat_1 = create_mat(size);
	mat_1 = addition_mat(res, mat_2, size);
	output_mat(mat_1, size);

	cout << "\n-12*E: ";
	clean_mat(mat_2, size);
	mat_2 = create_mat(size);
	mat_2 = multiply_by_num_mat(identity_mat, size, -12.0);
	output_mat(mat_2, size);

	cout << "\n(x^3)-10*(x^2)+7x-12E: ";
	clean_mat(res, size);
	res = create_mat(size);
	res = addition_mat(mat_1, mat_2, size);

	clean_mat(mat_1, size);
	clean_mat(mat_2, size);
	clean_mat(identity_mat, size);
	clean_mat(additional_mat, size);

	return res;
}
