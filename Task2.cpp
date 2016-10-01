#include<iostream>
#include<conio.h>
#include<time.h>
#include <algorithm>  
#include<vector>
using namespace std;
bool sorting(vector<int> &in, vector<int> &out);
bool test();
int main(){
	vector <int> topscore = {443,439,438,438,434,418,418,417,413,411,444};
	vector <int> out;
	sorting(topscore, out);
	if (test()){
		cout << "\n\n" << endl;
		cout << "Test Passed" << endl;
	}
	else
	{
		cout << "\n\n" << endl;
		cout << "Test Failed" << endl;
	}
	
	_getch();
}
bool sorting(vector<int> &in, vector<int> &out){
	int temp;
	out = in;
	if (!in.empty()){
		for (int i = 0; i < (in.size() - 1); i++){
			out[i] = in[i];
		}
		for (int i = 0; i < (out.size() - 1); i++){
			for (int j = 0; j < (out.size() - 1); j++){
				if (out[j]<out[j + 1]){
					temp = out[j];
					out[j] = out[j + 1];
					out[j + 1] = temp;

				}

			}
		}
		for (int i = 0; i < (out.size()); i++){
			cout << out[i] << endl;
		}
		return 1;
	}
	else
		return 0;
}
bool test(){
	int arr[10];
	for (int i = 0; i < 10; i++){
		arr[i] = 1 + rand() % 100;
	}
	vector<int>scores(arr, arr + sizeof(arr) / sizeof(int));
	sort(scores.begin(), scores.end());
	cout << "Sorted using algo." << endl;
	for (int i = 0; i < 10; i++){
		cout << scores[i] << endl;
	}
	scores.push_back(1 + rand() % 100);
	sort(scores.begin(), scores.end(), [](int a, int b){ return a>b; });
	cout << "Sorted using algo. after adding one more number" << endl;
	for (int i = 0; i < 10; i++){
		cout << scores[i] << endl;
	}
	vector<int> out;
	out = scores;
	cout << "Sorted using function." << endl;
	sorting(scores, out);
	for (int i = 0; i < 10; i++){
		if (scores[i] != out[i])return 0;
		else return 1;
	}
}
