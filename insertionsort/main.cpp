#include<vector>
#include<iostream>

void iss(std::vector<std::size_t>::iterator begin,std::vector<std::size_t>::iterator end)
{
    for(auto it = begin; it != end;it++){
        auto left = it;
        auto right = it + 1;
        while(right!=begin){
            if(*left>*right)
                std::iter_swap(left,right);
            right--;
            left--;
        }
    }
}
int main()
{
    std::vector<std::size_t> v = {5,1,3,4,2};
    iss(v.begin(),v.end());
    for(std::size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << "\n";
}