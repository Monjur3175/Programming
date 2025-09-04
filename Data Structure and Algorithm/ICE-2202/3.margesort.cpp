#include <bits/stdc++.h>
#include <vector>
using namespace std;

void do_merge(int l, int m, int r, vector<int> &v)
{
  int i = l, j = m;
  vector<int> temp;
  while (i < m and j < r)
  {
    if (v[i] < v[j])
    {
      temp.push_back(v[i]);
      i++;
    }
    else
    {
      temp.push_back(v[j]);
      j++;
    }
  }
  if (i < m)
  {
    for (; i < m; i++)
    {
      temp.push_back(v[i]);
    }
  }
  if (j < r)
  {
    for (; j < r; j++)
    {
      temp.push_back(v[j]);
    }
  }
  for (int y = 0; y < temp.size(); y++)
  {
    v[l + y] = temp[y];
  }
}
void merge_sort(int l, int r, vector<int> &v)
{
  cout << l << " " << r << endl;
  if (r - l == 1)
  {
    return;
  }
  int m = (l + r) / 2;
  merge_sort(l, m, v);
  merge_sort(m, r, v);
  do_merge(l, m, r, v);
}

int main()
{
  vector<int> v{10, 7, 9, 8, 1, 2, 3, 12, 5};
  merge_sort(0, 9, v);
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << ' ';
  }
  cout << endl;
}
