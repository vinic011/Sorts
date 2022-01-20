#include<vector>
#include<iostream>

// void bbs(std::vector<std::size_t>& v)
// {
//     for(std::size_t j = 0; j < v.size(); j++){
//         bool swapped = false;
//         for(std::size_t i = 0; i < v.size() - j;i++){
//             if(v[i+1]<v[i]){
//                 std::swap(v[i],v[i+1]);
//                 swapped = true;
//             }
//         }
//         if(swapped == false)
//             return;
//     }
// }

void bbs(std::vector<std::size_t>::iterator begin,std::vector<std::size_t>::iterator end)
{
    while(std::distance(begin,end) > 1){
        bool swapped = false;
        for(auto i = begin, j = i + 1;j < end; i++, j = i + 1){
            if(*i>*j)
                std::iter_swap(i,j);
                swapped = true;
        }
        if(!swapped)
            return;
        --end;
    }
}

int main()
{
    std::vector<std::size_t> v = {5,1,3,4,2};
    bbs(v.begin(),v.end());
    for(std::size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << "\n";
}