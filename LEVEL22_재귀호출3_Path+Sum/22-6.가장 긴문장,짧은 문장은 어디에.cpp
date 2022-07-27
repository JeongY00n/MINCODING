#include<iostream>
#include<cstring>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    char arr[4][11];
    int len[4], max=0, min=999, max_index, min_index;

    for (int i = 0; i < 4; i++) {
        cin >> arr[i];
        len[i] = strlen(arr[i]);
        if (max < len[i])
        {
            max = len[i];
            max_index = i;
        }
        if (min > len[i])
        {
            min = len[i];
            min_index = i;
        }
    }
    cout << "긴문장:" << max_index << endl;
    cout << "짧은문장:" << min_index << endl;

    
    return 0;
}