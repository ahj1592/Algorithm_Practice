/* MinAvgTwoSlice */

int solution(vector<int> &A) {
    int n = A.size();
    vector<int> sum(n + 1, 0);
    for(int i = 1; i < n + 1; i++) sum[i] = sum[i - 1] + A[i - 1];

    /* the number of elements of min_avg MUST be 2 or 3 */
    // case1: slice by 2
    double min_avg = 987654321;
    double min_index = 0;
    for(int i = 0; i < n - 1; i++){
        double avg = (double)(sum[i + 2] - sum[i]) / 2;
        if(avg < min_avg){
            min_avg = avg;
            min_index = i;
        }
    }

    // case2: slice by 3
    for(int i = 0; i < n - 2; i++){
        double avg = (double)(sum[i + 3] - sum[i]) / 3;
        if(avg < min_avg){
            min_avg = avg;
            min_index = i;
        }
    }
    return min_index;
}
