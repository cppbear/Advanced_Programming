#include <iostream>
#include <string>
#include "Administrator.h"
using namespace std;

int main()
{
	Athlete* athlete = new Athlete("James", "America");		//����һ��Athlete��������Ϊ"James"������Ϊ"America"
	athlete->addVisitedPlace("Tokyo");						//�Ǽ�James��ǰ����Tokyo
	athlete->addVisitedPlace("Washington");					//�Ǽ�James��ǰ����Washington
	cout << athlete->getName() << endl;						//��ȡJames������
	cout << athlete->getNationality() << endl;				//��ȡJames�Ĺ���
	bool check = athlete->checkVisitedPlace("Tokyo");		//���James�Ƿ���ǰ����Tokyo

	Administrator* admin = new Administrator();				//����һ��Administrator����
	admin->addAthlete(athlete);						//��athlete�Ǽǵ�admin��
	const int MAXATH = 100;
	Athlete* resultList[MAXATH];					//����Athlete����ָ������
	int resultNum = admin->findAthleteByNationality("America", resultList, MAXATH);		//��ѯ������"America"���˶�Ա
	//int resultNum = admin->findAthleteByVisitedPlace("Tokyo", resultList, MAXATH);
	for (int i = 0; i < resultNum; ++i) {
		cout << resultList[i]->getName() << endl;		//����������ҵ����˶�Ա������
	}
	return 0;
}
