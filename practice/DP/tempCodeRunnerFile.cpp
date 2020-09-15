    // REP(i,N)REPS(sum_w,W) {

    //     //i番目の品物を選ぶ場合
    //     if (sum_w - weight[i] >= 0) chmax(dp[i+1][sum_w], dp[i][sum_w - weight[i]] + value[i]);

    //     //i番目の品物を選ばない場合
    //     chmax(dp[i+1][sum_w], dp[i][sum_w]);
    // }