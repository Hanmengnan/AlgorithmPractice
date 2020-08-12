#include <iostream>
#include <vector>

using namespace std;

typedef struct item
{
  int n, e;
} item;

int main()
{

  int n, a, b;

  vector<int> mul(2002, 0), add(2002, 0);
  vector<item> nums1, nums2;

  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> a >> b;
    nums1.push_back({a, b});
  }

  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> a >> b;
    nums2.push_back({a, b});
  }

  for (int i = 0; i < nums1.size(); ++i)
  {
    for (int j = 0; j < nums2.size(); ++j)
    {
      a = nums1[i].e + nums2[j].e + 1000;
      b = nums1[i].n * nums2[j].n;
      mul[a] += b;
    }
  }
  int flag = 0;
  for (int i = 2001; i >= 0; --i)
  {
    if (mul[i] != 0)
    {
      if (flag)
        cout << " " << mul[i] << " " << i - 1000;
      else
        cout << mul[i] << " " << i - 1000;
      flag = 1;
    }
  }

  if (flag == 0)
    cout << 0 << " " << 0 << endl;
  else
    cout << endl;

  for (int i = 0; i < nums1.size(); ++i)
  {
    a = nums1[i].e + 1000;
    b = nums1[i].n;
    add[a] += b;
  }
  for (int j = 0; j < nums2.size(); ++j)
  {
    a = nums2[j].e + 1000;
    b = nums2[j].n;
    add[a] += b;
  }

  flag = 0;
  for (int i = 2001; i >= 0; --i)
  {
    if (add[i] != 0)
    {
      if (flag)
        cout << " " << add[i] << " " << i - 1000;
      else
        cout << add[i] << " " << i - 1000;
      flag = 1;
    }
  }

  if (flag == 0)
    cout << 0 << " " << 0 << endl;

  return 0;
}