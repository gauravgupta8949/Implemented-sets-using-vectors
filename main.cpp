#include<iostream>
#include<vector>

using namespace std;

int c,s,d;

//c represents command given
//s represents set number
//d represents data given
vector<vector<int>> sets(1);
vector<int> v;
vector<int> v1;
vector<int> v2;
vector<int> v3;
vector<int> v4;

class SET{
    public:
        void Insert();

        void Delete();

        void BelongsTo();

        void Union();

        void Intersection();

        void Size();

        void Difference();

        void SymmetricDifference();

        void Print();

};

bool isnumberthere(vector<int>& vec, int number) {
    for (int element : vec) {
        if (element == number) {
            return true;
        }
        
           
        }
     return false;
};
bool find(vector<int> set,int dat){
    for (int i = 0; i < set.size(); i++)
    {
        if(set[i]==dat){
            return true;
        }
    }
    return false;
}

int BinarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

void BubbleSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}



void SET::Insert(){
if(sets.size()<=s){
   sets.resize(s+1);
}

    if(sets[s].empty()){
   
    sets[s].push_back(d);
    cout<<sets[s].size()<<endl;
    }

    else{
        if(isnumberthere(sets[s],d)){
            cout<<sets[s].size()<<endl;
        }
        else{
            sets[s].push_back(d);
                cout<<sets[s].size()<<endl;
        }
    }
    

};


void SET::Delete(){

    if (sets.size()<=s){
        cout<<"-1"<<endl;
    }
    else{
        int result = BinarySearch(sets[s],d);
            if (result==-1){
                cout<<sets[s].size()<<endl;
            }
            else{
                sets[s].erase(sets[s].begin()+result);
                cout<<sets[s].size()<<endl;
            }
    }
    
};

void SET::BelongsTo(){
    if(sets.size()<=s){
        cout<<"-1"<<endl;
    }
    else if (isnumberthere(sets[s],d)){
        cout<<"1"<<endl;
    }
    else{
        cout<<"0"<<endl;
    }

};

void SET::Union(){
    if (sets.size()<=s){
        sets.resize(s+1);
    }
    if (sets.size()<=d){
        sets.resize(d+1);
    }
v2=sets[d];
    for (int num1 : sets[s]) {
        for (int num2 : sets[d]) {
            if (num1 == num2) {
                v1.push_back(num1);
            }
        }
    }
    for (int num3 : v1) {
        int result = BinarySearch(v2,num3);
        v2.erase(v2.begin()+result);
    }
    for (int num4 : v2){
        sets[s].push_back(num4);
    }
 
    v1.clear();
    v2.clear();
    cout<<sets[s].size()<<endl;    

};

void SET::Intersection(){
    if (sets.size()<=s){
        sets.resize(s+1);
    }
    if (sets.size()<=d){
        sets.resize(d+1);
    }

    for (int num1 : sets[s]) {
        for (int num2 : sets[d]) {
            if (num1 == num2) {
                v1.push_back(num1);
            }
        }
    }
sets[s]=v1;
v1.clear();
cout<<sets[s].size()<<endl;

};

void SET::Size(){

    if (sets.size()<=s){
        cout<<"0"<<endl;
        sets.resize(s+1);
    }
    else{
        cout<<sets[s].size()<<endl;
    }
 
};

void SET::Difference(){
   if(sets.size()<=s){
        sets.resize(s+1);
    }
    if(sets.size()<=d){
        sets.resize(d+1);
    }
    for(auto it=sets[s].begin();it !=sets[s].end();){
        if(find(sets[d],*it)){
            it = sets[s].erase(it);
        }
        else{
            ++it;
        }
    }

   cout<<sets[s].size()<<endl;

};

void SET::SymmetricDifference(){
     vector<int> sog4;
    if(sets.size()<=s){
        sets.resize(s+1);
    }
    if(sets.size()<=d){
        sets.resize(d+1);
    }
    for(auto it=sets[s].begin();it !=sets[s].end();it++){
        if(!find(sets[d],*it)){
            sog4.push_back(*it);

        };
    }
    for(auto it=sets[d].begin();it!=sets[d].end();it++){
        if(!find(sets[s],* it)){
            sog4.push_back(*it);
        }
    }
    sets[s]=sog4;
cout<<sets[s].size()<<endl;

sog4.clear();
};

void SET::Print(){

    if (sets.size()<=s || sets[s].size()==0){
        cout<<endl;
    }
    else{
        BubbleSort(sets[s]);
        for (int i = 0; i < sets[s].size()-1; ++i) {
        cout << sets[s][i] << ",";
        }
        cout<< sets[s][sets[s].size()-1]<<endl;
    }
    
};

int main(){

SET object;

while (cin>>c){
if (c==1){
    cin>>s>>d; 
    object.Insert();
}

else if (c==2){
    cin>>s>>d;
    object.Delete();
}

else if (c==3){
    cin>>s>>d;
    object.BelongsTo();
}

else if (c==4){
    cin>>s>>d;
    object.Union();
}

else if (c==5){
    cin>>s>>d;
    object.Intersection();
}

else if (c==6){
    cin>>s;
    object.Size();
}

else if (c==7){
    cin>>s>>d;
    object.Difference();
}

else if (c==8){
    cin>>s>>d;
    object.SymmetricDifference();
}

else if(c==9){
    cin>>s;
    object.Print();
}
}


return 0;
}