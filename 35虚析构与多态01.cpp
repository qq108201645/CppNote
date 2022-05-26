#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Shape
{
public:
	virtual void Draw() = 0;
	virtual ~Shape() {}//�����������������,������������������������
};//�����಻��ʵ����

class Circle :public Shape
{
public:
	void Draw()
	{
		cout << "Circle::Draw()..." << endl;
	}
	~Circle()
	{
		cout << "~Circle()..." << endl;
	}
};

class Square :public Shape
{
public:
	void Draw()
	{
		cout << "Square::Draw()..." << endl;
	}
	~Square()
	{
		cout << "~Square()..." << endl;
	}
};

class Rectangle :public Shape
{
public:
	void Draw()
	{
		cout << "Rectangle::Draw()..." << endl;
	}
	~Rectangle()
	{
		cout << "~Rectangle()..." << endl;
	}
};
void DrawAllShape(const vector<Shape*>& v)
{
	vector<Shape*>::const_iterator it;//*it=shape*
	for (it = v.begin(); it != v.end(); ++it)
	{
		(*it)->Draw();
	}
}
void DeleteAllShape(const vector<Shape*>& v)
{
	vector<Shape*>::const_iterator it;//*it=shape*
	for (it = v.begin(); it != v.end(); ++it)
	{
		delete (*it);
	}
}
//�ڶ��ַ���1
class ShapeFactory
{
public:
	static Shape* CreateShape(const string &name)
	{
		Shape* ps=nullptr;
		if (name == "Circle")
		{
			ps = new Circle;
		}
		else if (name == "Square")
		{
			ps = new Square;
		}
		else if (name == "Rectangle")
		{
			ps = new Rectangle;
		}
		return ps;
	}
};

int main()
{
	//Shape s;//��Shape��: ����ʵ����������
	vector<Shape*> v;//����������״
	//��һ�ַ���
	/*Shape* ps;
	ps=new Circle;//newһ��Circle
	v.push_back(ps);//����״�ŵ���������.vector
	ps=new Square;
	v.push_back(ps);
	ps=new Rectangle;
	v.push_back(ps);*/


	//�ڶ��ַ���2
	Shape* ps;
	ps = ShapeFactory::CreateShape("Circle");
	v.push_back(ps);
	ps = ShapeFactory::CreateShape("Square");
	v.push_back(ps);
	ps = ShapeFactory::CreateShape("Rectangle");
	v.push_back(ps);
	DrawAllShape(v);
	DeleteAllShape(v);
	return 0;
}