#include <iostream>
#include <vector>

using namespace std;
pair <int, int> partition(vector <int> &arr, int l, int r);

void quicksort(vector<int>& arr, int left, int right) {
    if (left < right) {
        pair<int, int> pivot = partition(arr, left, right);
        quicksort(arr, left, pivot.first-1);
        quicksort(arr, pivot.second+1, right);
    }
}

pair <int, int> partition(vector <int> &arr, int l, int r)
{
    int pivot = arr[rand()%(r-l+1)+l];
    int less = l;
    int greater = r;
    int i = l;
    
    for (int i=l; i <= greater; ){  
        if (arr[i] < pivot){
            swap(arr[i], arr[less]);
            ++less;
            ++i;
        }
        else if (arr[i] > pivot){
            swap(arr[i], arr[greater]);
            --greater;
        }
        else
            ++i;
    }
    return make_pair(less, greater);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
	bool temp = false;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
    
    for (int i=0; i<n-1; ++i){
    	if(arr[i]>arr[i+1]){
    		temp = true;
	    	break;
    		}
    }
    
	if(temp)
		quicksort(arr, 0, n - 1);
		
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    
    system("pause");
	
    return 0;
}
