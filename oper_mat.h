#ifndef _OPER_MAT_H_
#define _OPER_MAT_H_

//������� �-��
double** create_mat(int size);

//������ �������� ��-��� �-��
double** input_mat(int& size);

//������� �-��
void output_mat(double** mat, int size);

//������� � �������� �-��
void clean_mat(double** mat, int size);

//����������� ����� �-�� �� ������
void copy_mat(double** mat_from, double** mat_to, int size);

//�������� ���������� � �������
double** power_mat(double** mat_1, int size, int power);

//�������� ��������� �-��
double** create_identity_mat(int size);

//�������� ��������� �-�� �� �����
double** multiply_by_num_mat(double** mat_1, int size, double num);

//�������� ��������(���������)
double** addition_mat(double** mat_1, double** mat_2, int size);

//���������� ���������  � ������� ������������� �����������
double** calculator_mat(double** mat, int size);

#endif // _OPER_MAT_H_
