#include<vector>
#include<iostream>
#include<algorithm>

// void sls(std::vector<std::size_t>& v)
// {
//     for(std::size_t i = 0; i < v.size(); i++){
//         std::size_t* c = &v[i];
//         for(std::size_t j = i; j < v.size(); j++){
//             if(*c > v[j]){
//                 c = &v[j];
//             }
//         }
//         std::swap(*c,v[i]);
//     }
// }

void sls(std::vector<std::size_t>::iterator begin, std::vector<std::size_t>::iterator end)
{
    while(std::distance(begin,end)>1){
        std::iter_swap(begin,std::min_element(begin,end));
        begin++;
        sls(begin,end);
    }
}

int main()
{
    std::vector<std::size_t> v = {5,1,3,4,2};
    sls(v.begin(),v.end());
    for(std::size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << "\n";
}