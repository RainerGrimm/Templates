#include <iterator>

template<typename Iterator, typename Distance>
void advance(Iterator& pos, Distance n){
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
    
}


