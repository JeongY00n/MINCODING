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
    //시간 복잡도 : 

    for(int i = 1; i<n; i*=2){
        for(int j = i; j<i*2; j++){

        }
     }====> 시간 복잡도: n임

     for(int i = 1; i< n; i*=2)
     {

     }n개에서 반씩 범위를 줄여나가는 방식의 경우
     ====> 시간 복잡도: logn



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


     sort <- 정렬
     * 정렬에 사용되는 for문의 시간 복잡도: n^2

     * quick sort, merge sort, heap sort <- nlogn <=최악의 경우가 아니라 평균적인 시간 복잡도임(n^2인 경우도 존재)

     * c언어에서 구현되어있는 sort <- quick sort

     * c++ 에서 구현되어있는 sort <-sort() : intro sort <=nlogn의 시간복잡도가 보장된다
     java, python : tim sort <=nlogn의 시간 복잡도가 보장
    
     * #include<algorithm> 의 sort()

     * 배열 이름: 배열의 시작 주소를 의미

     * arr[10]={1,9,2,3,5,8,0,7,6,4};
     index = 0~9임
     * sort(arr, arr+10) => arr부터 arr+10사이에 있는 값들(arr~arr+9)을 오름차순으로 정렬하겠다
     
     index=8까지 오름차순으로 정렬하고싶다면
     * sort(arr, arr+9)

     * default=오름차순("<")

     bool cmp(int a, int b)
     {
        if(a>b) return true; // a가 b보다 앞에 있어야 한다.
        if(a<b) return false; // a가 b보다 뒤에 있어야 한다.

        // 완벽하게 같은 경우: false를 주게 되어 있음 <- strick weak ordering :같은 경우에서 true면 발생
        return false;
     }

     *내림차순 하고싶다면
     함수 만들어 놓고
     sort(arr, arr + 10, cmp);


     *NODE 정렬 방법
     struct NODE{
     int row;
     int col;
     }

     //ROW가 작은게 우선, ROW가 같으면 COL이 큰게 우선
     bool 함수 시작(NODE 일, NODE 이){

        if(일.row < 이.row) return true;
        if(일.row > 이.row) return false;

        //크고 작은 것 비교 완료<- 여기까지 왔으면 row값이 같은 경우
        if(일.col > 이.col) return true;
        if(일.col < 이.col) return false;

        //여기까지 왔으면 row와 col이 완벽히 동일
        return false;
    
    }

    bool operator<(NODE 일, NODE 이){ // 노드 비교에 사용할 '<' 연산자를 만듦  -> 노드 두개에 대한 sort()비교를 sort(A,B,함수 시작)이 아니라 sort(A,B)로 하기 위해서

        if(일.row < 이.row) return true;
        if(일.row > 이.row) return false;

        //크고 작은 것 비교 완료<- 여기까지 왔으면 row값이 같은 경우
        if(일.col > 이.col) return true;
        if(일.col < 이.col) return false;

        //여기까지 왔으면 row와 col이 완벽히 동일
        return false;

    }

    *벡터 정렬
    vector<int> v = {5,9,1,3,6,7}
    sort(v.begin(), v.end());
  
    ->내림차순 주고싶으면 위에서 만든 함수 cmp사용
    sort(v.begin(), v.end(), cmp);



    */
   

    return 0;
}

