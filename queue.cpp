#include "queue.hpp"

int CallCenter::process_call(){
    if (callsQueue.empty())
    {
        std::cout << "The Queue of calls is empty " << std::endl;
        return -1;
    }else{
        int id_processed = callsQueue.front();
        callsQueue.pop();
        std::cout << "The call of id " << id_processed << " is running " << std::endl;
        return id_processed;
    }

}

void CallCenter::receive_call(const int id){
    if(id < __id_max){
        std::cout << "Error: This id can be ready in processing please choose an id greater than " << __id_max << std::endl;
        return;
    }else{
        __id_max = id;
        callsQueue.push(id); // Add the new call at the queue
        std::cout << "New call added successfully !" << std::endl;
    }
}
void CallCenter::receive_call(){
    int new_id = callsQueue.size() + 1;
    callsQueue.push(new_id);
    __id_max = new_id;
    std::cout << "New call added successfully !" << std::endl;
}

void MerchOrderSystem::place_holder(int orderID, bool isPriority = false){
    if(isPriority){
        priority_queue.push(orderID);
        std::cout << "Prioritary merch added successfully \n";
    }
    else
    {
        simple_queue.push(orderID);
    }
        
}
int MerchOrderSystem::fulfill_order(){
    if(!priority_queue.empty()){
        int orderID = priority_queue.front();
        priority_queue.pop();
        return orderID;
    }
    else if(!simple_queue.empty()){
        int orderID = simple_queue.front();
        simple_queue.pop();
        return orderID;
    }
    else{
        return -1;
    }
    
}