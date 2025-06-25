#include<bits/stdc++.h>

using namespace std;

struct Item{
    int value;
    int weight;
    double ratio;
    Item(int value, int weight): value(value), weight(weight){
        ratio = (double)value/weight;
    }
};
bool compare(Item a, Item b){
    return a.ratio > b.ratio;
}

vector<double> knapShack(int W, vector<int> &values, vector<int> &weights){
    int n = values.size();
    vector<Item> items;
    for(int i = 0; i < n; i++){
        items.push_back(Item(values[i], weights[i]));
    }
    sort(items.begin(), items.end(), compare);
    vector<double> xi(n, 0);
    int remainingWeight = W;
    for(int i = 0; i < n && remainingWeight > 0; i++){
        int idx = find(values.begin(), values.end(), items[i].value) - values.begin();
        if(remainingWeight >= items[i].weight){
            remainingWeight -= items[i].weight;
            xi[idx] = 1;
        } else {
            xi[idx] = double(remainingWeight)/double(items[i].weight);
            remainingWeight = 0;
        }
    }
    return xi;
}

int main(){
    vector<int> values = {60, 100, 120, 50};
    vector<int> weights = {10, 20, 30, 10};
    int W = 65; // Trọng lượng tối đa của ba lô
    // Gọi hàm xếp ba lô tham lam
    std::vector<double> result = knapShack(W, values, weights);
    // In ra kết quả
    cout << "Giải pháp: ";
    for (double x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}