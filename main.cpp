#include <iostream>
#include "ForwardList.h"

using namespace std;

typedef ForwardList<int>::ForwardIterator fl_itr;

int main(){
    ForwardList<int>* fList = new ForwardList<int>();

     fList->push_back(3);
     fList->push_front(2);
    fList->push_front(1);
    fList->push_back(4);
    cout<<*fList<<endl;
    fList->pop_back();
    fList->pop_front();
    cout<<*fList<<endl;
    fList->drop(3);
    cout<<*fList<<endl;
    fList->clear();
    cout<<*fList<<endl;



}