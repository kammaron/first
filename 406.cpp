#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
		static bool comp(const pair<int ,int>& p1, const pair<int, int>& p2);
		static vector<pair<int, int> > reconstructQueue(vector< pair<int, int> >& people);
};
bool Solution::comp(const pair<int ,int>& p1, const pair<int, int>& p2)
{
	if(p1.first < p2.first) return false;
	else if(p1.first > p2.first) return true;
	else return (p1.second < p2.second);
}
vector<pair<int, int> > Solution::reconstructQueue(vector< pair<int, int> >& people)
{
	sort(people.begin(),people.end(),comp);
	vector<pair<int, int> > ret;
	vector<pair<int, int> >::iterator iter1 = people.begin();
	ret.push_back(*(iter1++));
	for(;iter1 != people.end();iter1++)
	{
		ret.insert(ret.begin() + (*iter1).second, *iter1);
	}
	return ret;


}
void display(vector< pair<int, int> >& people)
{
	for(int i=0;i<people.size();i++)
	{
		cout << people[i].first << "," << people[i].second << endl;
	}
}

int main()
{
	vector< pair<int,int> > input;
	vector< pair<int,int> > output;
	input.push_back(make_pair(7,0));
	input.push_back(make_pair(4,4));
	input.push_back(make_pair(7,1));
	input.push_back(make_pair(5,0));
	input.push_back(make_pair(6,1));
	input.push_back(make_pair(5,2));
	//sort(input.begin(),input.end(),Solution::comp);
	display(input);
	output = Solution::reconstructQueue(input);
	display(output);

}
