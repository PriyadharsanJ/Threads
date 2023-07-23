#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex mtx; // Mutex to synchronize access to the console

// Function to print even numbers from 2 to 20
void printEvenNumbers()
{
    for (int i = 2; i <= 20; i += 2)
    {
        unique_lock<mutex> lock(mtx); // Lock the mutex to ensure exclusive access to the console
        cout << i << ' ';
        lock.unlock(); // Unlock the mutex to allow other threads to access the console
    }
    cout << endl;
}

// Function to print odd numbers from 1 to 19
void printOddNumbers()
{
    for (int i = 1; i <= 19; i += 2)
    {
        unique_lock<mutex> lock(mtx); // Lock the mutex to ensure exclusive access to the console
        cout << i << ' ';
        lock.unlock(); // Unlock the mutex to allow other threads to access the console
    }
    cout << endl;
}

int main()
{
    thread evenThread(printEvenNumbers); // Create a thread to print even numbers
    thread oddThread(printOddNumbers);   // Create a thread to print odd numbers

    evenThread.join(); // Wait for the even numbers thread to finish
    oddThread.join();  // Wait for the odd numbers thread to finish

    return 0;
}
