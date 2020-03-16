#include<iostream>
#include<cstdio>
#include<string>
#include<math.h>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using  namespace std;
struct student
{
	/* data */
	string name;
	int question[20];
	int punish_time[20];
	int score;
	int accept;
	student()
	{
		name = "";
		for (int i = 0; i < 20; i++)
		{
			question[i] = 0;
			punish_time[i] = 0;
		}
		score = 0;
		accept = 0;
	}
	void give_score(int time, int ques_num)
	{
		score = 0;
		for (int i = 0; i < ques_num; i++)
		{
			if (question[i] > 0)
			{
				score += question[i];
				score += punish_time[i] * time;
			}
		}
	}
	void print()
	{
		const char* p = name.c_str();
		printf("%-10s %2d %4d\n", p, accept, score);
	}
	bool operator<(const student& ano)const
	{
		if (accept != ano.accept) return accept > ano.accept;
		if (score != ano.score) return score < ano.score;
		return name[0] < ano.name[0];
	}
};
student a[10000];
int main()
{
	int question_number = 0;
	int punish_time = 0;
	cin >> question_number >> punish_time;
	string name;
	int all_student_num = 0;
	while (cin >> name)
	{
		string score_num;
		a[all_student_num].name = name;
		for (int i = 0; i < question_number; i++)
		{
			cin >> score_num;
			a[all_student_num].question[i] = 0;
			a[all_student_num].punish_time[i] = 0;
			if (score_num[0] != '-' && score_num[0] != '0')
			{
				a[all_student_num].accept++;
				int iterator_1 = 0;
				while (score_num[iterator_1] != '(' && iterator_1 < score_num.size())
				{
					a[all_student_num].question[i] *= 10;
					a[all_student_num].question[i] += (score_num[iterator_1] - '0');
					iterator_1++;
				}
				if (score_num[iterator_1] == '(')
				{
					iterator_1++;
					while (score_num[iterator_1] != ')' && iterator_1 < score_num.size())
					{
						a[all_student_num].punish_time[i] *= 10;
						a[all_student_num].punish_time[i] += (score_num[iterator_1] - '0');
						iterator_1++;
					}
				}
			}
		}
		a[all_student_num].give_score(punish_time, question_number);
		all_student_num++;
	}
	sort(a, a + all_student_num);
	for (int i = 0; i < all_student_num; i++)
	{
		a[i].print();
	}
	return 0;
}
