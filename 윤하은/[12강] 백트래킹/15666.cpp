#include <iostream>
using namespace std;
int n, m;
int arr[10];
bool isUsed[10];
int nums[10];
void func(int k){
  if(k==m)
  {
    for(int i =0; i<m; i++)
      cout << arr[i];
    return;
  }
  for(int i = 0; i<n; i++)
    {
      if(!isUsed[nums[i]])
      {
        arr[k]=nums[i];
        isUsed[nums[i]] = true;
        func(k+1);
        isUsed[nums[i]] = false;
        
      }
    }
}
int main() {
  cin >> n >> m;
  for(int i = 0; i<n; i++)
    cin >> nums[i];

  func(0);
  
    
}
