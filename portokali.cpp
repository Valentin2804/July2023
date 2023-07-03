#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Map
{
    int K;
    int L;
    vector<vector<int>> table;

    public:

    Map() : K(1), L(1), table(K, std::vector<int>(L, 0))
    {
    }

    Map(int K, int L) : K(K), L(L), table(K, std::vector<int>(L, 0)) {
        if(K <= 0 || L <= 0 || K >= 10000 || L >= 10000 || L < K)
        {
            throw invalid_argument("Invalid parameters, this is the criteria: 0 < rows <= columns < 10000");
        }
    }

    void addBadOrrange(int x, int y)
    {
        if(x < 0 || y < 0 || x >= K || y >= L)
        {
            throw invalid_argument("Invalid parameters, coordinates should be unsigned and in the table");
        }
        table[x][y] = 1;
    }

    int calculateGoodOrrangesByDay(int R)
    {
        int count = 0;

        for(int r = 0; r < R; r++)
        {
            for (int i = 0; i < table.size(); i++) 
            {
                for (int j = 0; j < table[i].size(); j++) 
                {
                    if(table[i][j] == 1)
                    {
                        if(i != 0)
                        {
                            table[i-1][j] = 1;
                        }
                        if(j != 0)
                        {
                            table[i][j-1] = 1;
                        }
                        if(i != K - 1)
                        {
                            table[i+1][j] = 1;
                        }
                        if(j != L - 1)
                        {
                            table[i][j+1] = 1;
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < table.size(); i++) 
        {
            for (int j = 0; j < table[i].size(); j++) 
            {
                if(table[i][j] == 1)
                {
                    count++;
                }
            }
        }

        return count;
    }
};

int main()
{
    int K;
    int L;
    int R;

    cin >> K;
    cin >> L;
    cin >> R;

    Map map = Map(K, L);

    string line1;
    string line2;

    getline(cin, line1);
    getline(cin, line2);

    int x;
    int y;

    istringstream isStrStream (line1);
    istringstream isStrStream2 (line2);

    if(isStrStream >> x && isStrStream >> y)
    {
        map.addBadOrrange(x, y);
    }

    if(isStrStream2 >> x && isStrStream2 >> y)
    {
        map.addBadOrrange(x, y);
    }

    cout<< map.calculateGoodOrrangesByDay(R);

    return 0;
}