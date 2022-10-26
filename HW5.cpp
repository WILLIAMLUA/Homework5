//Xie, Kingsley
//Lua, William

#include<iostream>
#include<vector>

using namespace std;

// For this homework, you are going to implement an extendable vector based queue 
//that 
// uses "jump" trick to save space. 
// Finish function 
//              front() that prints the first element in the queue
//              deque() that dequeues the queue
//           enque(val) that enqueues val to the queue
//              print_vect() that prints out vect_que.
// Demonstrate that your code works in main.
// Refer to class PPT if you forgot all the different cases.

// required vector class
template <class T>
class vect_queue
{
    std::vector<T> vect;
    size_t size_;

    public:
    int que_front_, que_back_;
    
    // default constructor (vector)
    vect_queue()
    {
        size_ = 0;
        que_front_ = -1;
        que_back_ = -1;
    }

    // parameterized constructor
    vect_queue(T val)
    {
        vect.push_back(val);
        size_ = 1;
        que_front_ = 0;
        que_back_ = 0;
    }

    // return the first element of queue
    T front()
    {
        return vect.at(que_front_);
    }

    // remove element from front of queue
    void dequeue()
    {
        vect.erase(vect.begin());
        size_--;
        que_back_--;
        if (size_ == 0)
        que_front_ = -1;
    }

    // add element to the end of queue
    void enque(T val)
    {
        vect.push_back(val);
        size_++;
        que_back_++;
        if(que_front_ == -1)
        que_front_ = 0;
    }

    // print the vector
    void print_vect()
    {
        int i;
        for(i=0;i<size_;i++)
        cout << vect.at(i) << ", ";
        cout << endl;
    }
};

// tester code
int main()
{
    //Demonstrate your code works by adding/removing values in a vect_que class 
    //object. Print out your result.
    //You should include front index of queue, back index of queue, and the entire
    //vector (not queue) for each case.
    
    // create a class object
    vect_queue<int> v;
    
    //case 1:
    //add to an empty queue
    cout << "\nAdding to empty queue\n";
    v.enque(1);
    v.print_vect();
    cout << "Front index: " << v.que_front_ << endl;
    cout << "Back index : " << v.que_back_ << endl;
    
    //case2:
    //add to a non-empty queue without jump 
    cout << "\nAdding to non-empty queue\n";
    v.enque(1);
    v.print_vect();
    cout << "Front index: " << v.que_front_ << endl;
    cout << "Back index : " << v.que_back_ << endl;
    
    //case 3:
    //add to a non-empty queue with jump 
    cout << "\nAdding to non-empty queue\n";
    v.enque(2);
    v.print_vect();
    cout << "Front index: " << v.que_front_ << endl;
    cout << "Back index : " << v.que_back_ << endl;
    
    //case 4 & 5:
    //remove from a queue with number of elements > 1 
    //and que.front not at vect.back
    cout << "\nRemoving from queue with > 1 elements\n";
    v.dequeue();
    v.print_vect();
    cout << "Front index: " << v.que_front_ << endl;
    cout << "Back index : " << v.que_back_ << endl;

    //case 6:
    //remove from a queue with 1 element in it and que.front 
    cout << "\nRemoving from queue with 1 element\n";
    v.dequeue();
    v.print_vect();
    cout << "Front index: " << v.que_front_ << endl;
    cout << "Back index : " << v.que_back_ << endl;
    
    cout << "\nprogram ends here.\n";
    
    return 0;
}
