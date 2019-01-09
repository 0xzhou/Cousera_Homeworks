#include<iostream>
#include<iomanip>

using namespace std;
enum warriors {dragon,ninja,iceman,lion,wolf,NUMwarriors};// define warriors' name
char str_warriors[NUMwarriors][7] = { "dragon","ninja","iceman","lion","wolf" };// ??
enum colors {red,blue,NUMcolors};// define the warrios' color and const number of color
char str_colors[NUMcolors][5] = { "red","blue" };// ??

class Warrior
{
private:
	int Strength[NUMwarriors];
	int Number[NUMwarriors];
	int WCSeq[NUMwarriors];// Warrior Creating Sequence

public:
	Warrior()//constructor
	{
		for (int i = 0; i < NUMwarriors; i++)
			Number[i] = 0; // ????
	}
	friend class Headquarter;
};

class Headquarter
{
private:
	int Strength;
	int Number;
	Warrior W;
	int Clk; //???

public:
	Headquarter(int M, int N = 0, int C = 0) :Strength(M), Number(N), Clk(C) {};//constructor
	void Setwarrior(int nw, int sw)
	{
		W.Strength[nw] = sw;// ?????
	}

	void SetWCseq(int nc)
	{
		switch (nc)
		{
		case red:
			W.WCSeq[0] = iceman; W.WCSeq[1] = lion; W.WCSeq[2] = wolf; W.WCSeq[3] = ninja; W.WCSeq[4] = dragon;
			break;
		case blue:
			W.WCSeq[0] = lion; W.WCSeq[1] = dragon; W.WCSeq[2] = ninja; W.WCSeq[3] = iceman; W.WCSeq[4] = wolf;
			break;
		default:
			break;
		}
	}

	int CreatWarrior(int nc, int last_cnt)
	{
		int cnt = last_cnt;
		int w, i;//w -- which warrior; i -- iterator
		for (i = 0; i < NUMwarriors; i++)
		{
			w = W.WCSeq[cnt%NUMwarriors];// which warriors
			if (Strength - W.Strength[w] >= 0) //???
			{
				Strength -= W.Strength[w];
				break;
			}
			else
				cnt++; //????
		}
		if (i >= NUMwarriors)
		{
			cout << setw(3) << setfill('0') <<Clk << " " << str_colors[nc] << " headquarter stops making warriors" << endl;
			Clk = 0;
			return -1;//????
		}
		else
		{
			W.Number[w]++;
			Number++;
			cout << setw(3) << setfill('0') << Clk << " " << str_colors[nc] << " " << str_warriors[w] << " " << Number << " born with strength " << W.Strength[w] << ",";
			cout << W.Number[w] << " " << str_warriors[w] << " " << "in " << str_colors[nc] << " headquarter" << endl;
			cnt++;
			Clk++;
			return cnt;
		}
	}
	void PrintIndo();
};

int main()
{
	int ntc; // the number of test cases='ntc'
	cin >> ntc;
	for (int tc = 1; tc <= ntc; tc++)
	{
		
		int M;//initial strength of two headquarters
		cin >> M;
		Headquarter Red(M), Blue(M);
		for (int i = 0; i < NUMwarriors; i++)
		{
			int sw;
			cin >> sw;
			Red.Setwarrior(i, sw); Blue.Setwarrior(i, sw);//???
		}
		Red.SetWCseq(red); Blue.SetWCseq(blue);//???
		//		Red.PrintInfo(); Blue.PrintInfo();
		cout << "Case:" << tc << endl;
		int res1, res2;
		res1 = Red.CreatWarrior(red, 0);
		res2 = Blue.CreatWarrior(blue, 0);//???
		while (res1 > 0 && res2 > 0)
		{
			res1 = Red.CreatWarrior(red, res1);
			res2 = Blue.CreatWarrior(blue, res2);
		}
		while(res1>0)
			res1 = Red.CreatWarrior(red, res1);
		while(res2>0)
			res2 = Blue.CreatWarrior(blue, res2);
	}
	return 0;
}

void Headquarter::PrintIndo()//??
{
	cout << "Strength=" << Strength << "," << "Number=" << Number << endl;
	for (int i = 0;i < NUMwarriors; i++)
		cout << W.Strength[i] << ",";
	cout << endl;
	for (int i = 0; i < NUMwarriors; i++)
		cout << str_warriors[W.WCSeq[i]] << ",";
	cout << endl;
}
