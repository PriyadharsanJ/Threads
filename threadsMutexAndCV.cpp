#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

mutex m;
condition_variable cv;

bool ready = false;

void counters(int i, int j){

    unique_lock<mutex> lock(m);w
    cv.wait(lock, []{return ready;});
    if(i>j){
        for(i; i>=j ; i--){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    else{
        for(i; i<=j ; i++){
            cout<<i<<" ";
        }
    }
    cout<<endl;

}

int main(){

    cout<<"Main Thread started!\n";
    //thread worker(waitForSignal);
    thread worker1(counters, 100, 1);
    thread worker2(counters, 1, 100);

    this_thread::sleep_for(chrono::seconds(2));

    {
        lock_guard<mutex> lock(m);
        ready = true;
    }

    cv.notify_all();
    worker1.join();
    worker2.join();

    cout<<"Main thread finished.\n";

    return 0;
}

