#include<iostream>
#include<vector>
#include<thread>
#include<atomic>
#include<algorithm>
using namespace std;

auto temp = 0;
void sortAsc(vector<int> &v1){
    for(int i=0; i<v1.size(); i++){
        for(int j=i+1; j<v1.size(); j++){
            if(v1[i] > v1[j]){
                temp = v1[i];
                v1[i] = v1[j];
                v1[j] = temp;
            }
        }
    }
}

void sortDesc(vector<int> &v1){
    for(int i=0; i<v1.size(); i++){
        for(int j=i+1; j<v1.size(); j++){
            if(v1[i] < v1[j]){
                temp = v1[i];
                v1[i] = v1[j];
                v1[j] = temp;
            }
        }
    }
}

int main(){

    vector<int> v1 = {1,6,3,5,2,7,8,9,4};

    thread t1(sortAsc, ref(v1));
    t1.join();
    for(int i : v1){
        cout<<i<<" ";
    }
    cout<<endl;
    thread t2(sortDesc, ref(v1));
    t2.join();
    for(int i : v1){
        cout<<i<<" ";
    }
    return 0;
}
