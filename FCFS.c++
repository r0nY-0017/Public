#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << "---------First Come First Service---------\n\n";
    int n, a,b,at, bt, ct, tat, wt;
    vector<vector<int>> FCFS;
    vector<int> v;
    cout << "Enter Number of Process: ";
    cin >> n;
    for(int i=0; i<n; i++){
        cout << "Enter AT & BT for Process-" << i+1 << " : ";
        cin >> a >> b;
        v.push_back(a);
        v.push_back(i+1);
        v.push_back(b);
        FCFS.push_back(v);
        v.clear();
    }

    sort(FCFS.begin(), FCFS.end());

    for(int i=0; i<n; i++){
        swap(FCFS[i].front(), FCFS[i][1]);
    }

    int cur = 0;
    int sum_at = 0, sum_bt = 0, sum_ct = 0;
    int sum_tat = 0, sum_wt = 0;
    cout << "\n\nGantt Chart:\n";
    cout << cur << "___";
    for(int i=0; i<n; i++){
        at = FCFS[i][1], sum_at += at;
        bt = FCFS[i][2], sum_bt += bt;

        if(at>cur){
            cout << "(Idle)___";
            cur = at;
            cout << cur << "___";
        }
        cout << "(P" << FCFS[i].front() << ")___";
        ct = cur + bt, sum_ct  += ct;
        tat = ct - at, sum_tat += tat;
        wt = tat - bt, sum_wt  += wt;
        FCFS[i].push_back(ct);
        FCFS[i].push_back(tat);
        FCFS[i].push_back(wt);
        cur = ct;
        if(i+1==n) cout << cur;
        else cout << cur << "___";
    }
    
    sort(FCFS.begin(), FCFS.end());

    cout << "\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i=0; i < FCFS.size(); i++){
        for(int j=0; j < FCFS[i].size(); j++){
            if(j==0) cout << "P";
            cout << FCFS[i][j] << "\t";
        }    
        cout << endl;
    }
    cout << "------------------------------------------\n";
    cout << "Total\t" << sum_at << "\t" << sum_bt << "\t";
    cout << sum_ct << "\t" << sum_tat << "\t" << sum_wt << "\n";
    cout << "\nAverage TAT : " << (float(sum_tat)/n) << endl;
    cout << "Average WT : " << (float(sum_wt)/n) << endl;
return 0;
}
