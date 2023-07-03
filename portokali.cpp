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
        table[x-1][y-1] = 1;
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

            for (int i = 0; i < table.size(); i++) 
            {
                for (int j = 0; j < table[i].size(); j++) 
                {
                    if(table[i][j] == 0)
                    {
                        count++;
                    }

                    cout << table[i][j];
                }
                cout << "\n";
            }

            cout << "\n" << "\n";
        }
        
        for (int i = 0; i < table.size(); i++) 
        {
            for (int j = 0; j < table[i].size(); j++) 
            {
                if(table[i][j] == 0)
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

    int x;
    int y;
    int x1;
    int y1;

    cin >> x;
    cin >> y;
    cin >> x1;
    cin >> y1;

    map.addBadOrrange(x, y);

    map.addBadOrrange(x1, y1);
    
    cout<< map.calculateGoodOrrangesByDay(R);

    return 0;
}