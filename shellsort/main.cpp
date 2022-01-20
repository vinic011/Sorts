#include<vector>
#include<iostream>
#include<algorithm>

void shells(std::vector<std::size_t>::iterator begin,std::vector<std::size_t>::iterator end)
{
    const std::size_t s = std::distance(begin,end);
    std::size_t h = 0;
    while(3*h+1 < s)
        h = 3*h + 1;
    while(h>=1){
        for(auto it = begin; it != end -h;it++){
            auto left = it;
            auto right = it+h;
            while(left>=begin){
                if(*left>*right)
                    std::iter_swap(left,right);
                right -= h;
                left-=h;
            }
        }
        h = h/3;
    }

  //   std::size_t s = std::distance(begin, end);
  //   std::size_t h = 0;


  // while (h < s)
  //   h = 3 * h + 1;


  // while (h > 1) {
  //   h = h / 3;
  //   for (auto next = begin + h; next < end; ++next)
  //     for (auto left = next - h, right = next; left >= begin && *left > *right; right = std::exchange(left, left - h))
  //       iter_swap(left, right);
  // }
}
int main()
{
    std::vector<std::size_t> v = {5,1,3,4,2};
    shells(v.begin(),v.end());
    for(std::size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << "\n";
}