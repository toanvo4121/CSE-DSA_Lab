int countStop(int totalDistance, int maxDistanceFullTank, vector<int> stopPoint)
{
    stopPoint.push_back(totalDistance);
    int count = 0;
    int a = maxDistanceFullTank;
    if (a < stopPoint[0]) return -1;
    for (int i=0; i<(int)stopPoint.size()-1; i++){
        if (maxDistanceFullTank < stopPoint[i+1]-stopPoint[i]) return -1;
        if (i==0) a-=stopPoint[0];
        else a = a-(stopPoint[i]-stopPoint[i-1]);
        if (a < stopPoint[i+1] - stopPoint[i]){
            a = maxDistanceFullTank;
            count++;
        }
    }
    return count;
}