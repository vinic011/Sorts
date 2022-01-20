#include<vector>
#include<iostream>

void qks(std::vector<std::size_t>::iterator begin,std::vector<std::size_t>::iterator end)
{
    if(std::distance(begin,end)<=1)
        return;

    auto left = begin;
    auto right = end -1;
    auto pivot = *left;

    while(left!=right){
        while(left!=right && *left < pivot)
            left++;
        while(left!=right && *right > pivot)
            right--;
        if(left!=right)
            std::swap(*right,*left);
    }
    *left = pivot;
    qks(begin,left);
    qks(left+1,end);
}

int main()
{
    std::vector<std::size_t> v = {5,1,3,4,2};
    qks(v.begin(),v.end());
    for(std::size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << "\n";
}