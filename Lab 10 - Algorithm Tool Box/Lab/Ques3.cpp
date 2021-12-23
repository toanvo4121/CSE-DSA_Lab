int uniqueNumber(int x) {
    if(x>45) return -1;
    vector<int> arr;
    bool co[10];
    for(int i=0;i<10;i++) co[i]=0;
    if (x<10) return x;
    else { 
        for(int i= 9; i>0; i--) {
            if (x<10) {
                if (!co[x]) { arr.push_back(x); break;} 
            }
            if (x<i) continue;
            if (i==0 && x>0) return -1;
            arr.push_back(i);
            x-=i;
            co[i]=1;
        }
        int S = 0;
        while(!arr.empty()){
            S=S*10 + arr.back();
            arr.pop_back();
        }
        return S;
    }
}