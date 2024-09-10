#include <iostream>
using namespace std;

int main() 
{
    float n1, n2;
    cout<<"Input 2 Numbers: ";
    cin>>n1>>n2;
    
    char op;
    cout<<"input an Operator: ";
    cin>>op;
    
    switch(op)
    {
    
    case '+':
    cout<<n1 + n2<<endl;
    break;
    
    case '-':
    cout<<n1 - n2<<endl;
    break;
    
    case '/':
    cout<<n1 / n2<<endl;
    break;
    
    case '*':
    cout<<n1 * n2<<endl;
    break;

    default:
    cout<<"Enter Another Operator"<<endl;
    break;
    }

    return 0;
} 