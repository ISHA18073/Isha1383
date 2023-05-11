#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Job
{

int start, finish, profit;
};
int findLastNonConflictingJob(vector<Job> const &jobs, int n)
{
int low = 0;
int high = n;
while (low <= high)
{
int mid = (low + high) / 2;
if (jobs[mid].finish <= jobs[n].start)
{
if (jobs[mid + 1].finish <= jobs[n].start)
{
low = mid + 1;
}
else
{
return mid;
}
}
else
{
high = mid - 1;
}
}
return -1;
}
void findMaxProfitJobs(vector<Job> jobs)
{
sort(jobs.begin(),
jobs.end(),
[](Job &x, Job &y)
{
return x.finish < y.finish;
});
int n = jobs.size();
if (n == 0)
{
return;
}
int maxProfit[n];
vector<int> tasks[n];
maxProfit[0] = jobs[0].profit;
tasks[0].push_back(0);

for (int i = 1; i < n; i++)
{
int index = findLastNonConflictingJob(jobs, i);
int currentProfit = jobs[i].profit;
if (index != -1)
{
currentProfit += maxProfit[index];
}
if (maxProfit[i - 1] < currentProfit)
{
maxProfit[i] = currentProfit;
if (index != -1)
{
tasks[i] = tasks[index];
}
tasks[i].push_back(i);
}
else
{
tasks[i] = tasks[i - 1];
maxProfit[i] = maxProfit[i - 1];
}
}
cout << "The maximum profit is " << maxProfit[n - 1] << endl;
cout << "The jobs involved in the maximum profit are ";
for (int i : tasks[n - 1])
{
cout << "(" << jobs[i].start << ", " << jobs[i].finish << ", "
<< jobs[i].profit << ") ";
}
}
int main()
{
vector<Job> jobs{
{0, 6, 60},
{1, 4, 30},
{3, 5, 10},
{5, 7, 30},
{5, 9, 50},
{7, 8, 10}};
findMaxProfitJobs(jobs);
return 0;
}
