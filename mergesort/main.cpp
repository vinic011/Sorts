#include<vector>
#include<iostream>

void merge(std::vector<std::size_t>::iterator begin,std::vector<std::size_t>::iterator mid,std::vector<std::size_t>::iterator end)
{
    std::vector<std::size_t> v;
    auto a = begin, b = mid;
    while(a != mid && b != end){
        if(*a > *b){
            v.push_back(std::move(*b));
            b++;
        }else{
            v.push_back(std::move(*a));
            a++;
        }
    }
    std::move(a,mid,std::back_inserter(v));
    std::move(b,end,std::back_inserter(v));
    std::move(v.begin(),v.end(),begin);

}
void merges(std::vector<std::size_t>::iterator begin,std::vector<std::size_t>::iterator end)
{
    std::size_t s = std::distance(begin,end);
    if(s<=1)
        return;
    
    auto mid = begin + s/2;
    merges(begin,mid);
    merges(mid,end);
    merge(begin,mid,end);
}

int main()
{
    std::vector<std::size_t> v = {5,1,3,4,2};
    merges(v.begin(),v.end());
    for(std::size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << "\n";
}    