#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct NODE {
    int row;
    int col;
};

int n, m, cnt;
char map[21][21];




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    /*
    //�ð� ���⵵ : 

    for(int i = 1; i<n; i*=2){
        for(int j = i; j<i*2; j++){

        }
     }====> �ð� ���⵵: n��

     for(int i = 1; i< n; i*=2)
     {

     }n������ �ݾ� ������ �ٿ������� ����� ���
     ====> �ð� ���⵵: logn



     1
     logn
     n
     nlogn
     n^2
     n^2 logn
     n^3
     .
     .
     .


     sort <- ����
     * ���Ŀ� ���Ǵ� for���� �ð� ���⵵: n^2

     * quick sort, merge sort, heap sort <- nlogn <=�־��� ��찡 �ƴ϶� ������� �ð� ���⵵��(n^2�� ��쵵 ����)

     * c���� �����Ǿ��ִ� sort <- quick sort

     * c++ ���� �����Ǿ��ִ� sort <-sort() : intro sort <=nlogn�� �ð����⵵�� ����ȴ�
     java, python : tim sort <=nlogn�� �ð� ���⵵�� ����
    
     * #include<algorithm> �� sort()

     * �迭 �̸�: �迭�� ���� �ּҸ� �ǹ�

     * arr[10]={1,9,2,3,5,8,0,7,6,4};
     index = 0~9��
     * sort(arr, arr+10) => arr���� arr+10���̿� �ִ� ����(arr~arr+9)�� ������������ �����ϰڴ�
     
     index=8���� ������������ �����ϰ�ʹٸ�
     * sort(arr, arr+9)

     * default=��������("<")

     bool cmp(int a, int b)
     {
        if(a>b) return true; // a�� b���� �տ� �־�� �Ѵ�.
        if(a<b) return false; // a�� b���� �ڿ� �־�� �Ѵ�.

        // �Ϻ��ϰ� ���� ���: false�� �ְ� �Ǿ� ���� <- strick weak ordering :���� ��쿡�� true�� �߻�
        return false;
     }

     *�������� �ϰ�ʹٸ�
     �Լ� ����� ����
     sort(arr, arr + 10, cmp);


     *NODE ���� ���
     struct NODE{
     int row;
     int col;
     }

     //ROW�� ������ �켱, ROW�� ������ COL�� ū�� �켱
     bool �Լ� ����(NODE ��, NODE ��){

        if(��.row < ��.row) return true;
        if(��.row > ��.row) return false;

        //ũ�� ���� �� �� �Ϸ�<- ������� ������ row���� ���� ���
        if(��.col > ��.col) return true;
        if(��.col < ��.col) return false;

        //������� ������ row�� col�� �Ϻ��� ����
        return false;
    
    }

    bool operator<(NODE ��, NODE ��){ // ��� �񱳿� ����� '<' �����ڸ� ����  -> ��� �ΰ��� ���� sort()�񱳸� sort(A,B,�Լ� ����)�� �ƴ϶� sort(A,B)�� �ϱ� ���ؼ�

        if(��.row < ��.row) return true;
        if(��.row > ��.row) return false;

        //ũ�� ���� �� �� �Ϸ�<- ������� ������ row���� ���� ���
        if(��.col > ��.col) return true;
        if(��.col < ��.col) return false;

        //������� ������ row�� col�� �Ϻ��� ����
        return false;

    }

    *���� ����
    vector<int> v = {5,9,1,3,6,7}
    sort(v.begin(), v.end());
  
    ->�������� �ְ������ ������ ���� �Լ� cmp���
    sort(v.begin(), v.end(), cmp);



    */
   

    return 0;
}

