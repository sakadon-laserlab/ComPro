    // REP(i,(int)s.size()+1)REP(j,(int)t.size()+1) cout<<dp[i][j];
    // cout<<endl<<(int)s.size()<<endl;;

    // //DPループ
    // REP(i,s.size())REP(j,t.size()) {
    //     cout<<dp[i][j]<<endl;
    //     if(s[i] == t[j]) chmax(dp[i+1][j+1], dp[i][j] + 1);
    //     chmax(dp[i+1][j+1], dp[i+1][j]);
    //     chmax(dp[i+1][j+1], dp[i][j+1]);
    // }

    // //復元
    // string res = "";
    // int i = (int)s.size(), j = (int)t.size();
    // while (i > 0 && j > 0) {
    //     if (dp[i][j] == dp[i-1][j]) i--;
    //     else if (dp[i][j] == dp[i][j-1]) j--;
    //     else {
    //        res = s[i-1] + res;
    //        i--;
    //        j--; 
    //     }
    // }
    // cout<<dp[0][0]<<endl<<dp[1][1]<<endl<<dp[2][2]<<endl;
    // cout << res << endl;