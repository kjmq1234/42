#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

template <class T>
class Bag{
public:
	Bag(int bagCapacity = 3);
	~Bag();

	int Size() const;
	bool IsEmpty() const;
	T& Element() const;

	void Push(const T&);
	void Pop();

	void ChangeSize(T*& arr, const int size, const int newcapacity);

private:
	T* array;
	int capacity;
	int top;
};

template <class T>
Bag<T>::Bag(int bagCapacity)
	: capacity(bagCapacity) {
	if (capacity < 1)
		throw "Capacity must be > 0";
	array = new T[capacity];
	top = -1;
}

template <class T>
Bag<T>::~Bag() { delete[] array; }

template <class T>
int Bag<T>::Size() const {
	return top + 1;
}

template <class T>
bool Bag<T>::IsEmpty() const {
	if (top == -1)
		return 1;
	else
		return 0;
}

template <class T>
T& Bag<T>::Element() const {
	if (IsEmpty())
		throw "Bag is empty";
	return array[(rand() % Size())];
}

template <class T>
void Bag<T>::Push(const T& x) {
	if (capacity == top + 1)
	{
		ChangeSize(array, capacity, 2 * capacity);
		capacity *= 2;
	}
	array[++top] = x;
}

template <class T>
void Bag<T>::Pop() {
	if (IsEmpty())
		throw "Bag is empty, cannot delete";
	int deletePos = (rand() % Size());
	copy(array + deletePos + 1, array + top + 1, array + deletePos);
	array[top--].~T(); 
}

template <class T>
void Bag<T>::ChangeSize(T*& arr, const int size, const int newcapacity) {
	T* temp = new T[newcapacity];
	copy(arr, arr + size, temp);
	delete[] arr;
	arr = temp;
}

class Character {
private:
	char* name; // 이름
	int level, str, dex, gint, power, dpense, Hp, mana; // 차례로 레벨, 힘, 민첩, 지능, 공격력, 방어력, 체력, 정신력
public:
	Character(const char* name, int level, int str, int dex, int gint, int power, int dpense, int Hp, int mana)
		: level(level), str(str), dex(dex), gint(gint), power(power), dpense(dpense), Hp(Hp), mana(mana) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	void move() {
		cout << "이동했습니다." << endl;
	}

	void showInfo() {
		cout << "캐릭터 이름: " << name << endl;
		cout << "레벨: " << level << endl;
		cout << "힘: " << str << endl;
		cout << "민첩: " << dex << endl;
		cout << "지능: " << gint << endl;
		cout << "공격력:  " << power << endl;
		cout << "방어력: " << dpense << endl;
		cout << "체력: " << Hp << endl;
		cout << "정신력: " << mana << endl;
	}

	virtual void attack() = 0;

	~Character() {
		delete[] name;
	}
};

class Warrior : public Character {
private:
	char* weapon;
public:
	Warrior(const char* name, const char* weapon)
		:Character(name, 1, 100, 50, 20, 5, 3, 80, 20) {
		this->weapon = new char[strlen(weapon) + 1];
		strcpy(this->weapon, weapon);
	}

	void showInfo() {
		Character::showInfo();
		cout << "무기 이름: " << weapon << endl;
	}

	virtual void attack() {
		cout << weapon << "칼로 찔렀습니다." << endl;
	}

	~Warrior() {
		delete[] weapon;
	}
};

class Archer : public Character {
private:
	char* weapon;
public:
	Archer(const char* name, const char* weapon)
		:Character(name, 1, 50, 100, 20, 5, 3, 50, 50) {
		this->weapon = new char[strlen(weapon) + 1];
		strcpy(this->weapon, weapon);
	}

	void showInfo() {
		Character::showInfo();
		cout << "무기 이름: " << weapon << endl;
	}

	virtual void attack() {
		cout << weapon << "화살을 쐈습니다." << endl;
	}

	~Archer() {
		delete[] weapon;
	}
};

class Sorcerer : public Character {
private:
	char* weapon;
public:
	Sorcerer(const char* name, const char* weapon)
		:Character(name, 1, 20, 50, 100, 5, 3, 20, 80) {
		this->weapon = new char[strlen(weapon) + 1];
		strcpy(this->weapon, weapon);
	}

	void showInfo() {
		Character::showInfo();
		cout << "무기 이름: " << weapon << endl;
	}

	virtual void attack() {
		cout << weapon << "마법을 걸었습니다." << endl;
	}

	~Sorcerer() {
		delete[] weapon;
	}
};

int main(void) {
	srand(time(NULL));
	Character* element;
	cout << "-------4--------" << endl;
	Bag<Character*>* game = new Bag<Character*>();
	cout << "Size: " << game->Size() << endl;
	cout << "IsEmpty: " << game->IsEmpty() << endl;

	cout << "-------5--------" << endl;
	Warrior* power = new Warrior("타락파워전사", "마왕 김익수 교수님의 점수깎는 ");
	Archer* pale = new Archer("페일", "쏟아지는 과제의 ");
	Sorcerer* dongjun = new Sorcerer("김동준", "성적 산출 중인 김익수 교수님의 C뿌리기");

	game->Push(power);
	game->Push(pale);
	game->Push(dongjun);
	cout << "Size: " << game->Size() << endl;
	cout << "IsEmpty: " << game->IsEmpty() << endl << endl;
	element = game->Element();
	element->showInfo();
	element->move();
	element->attack();
	cout << endl;


	cout << "-------6--------" << endl;
	game->Push(power);
	game->Push(power);
	game->Push(pale);
	game->Push(pale);
	game->Push(dongjun);
	game->Push(dongjun);
	cout << "Size: " << game->Size() << endl;
	cout << "IsEmpty: " << game->IsEmpty() << endl << endl;
	element = game->Element();
	element->showInfo();
	element->move();
	element->attack();
	cout << endl;

	cout << "-------7--------" << endl;
	game->Pop();
	game->Pop();
	cout << "Size: " << game->Size() << endl;
	cout << "IsEmpty: " << game->IsEmpty() << endl << endl;
	element = game->Element();
	element->showInfo();
	element->move();
	element->attack();

	cout << endl;
}