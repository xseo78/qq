#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int median(vector<int>& coords) {
    sort(coords.begin(), coords.end());
    int n = coords.size();
    return coords[n / 2]; 
}

int main() {
    int N;
    cin >> N;
    
    vector<int> x_coords(N), y_coords(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> x_coords[i] >> y_coords[i];
    }
    
    int capital_x = median(x_coords);
    int capital_y = median(y_coords);
    
    cout << "Координати столиці: " << capital_x << " " << capital_y << endl;

    return 0;
}
