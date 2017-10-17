//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>

using namespace std;
int mass[1001], dp[1001];

int rec(int po, int c)
{
    if(po==0)
        return 0;
    if(mass[po]+mass[po-1]<=c)
        return rec(po-1, c-mass[po])+mass[po];
    else if(mass[po]<=c && c<=mass[po]+mass[po-1])
        return max(rec(po-1, c-mass[po])+mass[po], rec(po-1, c));
    return rec(po-1, c);
}

int main()
{
    int n, c;
    int i;
    
    cin >> n >> c;
    for(i=1;i<=n;i++)
        cin >> mass[i];
    
    cout << rec(n, c) << endl;
    
    return 0;
}
