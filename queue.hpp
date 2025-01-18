#pragma once 
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <string>
#include <queue>


class CallCenter{

    public:
        explicit CallCenter(int id_i = 0) : __id_max(id_i){
            std::cout <<  std::endl;
        } 
        void receive_call(const int); // Add a call at the back of the queue.
        void receive_call();
        int process_call(); // remove id from the call at the front of the queue.

    private:
    std::queue<int> callsQueue; // For storing ids of calls 
    int __id_max;// the greatest id 

};

class MerchOrderSystem {
    private:
        std::queue<int> priority_queue;
        std::queue<int> simple_queue;
    
    public:
        void place_holder(int orderID, bool isPriority);
        int fulfill_order();
};


#endif //QUEUE_HPP