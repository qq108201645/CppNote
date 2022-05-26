/************************************************************/
/************************************************************/
/**************** A star algorithm   ************************/
/************        by��Ƥɳ��    **************************/
/**************      qq1598058687    ************************/
/************************************************************/
/************************************************************/
#include<vector>
#include<string>
#include<list>
#include<algorithm>
#include<iostream>
using namespace std;

/* up,down,left,right */
const char *dir[] = { "��","��","��","��" };
/*	0:�հ׵� NULL tile
*	1:��ʼ�� Start
*	2:Ŀ��� Finish
*	3:ǽ	Wall
*	4:·��	Path
*/

struct Node
{
public:
	Node(char d_tile, int dx, int dy, int dg = 0, int df = 0)
		: tile(d_tile), x(dx), y(dy), g(dg), h(0), f(df), dir(0)
	{
	}
	/* ��������
	*	F=G+H
	*	G��ʾ�õ㵽��ʼ��λ����Ҫ�Ĵ���
	*	H��ʾ�õ㵽�յ�������پ��롣
	*	F����G��H���ܺͣ�������·��Ҳ����ѡ����С��Fֵ��������һ���ƶ�����߻�����ϸ���ܣ�
	*	��ͼ��
	*	����
	*/
	int x, y, g, h, f, dir;
	char tile;
	Node(const Node &r) :x(r.x), y(r.y), g(r.g), h(r.h), f(r.f), dir(0), tile(r.tile) {}
	Node& operator=(const Node &r) {
		if (this != &r)
		{
			x = r.x, y = r.y, g = r.g, h = r.h, f = r.f, dir = 0, tile = r.tile;
		}
		return *this;
	}
	void Assign(int dx, int dy, int dg = 0, int df = 0)
	{
		x = dx, y = dy, g = dg, h = df, dir = 0, tile = '\0';
	}
	void calculateCost(int x2, int y2)
	{
		g += 1;
		h = std::abs(x2 - x) + std::abs(y2 - y);
		f = g + h;
	}
};


class Astar
{
	int mWidth, mHeight, xStart, yStart, xFinish, yFinish, success;
public:
	string path;
	vector<vector<Node>> nodeMap;
	vector <Node>openlist;	// open��
	vector < Node>closedlist;	// closed��
	Astar()
	{
		// Assign(w, h);
	}
	void Assign(int w, int h)
	{
		nodeMap.resize(h);
		mWidth = w, mHeight = h;
		xStart = yStart = xFinish = yFinish = -1, success = 0;
		for (int i = 0; i < mHeight; ++i)
		{
			for (int j = 0; j < mWidth; ++j)
				nodeMap[i].push_back(Node('.', j, i, 0, 0));
		}
	}
	void free()
	{
		for (size_t i = 0; i < nodeMap.size(); ++i)
		{
			nodeMap[i].clear();
		}
		nodeMap.clear();

		path.clear();
		openlist.clear();
		closedlist.clear();
	}
	~Astar()
	{
		free();
	}

	void setWall(int x, int y)	// �����ϰ�
	{
		char c = nodeMap[y][x].tile;

		if (c != 'A' && c != 'B')
		{
			nodeMap[y][x].tile = (c == '.' ? '#' : '.');
		}
	}
	void setFinish(int x, int y)	// ����Ŀ��
	{
		char c = nodeMap[y][x].tile;

		if (c != 'A'&& c != '#')
		{
			if ((xFinish != -1 && yFinish != -1) && (xFinish != x || yFinish != y))
				nodeMap[yFinish][xFinish].tile = '.';//���ǰ�������ù�����0

			nodeMap[y][x].tile = (c == '.' ? 'B' : '.');
			xFinish = x, yFinish = y;
		}
	}
	void setStart(int x, int y)	// ���ÿ�ʼ
	{
		char c = nodeMap[y][x].tile;

		if (c != 'B'&& c != '#')
		{
			if ((xStart != -1 && yStart != -1) && (xStart != y || yStart != x))
				nodeMap[yStart][xStart].tile = '.';

			nodeMap[y][x].tile = (c == '.' ? 'A' : '.');

			xStart = x, yStart = y;
		}
	}
	int direction[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };	// �������ɽڵ���Χ�������ҵ������ƶ�ֵ

	vector<Node>::iterator findLeastNode(vector<Node>& v)
	{
		auto result = v.begin();
		for (auto i = v.begin(); i != v.end(); i++) {
			if (result->f > i->f) {
				result = i;
			}
		}
		return result;
	}
	string pathFind()
	{
		nodeMap[yStart][xStart].calculateCost(xFinish, yFinish);
		openlist.push_back(nodeMap[yStart][xStart]);

		// A* �㷨
		while (!openlist.empty())
		{

			auto curit = findLeastNode(openlist);
			

			int cx = curit->x, cy = curit->y;
			//��Ҫ�������
			Node curNode = *curit;
			//Node curNode = nodeMap[cy][cx];

			closedlist.push_back(*curit);
			openlist.erase(curit);


			if (cx == xFinish && cy == yFinish)
			{
				char c;
				while (!(cx == xStart && cy == yStart))
				{
					int j = nodeMap[cy][cx].dir;
					c = j ^ 1;
					path = c + path;//��ǰ����
					cx += direction[j][0];
					cy += direction[j][1];
				}
				return path;
			}

			for (int i = 0; i < sizeof(direction) / sizeof(*direction); i++)
			{
				int dx = cx + direction[i][0], dy = cy + direction[i][1];

				if (!(dx < 0 || dx >= mWidth || dy < 0 || dy >= mHeight || nodeMap[dy][dx].tile == '#' ||
					find_if(closedlist.begin(), closedlist.end(),
						[&](Node &a) {return dx == a.x && dy == a.y; }) != closedlist.end()))
				{

					Node tmp('.', dx, dy, curNode.g, curNode.f);
					tmp.calculateCost(xFinish, yFinish);

					auto open_it = find_if(openlist.begin(), openlist.end(),
						[&](Node &a) {return dx == a.x && dy == a.y; });

					if (open_it == openlist.end())
					{
						openlist.push_back(tmp);
						nodeMap[dy][dx].dir = i ^ 1;

					}
					else if (open_it != openlist.end() && open_it->f > tmp.f)
					{
						*open_it = tmp;

						nodeMap[dy][dx].dir = i ^ 1;
					}

				}
			}

		}
		return ""; // no route found
	}
	void ShowPath() {
		if (path.size())
		{
			for (auto &i : path)
			{
				cout << " " << dir[i];
			}
			cout << endl;
		}
	}
	//	private:
	void  ShowMap()
	{

		if (path.size())
		{
			int cx = xStart, cy = yStart;
			for (size_t i = 0; i < path.size() - 1; ++i)
			{
				int j = path[i];
				cx += direction[j][0], cy += direction[j][1];
				nodeMap[cy][cx].tile = 'r';
			}
			// 		nodeMap[yStart][xStart].tile = 'A';
			// 		nodeMap[yFinish][xFinish].tile = 'B';
		}
		for (auto i = 0; i < mHeight; ++i) {
			for (int j = 0; j < mWidth; ++j)
			{
				cout << nodeMap[i][j].tile;
			}
			cout << endl;
		}
	}
};

int main()
{
	Astar astar;
	//��ʼ����ͼ��С
	astar.Assign(10, 10);

	/* ����ǽ */
	for (int i = 2; i < 8; i++)
	{
		astar.setWall(i, 5);
		astar.setWall(5, i);
	}
	astar.setWall(0, 5);
	astar.setWall(1, 5);
	astar.ShowMap();
	/* ����������յ� */
	astar.setStart(3, 2);
	astar.setFinish(2, 6);

	cout << "�ܹ�����:" << astar.pathFind().size() << endl;
	astar.ShowPath();
	astar.ShowMap();

	return 0;
}