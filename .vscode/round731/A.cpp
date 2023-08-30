using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <math.h>
int N;
int main()
{
    int Q, Ax, Ay, Bx, By, Fx, Fy;
    cin >> Q;
    
    for(int i = 0; i < Q; i++)
    {
        int res = abs(Ax - Bx) + abs(Ay - By);
        cin >> Ax >> Ay >> Bx >> By >> Fx >> Fy;
        if((Ax == Bx && Bx == Fx && ((Fy >= Ay && Fy <= By) || (Fy >= By && Fy <= Ay))) || (Ay == By && By==Fy && ((Fx >= Ax && Fx <= Bx) || (Fx>=Bx && Fx <= Ax))))
        {
            res += 2;
        }
        cout << res << "\n";
    }
    
}

