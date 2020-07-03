#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, m;
    cin >> n >> k >> m;
    vector<float> score;
    for (int i = 0; i < n; ++i)
    {
        vector<int> sum(k);
        for (int j = 0; j < k; ++j)
        {
            cin >> sum[j];
        }
        sort(sum.begin(), sum.end());
        int count = 0;
        for (int j = 1; j < k - 1; ++j)
        {
            count += sum[j];
        }
        score.push_back(double(count) / (k - 2));
    }
    sort(score.begin(), score.end());
    for (int i = score.size() - m; i < score.size() - 1; ++i)
    {
        printf("%.3f ", score[i]);
    }
    printf("%.3f", score[score.size() - 1]);

    return 0;
}