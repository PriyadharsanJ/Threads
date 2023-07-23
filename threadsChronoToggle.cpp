#include<iostream>
#include<chrono>
#include<thread>
#include<future>
#include<algorithm>
using namespace std;

int val = 0;

void Fun(){
    this_thread::sleep_for(chrono::milliseconds(5000));
}

int main(){

    future<void> f1 = async(Fun);
    future_status status;

    do{
        status = f1.wait_for(chrono::milliseconds(500));
        if(status == future_status::timeout){
            val = !val;
            cout<<val<<endl;
        }
    }while(status!=future_status::ready);

    //    cout<<"Future result : "<<f.get()<<endl;
    return 0;
}
