#include <exception>
using namespace std;

class Exception : public exception{
public:
    const char* what() const noexcept override{
        return "List is empty";
    }
};

template<typename Type>

struct Element
{
    Type number;
    Element* pointer;
    Element(Type num, Element* ptr = nullptr) : number(num), pointer(ptr){}
};

template<typename Type>
class Linked_list
{
private:
    Element<Type>* ptr_last_item = nullptr;
public:
    void push(Type num){
        Element<Type>* element   = new Element<Type>(num, ptr_last_item);
        (*element).number  = num;
        (*element).pointer = ptr_last_item;
        ptr_last_item      = element;
    }
    void print(){
        Element<Type>* element = ptr_last_item;
        while((*element).pointer != nullptr){
            cout << (*element).number << " ";
            element = (*element).pointer;
        }   cout << (*element).number << endl;
    }
    bool is_empty(){
        return !ptr_last_item;
    }
    
    Type top(){
        if (is_empty())
            throw Invalid();
        return (*ptr_last_item).number;
    }
    Type pop(){
        if (is_empty())
            throw Invalid();
        Type return_value = (*ptr_last_item).number;
        Element<Type>* element = (*ptr_last_item).pointer;
        delete ptr_last_item;
        ptr_last_item = element;
        return return_value;
    }
};
