#include <iostream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;
void solution(int numOfAllPlayers, int numOfQuickPlayers, char *namesOfQuickPlayers, int numOfGames, int *numOfMovesPerGame)
{
    map<char, int> isFast;
    vector<char> player(numOfAllPlayers);
    for (int i = 0; i < numOfAllPlayers; i++)
        player[i] = 'A' + i;
    for (int i = 0; i < numOfQuickPlayers; i++)
        isFast[namesOfQuickPlayers[i]] = -1;
    char cur = 'A';
    for (int move = 0, start = 0; move < numOfGames; move++) //start는 현재술래
    {
        isFast[cur]++; //현재술래
        int next = start + numOfMovesPerGame[move];
        if (move == 0){  
            next += 1;
            if(next > 0) next+=1;
            next-=1;
        }
        if (next >= numOfAllPlayers)
            next %= (numOfAllPlayers - 1);
        if (next <=0) { 
            next*=-1;
            if (next >= numOfAllPlayers)
            next %= (numOfAllPlayers - 1);
            next=numOfAllPlayers-next;
        }
        if (isFast[player[next]] == -1)
        {
            start = next;
            continue;
        }
        cur = player[next];
        player[next] = player[start];
        player[start] = cur;
        start = next;
    }
    isFast[cur]++;
    for (int i = 1; i < numOfAllPlayers; i++)
    {
        if (isFast[player[i]] == -1)
            isFast[player[i]] = 0;
        cout << player[i] << " " << isFast[player[i]] << "\n";
    }
    if (isFast[player[0]] == 0)
        isFast[player[0]] = 0;
    cout << player[0] << " " << isFast[player[0]] << "\n";
}

struct input_data
{
    int numOfAllPlayers;
    int numOfQuickPlayers;
    char *namesOfQuickPlayers;
    int numOfGames;
    int *numOfMovesPerGame;
};

void process_stdin(struct input_data &inputData)
{
    string line;
    istringstream iss;

    getline(cin, line);
    iss.str(line);
    iss >> inputData.numOfAllPlayers;

    getline(cin, line);
    iss.clear();
    iss.str(line);
    iss >> inputData.numOfQuickPlayers;

    getline(cin, line);
    iss.clear();
    iss.str(line);
    inputData.namesOfQuickPlayers = new char[inputData.numOfQuickPlayers];
    for (int i = 0; i < inputData.numOfQuickPlayers; i++)
    {
        iss >> inputData.namesOfQuickPlayers[i];
    }

    getline(cin, line);
    iss.clear();
    iss.str(line);
    iss >> inputData.numOfGames;

    getline(cin, line);
    iss.clear();
    iss.str(line);
    inputData.numOfMovesPerGame = new int[inputData.numOfGames];
    for (int i = 0; i < inputData.numOfGames; i++)
    {
        iss >> inputData.numOfMovesPerGame[i];
    }
}

int main()
{
    struct input_data inputData;
    process_stdin(inputData);

    solution(inputData.numOfAllPlayers, inputData.numOfQuickPlayers, inputData.namesOfQuickPlayers, inputData.numOfGames, inputData.numOfMovesPerGame);
    return 0;
}