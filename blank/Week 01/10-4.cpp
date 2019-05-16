#include <iostream>
#include <string>
using namespace std;
class Dogs {
	string m_breed;
	protected:
	  int m_year;
	public:
	  Dogs(string breed, int year) {
		m_breed = breed;
		m_year = year;
	}
	string Get_Breed() {
		return m_breed;
	}
};
class Name {
	protected:
	  string m_name;
	string m_parent;
	char m_gender;
	void Show_Name();
	public:
	  Name(string name, string parent, char gender) {
		m_name = name;
		m_parent = parent;
		m_gender = gender;
	}
};
void Name::Show_Name() {
	cout << "이 름 : " << m_name << endl;
}
class PetDogs:public Dogs, protected Name {
	// 빈칸
	double m_weight;
	int m_lifeyear;
	public:
	  PetDogs(string breed, int year, string name, string parent, char gender, double weight, int lifeyear)
	  : Dogs(breed, year), Name(name, parent, gender) {
		// 빈칸
		m_weight = weight;
		m_lifeyear = lifeyear;
	}
	void Show_Pet();
};
void PetDogs::Show_Pet() {
	string gender_type[2] = {
		"암컷", "수컷"
	};
	cout << "품 종 : " << Dogs::Get_Breed() << endl;            // 빈칸
	cout << "나 이 : " << m_year << "살\n";                     // 빈칸
	cout << "이 름 : " << m_name << endl;                       // 빈칸
	cout << "성 별 : " ;
	switch(m_gender) {
		case 'F':
		    cout << gender_type[0] << endl;                     // 빈칸
		break;
		case 'M':
		    cout << gender_type[1] << endl;                     // 빈칸
	}
	cout << "평균수명 : " << m_lifeyear << "년\n";              // 빈칸
	cout << "부 모 : " << m_parent << "\n";                     // 빈칸
	cout << "몸무게 : " << m_weight << "Kg" << endl;            // 빈칸
}
int main() {
	PetDogs pug("퍼그", 4, "퍼글이", "퍼야+퍼냐", 'M', 2.5, 13);
	pug.Show_Pet();                                             // 빈칸
    system("PAUSE");
	return 0;
}
