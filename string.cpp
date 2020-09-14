#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>
#include <string.h>
#include <memory>
#include <limits>
#include <list>
#include <regex>
#include <functional>
#include <math.h>
#include <unordered_set>
using namespace std;

/*
begin:
end:
Time Complexity:
Space Complexity:
Method:
*/

bool duplicate(int numbers[], int length, int *duplication)
{
    for (int i = 0; i < length; i++)
    {
        if (numbers[i] < i)
        {
            *duplication = numbers[i];
            return true;
        }
        while (i != numbers[i])
            swap(numbers[i], numbers[numbers[i]]);
    }
    return false;
}

int main()
{
    cout << -3.e-15 << endl;
    return 0;
}
