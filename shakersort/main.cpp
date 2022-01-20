#include <vector>
#include <iostream>

// void sks(std::vector<std::size_t> &v)
// {
//     for (std::size_t j = 0; j < v.size(); j++)
//     {
//         bool swapped = false;
//         if (2*(j/2)-j == 0){
//             for (std::size_t i = j; i < v.size() - j; i++){
//                 if (v[i + 1] < v[i]){
//                     std::swap(v[i], v[i + 1]);
//                     swapped = true;
//                 }
//             }
//         }
//         else{
//             for (std::size_t i = v.size() - j -1; i > j - 1; i--){
//                 if (v[i + 1] < v[i]){
//                     std::swap(v[i], v[i + 1]);
//                     swapped = true;
//                 }
//             }
//         }
//         if (swapped == false)
//             return;
//     }
// }
void sks(std::vector<std::size_t>::iterator begin,std::vector<std::size_t>::iterator end)
{
    while(std::distance(begin,end)>1){
        auto left = begin;
        auto right = left + 1;
        bool swapped = false;
        while(right!=end){
            if(*left>*right){
                std::iter_swap(left,right);
                swapped = true;
            }
            left++;
            right++;
        }
        if(!swapped)
            return;
        begin++;
        
        right = end - 1;
        left = right - 1;
        swapped = false;
        while(left!=begin-1){
            if(*left>*right){
                std::iter_swap(left,right);
                swapped = true;
            }
            left--;
            right--;
        }
        if(!swapped)
            return;
        end--;
    }


}

int main()
{
    std::vector<std::size_t> v = {5, 1, 3, 4, 2};
    sks(v.begin(),v.end());
    for (std::size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << "\n";
}