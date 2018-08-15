#include <iostream>
using namespace std;

//call by reference
void swap(char* &a, char* &b){
    char *temp = b;
    b = a;
    a = temp;
}

int main(){
    char *str1 = "apple";
    char *str2 = "mango";
    swap(str1, str2);
    cout<<"str1 is "<<str1<<", str2 is "<<str2<<endl;
    return 0;
}


//Method 2 : by passing addresses
/*void swap(char **a, char **b){
    char *temp = *b;
    *b = *a;
    *a = temp;
}

int main(){
    char *str1 = "apple";
    char *str2 = "mango";
    swap(&str1, &str2);
    cout<<"str1 is "<<str1<<", str2 is "<<str2<<endl;
    return 0;
}*/