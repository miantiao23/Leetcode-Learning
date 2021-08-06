//#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;


/*****************************************************
You have a lock in front of you with 4 circular wheels.
Each wheel has 10 slots: '0', '1', '2', '3', '4', '5',
'6', '7', '8', '9'.The wheels can rotate freely and wr-
ap around: for example we can turn '9'to be '0', or '0'
to be '9'. Each move consists of turning one wheel one
slot.

The lock initially starts at '0000', a string represen-
ting the state of the 4 wheels.You are given a list of
 deadends dead ends, meaning if the lock displays any
of these codes, the wheels of the lock will stop turni-
ng and you will be unable to open it.

Given a target representing the value of the wheels th-
at will unlock the lock,return the minimum total number
of turns required to open the lock, or -1 if it is im-
possible.

1) 1 <= deadends.length <= 500
2) deadends[i].length == 4
3) target.length == 4
4) target will not be in the list deadends.
5) target and deadends[i] consist of digits only.
******************************************************/

class solution{
public:
    int openLock(vector<string>& deadends, string target)
    {
        std::unordered_set<std::string> checkQue (deadends.begin(), deadends.end());
        int steps = 0;
        std::string currentNum = "0000";
        std::string currentNumUpdate = "0000";
        std::queue<string> currentStack;
        std::cout<<"queue size: "<<currentStack.size()<<'\n';
        currentStack.push(currentNum);
        std::unordered_set<std::string> visitedStack;

        std::unordered_set<std::string>::const_iterator it = checkQue.find(currentNum);
        if(it != checkQue.end())
            return -1;

        int bitNum = 0;

        while(currentStack.empty() == 0)
        {
            int stepSize = currentStack.size();
            for(int countSteps = 0; countSteps < stepSize; countSteps++)
            {
                currentNumUpdate = currentStack.front();
                currentStack.pop();
//                currentNumUpdate = currentNum;

                for(int i = 0; i < 4; i++)
                {
                    char tempChar = currentNumUpdate[i];
                    for(int j = -1; j <= 1; j += 2)
                    {
                        currentNumUpdate[i] = (tempChar - '0' + j + 10)%10 + '0';
                        it = visitedStack.find(currentNumUpdate);
                        if(it != visitedStack.end())
                            continue;

                        if(currentNumUpdate.compare(target) == 0)
                            return steps + 1;
                        it = checkQue.find(currentNumUpdate);
                        if(it == checkQue.end())
                        {
                            visitedStack.insert(currentNumUpdate);
                            currentStack.push(currentNumUpdate);
                        }

                    }
                    currentNumUpdate[i] = tempChar;
                }

            }
          steps++;
        }
        return -1;
    }
};
int main()
{
//    std::vector<std::string> deadends = {"0000"};
    std::vector<std::string> deadstarts = {"0000"};
    std::vector<std::string> deadends = {"8887","8889","8878",
                                         "8898","8788","8988",
                                         "7888","9888"};
    string target ("8888");
//    std::vector<std::string> deadends = {"8888"};
//    string target ("0009");
//    std::vector<std::string> deadends = {"0201","0101","0102","1212","2002"};
//    string target ("0202");

    solution a;
    std::cout<<"The steps is "<<a.openLock(deadends, target)<<'\n';


    return 0;
}
