#include <iostream>
#include "../../src/TStack.h"


using namespace std;



int main()
{
    TStack s;
    int vec[] = {1,2,3,4,5,6,7,8,9};
    int val;
    unsigned int i;
    s.begin();

    for(i=0;i<sizeof(vec)/sizeof(int);i++){
        if(s.push(&vec[i], sizeof(vec[i]))){
            cout<<"Se guardo:"<<vec[i]<<endl;
        }else{
            s.pop(&val, sizeof(val));
            cout<<"Pila llena, saco el ultimo elemento:"<<val<<endl;
        }
    }

    while(!s.isEmpty()){
        s.peek(&val, sizeof(val));
        cout<<"Peek:"<<val<<endl;
        s.pop(&val, sizeof(val));
        cout<<"pop:"<<val<<endl;
    }


    cout << "Hello world!" << endl;
    return 0;
}
