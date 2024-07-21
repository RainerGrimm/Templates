#include <iterator>
#include <forward_list>
#include <list>
#include <vector>
#include <iostream>

template<typename Iterator, typename Distance>
void advance_(Iterator& pos, Distance n){
    using category = typename std::iterator_traits<Iterator>::iterator_category;
   
   if constexpr (std::is_same<category, std::random_access_iterator_tag>::value){
        pos += n;
    }
    else if constexpr (std::is_same<category, std::bidirectional_iterator_tag>::value){
        if (n >= 0){
            while (n--) ++pos;
            
        }
        else{
            while (n++) --pos;
        }
    }
    else{  // input iterator 
        while (n--) ++pos;
    }
}
  
int main(){
    
    std::cout << '\n';
    
    std::vector<int> myVec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto myVecIt = myVec.begin();
    std::cout << "*myVecIt: " << *myVecIt << '\n';
    advance_(myVecIt, 5);
    std::cout << "*myVecIt: " << *myVecIt << '\n';
    
    std::cout << '\n';
    
    std::list<int> myList{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto myListIt = myList.begin();
    std::cout << "*myListIt: " << *myListIt << '\n';
    advance_(myListIt, 5);
    std::cout << "*myListIt: " << *myListIt << '\n';
    
    std::cout << '\n';
    
    std::forward_list<int> myForwardList{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto myForwardListIt = myForwardList.begin();
    std::cout << "*myForwardListIt: " << *myForwardListIt << '\n';
    advance_(myForwardListIt, 5);
    std::cout << "*myForwardListIt: " << *myForwardListIt << '\n';
    
    std::cout << '\n';
    
}
