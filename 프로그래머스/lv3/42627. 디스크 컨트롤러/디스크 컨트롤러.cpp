#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

bool cmp2(vector<int> a, vector<int> b)
{
    if (a[1] == b[1])
        return a[0] < b[0];
    return a[1] < b[1];
}

int solution(vector<vector<int>> jobs) {
    
    int answer = 0;
    int finishCount = 0;
    int time = 0;
    int jobsIndex = 0;
    vector<vector<int>> run;
    
    sort(jobs.begin(), jobs.end(), cmp);

    while(finishCount < jobs.size())
    {
        if(jobsIndex < jobs.size() && jobs[jobsIndex][0] <= time){ //작업 끝나기 전 까지 들어온것들 넣기
            while (jobsIndex < jobs.size() && jobs[jobsIndex][0] <= time)
            {
                run.push_back(jobs[jobsIndex]);
                jobsIndex++;
            }
        }
        else if(run.empty())//들어온거 없으면
        {
            time = jobs[jobsIndex][0]; //시간이동
            continue;
        }
        sort(run.begin(), run.end(), cmp2);
        time += run[0][1]; // 끝난 기점으로 시간 갱신
        answer += (time - run[0][0]); // 현재 시간에서 시작 시간 빼서 더하기
        run.erase(run.begin() + 0);
        finishCount++;
    }
    
    return ((int)(answer / jobs.size()));
}